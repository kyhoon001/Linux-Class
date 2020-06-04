from PyQt5.QtWidgets import *
from PyQt5.uic import *
from sense_hat import SenseHat

class MyApp(QMainWindow):
    def __init__(self):
        super().__init__()
        loadUi("dial.ui",self)
        self.sen = SenseHat()
        
        
        
        
        self.dr = 0
        self.dg = 0
        self.db = 0
        
        
        self.oldY = 0
        self.oldX = 0
        
        self.oldR = 0
        self.oldG = 0
        self.oldB = 0
        #self.sense = SenseHat()
        #self.sense.show_message("HI HI hI HI HI Hi")
        
        
    def change(self, value) :
        
        pass
        """
        x = value // 8
        y = value % 8
        
        oy = self.oldY
        ox = self.oldX
        
        oR = self.oldR
        oG = self.oldG
        oB = self.oldB
        
        if oy != y and ox != x :
            self.oldR 
            self.sen.set_pixel(x, y, 255,255,255)
            self.sen.set_pixel(x, y, self.oldR, self.oldG, self.oldB)
                
        
        self.sen.set_pixel(x,y,255,255,255)
        
        self.oldY = y
        self.oldX = x
        
        """
    def closeEvent(self, e) :
        self.sen.clear()
        
        
    def kok(self) :
        x = self.dial.value() // 8
        y = self.dial.value() % 8
        
        self.sen.set_pixel(x, y, 255,255,255)
        self.sen.set_pixel(x, y, self.dr,self.dg,self.db)
        #self.sen.set_pixel(x,y, self.dr, self.dg, self.db)
        pass
        
    def red(self,value) :
        self.dr = value
        
    def black(self, value) :
        self.db = value
        
    def green(self,value) :
        self.dg = value
        
app = QApplication([])
win = MyApp()
win.show()
app.exec()