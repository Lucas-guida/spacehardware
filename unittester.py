import unittest
from Datefun import doy,frcofd,ep2dat
#from Fileio import *

class TestAROMethods(unittest.TestCase):
    
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
        
if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestAROMethods)
    unittest.TextTestRunner(verbosity=2).run(suite)