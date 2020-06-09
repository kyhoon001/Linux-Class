from PyQt5.QtWidgets import *
from PyQt5.uic import *
from PyQt5.QtGui import *
import numpy as np
import cv2
from PyQt5.QtTest import *
from PyQt5.QtCore import *
import time

class MyApp(QMainWindow) :
    def __init__(self):
        super().__init__()
        loadUi("camera.ui",self)
        
        
        
        self.cam = cv2.VideoCapture(0)
        #self.cam = dv2.VideoCapture('name.mp4') # 이건 파일을 활용할 때 쓰는 코드 
        #캠 사이즈가 안 맞을경우 오류 발생할 수 있음.
        self.cam.set(3, 480) # 3 은 width를 의미함 
        self.cam.set(4, 320) # 4는 height를 의미함
        
        
        self.tm = QTimer()
        self.tm.setInterval(33) # 프레임 조절 33이면 30프레임정도 
        self.tm.timeout.connect(self.gogo)
        self.tm.start()
        
    def gogo(self) :

        ret, self.img = self.cam.read()
        self.img2 = self.process(self.img)
        self.img3 = self.process2(self.img)
        self.img4 = self.process3(self.img)
            
        self.printScreen(self.img, self.pic1)
        self.printScreen(self.img2, self.pic2)
        self.printScreen(self.img3, self.pic3)
        self.printScreen(self.img4, self.pic4)
        self.printScreen(self.img, self.pic5)
        self.printScreen(self.img, self.pic6)
        self.printScreen(self.img, self.pic7)
        self.printScreen(self.img, self.pic8)
        
        
        
    def slot1(self):
        #self.tm.start()
        
        """
        for i in range(100): #반복문을 사용해서 동영상처럼 찍히게 만들어 주었음
            ret, self.img = self.cam.read()
            self.img2 = self.process(self.img)
            self.img3 = self.process2(self.img)
            self.img4 = self.process3(self.img)
            
            self.printScreen(self.img, self.pic1)
            
            self.printScreen(self.img2, self.pic2)
            self.printScreen(self.img3, self.pic3)
            self.printScreen(self.img4, self.pic4)
            self.printScreen(self.img, self.pic5)
            self.printScreen(self.img, self.pic6)
            self.printScreen(self.img, self.pic7)
            self.printScreen(self.img, self.pic8)
            QTest.qWait(1)
        
        """
    def process(self, img) : # blur func 모자이크처럼 처리해줌
        img = cv2.blur(img,(50,50))
        return img
        
    def process2(self, img) : #테두리를 처리함
        img = cv2.Canny(img, self.dial.value(), self.dial2.value())
        return img
    
    def process3(self, img) :
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        #img = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, np.ones(3,3), np.unit8)
        #img = cv2.threshold(img, 120, 255, cv2.THRESH_BINARY) 안 됨 ㅠㅠ 
        return img


    def printScreen(self, imgBGR, pic) :
        imgRGB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB) # rgb로 변경하는 과정
        h, w, byte = imgRGB.shape
        img = QPixmap(QImage(imgRGB, w, h, byte * w, QImage.Format_RGB888))
        pic.setPixmap(img)
        

app = QApplication([])
win = MyApp()

win.show()
app.exec()