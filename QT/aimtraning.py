from PyQt5.QtWidgets import *
from PyQt5.uic import *
from PyQt5.QtCore import *  # 위젯과 모듈들이 많이 들어있음
from PyQt5 import QtTest
import random

class MyApp(QMainWindow) :
    def __init__(self):
        super().__init__()
        loadUi("hi2.ui",self)
        self.main()
        
    def main(self):
        self.timer = QBasicTimer()
        self.timer.start(600,self)
        
        
    def colorChange(self):
        print("COLOR")
        color = QColorDialog.getColor()
        if color.isValid():
            self.frame.setStyleSheet("background-color:%s" % color.name()) # 뒤는 파이썬 문법
        
    def nameChange(self):
        print("NAME")
        
        name, ok = QInputDialog.getText(self, "이름을 입력하세요", "너의 이름?")
        if ok :
            self.label.setText(name)
            self.label.adjustSize()
    
    def mousePressEvent(self,e) :  # 마우스를 추적할 수 있는 함수
        #따로 뭐 준거 없음.
        x = e.x()
        y = e.y()
        print(x,y)
        
        tx = self.label.x()
        ty = self.label.y()
        twidth = self.label.width()
        theight = self.label.height()
        
        if tx <= x <= tx + twidth:
            if ty <= y <= ty + theight:
                self.frame.setStyleSheet("background-color:#FF3256")
                QtTest.QTest.qWait(200)
                self.frame.setStyleSheet("background-color:$FFFFFF")
        
        
    def timerEvent(self,e):
        x = random.randint(0,self.frame.size().width() - self.label.size().width())
        y = random.randint(0,self.frame.size().height() - self.label.size().height())
        self.label.move(x,y)

app = QApplication([])
win = MyApp()
win.show()
app.exec()
