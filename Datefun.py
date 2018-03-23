import datetime as dt
import numpy as np

def doy(YR,MD,D):
   days_in_the_year = (dt.date(YR, MD, D) - dt.date(YR,1,1)).days + 1
   return days_in_the_year

# frcord(Hour,Minute,Second)
# This function will produce the fractional hour format
# Input range:
# Hour: 0 - 23 hours
# Minute: 0 - 60 minutes
# Second: 0 - 60 seconds
def frcofd(HR,MI,SE):
    return (HR + MI/60 + SE/3600)/24
    
def ep2dat(NotJulianDate):
   
    year = int(NotJulianDate[:2])
    days = float(NotJulianDate[2:])
    
    if year<57:
        year = 2000+year;
    else:
        year = 1900+year;
    
    #creates a date object starting at the given year
    dat = dt.datetime(year,1,1,0,0);
    #computes a time difference by the number of days in TLE
    timediff = dt.timedelta(days-1);
    #adds the objects
    final= dat + timediff;
    # might be off by 1 day
    return final

def curday():
    return dt.datetime.utcnow();

# output is the JD of the epoch
def ep2JD(epoch):
    """ Not needed now
    # computes the year we are in from epoch
    year = int(epoch[:2]);
    
    refepochFloat = np.float(epoch);
    dfrac = np.float(epoch[5:]);
    
    if year<57:
        year = 2000+year;
    else:
        year = 1900+year;
    # creates datetime object from year and days
    RefEpochdt = dt.datetime.strptime(epoch[:5], '%y%j');
    JDM = RefEpochdt;
    # gets the remaineder of hte day for datime object
    hr = np.int(dfrac*24)
    rem = dfrac*24 - hr
    mins = np.int(60*rem)
    rem2 = rem*60 - mins
    secs = np.int(60*rem2)
    mics = np.int((rem2*60-secs)*10**6)
    
    RefEpochdt = RefEpochdt.replace(hour=hr, minute=mins, second=secs, microsecond=mics)
    # gets the time delta from system refrence
    """
    JD = dt.datetime(year=epoch.year, month=epoch.month, day=epoch.day) - dt.datetime(1,1,1) ;
    JDM = JD.days  + 1721423.5 + 2;
    
    # comutes JD from time delta + hardcoded value of system refence + 2 days lost from conversion
    RefEpochJD = epoch - dt.datetime(1,1,1);
    JD = RefEpochJD.days + RefEpochJD.seconds/86400 + RefEpochJD.microseconds/(86400*1000)+ 1721423.5 + 2;
    #JD (1,1,1) = 1721423.5
    
    return (JD,JDM)