# -*- coding: utf-8 -*-
"""
Created on Sun Mar  4 16:08:14 2018

@author: Mohammed
"""
from collections import namedtuple
filename = 'station.dat';
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
    else : #line containing az elmin and elmax
        [az,elmin,elmax] = line.split(",");
        data_az[count1] = az;
        data_elmin[count1] = elmin[1:];
        data_elmax[count1] = elmax[1:-1];
        count1 = count1 + 1;
#append additional 360 point
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