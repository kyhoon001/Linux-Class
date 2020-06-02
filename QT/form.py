from PyQt5.QtWidgets import *

app = QApplication([])
win = QWidget()

app.setApplicationName("six W") # 어플리케이션 이름 바꾸는 것
form = QFormLayout()

line1 = QLineEdit()
line2 = QLineEdit()
line3 = QLineEdit()

form.addRow("What?", line1) # 뒤에는 위젯이 들어가야함
form.addRow("why?", line2) 
form.addRow("Where?", line3)

btn1 = QPushButton("OK")
form.addRow(btn1)
#form.addRow(QPushButton("OK"))

def msg():
    print("#####") # 이렇게 하면 콘솔 창에 표시됨.
    print(line1.text()) # 첫 번째 줄에 쓴걸 콘솔창에 표시
    mbox = QMessageBox() #메세지 박스로 띄워줌.
    mbox.setText("okok?") # 메세지 박스에 들어갈 텍스트
    mbox.exec() # 메시지 박스는 exec로 실행

btn1.clicked.connect(msg)

win.setLayout(form)
win.show()
app.exec()