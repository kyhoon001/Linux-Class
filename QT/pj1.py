'''
from PyQt5.QtWidgets import *

app = QApplication([])
app.setApplicationName("mainwindow")
win = QMainWindow()

global satus
status = win.statusBar()
#status.showMessage("asd")
win.resize(240,240)
main = QWidget()

def ch(text):
#    print(self)
#    name = self.text()
    status.showMessage(text)

btn1 = QPushButton("보라돌이",main)
btn1.move(20,20)
btn2 = QPushButton("뚜비",main)
btn2.move(100,20)
btn3 = QPushButton("나나",main)
btn3.move(20,120)
btn4 = QPushButton("뽀",main)
btn4.move(100,120)

btn1.clicked.connect(ch(btn1.text()))
btn2.clicked.connect(ch(btn2.text()))
btn3.clicked.connect(ch(btn3.text()))
btn4.clicked.connect(ch(btn4.text()))

win.setCentralWidget(main)
win.show()
app.exec()
'''

from PyQt5.QtWidgets import *
app = QApplication([])
win = QMainWindow()
win.resize(500,500)
status = win.statusBar()
menu = win.menuBar()
homenu = menu.addMenu("HoHO")
kkmenu = menu.addMenu("KK")

q1 = QAction("SUBGOGO", win)
q2 = QAction("SUBTOTO", win)

homenu.addAction(q1)
kkmenu.addAction(q2)

def BBQ():
    msg = QMessageBox()
    msg.setText("hohohohoho")
    msg.exec()

def exex():
    quit()

q1.triggered.connect(BBQ)
q2.triggered.connect(exex)

main = QWidget()

name = ["보라", "뚜비", "나나", "뽀"]
btn = []

gpoX=[0,100,0,100]
gpoY=[0,0,100,100]

def btn1() :
    status.showMessage("보라돌이")
    pass
def btn2() :
    status.showMessage("뚜비")
    pass
def btn3() :
    status.showMessage("나나")
    pass
def btn4() :
    status.showMessage("뽀")
    pass


for i in range(0,4) :
    btn.append(QPushButton(name[i],main))
    btn[i].move(gpoX[i], gpoY[i])
    
btn[0].clicked.connect(btn1)
btn[1].clicked.connect(btn2)
btn[2].clicked.connect(btn3)
btn[3].clicked.connect(btn4)
    
win.setCentralWidget(main)
win.show()
app.exec()