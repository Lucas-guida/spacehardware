import datetime
import time

def ep2dat(NotJulianDate):
    year = int(NotJulianDate[:2])
    days = float(NotJulianDate[2:])
    
    if year<19:
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