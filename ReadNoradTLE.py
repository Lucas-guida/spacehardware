from collections import namedtuple

def ReadNoradTLE(line0,line1,line2):
    SatelliteSet = namedtuple('Satellite',['name','refepoch','incl','raan', \
    'eccn','argper','meanan','meanmo','ndot','nddot6','bstar','orbitnum'])
    
    name = line0.split(" ")[1];
    
    lineTemp1 = line1.split(" ");
    
    refepoch = lineTemp1[3];
    ndot = lineTemp1[4];
    nddot6 = lineTemp1[5];
    bstar = lineTemp1[6];
    orbitnum = lineTemp1[8];
    
    lineTemp2 = line2.split(" ");
    
    incl = lineTemp2[2];
    raan = lineTemp2[3];
    eccn = lineTemp2[4];
    argper = lineTemp2[5];
    meanan = lineTemp2[6];
    meanmo = lineTemp2[7];    
    
    Satellite = SatelliteSet(name,refepoch,incl,raan,eccn,argper,meanan,meanmo\
                             ,ndot,nddot6,bstar,orbitnum);
    return Satellite