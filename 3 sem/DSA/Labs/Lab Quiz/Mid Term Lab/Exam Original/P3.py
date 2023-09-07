
A = [None for i in range(20)]


def firstHash(x):
    return x % 7

def secondHash(x):
    return x % 3

def doubleHash(element):
    r = 0
    i = 0
    while r != 20:
        pos = firstHash(element) + i * secondHash(element)
        # print(pos)
        if A[pos] == None:
            A[pos] = element
            print(A,' ',' ')
            r += 1
            break
        else:
            i += 1
            continue

for i in range(0,19):
    element = int(input('Enter number: '))
    doubleHash(element)
    if i == 9 or i == 18:
        B = str(A)
        print('Array after adding 10 elements: '+B,' ',' ')