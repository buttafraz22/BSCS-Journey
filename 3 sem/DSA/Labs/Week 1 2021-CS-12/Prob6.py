# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 22:52:25 2022

@author: Afraz Butt
"""
from funcs import *

number = int(input("Enter Number: "))
if(SumRecursive(number) == SumIterative(number)):
    print("Sum of Digits is: "+str(SumRecursive(number)))