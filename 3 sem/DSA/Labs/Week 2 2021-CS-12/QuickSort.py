import time
from funcs import *

size = int(input('Enter Size: '))
array = RandomArray(size)
# print('Data: ' + str(array))

start = int(input('Enter starting: '))
end = int(input('Enter ending: '))

starting = time.time()
print(QuickSort(array,start,end))

ending = time.time()

total_time = ending - starting

print('Total time is: '+ str(total_time))