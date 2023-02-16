from PyQt5 import QtGui, QtWidgets, QtCore
import sys
import openDialog, red, green, yellow

app = QtWidgets.QApplication(sys.argv)
MainWindow = QtWidgets.QMainWindow()

def mainUi():
    global ui
    ui = openDialog.Ui_MainWindow()
    ui.setupUi(MainWindow)
    ui.btn_red.clicked.connect(red_UI)
    ui.btn_green.clicked.connect(green_UI)
    ui.btn_yellow.clicked.connect(yellow_UI)
    MainWindow.show()

def yellow_UI():
    global ui
    ui = yellow.Ui_MainWindow()
    ui.setupUi(MainWindow)
    ui.btn_back.clicked.connect(mainUi)
    MainWindow.show()
    

def green_UI():
    global ui
    ui = green.Ui_MainWindow()
    ui.setupUi(MainWindow)
    ui.btn_back.clicked.connect(mainUi)
    MainWindow.show()

def red_UI():
    global ui
    ui = red.Ui_MainWindow()
    ui.setupUi(MainWindow)
    ui.btn_back.clicked.connect(mainUi)
    MainWindow.show()


mainUi()
sys.exit(app.exec_())