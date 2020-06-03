from PyQt5.QtWidgets import *
from PyQt5.uic import * # to use UI

class MyApp(QMainWindow):
    def __init__(self) :
        super().__init__()
        #self.setWindowTitle("메모장")
        #self.main()
        loadUi("bbq.ui",self)
        
    def openWorld(self):
        path = QFileDialog.getOpenFileName(self, "오픈",)[0]
        if path:
            self.Editor.setPlainText(open(path).read())
        #self.Editor.appendPlainText("Welcome")
        #-> Editor라는 이름의 plaintext widget에 해당 값을 넣음
        print("welcome")
    
    def saveWorld(self):
        path = QFileDialog.getSaveFileName(self, "저장",)[0]
        if path:
            with open(path, "w") as f:
                f.write(self.Editor.toPlainText())      
        print("SAVE")
        
    def closeWorld(self):
        self.Editor.appendPlainText("BYE")
        print("BYE")
    def whoWorld(self):
        QMessageBox.about(self, "HOHO", "HAHAHAHAHA")
        print("WhoWorld")
        
        
    def main(self):
        print("GOGOGO")


app = QApplication([])
win = MyApp()


win.show()
app.exec()