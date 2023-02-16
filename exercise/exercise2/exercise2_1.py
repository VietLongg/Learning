list_1 = [1, 2, 3]
list_2 = ['a', 'b', 'c']
newDict = dict()

def MakeDict(list_1, list_2):
    for i in range(len(list_1)):
        newDict.update({list_1[i]:list_2[i]})
    return newDict

returnDict = MakeDict(list_1, list_2)
print(returnDict)

