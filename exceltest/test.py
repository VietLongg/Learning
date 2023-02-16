import openpyxl

if __name__ == "__main__":
    filePath = '/home/long/Desktop/long/excel/listPaths.xlsx'
    wb = openpyxl.load_workbook(filePath)
    print(wb.sheetnames)
    sheet = wb['Sheet']
    listPaths = list(sheet.values)


            

    
