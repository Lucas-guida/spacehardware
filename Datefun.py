import datetime as dt
import numpy as np

def doy(YR,MD,D):
   days_in_the_year = (datetime.date(YR, MD, D) - datetime.date(YR,1,1)).days + 1
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
    dt = datetime.datetime(year,1,1,0,0);
    #computes a timd difference by the number of days in TLE
    timediff = datetime.timedelta(days);
    #adds the objects
    final= dt + timediff;
    # might be off by 1 day
    return str(final)

def curday():
    return datetime.datetime.utcnow();

# output is the JD of the epoch
def ep2JD(epoch):
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
    # gets the remaineder of hte day for datime object
    hr = np.int(dfrac*24)
    rem = dfrac*24 - hr
    mins = np.int(60*rem)
    rem2 = rem*60 - mins
    secs = np.int(60*rem2)
    mics = np.int((rem2*60-secs)*10**6)

    RefEpochdt = RefEpochdt.replace(hour=hr, minute=mins, second=secs, microsecond=mics)
    # gets the time delta from system refrence
    RefEpochJD = RefEpochdt - dt.datetime(1,1,1);
    # comutes JD from time delta + hardcoded value of system refence + 2 days lost from conversion
    JD = RefEpochJD.days + RefEpochJD.seconds/86400 + 1721423.5 + 2;
    #JD (1,1,1) = 1721423.5
    
    return JD