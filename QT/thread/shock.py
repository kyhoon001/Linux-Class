from PyQt5.QtWidgets import *
from gpiozero import *
from PyQt5.uic import *


class MyApp(QMainWindow) :
    def __init__(self):
        super().__init__()
        loadUi("shock.ui",self)
        self.frame1.move(10,10)
        self.frame2.move(10,10)
        self.tick = 0
        self.resize(240,260)
        
        self.btn = Button(24)
        
        self.tick = self.btn.is_active
        
        self.led1 = LED(18)
        self.led2 = LED(15)
        self.led1.source = self.btn
        self.led2.source = self.btn
        
        self.btn.when_pressed = self.press
        print(self.tick)
    def press(self):
        tick = self.tick
        f1 = self.frame1
        f2 = self.frame2
        print(tick)
        if tick % 2 == 0 :
            f1.setVisible(False)
            f2.setVisible(True)
        else :
            f1.setVisible(True)
            f2.setVisible(False)

        self.tick += 1
        
app = QApplication([])
win = MyApp()
win.show()
app.exec()