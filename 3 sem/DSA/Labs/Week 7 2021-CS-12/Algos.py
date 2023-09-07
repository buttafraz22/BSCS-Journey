import numpy as np
import math

def countSort(A):
    max_element = max(A)
    min_element = min(A)
    ranges = max_element - min_element + 1
    
    C = [0 for i in range(0,ranges)]
    B = [0 for i in range(len(A))]
    
    for i in range(0, len(A)):
        C[A[i]-min_element] += 1   #minimum element count is stored at beginning
    
    for i in range(1, len(C)):
        C[i] = C[i] + C[i-1]
    
    for i in range(len(A)-1, -1, -1):
        B[C[A[i] - min_element] - 1] = A[i]
        C[A[i] - min_element] -= 1
    
    return B


def countingSort(arr, d):
    n = len(arr)
    copy_sort = [0] * (n)
    counters = [0] * (10) #10 is for Decimal base 10
 
    
    for i in range(0, n):
        idx = arr[i] // d
        # counters[idx % d] += 1
        counters[idx % 10] += 1
 
    
    for i in range(1, 10):
        counters[i] += counters[i - 1]
 
    
    i = n - 1
    while i >= 0:
        idx = arr[i] // d
        copy_sort[counters[idx % 10] - 1] = arr[i]
        counters[idx % 10] -= 1
        i -= 1
 
    i = 0
    for i in range(0, len(arr)):
        arr[i] = copy_sort[i]

def RadixSort(A):
    max_element = max(A)
 
    d = 1
    while max_element / d >= 1:
        countingSort(A, d)
        d *= 10
    return A

def InsertionSort(array,start,end):
    for i in range(start,end+1):
        key = array[i]
        j = i - 1
        
        while key < array[j] and j >= start: #backwards linear scan
            array[j + 1] = array[j]
            j = j - 1
        
        array[j + 1] = key
    return array

def BucketSort(array):
    B = []
    n = len(array)
    for i in range(n+1):
        B.append([])
    
    for i in range(0,n):
        mul = n * array[i]
        mul = math.floor(mul)
        B[mul].append(array[i])
    
    for b in B:
        if len(b) == 0 or len(b) == 1:
            continue
        
        print(b)
        b = InsertionSort(b,0,len(b))
    
    
    b = np.array(B)
    b.flatten()
    return b
    
    
array =  [0.897,0.565,0.656,0.1234,0.665,0.3434]
print(BucketSort(array))