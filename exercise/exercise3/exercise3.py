from filePath_generator import listGenerator

class FileHandler:
    def __init__(self) -> None:
        pass
    
    def FilterFile(self, recListPaths, recFileExt):
        retDict = dict()
        for item in recListPaths:
            if recFileExt == item[item.rfind('.')+1:]:
                filePath, fileName = item.rsplit('/', 1)
                if fileName not in retDict:
                    retDict[fileName] = list()
                retDict[fileName].append(filePath)
        return(retDict)

if __name__ == "__main__":
    a = FileHandler()

    amount = int(input("Enter your number of list path: "))
    listPaths = listGenerator(amount)
    extSearch = input("Enter your file extension: ")

    ret = a.FilterFile(listPaths, extSearch)
    for i in ret:
        print('{0} | {1}'.format(i, ret[i]))