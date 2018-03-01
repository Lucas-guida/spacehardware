import time

def ep2dat(JulianDate):
    return time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(JulianDate))