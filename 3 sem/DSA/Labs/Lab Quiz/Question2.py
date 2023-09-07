# print(ord('z'))
def StringOccurenceSmall(x):
    arr_letters = [] 
    for i in range(0,len(x)):
        if ord(x[i]) >= 97 and ord(x[i]) <= 122:
            arr_letters.append(x[i])
    
    count_letters = 0
    inner_count = 0
    check = 0
    counter_arr = []
    print(arr_letters)
    copy = arr_letters.copy()
    while count_letters < len(arr_letters) - 1:
        if ord(arr_letters[count_letters]) == ord(arr_letters[inner_count]):
            check += 1
        
        elif inner_count >= len(arr_letters) - 1:
            inner_count = 0
            if check == 0:
                counter_arr.append(check + 1)
            else:
                counter_arr.append(check)
                print(arr_letters[count_letters])
                arr_letters.pop(count_letters)
                
            check = 0
            count_letters += 1
            continue
        inner_count += 1 #CL = 0, IC = VAR , CHECK = 0
    print(counter_arr)
print(StringOccurenceSmall('AabAdBCaSDcgED'))