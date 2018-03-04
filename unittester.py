import unittest
from Datefun import doy,frcofd,ep2dat,curday
from Fileio import errmsg,Banner,ReadStationFile,ReadNoradTLE

from OMPython import OMCSessionZMQ

class TestAROMethods(unittest.TestCase):
    
    # Test of Datefun functions
    def test_curday(self):
        self.assertIsNotNone(curday())
    
    def test_doy(self):
        # Checks to see if it equals the expected values
        self.assertEqual(doy(2018,3,1),60)
        self.assertEqual(doy(2009,3,14),73)
   
    def test_dayFraction(self):
        # Checks to see if the two answers are equal to within 7 decimal places
        self.assertAlmostEqual(frcofd(3,23,14.444),0.141139398)
        self.assertAlmostEqual(frcofd(12,3,14.12345678901234),0.502246799)

    def test_ep2dat(self):
        self.assertEqual(ep2dat('8650.28438588'),'1986-02-20 06:49:30.940032')
        self.assertEqual(ep2dat('0850.28438588'),'2008-02-20 06:49:30.940032')
        
    # Test of Fileio functions
    
    def test_ReadNoradTLE(self):
        line0 = 'name';
        line1 = '1 20830U 90088A 05053.88610693 .00000015 00000-0 00000-0 0 2777';
        line2 = '2 20830 55.1681 285.7420 0086707 136.1120 224.6824 2.00574691105728';
        Satellite = ReadNoradTLE(line0,line1,line2);
        self.assertEqual(Satellite.eccn,'0086707');
        self.assertEqual(Satellite.incl,'55.1681');
        self.assertEqual(Satellite.meanan,'224.6824');
        
    def test_ReadStationFile(self):
        Station = ReadStationFile('test.txt');
        self.assertEqual(Station.stnlong,'281.92');
        self.assertEqual(Station.az_el_lim.elmin,'9.0');
        
   
    def test_SatelliteModel(self):
         omc = OMCSesionZMQ();
         
        
if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestAROMethods)
    unittest.TextTestRunner(verbosity=2).run(suite)