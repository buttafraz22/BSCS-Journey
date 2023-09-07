# -*- coding: utf-8 -*-
"""
Created on Thu Sep  8 18:50:14 2022

@author: Afraz Butt
"""

from funcs import *

Arr = readInt("txt_files/prob1.txt")
Arr.sort()
x = int(input('Enter the number: '))

output = SearchB(Arr, x)
joined = (','.join(map(str,output)))
print("Index is : "+joined)