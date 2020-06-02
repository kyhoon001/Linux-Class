from PyQt5.QtWidgets import *

app = QApplication([])
win = QWidget()

button = QPushButton("GOGO", win)
button.move(100,100) #버튼 이동 

btn2 = QPushButton("NONO", win)
btn2.move(50,50)

win.show()
app.exec()