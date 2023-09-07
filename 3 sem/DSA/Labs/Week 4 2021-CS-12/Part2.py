# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 19:23:44 2022

@author: Afraz Butt
"""
# from cProfile import label
import math
import time
# from multiprocessing import forkserver
# from operator import index
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('Csv/Train.csv')
dd = pd.read_csv('Csv/Test.csv')


# print(df.dtypes)
# the last one is string type. rest are int

cough = df['COUGH'].values.tolist()
muscle_ache = df['MUSCLE_ACHES'].values.tolist()
tiredness = df['TIREDNESS'].values.tolist()
sore_throat = df['SORE_THROAT'].values.tolist()
runny_nose = df['RUNNY_NOSE'].values.tolist()
stuffy_nose = df['STUFFY_NOSE'].values.tolist()
fever = df['FEVER'].values.tolist()
nausea = df['NAUSEA'].values.tolist()
vomiting = df['VOMITING'].values.tolist()
diarrhea = df['DIARRHEA'].values.tolist()
breath_short = df['SHORTNESS_OF_BREATH'].values.tolist()
breath_difficult = df['DIFFICULTY_BREATHING'].values.tolist()
loss_taste = df['LOSS_OF_TASTE'].values.tolist()
loss_smell = df['LOSS_OF_SMELL'].values.tolist()
itchy_nose = df['ITCHY_NOSE'].values.tolist()
itchy_eyes = df['ITCHY_EYES'].values.tolist()
itchy_mouth = df['ITCHY_MOUTH'].values.tolist()
itchy_innerEar = df['ITCHY_INNER_EAR'].values.tolist()
sneezing = df['SNEEZING'].values.tolist()
pink_eye = df['PINK_EYE'].values.tolist()
disease_type = df['TYPE'].values.tolist()

# plt.scatter(cough,muscle_ache,tiredness)
# plt.show()


coughT = dd['COUGH'].values.tolist()
muscle_acheT = dd['MUSCLE_ACHES'].values.tolist()
tirednessT = dd['TIREDNESS'].values.tolist()
sore_throatT = dd['SORE_THROAT'].values.tolist()
runny_noseT = dd['RUNNY_NOSE'].values.tolist()
stuffy_noseT = dd['STUFFY_NOSE'].values.tolist()
feverT = dd['FEVER'].values.tolist()
nauseaT = dd['NAUSEA'].values.tolist()
vomitingT = dd['VOMITING'].values.tolist()
diarrheaT = dd['DIARRHEA'].values.tolist()
breath_shortT = dd['SHORTNESS_OF_BREATH'].values.tolist()
breath_difficultT = dd['DIFFICULTY_BREATHING'].values.tolist()
loss_tasteT = dd['LOSS_OF_TASTE'].values.tolist()
loss_smellT = dd['LOSS_OF_SMELL'].values.tolist()
itchy_noseT = dd['ITCHY_NOSE'].values.tolist()
itchy_eyesT = dd['ITCHY_EYES'].values.tolist()
itchy_mouthT = dd['ITCHY_MOUTH'].values.tolist()
itchy_innerEarT = dd['ITCHY_INNER_EAR'].values.tolist()
sneezingT = dd['SNEEZING'].values.tolist()
pink_eyeT = dd['PINK_EYE'].values.tolist()


def eucledian_distances():
    # distances = []
    disease_name = []
    count = 0
    
    for count in range(0,18):
        distances = []
        for i in range(0,len(cough)):
            # if count == 18:
            #     count = 0
                
            sum = 0
            sum  = math.pow(cough[i] - coughT[count],2)
            sum = sum + math.pow(muscle_ache[i] - muscle_acheT[count] ,2)
            sum = sum + math.pow(tiredness[i] - tirednessT[count],2)
            sum = sum + math.pow(sore_throat[i] - sore_throatT[count],2)
            sum = sum + math.pow(runny_nose[i] - runny_noseT[count],2)
            sum = sum + math.pow(stuffy_nose[i] - stuffy_noseT[count],2)
            sum = sum + math.pow(fever[i] - feverT[count],2)
            sum = sum + math.pow(nausea[i] - nauseaT[count],2)
            sum = sum + math.pow(vomiting[i] - vomitingT[count],2)
            sum = sum + math.pow(diarrhea[i] - diarrheaT[count],2)
            sum = sum + math.pow(breath_short[i] - breath_shortT[count],2)
            sum = sum + math.pow(breath_difficult[i] - breath_difficultT[count],2)
            sum = sum + math.pow(loss_smell[i] - loss_smellT[count],2)
            sum = sum + math.pow(loss_taste[i] - loss_tasteT[count],2)
            sum = sum + math.pow(itchy_nose[i] - itchy_noseT[count],2)
            sum = sum + math.pow(itchy_eyes[i] - itchy_eyesT[count],2)
            sum = sum + math.pow(itchy_innerEar[i] - itchy_innerEarT[count],2)
            sum = sum + math.pow(itchy_mouth[i] - itchy_mouthT[count],2)
            sum = sum + math.pow(sneezing[i] - sneezingT[count],2)
            sum = sum + math.pow(pink_eye[i] - pink_eyeT[count],2)
            
            
            sum = math.sqrt(sum)
            
            if sum <= 0:
                continue
            
            distances.append(sum)
    
        mini = distances.index(min(distances))
        disease_name.append(disease_type[mini])
    return disease_name

start = time.time()
print(eucledian_distances())
end = time.time()

time_diff = round((end  - start),2)
print(str(time_diff) + ' seconds in execution')