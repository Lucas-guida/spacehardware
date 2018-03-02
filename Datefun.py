import datetime

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
    ## need to change that from slides 5 57 is the difference
    
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
