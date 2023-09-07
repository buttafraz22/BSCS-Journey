# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 13:55:05 2022

@author: Afraz Butt
"""

import matplotlib.pyplot as plt 
import pandas as pd

def get_updated_list(list1,list2):
    list3 = []
    #print(type(list1))
    for i in list2:
        list3.append(i.replace('4/12/2016',' ').strip())
        
    j,k = 0,0
    summ = 0
    final_list = []
    lbls = []
    #print(list3)
    # count = 0
    controller_str = list3[0]
    
    while j < 792:
        
        if list3[k] == controller_str:
            #print(list3[k])
            var = list1[j]
            summ += var 
            #print(summ)
            k += 1
        elif list3[k] != controller_str:
            lbls.append(controller_str)
            controller_str = list3[k]
            #print(controller_str)
            final_list.append(summ)
            summ = 0
        
        
        j += 1
    
    
    
    return final_list,lbls

    
    
df = pd.read_csv('Csv/dailySteps_merged.csv')
print(df.dtypes)

list_ID = df['Id'].values.tolist()
list_Ac = df['ActivityDay'].values.tolist()
list_steps = df['StepTotal'].values.tolist()

plt.plot(list_Ac, list_steps)
plt.xticks(rotation = 90)
plt.title('Daily steps')
plt.xlabel('Dates')
plt.ylabel('Steps')
plt.show()

dd = pd.read_csv('Csv/dailyActivity_Merged.csv')

print(dd.dtypes)

list_D = dd['TotalDistance'].values.tolist()
list_date = dd['ActivityDate'].values.tolist()

plt.bar(list_date, list_D,width = 1, color = ['blue','green'])
plt.xticks(rotation = 90)
plt.title('Daily steps')
plt.xlabel('Dates')
plt.ylabel('Distance')
plt.show()

bp = pd.read_csv('Csv/minuteSleep_merged.csv')
list_date = bp['date'].values.tolist()
list_date=list_date[0:30]
list_val = bp['value'].values.tolist()
list_val = list_val[0:30]
print(len(list_val))
print(len(list_date))

plt.scatter(list_date,list_val,marker = 'o')
plt.title('Date and Time')
#plt.xlabel('Dates')
plt.ylabel('Time')
plt.xticks(rotation = 90)
plt.show()

df = pd.read_csv('Csv/hourlySteps_merged.csv')

list1 = df['StepTotal'].values.tolist()
list1 = list1[0:794]
list1 = list(map(int,list1))
list2 = df['ActivityHour'].values.tolist()
list2 = list2[0:794]
list_updated,list2 = get_updated_list(list1, list2)


plt.pie(list_updated, labels = list2)
plt.show()