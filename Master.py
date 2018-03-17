# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday,ep2JD
from Fileio import Banner,errmsg,ReadStationFile,ReadNoradTLE,STKout,anyKey
import tkinter as tk
from tkinter import filedialog
import numpy as np
import datetime as dt

# startup
Banner();

root = tk.Tk()
root.withdraw()
# get filepath from user
Station_fp = filedialog.askopenfilename(title = "Select the file containing station parameters");
TLE_fp = filedialog.askopenfilename(title = "Select latest NORAD TLE");
#get start and stop times from user
start_time = input("Please enter the start time of your tracking period in YYYY/MM/DD HH:MM:SS\n");
duration = input("Please enter the duration of your tracking period in min.\n");

duration = np.float(duration)*60; #conversion to seconds for OM Simulation time
strt = dt.datetime.strptime(start_time,'%Y/%m/%d %X');

# read station file with station params
Station = ReadStationFile(Station_fp);
print("The station file was successfully read...\n");
# create database of TLE's for all satellites
tlefile = open(TLE_fp, 'r');
print("The TLE file was successfully read...\n");

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
for i in range(0,int(numSat),1):
    curr_sat = TLEData[i];
    curr_epoch = ep2dat(curr_sat.refepoch);
    delta_tstart[i] = (strt - curr_epoch).total_seconds();
    
#Start OM connection
# now we use this information to generate the LOS times

#times = initalize array of durations // # of seconds each sat is avaiable during interval


'''
for sat i in TLEData
    get time from epoch to start of tracking time
    pass TLE data into satelite model in OM
    run it through ECI -> ECF -> look angles
    get array back that would have look angles for the duration with 1e60 when it cant find it
    determine durations 
'''
