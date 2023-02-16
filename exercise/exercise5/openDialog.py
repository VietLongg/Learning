# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'openDialog.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 450)
        MainWindow.setStyleSheet("")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.btn_red = QtWidgets.QPushButton(self.centralwidget)
        self.btn_red.setGeometry(QtCore.QRect(40, 190, 211, 61))
        font = QtGui.QFont()
        font.setPointSize(20)
        font.setBold(True)
        font.setItalic(False)
        font.setWeight(75)
        self.btn_red.setFont(font)
        self.btn_red.setAutoFillBackground(False)
        self.btn_red.setStyleSheet("background-color: rgb(239, 41, 41);\n"
"")
        self.btn_red.setObjectName("btn_red")
        self.btn_yellow = QtWidgets.QPushButton(self.centralwidget)
        self.btn_yellow.setGeometry(QtCore.QRect(290, 190, 211, 61))
        font = QtGui.QFont()
        font.setPointSize(20)
        font.setBold(True)
        font.setItalic(False)
        font.setWeight(75)
        self.btn_yellow.setFont(font)
        self.btn_yellow.setAutoFillBackground(False)
        self.btn_yellow.setStyleSheet("background-color: rgb(237, 212, 0);\n"
"")
        self.btn_yellow.setObjectName("btn_yellow")
        self.btn_green = QtWidgets.QPushButton(self.centralwidget)
        self.btn_green.setGeometry(QtCore.QRect(540, 190, 211, 61))
        font = QtGui.QFont()
        font.setPointSize(20)
        font.setBold(True)
        font.setItalic(False)
        font.setWeight(75)
        self.btn_green.setFont(font)
        self.btn_green.setAutoFillBackground(False)
        self.btn_green.setStyleSheet("background-color: rgb(115, 210, 22);")
        self.btn_green.setObjectName("btn_green")
        self.lb_color = QtWidgets.QLabel(self.centralwidget)
        self.lb_color.setGeometry(QtCore.QRect(100, 30, 621, 121))
        font = QtGui.QFont()
        font.setPointSize(49)
        font.setBold(True)
        font.setWeight(75)
        self.lb_color.setFont(font)
        self.lb_color.setTextFormat(QtCore.Qt.AutoText)
        self.lb_color.setAlignment(QtCore.Qt.AlignCenter)
        self.lb_color.setObjectName("lb_color")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btn_red.setText(_translate("MainWindow", "RED"))
        self.btn_yellow.setText(_translate("MainWindow", "YELLOW"))
        self.btn_green.setText(_translate("MainWindow", "GREEN"))
        self.lb_color.setText(_translate("MainWindow", "PICK A COLOR"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
