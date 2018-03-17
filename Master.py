# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday
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