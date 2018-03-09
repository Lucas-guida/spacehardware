# -*- coding: utf-8 -*-
"""
Created on Fri Mar  9 11:03:54 2018

@author: Lucas
"""

import datetime as dt
import numpy as np

refepochString = "05053.88610693";

# The time we pass here is the tracking start time

RefEpoch = dt.datetime.strptime(refepochString[:2],'%y')
RefEpoch = RefEpoch + dt.timedelta(float(refepochString[3:]) -1)

J2 = dt.datetime(2000, 1, 1, 12, 0)

detla = RefEpoch - J2;

