# from re import I
from keyNode import KeyNode

class MyHashTable:
    keyNode_list = []
    def __init__(self, hsize):
        self.keyNode_list = [None] * hsize
        self.size = hsize
        self.keys_occupied = 0
    
    def GetHashTableSize(self):
        return self.size
    
    def GetNumberOfKeys(self):
        return self.keys_occupied
    
    def HashFunction(self,string):
        MODULUS = self.size
        sum = 0
        
        for i in string:
            sum += ord(i)
        
        return sum % MODULUS
    
    def addKeys(self,list):
        for i in list:
            if self.keyNode_list[self.keys_occupied] != None:
                self.ReHash(i)
                continue
            self.keyNode_list[self.keys_occupied] = i
        
    def UpdateKey(self,key,value):
        """Updates value of Key"""
        for item in self.keyNode_list:
            if item.key == key:
                item.value = value
                break
            
    def SearchKey(self,key):
        """ Searches for Key in Hash Table"""
        # print(self.keyNode_list[0].key)
        for i in self.keyNode_list:
            if i != None:
                if i.key == key:
                    return i.value
        
        return 0    
    
    def ReHash(self,KeyNode):
        idx = self.HashFunction(KeyNode.key)
        for i in range(idx,self.size):
            if self.keyNode_list[i] == None:
                self.keyNode_list[i] = KeyNode
                break
    