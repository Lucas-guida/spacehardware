# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday,ep2JD
from Fileio import Banner,errmsg,ReadStationFile,ReadNoradTLE,STKout,anyKey,STKpoint,CompFile
import tkinter as tk
from tkinter import filedialog
import numpy as np
import datetime as dt
import time
import math
from minLB import minLB

from OMPython import ModelicaSystem

################################################################################################################
# startup and user input
################################################################################################################
Banner();

root = tk.Tk()
root.withdraw()
# get filepath from user
Station_fp = filedialog.askopenfilename(title = "Select the file containing station parameters");
TLE_fp = filedialog.askopenfilename(title = "Select latest NORAD TLE");
#get start and stop times from user
start_time = input("Please enter the start time of your tracking period in YYYY/MM/DD HH:MM:SS.SSSSSS\n");
duration = input("Please enter the duration of your tracking period in min.\n");

duration = np.float(duration)*60; #conversion to seconds for OM Simulation time
strt = dt.datetime.strptime(start_time[:19],'%Y/%m/%d %H:%M:%S');
mills = int(float(start_time[19:])*1000*1000);
dat = dt.timedelta(microseconds=mills);
strt=strt + dat;

# read station file with station params
Station = ReadStationFile(Station_fp);
print("The station file was successfully read...");
# create database of TLE's for all satellites
tlefile = open(TLE_fp, 'r');
print("The TLE file was successfully read...\n");

################################################################################################################
# Read in Link information from User
################################################################################################################
Di = input("What is the dish diameter [m]: ");
Freq = input("What is the frequency [GHz]: ");
EIRP = input("What is the EIRP [dBW]: ");

################################################################################################################
#Giving the user the option to see the selected TLE's
################################################################################################################
view = input("Would you like to view the TLE's [Y/N] (Caps important): ")

################################################################################################################
# Array Setup
################################################################################################################

numSat = sum(1 for line in tlefile)/3;
tlefile.close();

tlefile = open(TLE_fp, 'r');
TLES = [['']*3 for i in range(int(numSat))]

for i in range(0,int(numSat)):
    for j in range(0,3):
        line=tlefile.readline();
        TLES[i][j] = line[0:-2];

#extracting TLE information
TLEData = [()]*int(numSat);
for i in range(0,int(numSat)):
    TLEData[i] = ReadNoradTLE(TLES[i][0],TLES[i][1],TLES[i][2]);
    if view == 'Y':
        print("Name: "+TLEData[i].name + " RAAN: "+ str(TLEData[i].raan) + " ArgPer: "+ str(TLEData[i].argper) + " inc: "+ str(TLEData[i].incl))
print("\n")
#find delta t from epoch to tstart 
delta_tstart = [0]*(int(numSat));

stepSize =60;

times = [['']*int(duration/stepSize) for i in range(int(numSat))];
Azarray = [['']*int(duration/stepSize) for i in range(int(numSat))];
Elarray = [['']*int(duration/stepSize) for i in range(int(numSat))];
dAzarray = [['']*int(duration/stepSize) for i in range(int(numSat))];
dElarray = [['']*int(duration/stepSize) for i in range(int(numSat))];
startTimes = ['']*int(duration/stepSize);
startTimesIndex = ['']*int(duration/stepSize);
distance = ['']*int(numSat)
ddis = ['']*int(numSat)
dB = ['']*int(numSat)

#####################################################################################################################
# Computing positional information for each sat
#####################################################################################################################

mod = ModelicaSystem('./Sattraj.mo', "Sattraj.Master","Modelica.Constants\n")
print("\n##############################################################################################################################")
print("  Sat No.          Name                         AOS                          LOS                  Min. Expected Level (dBm)");
for i in range(0,int(numSat),1):
#for i in range(0,0,1):
#i = 0  
    curr_sat = TLEData[i];
    curr_epoch = ep2dat(curr_sat.refepoch);
    delta_tstart[i] = (strt - curr_epoch).total_seconds();
        
    #Start OM connection
    # now we use this information to generate the LOS times
    stepSize=60;
    JDates = ep2JD(strt);
    
       
    mod.setParameters(az_vel_lim2 = Station.az_el_nlim, el_vel_lim2=Station.az_el_nlim, din2=JDates[0], tm2 =JDates[1])
    mod.setParameters(**{"GPS.argper0":TLEData[i].argper,"GPS.inc":TLEData[i].incl,"GPS.raan0":TLEData[i].raan,"GPS.M0":TLEData[i].meanan, "GPS.N0":TLEData[i].meanmo, "GPS.ecc":TLEData[i].eccn, "GPS.Ndot2":TLEData[i].ndot, "GPS.Nddot6":0, "GPS.tstart":delta_tstart[i]})
    mod.setParameters(**{'ARO.elevation':Station.stnalt, 'ARO.latitude':Station.stnlat, 'ARO.longitude': Station.stnlong})
    mod.setSimulationOptions(stopTime=duration, stepSize=stepSize)
    mod.setSimulationOptions(startTime=0.)
    mod.simulate()
    (times[i],Az,El,dAz,dEl)=mod.getSolutions("time","azimuth2","elevation2","dAz2","dEl2");
    Azarray[i] =Az; 
    Elarray[i] =El; 
    dAzarray[i] =dAz; 
    dElarray[i] =dEl;
    
    if i == 3:
        Azarrayasd =Az; 
        Elarrayasd =El; 
        dAzarrayasd =dAz; 
        dElarrayasd =dEl;
        
    start= False;
    startTime=0;
    satDuration=0;
    ##################################################################################################################
    #Computing the AOS AND LOS
    ##################################################################################################################
    for j in range(0,len(times[i])-1):
        if El.item(j) < float(Station.az_el_lim.elmax[0]) and El.item(j) > float(Station.az_el_lim.elmin[0]) and Az.item(j) != 10^60 and El.item(j) != 10^60:
            if start == False:
                start = True;
                
                (x,y,z)=mod.getSolutions("p3.x","p3.y","p3.z")
                xs=x[j]
                ys=y[j]
                zs=z[j]
                AzS=Az.item(j)
                ElS=El.item(j)
                distance[i] = math.sqrt(ys**2 + ys**2 + ys**2)
                r2 = math.sqrt(x[j+1]**2 + y[j+1]**2 + z[j+1]**2)
                ddis[i] = (r2 - distance[i])/60; 
                startTime= times[i][j];
                startTimes[i]=startTime;
                startTimesIndex[i]=j;
            else:
                satDuration= satDuration + 60;
        else:
            if start != False:
                xf=x[j]
                yf=y[j]
                zf=z[j]
                Azf=Az.item(j)
                Elf=El.item(j)
                break;
    startDelta = strt + dt.timedelta(seconds=startTime);
    endDelta = strt + dt.timedelta(seconds=startTime+satDuration);
    
    if satDuration==0:
        continue;
    
    # outputs for testing    
    if i == 0:
        (x,y,z,xv,yv,zv)=mod.getSolutions("GPS.p_sat_p.x","GPS.p_sat_p.y","GPS.p_sat_p.z","GPS.v_sat_p.x","GPS.p_sat_p.y","GPS.p_sat_p.z")
        STKout('periNEW',"22 Feb 2005 21:15:59.638752",times[0],"Custom Perifocal CentralBody/Earth",[x,y,z],[xv,yv,zv])
    
    if i == 0:
        (x,y,z,xv,yv,zv)=mod.getSolutions("p.x","p.y","p.z","v.x","v.y","v.z")
        STKout('eciNEW',"22 Feb 2005 21:15:59.638752",times[0],"Earth",[x,y,z],[xv,yv,zv])
        
    if i == 0:
        #print(curr_epoch)
        (x,y,z,xv,yv,zv,timeSTK)=mod.getSolutions("p3.x","p3.y","p3.z","v3.x","v3.y","v3.z","time")
        STKout('topoNEW',"22 Feb 2005 21:15:59.638752",times[0],"Custom Topo Facility/Algonquin",[x,y,z],[xv,yv,zv])
    
    # computing the EIRP*Ls*La*Gr
    AOSdB = minLB(AzS, ElS, xs,ys,zs,float(Di),float(Freq),float(EIRP))
    LOSdB = minLB(Azf, Elf, xf,yf,zf,float(Di),float(Freq),float(EIRP))
    dB[i] = min(AOSdB, LOSdB)
    
    print("   " + '{:2d}'.format(i) + "      " + TLEData[i].name + "   " + str(startDelta) + "   " + str(endDelta) +  "        " +str(dB[i]));
    

    time.sleep(3)

##############################################################################################################################################
# Outputs selcected sat to user
##############################################################################################################################################
#times = initalize array of durations // # of seconds each sat is avaiable during interval
a = int(input("\nPlease select a satellite by its number: "))
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
print("            UTC                 Az [deg]      El [deg]      Az-vel [deg/sec]      Elz-vel [deg/sec]      Range [km]      Range Rate [km/sec]       Doppler[kHz]       Level [dBm]")
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
UTC = strt + dt.timedelta(seconds=startTimes[a])

azumith = Azarray[a][startTimesIndex[a]];
elevation = Elarray[a][startTimesIndex[a]];
dazumith = dAzarray[a][startTimesIndex[a]];
delevation = dElarray[a][startTimesIndex[a]];
#STKpoint('Pointing_Satellite_'+str(a),times[a],Azarray[a],Elarray[a]);
# BW is 2 MHz
# cacculating approx dopler shift should probaby refine
vs=14000;
vo=11805.92033;
if ddis[a]>=0:
   f = (2.99*10**8 - vo)*1.57542/(2.99*10**8 + vs) - 1.57542
else:
   f = (2.99*10**8 + vo)*1.57542/(2.99*10**8 - vo) - 1.57542

CompFile(TLEData[a].name, UTC, azumith,dazumith ,elevation,delevation)

print( str(UTC) +"      "+ str(round(azumith,2)) +"         "+ str(round(elevation,2)) +"                "+ str(round(dazumith,2)) +"                   "+ str(round(delevation,2)) + "              " + str(round(distance[a],2)) + "                   " + str(round(ddis[a],2)) + "       " + str(f*10**6) + "    "+str(round(dB[a],2)))  
