# -*- coding: utf-8 -*-
"""
Created on Wed Mar  7 11:14:14 2018

@author: Mohammed
"""
import numpy as np
from Fileio import STKout
position = np.arange(15).reshape(5,3)
vel = np.arange(15).reshape(5,3)
time = np.arange(5).reshape(5,1)
STKout('name','24 Apr 2005 06:00:00.00',time,'J2000',position,vel)
