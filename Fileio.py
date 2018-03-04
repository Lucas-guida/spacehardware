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

#from collections import namedtuple
from collections import namedtuple
"""
from tkinter import filedialog
from tkinter import *

root = Tk()
root.filename =  filedialog.askopenfilename(initialdir = "/",title = "Select file",filetypes = (("jpeg files","*.jpg"),("all files","*.*")))
"""
def ReadStationFile(filename):
    file = open(filename,"r");
    m = 8; #no. of fixed params
    count = 0;
    count1 = 0;

    #count the no. of lines in a file
    with open(filename) as f:
        for n, l in enumerate(f):
            pass
    f.close()
    n = n+1
    data=[None]*m;
    data_az = [None]*(n-m+1)
    data_elmin = [None]*(n-m+1)
    data_elmax = [None]*(n-m+1)
    
    #start collecting data
    for line in file:
        if line.find(",") == -1 :
            data[count] = line;
            count = count +1;
        else : #lines containing az elmin and elmax
            [az,elmin,elmax] = line.split(",");
            data_az[count1] = az;
            data_elmin[count1] = elmin[1:];
            data_elmax[count1] = elmax[1:-1];
            count1 = count1 + 1;
    #append additional 360 deg point
    data_az[count1]= '360';
    data_elmin[count1]= data_elmin[0];
    data_elmax[count1]= data_elmax[0];
    
    StationSet = namedtuple('Station',['name','stnlat','stnlong','stnalt',\
                                   'utc_offset','az_el_nlim','az_el_lim',\
                                      'st_az_speed_max','st_el_speed_max']);
    
    az_el_limSet = namedtuple('az_el_limSet',['az','elmin','elmax']);
    
    
    az_el_lim = az_el_limSet(data_az,data_elmin,data_elmax);
    
    Station = StationSet(data[0][:-1],data[1][:-1],data[2][:-1],data[3][:-1],\
                    data[4][:-1],data[5][:-1],az_el_lim,data[6][:-1],\
                   data[7]);
    file.close()
    return Station

def ReadNoradTLE(line0,line1,line2):
    SatelliteSet = namedtuple('Satellite',['name','refepoch','incl','raan', \
    'eccn','argper','meanan','meanmo','ndot','nddot6','bstar','orbitnum'])
    
    name = line0;
    
    lineTemp1 = line1.split(" ")
    
    refepoch = lineTemp1[18:31];
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