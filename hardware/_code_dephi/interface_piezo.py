# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/Users/louisdellavittoria/Desktop/Etudes/2_2A/Projet/PROTIS/interface_piezo.ui'
#
# Created by: PyQt5 UI code generator 5.15.10
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets
from class_piezo import *
import time


class AutomationWorker(QtCore.QThread):
    def __init__(self, controller_piezo):
        super().__init__()
        self.controller_piezo = control_piezo()

    def run(self):
        mesure = []
        for i in range(0, 20):
            mesure.append(i)
            print(i)
            time.sleep(1)
            self.controller_piezo.GoToDistance(i)
        self.controller_piezo.set_zero()

class Ui_MainWindow2(QtWidgets.QWidget):
    def __init__(self):
        super().__init__()
        self.controller_piezo = control_piezo()  # Initialisez ici votre contrôleur piezo

    def setupUi(self, MainWindow2):
        MainWindow2.setObjectName("Fenêtre de contrôle de la cale piezo-électrique")
        MainWindow2.resize(470, 700)
        MainWindow2.setStyleSheet("background-color:white")
        self.centralwidget = QtWidgets.QWidget(MainWindow2)
        self.centralwidget.setObjectName("centralwidget")
        self.frame = QtWidgets.QFrame(self.centralwidget)
        self.frame.setGeometry(QtCore.QRect(30, 10, 411, 641))
        self.frame.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setLineWidth(0)
        self.frame.setObjectName("frame")
        self.label = QtWidgets.QLabel(self.frame)
        self.label.setGeometry(QtCore.QRect(30, 50, 351, 351))
        self.label.setText("")
        #C:/Users/LEnsE/Documents/Dephi-GRA/Dephi-GRA/KPC101.jpg
        #/Users/louisdellavittoria/Desktop/Etudes/2_2A/Projet/PROTIS/KPC101.jpg
        self.label.setPixmap(QtGui.QPixmap("C:/Users/LEnsE/Documents/Dephi-GRA/Dephi-GRA/KPC101.jpg"))
        self.label.setScaledContents(True)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.frame)
        self.label_2.setGeometry(QtCore.QRect(20, 20, 371, 21))
        self.label_2.setStyleSheet("    font-size: 15px;\n"
        "    font-weight: bold;\n"
        "    color: white;\n"
        "    background-color: grey;\n"
        "    border: 2px solid orange; /* Bordure verte */\n"
        "    border-radius: 5px; /* Coins arrondis */\n"
        "    padding: ")
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.frame_2 = QtWidgets.QFrame(self.frame)
        self.frame_2.setGeometry(QtCore.QRect(30, 430, 351, 201))
        self.frame_2.setStyleSheet("border-radius: 10px;\n"
        "background-color: lightgrey\n"
        "")
        self.frame_2.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame_2.setObjectName("frame_2")
        self.verticalLayoutWidget_3 = QtWidgets.QWidget(self.frame_2)
        self.verticalLayoutWidget_3.setGeometry(QtCore.QRect(10, 10, 331, 181))
        self.verticalLayoutWidget_3.setObjectName("verticalLayoutWidget_3")
        self.verticalLayout_6 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_3)
        self.verticalLayout_6.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_3 = QtWidgets.QLabel(self.verticalLayoutWidget_3)
        self.label_3.setStyleSheet("    font-size: 14px;\n"
        "    font-weight: bold;\n"
        "    color: white;\n"
        "    background-color: grey;\n"
        "    border: 2px solid grey; /* Bordure verte */\n"
        "    border-radius: 8px; /* Coins arrondis */\n"
        "")
        self.label_3.setObjectName("label_3")
        self.horizontalLayout.addWidget(self.label_3)
        self.doubleSpinBox = QtWidgets.QDoubleSpinBox(self.verticalLayoutWidget_3)
        self.doubleSpinBox.setStyleSheet("QDoubleSpinBox {\n"
        "        background-color: #2E3440;\n"
        "        color: white;\n"
        "        font-weight: bold;\n"
        "        border: 2px solid black;\n"
        "        border-radius: 8px;\n"
        "        padding: 5px;\n"
        "        font-size: 15px;\n"
        "    }\n"
        "\n"
        "    QDoubleSpinBox::up-button { \n"
        "        background-color: #4CAF50;\n"
        "        border: 1px solid #4C566A;\n"
        "        border-radius: 5px;\n"
        "        width: 20px;\n"
        "        height: 12px;\n"
        "    }\n"
        "\n"
        "    QDoubleSpinBox::up-button:hover {\n"
        "        background-color: #45a049;\n"
        "    }\n"
        "\n"
        "    QDoubleSpinBox::down-button {\n"
        "        background-color: #fc3535;\n"
        "        border: 1px solid #4C566A;\n"
        "        border-radius: 5px;\n"
        "        width: 20px;\n"
        "        height: 12px;\n"
        "    }\n"
        "\n"
        "    QDoubleSpinBox::down-button:hover {\n"
        "        background-color: #f55656;\n"
        "    }\n"
        "\n"
        "")
        self.doubleSpinBox.setAlignment(QtCore.Qt.AlignCenter)
        self.doubleSpinBox.setReadOnly(False)
        self.doubleSpinBox.setButtonSymbols(QtWidgets.QAbstractSpinBox.UpDownArrows)
        self.doubleSpinBox.setSingleStep(0.03)
        self.doubleSpinBox.setObjectName("doubleSpinBox")
        self.doubleSpinBox.valueChanged.connect(self.set_value)
        self.horizontalLayout.addWidget(self.doubleSpinBox)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.verticalLayout_6.addLayout(self.verticalLayout_2)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.pushButton = QtWidgets.QPushButton(self.verticalLayoutWidget_3)
        self.pushButton.setStyleSheet("QPushButton {\n"
        "    background-color: #4CAF50;\n"
        "    color: white;\n"
        "    font-size: 14px;\n"
        "    font-weight: bold;\n"
        "    border: 2px solid #2E7D32;\n"
        "    border-radius: 5px;\n"
        "    padding: 1px;\n"
        "}\n"
        "\n"
        "QPushButton:hover {\n"
        "    background-color: #45a049;\n"
        "    border-color: #1B5E20;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: #388E3C;\n"
        "    border-color: #1B5E20;\n"
        "}")
        self.pushButton.setObjectName("pushButton")
        self.pushButton.clicked.connect(self.go_to_distance)
        self.verticalLayout_3.addWidget(self.pushButton)
        self.pushButton_2 = QtWidgets.QPushButton(self.verticalLayoutWidget_3)
        self.pushButton_2.setStyleSheet("QPushButton {\n"
        "    background-color: #4CAF50;\n"
        "    color: white;\n"
        "    font-size: 14px;\n"
        "    font-weight: bold;\n"
        "    border: 2px solid #2E7D32;\n"
        "    border-radius: 5px;\n"
        "    padding: 1px;\n"
        "}\n"
        "\n"
        "QPushButton:hover {\n"
        "    background-color: #45a049;\n"
        "    border-color: #1B5E20;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: #388E3C;\n"
        "    border-color: #1B5E20;\n"
        "}")
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_2.clicked.connect(self.init_piezo)
        self.verticalLayout_3.addWidget(self.pushButton_2)
        self.pushButton_3 = QtWidgets.QPushButton(self.verticalLayoutWidget_3)
        self.pushButton_3.setStyleSheet("QPushButton {\n"
        "    background-color: #4CAF50;\n"
        "    color: white;\n"
        "    font-size: 14px;\n"
        "    font-weight: bold;\n"
        "    border: 2px solid #2E7D32;\n"
        "    border-radius: 5px;\n"
        "    padding: 1px;\n"
        "}\n"
        "\n"
        "QPushButton:hover {\n"
        "    background-color: #45a049;\n"
        "    border-color: #1B5E20;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: #388E3C;\n"
        "    border-color: #1B5E20;\n"
        "}")
        self.pushButton_3.setObjectName("pushButton_3")
        self.pushButton_3.clicked.connect(self.start_automation)
        self.verticalLayout_3.addWidget(self.pushButton_3)
        self.verticalLayout_6.addLayout(self.verticalLayout_3)
        self.label_8 = QtWidgets.QLabel(self.frame)
        self.label_8.setGeometry(QtCore.QRect(40, 420, 81, 16))
        self.label_8.setStyleSheet("    font-size: 12px;\n"
        "    font-weight: bold;\n"
        "    color: white;\n"
        "    background-color: grey;\n"
        "    border: 2px solid grey; /* Bordure verte */\n"
        "    border-radius: 8px; /* Coins arrondis */\n"
        "")
        self.label_8.setAlignment(QtCore.Qt.AlignCenter)
        self.label_8.setObjectName("label_8")
        self.pushButton_4 = QtWidgets.QPushButton(self.frame)
        self.pushButton_4.setGeometry(QtCore.QRect(280, 390, 91, 16))
        self.pushButton_4.setStyleSheet("    font-size: 11px;\n"
        "    font-weight: bold;\n"
        "    color: white;\n"
        "    background-color: grey;\n"
        "    border: 2px solid grey; /* Bordure verte */\n"
        "    border-radius: 8px; /* Coins arrondis */\n"
        "")
        self.pushButton_4.setObjectName("pushButton_4")
        MainWindow2.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow2)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 470, 36))
        self.menubar.setObjectName("menubar")
        MainWindow2.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow2)
        self.statusbar.setObjectName("statusbar")
        MainWindow2.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow2)
        QtCore.QMetaObject.connectSlotsByName(MainWindow2)

    def retranslateUi(self, MainWindow2):
        _translate = QtCore.QCoreApplication.translate
        MainWindow2.setWindowTitle(_translate("MainWindow2", "Fenêtre de contrôle de la cale piezo-électrique"))
        self.label_2.setText(_translate("MainWindow2", "Fenêtre de contrôle de la cale piezo-électrique"))
        self.label_3.setText(_translate("MainWindow2", "Déplacement (µm) :"))
        self.pushButton.setText(_translate("MainWindow2", "Déplacer la cale piezo-électrique"))
        self.pushButton_2.setText(_translate("MainWindow2", "Revenir à la position initiale"))
        self.pushButton_3.setText(_translate("MainWindow2", "Déplacement automatisé 0 --> 20"))
        self.label_8.setText(_translate("MainWindow2", "Contrôles"))
        self.pushButton_4.setText(_translate("MainWindow2", "Infos piezo"))

    def set_value(self):
        self.value_distance = self.doubleSpinBox.value()
        print(self.value_distance)

    def init_piezo(self):
        print("Initialisation de la cale piezo-électrique")
        self.controller_piezo.set_zero()
        print("Initialisation terminée")

    def go_to_distance(self):
        print("Déplacement de la cale piezo-électrique")
        print(self.value_distance)
        self.controller_piezo.GoToDistance(self.value_distance)
        print("Déplacement terminé")

    def start_automation(self):
        self.automation_worker = AutomationWorker(self.controller_piezo)
        self.automation_worker.start()

