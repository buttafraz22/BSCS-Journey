# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 18:14:58 2022

@author: Afraz Butt
"""
from funcs import *
import time

size = int(input('Enter Size: '))
array = RandomArray(size)

start = int(input('Enter starting: '))
end = size - 1

starting = time.time()
print(MergeSort(array,start,end))

ending = time.time()

total_time = ending - starting

print('Total time is: '+ str(total_time))
write_to_csv('Csv_txt/SortedMergeSort.csv', array)