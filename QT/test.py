from PyQt5.QtWidgets import *
from PyQt5.uic import *
import hashlib

class MyApp(QMainWindow) :
    def __init__(self):
        super().__init__()
        loadUi("hi.ui",self)
        self.main()
        
    def main(self):
        pass
    
    def check(self):
        me = self.me.text()
        you = self.you.text()
        age = self.age.value()
        
        #hashCode1 = hashlib.sha256(me.encode()).hexdigest()
        #print(hashCode1)
        #print(type(hashCode1)) # str임
        #hashCode1 = int(hashCode1, 16)
        hashCode1 = int(hashlib.sha256(me.encode()).hexdigest(),16)        
        hashCode2 = int(hashlib.sha256(me.encode()).hexdigest(),16)
        
        cal = (hashCode1 + hashCode2) + (777 * age)
        cal = cal % 101
        print(cal)
        
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setText("확률은"+ str(cal) + "%입니다.")
        msg.exec()
        
        #print("check")
        #print(self.me.text())
        #print(self.you.text())
        #print(self.age.value())
        
    def clear(self):
        print("clear")
        self.me.setText("")
        self.you.setText("")
        self.age.setValue(0)
    
    
    
    
app = QApplication([])
win = MyApp()
win.show()
app.exec()