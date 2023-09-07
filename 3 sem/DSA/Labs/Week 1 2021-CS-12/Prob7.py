# -*- coding: utf-8 -*-
"""
Created on Wed Sep  7 05:52:52 2022

@author: Afraz Butt
"""
from funcs import *

Mat = read2D('txt_files/prob7.txt')


row = RowWiseSum(Mat)
row_sum = ('\n'.join(map(str,row)))
print('Row-wise: \n'+row_sum)

column = ColumnWiseSum(Mat)
stripped = (' '.join(map(str,column)))
print("Column Wise sum is: "+stripped)