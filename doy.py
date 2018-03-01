import datetime as dt
def doy(YR,MD,D):
   days_in_the_year = (dt.date(YR, MD, D) - dt.date(YR,1,1)).days + 1
   return days_in_the_year

