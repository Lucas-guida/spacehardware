# Master.py- main program which calls other subfunctions
from Datefun import doy,frcofd,ep2dat,curday
from Fileio import Banner,errmsg,ReadStationFile,ReadNoradTLE,STKout,anyKey
import tkinter as tk
from tkinter import filedialog
import numpy as np

root = tk.Tk()
root.withdraw()
# get filepath from user
station_fp = filedialog.askopenfilename();
TLE_fp = filedialog.askopenfilename();
# read station file with station params
Station = ReadStationFile(station_fp);
# create database of TLE's for all satellites
TLE_file = open(TLE_fp)
