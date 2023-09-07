import time
from funcs import *

size = int(input('Enter Size: '))
array = RandomArray(size)

# array = []
starting = time.time()
B = [0 for i in range(len(array))]
print(RadixSort(array))

ending = time.time()

total_time = round((ending - starting),3)

print('Total time is: '+ str(total_time) + " seconds")