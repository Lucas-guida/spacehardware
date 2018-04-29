import datetime as dt
import numpy as nm
import math

tlefile = open(r'C:\Users\Mohammed\Desktop\YorkU\trackingARO\test_date.txt','rt')

line0 = tlefile.readline();
line1 = tlefile.readline();
line2 = tlefile.readline();

tlefile.close()

print(line0,line1,line2)
# pull out Reference Epoch
refEpoch_string= line1[18:32];
refEpoch_float= nm.float(line1[18:32]);
refEpochdt = dt.datetime.strptime(refEpoch_string[:5],'%y%j');
hr = (refEpoch_float - math.floor(refEpoch_float))*24; 
rem = hr - math.floor(hr);
mins = rem*60;
rem1 = mins - math.floor(mins);
secs = 60*rem1;
mcs = (rem1*60-math.floor(secs))*10**6;
# refepochdt variable date time in UTC
refEpochdt = refEpochdt.replace(hour = int(hr),minute = int(mins), second = int(secs),microsecond = int(mcs));
# compute the delta to local time
curr_time = dt.datetime.utcnow();
curr_time = curr_time.replace(hour=17,minute=0,second=0,microsecond=0);
timedelta = curr_time - refEpochdt;
epsec = timedelta.total_seconds();



