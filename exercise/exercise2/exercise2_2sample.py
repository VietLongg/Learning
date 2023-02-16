def FilterFile(listPaths, ext):
    dicttmp = dict()
    for listPath in listPaths:
        path = listPath[:listPath.rfind('/')]
        file = listPath[listPath.rfind('/') + 1:]
        if file[file.rfind('.')+1:] == ext:
            if file not in dicttmp:
                dicttmp[file] = list()
            dicttmp[file].append(path)
    return dicttmp

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