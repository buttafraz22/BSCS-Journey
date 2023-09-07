# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 20:39:38 2022

@author: Afraz Butt
"""

from funcs import *

Arr = readInt("txt_files/prob1.txt")
x = int(input('Enter the number: '))

output = SearchA(Arr, x)
joined = (','.join(map(str,output)))
print("Index: "+joined)