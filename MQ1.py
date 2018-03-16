from Fileio import ReadNoradTLE

import datetime as dt;
import numpy as np;

tlefile = open(r'gps-ops_180315.txt', 'rt');

line0 = tlefile.readline();
line1 = tlefile.readline();
line2 = tlefile.readline();

tlefile.close();

data = ReadNoradTLE(line0,line1,line2);
epoch = data.refepoch;
print(data)
# these do the same thing
refepochFloat = np.float(epoch);
refepochFloat
# these do the same thing
refepochString = line1[18:32];
refepochString

RefEpochdt = dt.datetime.strptime(refepochString[:5], '%y%j');

dfrac = refepochFloat - np.int(refepochFloat);
hr =  9;
rem = dfrac*24 - hr;
mins = 36;
rem2 = rem*60 - mins;
secs = np.int(60*rem2);
mics = np.int((rem2*60 - secs)*10**6);

RefEpochdt = RefEpochdt.replace(day=15, hour=hr, minute=mins, second=secs, microsecond=mics);
print(RefEpochdt)
