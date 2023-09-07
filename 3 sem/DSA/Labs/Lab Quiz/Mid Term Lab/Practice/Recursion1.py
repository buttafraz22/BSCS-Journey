"""Write a Python program to calculate the sum of a list of numbers."""
def RecursiveSum(listt):
    if len(listt) == 1:
        return listt[0]
    
    else:
        return listt[0] + RecursiveSum(listt[1:])

""" Write a Python program to get the sum of a non-negative integer."""
def IntegerSum(num):
    if num < 10:
        return num
    
    else:
        return ( num % 10 ) + IntegerSum(num//10)

"""Write a Python program to calculate the sum of the positive integers of n+(n-2)+(n-4)... (until n-x =< 0). """
def PositiveIntegersSum(n):
    if n <= 0:
        return n
    else:
        return n + PositiveIntegersSum(n-2)

""" Write a Python program of recursion list sum."""
def RecursionListSum(lsit):
    total = 0
    
    for item in lsit:
        if type(item) == list:
            total = total + RecursionListSum(item)
        else:
            total = total + item
            
    return total
"""Write a Python Program to calculate power of an integer."""
def power(a,b):
	if b==0:
		return 1
	elif a==0:
		return 0
	elif b==1:
		return a
	else:
		return a*power(a,b-1)

print(RecursionListSum([10,2,[8,2,9],[8,1,2,4,5,6,7],5]))