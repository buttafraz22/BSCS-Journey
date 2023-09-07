# -*- coding: utf-8 -*-
"""
Created on Fri Sep 23 15:33:28 2022

@author: Afraz Butt
"""

import random

class Toad:
    def __init__(self, is_trustworthy):
        self.truthful: bool = bool(int(is_trustworthy))
        
    def is_trustworthy(self):
        return self.truthful

    def tell_about(self,toad):
        b_trustworthy= toad.is_trustworthy()
        
        if(self.is_trustworthy()):
            return b_trustworthy
        else:
            r = random.random()
            if(r<0.5):
                return True
            else:
                return False

def getPopulation(n):
    if n % 2 != 0:
        return
    
    toads = []
    limit = n // 2
    
    count_truthful = 0
    while count_truthful <= limit :
        
        for i in range(0,n):
            rand = random.randint(0, 1)
            td = Toad(rand)
            toads.append(td)
        
        for i in toads:
            if (i.is_trustworthy()) :
                count_truthful += 1
        
        if count_truthful > limit:
            #print(count_truthful)
            break
        
        toads.clear()
        count_truthful = 0
    
    return toads

def TruthFulToadsA(population):
    list_indices = []
    for i in population:
        
        for j in population:
            
            first_toad = i.tell_about(j)
            if first_toad == j.is_trustworthy():
                list_indices.append(population.index(i))
                break
    
    del_indices = []
    for k in list_indices:
        if (population[k].is_trustworthy()):
            continue
        elif population[k].is_trustworthy() == False:
            del_indices.append(k)
                
    for m in del_indices:
        list_indices.pop(list_indices.index(m))
        
    return   list_indices

# population = getPopulation(30)

def TruthFulToadsB(population):
    limit = len(population) // 2
    #print(limit)
    
    list_indices = []
    
    count = 0
    while count <= limit:
        first = population[count]
        second = population[count + 1]
        
        if first.tell_about(second) == True and first.is_trustworthy() == True:
            list_indices.append(population.index(first))
                        
        count += 1

    if len(list_indices) < limit // 2:
        #print(list_indices)
        return None
    
    return list_indices
        
    
# print(TruthFulToadsA(population))
# print(TruthFulToadsB(population))