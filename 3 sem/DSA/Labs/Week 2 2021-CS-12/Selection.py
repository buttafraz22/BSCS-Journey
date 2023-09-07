# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 15:05:50 2022

@author: Afraz Butt
"""

from funcs import *
import time

size = int(input('Enter Size: '))
array = RandomArray(size)

start = int(input('Enter starting: '))
end = int(input('Enter ending: '))

starting = time.time()
print(SelectionSort(array,start,end))

ending = time.time()

total_time = ending - starting

print('Total time is: '+ str(total_time))
write_to_csv('Csv_txt/SortedSelectionSort.csv', array)