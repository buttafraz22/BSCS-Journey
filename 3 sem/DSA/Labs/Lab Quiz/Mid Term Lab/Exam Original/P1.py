import matplotlib.pyplot as plt
import random
import csv
from datetime import datetime

def write_to_csv(path , arr):
    #arr = str(arr)
    new_arr = [[data] for data in arr]
    #new_arr.append(arr)
    
    with open(path, 'w' ,newline = '') as myfile:
        writer = csv.writer(myfile, quoting=csv.QUOTE_ALL)
        writer.writerows(new_arr)
    
def RandomArray(size):
    A = []
    for i in range(0,size):
        A.append(random.randint(1,7))
    return A

def QuickSort(A, p, r):
    if p < r:
        q = Partition(A, p, r)
        QuickSort(A, p, q - 1)
        QuickSort(A, q + 1, r)
    return A

def Partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1


# li = RandomArray(10)
# print(QuickSort(li,0,9))
seconds = []
n = []

for i in range(10,500,10):
    n.append(i)
    li = RandomArray(i)
# r = random.choice(li)
    r = len(li) - 1
    time = datetime.now()
    QuickSort(li,0,r)
    end = datetime.now()
    
    diff = (end - time)
    diff = diff.total_seconds() * 1000
    seconds.append(diff)
    k = []
    k.append(i)
    k.append(seconds)
    write_to_csv('Time.csv',k)

