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
    
    
    az_el_lim = az_el_limSet(data[6],data[7],data[8]);
    
    Station = StationSet(data[0],data[1],data[2],data[3],data[4],data[5],\
                         az_el_lim,data[9],data[10]);
                         
    return Station;
