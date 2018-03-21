# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday,ep2JD
from Fileio import Banner,errmsg,ReadStationFile,ReadNoradTLE,STKout,anyKey
import tkinter as tk
from tkinter import filedialog
import numpy as np
import datetime as dt

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
strt=strt+dat;
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
#for i in range(0,int(numSat),1):
i = 0  
curr_sat = TLEData[i];
curr_epoch = ep2dat(curr_sat.refepoch);
delta_tstart[i] = (strt - curr_epoch).total_seconds();
    
#Start OM connection
# now we use this information to generate the LOS times
stepSize=60;
"""
times = [['']*int(duration/stepSize) for i in range(int(numSat))];
xs = [['']*int(duration/stepSize) for i in range(int(numSat))];
ys = [['']*int(duration/stepSize) for i in range(int(numSat))];
zs = [['']*int(duration/stepSize) for i in range(int(numSat))];
"""
mod = ModelicaSystem('./Sattraj.mo', "Sattraj.Master","Modelica.Constants")
#for i in range(0,int(numSat)):
i = 0;
# function paramaters // need to add din and tm
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
print('Displaying satellite: '+ TLEData[i].name)
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
mod.setParameters(raan2=TLEData[i].raan, inc2=TLEData[i].incl, argper2=TLEData[i].argper, az_vel_lim2 = Station.az_el_nlim, el_vel_lim2=Station.az_el_nlim )
mod.setParameters(**{"GPS.M0":TLEData[i].meanan, "GPS.N0":TLEData[i].meanmo, "GPS.ecc":TLEData[i].eccn, "GPS.Ndot2":TLEData[i].ndot, "GPS.Nddot6":0, "GPS.tstart":delta_tstart[i]})
mod.setParameters(**{'ARO.elevation':Station.stnalt, 'ARO.latitude':Station.stnlat, 'ARO.longitude': Station.stnlong})
print("\nDisplaying the set parameters")
print("---------------------------------------------------")
print(mod.getParameters())
print('\n Simulating please wait\n')
mod.setSimulationOptions(stopTime=duration, stepSize=stepSize)
mod.setSimulationOptions(startTime=0.)
mod.simulate()
print('Displaying the set of ouputs')
print("---------------------------------------------------")
print(mod.getSolutions())
(times,xs,ys,zs)=mod.getSolutions("time","p3.x","p3.y","p3.z")
#times = initalize array of durations // # of seconds each sat is avaiable during interval