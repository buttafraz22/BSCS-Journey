# -*- coding: utf-8 -*-
"""
Created on Wed Sep  7 06:27:03 2022

@author: Afraz Butt
"""

from funcs import *

str = input('Enter string: ')
if PalindromRecursive(str) is True:
    print('Palindrome')
else:
    print('Not Palindrome')