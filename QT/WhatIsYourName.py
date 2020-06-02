from PyQt5.QtWidgets import *

app = QApplication([])
win = QWidget()

win.resize(400,200)

label = QLabel("너의 이름은? : ", win)
label.move(20,50)

text = QLineEdit(win)
text.move(200,50)

btn1 = QPushButton("입력",win)
btn1.move(20,100)

btn2 = QPushButton("삭제",win)
btn2.move(260,100)



win.show()
app.exec()