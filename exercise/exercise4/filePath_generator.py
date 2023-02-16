import random as r
import datetime as dt
numList = ['1', '2', '3', '4']
charList = ['C']
folderList = ['Folder', 'Library']
extensionList = ['py', 'txt']
listPaths = list()

def listGenerator(amountList):
    for i in range(amountList):
        randomListPath = r.choice(charList) + ":/" + r.choice(folderList) + "_" + r.choice(numList) + "/File_" + r.choice(numList) + '.' + r.choice(extensionList) + "|" + dt.datetime.now().strftime("%x")
        while (randomListPath in listPaths):
            randomListPath = r.choice(charList) + ":/" + r.choice(folderList) + "_" + r.choice(numList) + "/File_" + r.choice(numList) + '.' + r.choice(extensionList) + "|" + dt.datetime.now().strftime("%x")
        listPaths.append(randomListPath)
    return listPaths