def Banner():
    print ("---------------------------------------------------")
    print ("ENG4350: Lucas Santaguida and Mohammed Kagalwala")
    print ("Space Hardware")
    print ("2018-02-28")
    print ("Version 0.1")
    print ("Welcome to our ARO tracker")
    print ("---------------------------------------------------")
    return;
    
    # ERRMSG()
# This function will display an error meassage to the console, and provide an auditory warning.
def errmsg(string):
    import winsound
    duration = 500  # millisecond
    freq = 440  # Hz
    winsound.Beep(freq, duration)
    print(string)
    return

from collections import namedtuple
"""
from tkinter import filedialog
from tkinter import *

root = Tk()
root.filename =  filedialog.askopenfilename(initialdir = "/",title = "Select file",filetypes = (("jpeg files","*.jpg"),("all files","*.*")))
"""
def ReadStationFile(filename):
    file = open(filename,"r");
    n = 12;
    count =0;
    data=[None]*n;
    
    for line in file:
        data[count]=line;
        count = count +1;
        
    
    StationSet = namedtuple('Station',['name','stnlat','stnlong','stnalt',\
                                       'utc_offset','az_el_nlim','az_el_lim',\
                                       'st_az_speed_max','st_el_speed_max']);
    
    az_el_limSet = namedtuple('az_el_limSet',['az','elmin','elmax']);
    
    
    az_el_lim = az_el_limSet(data[6][:-1],data[7][:-1],data[8][:-1]);
    
    Station = StationSet(data[0][:-1],data[1][:-1],data[2][:-1],data[3][:-1],\
                         data[4][:-1],data[5][:-1],az_el_lim,data[9][:-1],\
                         data[10]);
                         
    return Station;

#from collections import namedtuple

def ReadNoradTLE(line0,line1,line2):
    SatelliteSet = namedtuple('Satellite',['name','refepoch','incl','raan', \
    'eccn','argper','meanan','meanmo','ndot','nddot6','bstar','orbitnum'])
    
    name = line0;
    
    lineTemp1 = line1.split(" ");
    
    refepoch = lineTemp1[3];
    ndot = lineTemp1[4];
    nddot6 = lineTemp1[5];
    bstar = lineTemp1[6];
    orbitnum = lineTemp1[8];
    
    lineTemp2 = line2.split(" ");
    
    incl = lineTemp2[2];
    raan = lineTemp2[3];
    eccn = lineTemp2[4];
    argper = lineTemp2[5];
    meanan = lineTemp2[6];
    meanmo = lineTemp2[7];    
    
    Satellite = SatelliteSet(name,refepoch,incl,raan,eccn,argper,meanan,meanmo\
                             ,ndot,nddot6,bstar,orbitnum);
    return Satellite