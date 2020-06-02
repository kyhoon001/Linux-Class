from PyQt5.QtWidgets import *

app = QApplication([])
win = QWidget()

win.resize(400,400)

label = QLabel("Your heart bit:",win)
label.move(20,100)

text = QLineEdit(win)
text.move(200,100)

btn = QPushButton("GOGO",win)
btn.setGeometry(100,300,100,40) # 사이즈를 조절해줄 수 있음. 앞에는 위치이고 뒤에는 사이즈 
btn.move(100,300)


win.show()
app.exec()