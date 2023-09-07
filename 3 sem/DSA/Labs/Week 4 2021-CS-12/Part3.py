# -*- coding: utf-8 -*-
"""
Created on Wed Sep 28 20:19:44 2022

@author: Afraz Butt
"""


import numpy as np


def MatAdd(A,B):
    result = []
    for i in range(len(A)):
        temp_list = []
        for j in range(len(A[0])):
            temp_list.append(A[i][j] + B[i][j])
        
        result.append(temp_list)
    
    return result



def MatMul(A,B):
    result =[[0 for c in range(len(B[0]))] for r in range(len(A))]
    
    for i in range(len(A)):
        # temp_list = []#Iterate through rows
        for j in range(len(B[0])):
            #Iterate through columns
            for k in range(len(B)):
                result[i][j]+=(A[i][k] * B[k][j])
            
        # result.append(temp_list)
    return result

def MatMulR(A,B,n):
    if n == 1 :
        return A[0] * B[0]
    
    else:
        half = n // 2
        full = n + 1
        # length = len(A)
        A = np.array(A)
        B = np.array(B)
        
        A_11 = A[0:half,0:half]
        A_22 = A[half : full , half:full]
        A_12 = A[0:half , half:full]
        A_21 = A[half : full ,0:half]
        
        B_11 = B[0:half,0:half]
        B_22 = B[half : full , half:full]
        B_12 = B[0:half , half:full]
        B_21 = B[half : full,0:half]
        # print(B_21)
        
        C_11 = np.add(MatMulR(A_11,B_11,half) , MatMulR(A_12,B_21,half))
        C_11 = C_11.tolist()
        C_12 = np.add(MatMulR(A_11,B_12,half) , MatMulR(A_12,B_22,half))
        C_12 = C_12.tolist()
        C_21 = np.add(MatMulR(A_21,B_11,half) , MatMulR(A_22,B_21,half))
        C_21 = C_21.tolist()
        C_22 = np.add(MatMulR(A_21,B_12,half) , MatMulR(A_22,B_22,half))
        C_22 = C_22.tolist()
        return np.vstack((np.hstack((C_11, C_12)), np.hstack((C_21, C_22))))

def MatMulRecursive(A,B):
    n = len(A)
    return MatMulR(A,B,n)   

def MatMulStrass(A,B , n):
    if(len(A)) == 1:
        return A[0] * B[0]
    
    else:
        half = n // 2
        full = n + 1
        # length = len(A)
        A = np.array(A)
        B = np.array(B)
        
        a_11 = A[0:half,0:half]
        a_22 = A[half : full , half:full]
        a_12 = A[0:half , half:full]
        a_21 = A[half : full ,0:half]
        
        b_11 = B[0:half,0:half]
        b_22 = B[half : full , half:full]
        b_12 = B[0:half , half:full]
        b_21 = B[half : full,0:half]
        
        p_1 = MatMulStrass(a_11, b_12-b_22 , half)
        p_2 = MatMulStrass(a_11 + a_12,b_22, half)
        p_3 = MatMulStrass(a_21 + a_22 , b_11 ,half)
        p_4 = MatMulStrass(a_22,b_21 - b_11 , half)
        p_5 = MatMulStrass(a_11 + a_22 , b_11 + b_22,half)
        p_6 = MatMulStrass(a_12 - a_22 , b_21 + b_22,half)
        p_7 = MatMulStrass(a_11 - a_21 , b_11 + b_12,half)
        
        c_11  = p_5 + p_4 - p_2 + p_6
        c_12 = p_1 + p_2
        c_21 = p_3 + p_4
        c_22 = p_1 + p_5 - p_3 - p_7
        
        result = np.vstack((np.hstack((c_11, c_12)), np.hstack((c_21, c_22))))
        return result


def MatMulStrassen(A,B):
    n = len(A)
    return MatMulStrass(A,B,n)

A = [[15,6,7,8],[2,3,4,8],[1,9,7,8],[2,6,8,2]]
B = [[1,2,3,4],[4,5,6,4],[7,8,9,1],[3,8,6,2]]
print(MatMulRecursive(A,B))