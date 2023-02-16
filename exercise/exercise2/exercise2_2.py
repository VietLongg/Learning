def FilterFile(recListPaths, recFileExt):
    retDict = dict()
    for item in recListPaths:
        if recFileExt == item[item.rfind('.')+1:]:
            filePath, fileName = item.rsplit('/', 1)
            if fileName not in retDict:
                retDict[fileName] = list()
            retDict[fileName].append(filePath)
    return(retDict)

listPaths = [
                'C:/Folder_1/File_1.py',
                'C:/Folder_1/File_2.py',
                'C:/Folder_1/File_3.txt',
                'C:/Folder_1/File_4.txt',
                'C:/Folder_2/File_1.py',
                'C:/Folder_2/File_2.py',
                'C:/Folder_2/File_3.py',
                'C:/Folder_2/File_4.txt',
                'C:/Folder_3/File_1.py'
            ]         
ret = FilterFile(listPaths, 'py')
print(ret)
#STEP 1:    Check if file extension in file path.
#STEP 2:    While (STEP 1): Rsplit file path into filePath & fileName
#STEP 3:    Check if fileName was in DICT
#STEP 4:    If not (STEP 3): create a new key:value for DICT, with key = fileName & value = filePath
#           else append filePath to fileName, already in DICT