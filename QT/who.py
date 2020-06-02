from PyQt5.QtWidgets import *

app = QApplication([])
win = QWidget()

#QVBoxLayout 이 있고, QHBoxLayout 이 있음.

win.resize(300,100)
mainlay = QVBoxLayout()  # vertical, horizon
lay1 = QVBoxLayout() # QVBoxLayout은 하나의 Layout 아래로 내려가면서 배치한다는 뜻
lay2 = QHBoxLayout() # QHBoxLayout은 여러개 가능 = 오른쪽으로 늘어지면서 배치한다는 뜻

mainlay.addLayout(lay1)
mainlay.addLayout(lay2)
lay1.addWidget(QLabel("누구를 택할까?"))
lay2.addWidget(QPushButton("박보영"))
lay2.addWidget(QPushButton("박보검"))
lay2.addWidget(QPushButton("사나"))

win.setLayout(mainlay)
win.show()
app.exec()