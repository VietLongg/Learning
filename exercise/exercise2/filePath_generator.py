import random as r
numList = ['1', '2', '3', '4']
charList = ['C', 'D', 'E']
extensionList = ['py', 'txt']
listPaths = list()

def listGenerator(amountList):
    for i in range(amountList):
        randomListPath = r.choice(charList) + ":/Folder_" + r.choice(numList) + "/File_" + r.choice(numList) + '.' + r.choice(extensionList)
        while (randomListPath in listPaths):
            randomListPath = r.choice(charList) + ":/Folder_" + r.choice(numList) + "/File_" + r.choice(numList) + '.' + r.choice(extensionList)
        listPaths.append(randomListPath)
    return listPaths