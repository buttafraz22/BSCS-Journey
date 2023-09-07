import math
def FIND_MAXIMUM_SUBARRAY(A,low,high):
    if high == low:
        return low,high,A[low - 1]
    else:
        mid = (low + high) // 2
        left_low , left_high , left_summ = FIND_MAXIMUM_SUBARRAY(A,low,mid)
        right_low , right_high , right_summ = FIND_MAXIMUM_SUBARRAY(A,mid + 1,high)
        cross_low , cross_high , cross_summ = FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high)
        
        if left_summ >= right_summ and left_summ >= cross_summ:
            return left_low , left_high , left_summ
        
        elif right_summ >= left_summ and right_summ >= cross_summ:
            return right_low , right_high , right_summ
        
        else:
            return cross_low , cross_high , cross_summ

def FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high):
    left_sum = -(math.inf)
    max_left = 0
    max_right = 0
    summ = 0
    for i in range(mid,low - 1,-1):
        summ = summ + A[i]
        if summ > left_sum:
            left_sum = summ
            max_left = i
    right_sum = -(math.inf)
    summ = 0
    for j in range(mid + 1, high + 1):
         summ = summ + A[i]
         if summ > right_sum:
            right_sum = summ
            max_right = j
    return max_left,max_right,left_sum + right_sum

A =  [-1,-1,-1,-1,-1]
B =  [-5, 2, 8,-15,5]

print(FIND_MAXIMUM_SUBARRAY(B,0,len(B)))      