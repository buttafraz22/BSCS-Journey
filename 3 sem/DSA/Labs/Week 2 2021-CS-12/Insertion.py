# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 13:48:13 2022

@author: Afraz Butt
"""
from funcs import *
from datetime import datetime

size = int(input('Enter Size: '))
array = RandomArray(size)

start = int(input('Enter starting: '))
end = int(input('Enter ending: '))

starting = datetime.now()
print(InsertionSort(array,start,end))

ending = datetime.now()

total_time = (ending - starting).total_seconds() * 1000

print('Total time is: '+ str(total_time)+'miliseconds')
write_to_csv('Csv_txt/SortedInsertionSort.csv', array)
