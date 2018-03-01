from ReadNoradTLE import ReadNoradTLE

line0 = 'name';
line1 = '1 20830U 90088A 05053.88610693 .00000015 00000-0 00000-0 0 2777';
line2 = '2 20830 55.1681 285.7420 0086707 136.1120 224.6824 2.00574691105728';
    
Satellite = ReadNoradTLE(line0,line1,line2);

print(Satellite);
print('\n');
print(Satellite.name);

