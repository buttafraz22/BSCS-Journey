from MyHashTable import MyHashTable
from keyNode import KeyNode

def readString(path):
    with open(path,'r') as f:
        list_keyN = []
        lines = f.readlines()
        for item in lines:
            va = item.strip().split(' ')
            key = va[0]
            value = int(va[1])
            keyNode = KeyNode(key,value)
            list_keyN.append(keyNode)
        
        # for i in list_keyN:
        #     print(i.key)
        return list_keyN

keyNode_list = readString('words.txt')
hash_table = MyHashTable(128)
hash_table.addKeys(keyNode_list)
(hash_table.UpdateKey('cat',4))
print(hash_table.SearchKey('cat'))
# for i in hash_table.keyNode_list:
#     print(i.key)