from PyQt5.QtWidgets import *

app = QApplication([])
app.setApplicationName("My Friends")
win = QMainWindow()

global status
status = win.statusBar()
status.showMessage("인맥을 관리합시다.")

win.resize(300,200)

menu = win.menuBar()
m1 = menu.addMenu("메뉴")

mexex = QAction("종료",win)
madd = QAction("추가",win)
mde = QAction("제거",win)

m1.addAction(madd)
m1.addAction(mde)
menu.addAction(mexex)
main = QWidget()


line1 = QLineEdit()
form = QFormLayout()
label = QLabel("인맥을 관리합시다.")


lo = QHBoxLayout()
btnadd = QPushButton("추가")
btndel = QPushButton("제거")
lo.addWidget(btnadd)
lo.addWidget(btndel)

form.addWidget(label)
form.addRow("name",line1)
form.addRow(lo)


#######################################function#####################
global friends
friends = ["호랑이","고라니","james","man"]


def add() :
    name = line1.text()
    if friends.count(name) >= 1 :
        status.showMessage("이미 친구입니다.")
        print("이미 친구입니다!")
    else :
        friends.append(name)
        status.showMessage("환영합니다 나의 인맥")
        print("add")
    pass

def de() :
    name = line1.text()
    if friends.count(name) >= 1 :
        friends.remove(name)
        status.showMessage(name + " 더 이상 내 친구가 아닙니다.")
        print("delete")
    else :
        print(name + " 그런 친구는 없습니다.")
        status.showMessage(name + " 그런 친구는 없습니다.")

def exex() :
    print("bye")
    exit()
    pass




#######################################################################









btnadd.clicked.connect(add)
btndel.clicked.connect(de)

# 메뉴에 있는거는 triggered로 연결해줌
madd.triggered.connect(add)
mde.triggered.connect(de)
mexex.triggered.connect(exex)

main.setLayout(form)
win.setCentralWidget(main)
win.show()
app.exec()
