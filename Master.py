# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday,ep2JD
from Fileio import Banner,errmsg,ReadStationFile,ReadNoradTLE,STKout,anyKey
import tkinter as tk
from tkinter import filedialog
import numpy as np

# startup
Banner();
stringText = input("Please write the name of the textfile ie. text.txt \n")

tlefile = open(stringText, 'r');
print("the file was successfully read...");

numSat = sum(1 for line in tlefile)/3;
tlefile.close();

tlefile = open(stringText, 'r');
TLES = [['']*3 for i in range(int(numSat))]


for i in range(0,int(numSat)):
    for j in range(0,3):
        line=tlefile.readline();
        TLES[i][j] = line[0:-2];

#extracting TLE information
TLEData = [()]*int(numSat);
for i in range(0,int(numSat)):
    TLEData[i] = ReadNoradTLE(TLES[i][0],TLES[i][1],TLES[i][2]);


# now we use this information to generate the LOS times

#times = initalize array of durations // # of seconds each sat is avaiable during interval

epoch = ep2JD(TLEData[0].refepoch);



'''
for sat i in TLEData
    get time from epoch to start of tracking time
    pass TLE data into satelite model in OM
    run it through ECI -> ECF -> look angles
    get array back that would have look angles for the duration with 1e60 when it cant find it
    determine durations 
'''

"""this code is broken what you do
root = tk.Tk()
root.withdraw()
# get filepath from user
station_fp = filedialog.askopenfilename();
TLE_fp = filedialog.askopenfilename();
# read station file with station params
Station = ReadStationFile(station_fp);
# create database of TLE's for all satellites
TLE_file = open(TLE_fp)
"""