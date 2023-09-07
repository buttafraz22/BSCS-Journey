# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 02:29:05 2022

@author: Afraz Butt 2021-CS-12
"""
import numpy as np
import itertools

def readInt(path):
    arr = []
    with open (path ,'r') as f:
        line = f.readlines()
        for i in line:
            k = i.strip()
            arr.append(int(k))
    
        return arr

def read2D(path):
    arr = []
    with open (path,'r') as f:
        lines = f.readlines()
        for i in lines:
            per_line = (i.split(','))
            arr_e = []
            for j in per_line:
                final_int = int(j)
                arr_e.append(final_int)
            arr.append(arr_e)
            
    return arr   


def SearchA(Arr,x):
    arr_indices = []
    index = 0
    for i in Arr:
        if i == x:
            arr_indices.append(index)
        index += 1
    return arr_indices

def SearchB(Arr,x):
    arr_indices = []
    index = 0
    for i in Arr:
        if i == x:
            arr_indices.append(index)
        index += 1
    return arr_indices

def Minimum(Arr,starting,ending):
    arr = Arr[starting : ending + 1]
    sliced_min = min(arr)
    
    index_min = Arr.index(sliced_min)
    return index_min

def Sort4(Arr):
    arr_sort = []

    for i in range(0,len(Arr)):
        end = len(Arr)
        minimum = Minimum(Arr,0,end)
        arr_sort.append(Arr[minimum])
        Arr.remove(Arr[minimum])
  
    return arr_sort

def SumRecursive(number):
    if(number == 0):
        return 0
    else:
        return (number % 10) + SumRecursive(number // 10)

def SumIterative(number):
    temp = number
    sum = 0
    while temp != 0:
        sum += (temp % 10)
        temp = temp // 10
    return sum

def StringReverse(str,starting,ending):
    new_str = str[starting : ending + 1]
    reverse_str = new_str[::-1]
    return reverse_str

def RowWiseSum(Mat):
    row = []
    for i in Mat:
        row.append(sum(i))
    return row

def ColumnWiseSum(Mat):
    column = np.sum(Mat,axis = 0)
    return column

def SortedMerge(Arr1,Arr2):
    merge_unsorted = Arr1 + Arr2
    merge_sorted = Sort4(merge_unsorted)
    return merge_sorted

def PalindromRecursive(str):
    if len(str) == 1:
        return True
    else:
        if str[0] == str[len(str) - 1]:
            reduced_string = str[1:len(str) - 1]
            if PalindromRecursive(reduced_string) is True:
                return True
        return False
    
def Sort10(Arr):
    positive_unsorted = []
    negative_unsorted = []
    out = []

    for i in Arr:
        if i >= 0:
            positive_unsorted.append(i)
        elif i < 0:
            negative_unsorted.append(i)
        
    
    positive_unsorted.sort()
    negative_unsorted.sort()
        
    out = [i for in_Arr in itertools.zip_longest(negative_unsorted, positive_unsorted) for i in in_Arr]
    final = filter(None,out)
    return list(final)
    