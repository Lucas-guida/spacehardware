import datetime as dt
from Datefun import doy,frcofd,ep2dat,curday,ep2JD

apple = '05012.55'

epochJD = ep2JD(apple);

print(epochJD)
