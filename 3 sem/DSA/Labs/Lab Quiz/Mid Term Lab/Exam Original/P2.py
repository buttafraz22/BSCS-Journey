
def parent(index):
    return index // 2

def left(index):
    return 2*index + 1

def right(index):
    return 2*index + 2

def max_heapify(array,index,n):
    l,r = left(index),right(index)
    
    largest = index
    
    if l < n and array[l] > array[index]:
        largest = l
        
    
        
    if r < n and array[r] > array[largest]:
        largest = r
    
    
    if largest != index:
        (array[index] ,array[largest]) = (array[largest] , array[index])
        max_heapify(array,largest,n)

def build_max_heap(array):
    heap_size = len(array)
    
    for i in range(((heap_size // 2)), -1 , -1):
        max_heapify(array,i,heap_size)
    
    # print(array)

def heap_sort(array):
    build_max_heap(array)
    n = len(array)
    
   
    for i in range(n-1,0,-1):
        array[0] , array[i] = array[i] , array[0]
    
        max_heapify(array,0,i) #limit
    
    return array

