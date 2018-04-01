# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday,ep2JD
from Fileio import Banner,errmsg,ReadStationFile,ReadNoradTLE,STKout,anyKey,STKpoint
import tkinter as tk
from tkinter import filedialog
import numpy as np
import datetime as dt
import time

from OMPython import ModelicaSystem

# startup
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
# comody
print("  ___          _         ___     ")
print(" |   |        |_|       |   |  ")
print(" |___|         ___      |___| ")
print("\  |  /        | |    \ \ |   ")
print(" \_|_/         | |     \_\|   ")
print("  _|_           |        _|    ")
print(" | | |          |      _/  \_   ")
print("_|   |_         |            |\n")
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

mod = ModelicaSystem('./Sattraj.mo', "Sattraj.Master","Modelica.Constants\n")
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
    
       
    mod.setParameters(raan2=TLEData[i].raan, inc2=TLEData[i].incl, argper2=TLEData[i].argper, az_vel_lim2 = Station.az_el_nlim, el_vel_lim2=Station.az_el_nlim, din2=JDates[0], tm2 =JDates[1])
    mod.setParameters(**{"GPS.M0":TLEData[i].meanan, "GPS.N0":TLEData[i].meanmo, "GPS.ecc":TLEData[i].eccn, "GPS.Ndot2":TLEData[i].ndot, "GPS.Nddot6":0, "GPS.tstart":delta_tstart[i]})
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
    #print(len(Azarray))
    #print(float(Station.az_el_lim.elmax[0]))
    for j in range(0,len(times[i])-1):
        if El.item(j) < float(Station.az_el_lim.elmax[0]) and El.item(j) > float(Station.az_el_lim.elmin[0]) and Az.item(j) != 10^60 and El.item(j) != 10^60:
            if start == False:
                start = True;
                startTime= times[i][j];
                startTimes[i]=startTime;
                startTimesIndex[i]=j;
            else:
                satDuration= satDuration + 60;
        else:
            if start != False:
                break;
    startDelta = strt + dt.timedelta(seconds=startTime);
    endDelta = strt + dt.timedelta(seconds=startTime+satDuration);
    
    if satDuration==0
        continue;
    
    print("   " + '{:2d}'.format(i) + "      " + TLEData[i].name + "   " + str(startDelta) + "   " + str(endDelta));
    

    time.sleep(3)

#times = initalize array of durations // # of seconds each sat is avaiable during interval
a = int(input("\n Please select a satellite by its number \n"))
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
print("             UTC                Az [deg]          El [deg]            Az-vel [deg/sec]           Elz-vel [deg/sec]         Range [km]         Range Rate [km/sec]   Doppler[kHz]  Level [dBm]")
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
UTC = strt + dt.timedelta(seconds=startTimes[a])

azumith = Azarray[a][startTimesIndex[a]];
elevation = Elarray[a][startTimesIndex[a]];
dazumith = dAzarray[a][startTimesIndex[a]];
delevation = dElarray[a][startTimesIndex[a]];
#STKpoint('Pointing_Satellite_'+str(a),times[a],Azarray[a],Elarray[a]);
print( str(UTC) +"          "+ str(azumith) +"            "+ str(elevation) +"          "+ str(dazumith) +"         "+ str(delevation))  
