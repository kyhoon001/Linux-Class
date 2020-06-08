from PyQt5.QtWidgets import *
from PyQt5.uic import *
from PyQt5.QtCore import *




class MyApp(QMainWindow) :
    def __init__(self):
        super().__init__()
        loadUi("pj04_1.ui", self)
        self.main()
        
    def main(self):
        self.timer = QTimer()
        self.timer.setInterval(100)
        self.timer.timeout.connect(self.run)
        self.timer.start()
        
        
        self.timer2 = QTimer()
        
        pass


    def run(self):
        self.timer2.stop()
        x = int(self.frame.x())
        y = int(self.frame.y())
        
        self.frame.move((x+3),y)
        msg = QMessageBox()
        msg.setText("GOGO")
#        msg.exec()
        
        
    def go(self) :
        self.timer.start()
        
    def stop(self):
        self.timer.stop()
        self.timer2.setInterval(100)
        self.timer2.timeout.connect(self.back)
        self.timer2.start()
        
        
        pass
        
    def back(self):
        x = int(self.frame.x())
        y = int(self.frame.y())
        
 
        self.frame.move((x-3),y)
        msg = QMessageBox()
        msg.setText("GOGO")
       

app = QApplication([])
win = MyApp()

win.show()
app.exec()