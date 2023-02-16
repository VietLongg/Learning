
import openpyxl
def Filter(recListPaths, recFolderPaths, recFileExt, recCreatedDate):
    retDict = dict()

    for item in recListPaths:
        item = item[0]
        fileExt, createdDate = item[item.rfind('.') + 1:].split('|')
        if recFolderPaths == item[:item.find('_')] and recFileExt == fileExt and recCreatedDate == createdDate:
            folderPath, fileName = item[:item.rfind('|')].rsplit('/', 1)
            if fileName not in retDict:
                retDict[fileName] = list()
            retDict[fileName].append(folderPath)
    return(retDict)

if __name__ == "__main__":
    filePath = '/home/long/Desktop/long/excel/listPaths.xlsx'
    wb = openpyxl.load_workbook(filePath)
    # print(wb.sheetnames)
    sheet = wb['Sheet']
    listPaths = list(sheet.values)
    extSearch = input("Enter your file extension: ")
    ret = Filter(listPaths, 'C:/Folder', extSearch, '02/09/23')
    print(ret)
