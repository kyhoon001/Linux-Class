from PyQt5.QtWidgets import *
from PyQt5.uic import *
from PyQt5.QtCore import *
from time import sleep 


class MyThread(QThread): # timer는 내부적으로 쓰레드가 돌고있음
    
    mySignal = pyqtSignal(int, int)
    
    
    def __init__(self) :
        super().__init__()
        
    def run(self):
        print(int(self.currentThreadId()))
        for i in range(5):
            for x in range(101):
                self.mySignal.emit(1,x)
                sleep(0.1)
        
        
        #self.MySignal.emit(0,0)
        pass
    
        
        
class MyApp(QMainWindow):
    def __init__(self):
        super().__init__()
        loadUi("progressbar.ui",self)
        
        v = self.gridLayout
        self.pb = []
        for i in range(5):
            self.pb.append(v.itemAt(i).widget())
        
        for i in range(5):
            self.pb[i].setValue(100)
        
        self.th = []
        for i in range(5):
            self.th.append(MyThread())
            self.th[i].mySignal.connect(self.setset)
        
    def gogo(self):
        for i in range(5):
            self.th[i].start()
       
    def setset(self, i, x) :
        self.pb[i].setValue(x)
        
        
app = QApplication([])
win = MyApp()
win.show()
app.exec()
        
        
        