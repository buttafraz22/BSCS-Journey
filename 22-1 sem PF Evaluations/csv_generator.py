import pandas as pd

list_roll_numbers = [str(i) for i in range(111,161)]
list_roll_numbers.append('2XX')

df = pd.DataFrame(list_roll_numbers)

df.to_csv('Section C.csv',header=['Roll Numbers'],index=False)