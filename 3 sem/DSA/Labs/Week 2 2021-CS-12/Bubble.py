# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 14:51:04 2022

@author: Afraz Butt
"""

from funcs import *
import time

size = int(input('Enter Size: '))
array = RandomArray(size)

start = int(input('Enter starting: '))
end = int(input('Enter ending: '))

starting = time.time()
array = BubbleSort(array,start,end)
print(array)

ending = time.time()

total_time = ending - starting

print('Total time is: '+ str(total_time))

write_to_csv('Csv_txt/SortedBubbleSort.csv', array)