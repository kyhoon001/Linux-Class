from PyQt5.QtWidgets import *


app = QApplication([])
win = QWidget()

win.resize(300,100)

btn1 = QPushButton("OK")
btn2 = QPushButton("No")

lay = QVBoxLayout()
lay.addWidget(btn1)
lay.addWidget(btn2)

win.setLayout(lay)



win.show()
app.exec()