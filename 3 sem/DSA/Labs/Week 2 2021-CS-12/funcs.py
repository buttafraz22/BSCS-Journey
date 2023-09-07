# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 13:21:00 2022

@author: Afraz Butt
"""

from random import randint
import csv
import time
import math

def ShuffleArray(array,start,end):
    for i in range(start,end):
        rnd = randint(start,end)
        array[i] , array[rnd] = array[rnd] , array[i]
    return array

def write_to_csv(path , arr):
    #arr = str(arr)
    new_arr = [[data] for data in arr]
    #new_arr.append(arr)
    
    with open(path, 'w' ,newline = '') as myfile:
        writer = csv.writer(myfile, quoting=csv.QUOTE_ALL)
        writer.writerows(new_arr)

def readInt(path):
    arr = []
    with open (path ,'r') as f:
        line = f.readlines()
        for i in line:
            k = i.strip() #strip method removes the whitespaces from string
            arr.append(int(k))
    
        return arr

def RandomArray(size):
    arr = []
    for i in range(0,size):
        arr.append(randint(1, 256))
    
    return arr

def InsertionSort(array,start,end):
    for i in range(start,end+1):
        key = array[i]
        j = i - 1
        
        while key < array[j] and j >= start: #backwards linear scan
            array[j + 1] = array[j]
            j = j - 1
        
        array[j + 1] = key
    return array

def BubbleSort(array,start,end):
    for i in range(start,end + 1):
        for j in range(start ,end - i):
            if array[j + 1] < array[j]: #adjacent elements swapped
                array[j+1] , array[j] = array[j],array[j+1]
                
    return array

def SelectionSort(array,start,end):
    for i in range(start,end):
        for j in range(i + 1 , end):
            if array[j] < array[i]: #minimum elements swapped
                array[j] , array[i] = array[i] , array[j]  
                
    array[end] = array[end - 1]
    return array

def Merge(array,p,q,r):
    left = array[p : q + 1] 
    right = array[q + 1 : r + 1]
    
    left.append(math.inf) #sentinel variables
    right.append(math.inf)
    
    i = 0
    j = 0
    for k in range(p,r + 1):
        if left[i] < right[j]:
            array[k] = left[i]
            i = i  + 1
        else:
            array[k] = right[j]
            j = j  + 1
   
  
def MergeSort(array,start,end):
    if start < end:
        q = (start+end) // 2
        MergeSort(array, start, q) #Recursive call 
        MergeSort(array, q + 1, end)
        Merge(array, start, q, end)
        return array

def HybridMergeSort(array,start,end):
    if start < end and end > 70 :
        q = (start+end)//2
        MergeSort(array, start, q)
        MergeSort(array, q + 1, end)
        Merge(array, start, q, end)
        return array
    
    elif start < end and  end <= 70: #below 70, insert sort performs better
        arr = InsertionSort(array, start, end)
        return arr
        
def run_times(arr):
    run_times = []
    new_arr = arr.copy()
    new_arr2 = arr.copy()
    new_arr3 = arr.copy()
    new_arr4 = arr.copy()
    new_arr5 = arr.copy()
    
    start = time.time()
    arr  = InsertionSort(arr,0,len(arr)-1)
    end = time.time()
    
    run_times.append(round((end - start),4))
    
    
    start = time.time()
    arr = BubbleSort(new_arr,0,len(arr)-1)
    end = time.time()
    
    run_times.append(round((end - start),4))
    
    
    start = time.time()
    arr = SelectionSort(new_arr2,0,len(arr)-1)
    end = time.time()
    
    run_times.append(round((end - start),4))
    
    start = time.time()
    arr = MergeSort(new_arr4,0,len(arr)-1)
    end = time.time()
    
    run_times.append(round((end - start),4))
    
    start = time.time()
    arr = HybridMergeSort(new_arr5,0,len(arr)-1)
    end = time.time()
    
    run_times.append(round((end - start),4))
    
    
    return run_times

def read_strings(path):
    with open(path,'r') as f:
        lines = f.readlines()
        words = []
        for i in lines:
            words.append(i.strip())
        return words
    
def Partition(A,p,r):
    x = A[r]
    i = p - 1
    for j in range(p,r):
        if A[j] <= x:
            i += 1
            A[j] ,A[i] = A[i],A[j]
    
    A[i + 1] , A[r] = A[r] , A[i + 1]
    return i + 1

def QuickSort(A,p,r):
    if p < r :
        q = Partition(A,p,r)
        QuickSort(A , p , q - 1)
        QuickSort(A,q + 1 , r)
    return A

def CountingSort(A,B,k):
    C = [0] * k
    B = [0] * k
    
    # Indexing the list of counts to put in
    for i in range (0,k):
        C[A[i]] = C[A[i]] + 1
    
    for i in range(1, len(C)):
        C[i] = C[i] + C[i - 1]
    
    #Outputting the elements
    for j in range(len(A) - 1,-1,-1):
        B[ C[A[j]]-1 ] = A[j]
        C[A[j]] = C[A[j]] - 1
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
