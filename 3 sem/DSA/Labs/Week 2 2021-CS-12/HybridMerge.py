# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 19:53:33 2022

@author: Afraz Butt
"""

from funcs import *

size = int(input('Enter Size: '))
array = RandomArray(size)

start = int(input('Enter starting: '))
end = int(input('Enter ending: '))

starting = time.time()
print(HybridMergeSort(array,start,end))

ending = time.time()

total_time = ending - starting

print('Total time is: '+ str(total_time))
write_to_csv('Csv_txt/SortedHybridSort.csv', array)