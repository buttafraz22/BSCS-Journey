# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 21:15:39 2022

@author: Afraz Butt
"""

from funcs import *

Arr = readInt("txt_files/prob3.txt")

starting = int(input('Starting Index: '))
ending = int(input('Ending Index: '))

print(Minimum(Arr, starting, ending))