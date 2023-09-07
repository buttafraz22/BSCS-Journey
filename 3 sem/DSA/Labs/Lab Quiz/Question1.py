# COUNT = 0


def PrintArray(A,startingIndex,EndingIndex):
    
    if startingIndex == EndingIndex:
        print(A[EndingIndex],' ',end=' ')
    
    else:
        PrintArray(A,startingIndex + 1, EndingIndex)
        print(A[startingIndex],' ',end=' ')
        

A = [4,5,6,7]
PrintArray(A,0,3)
