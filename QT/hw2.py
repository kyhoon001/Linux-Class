from PyQt5.QtWidgets import *

app = QApplication([])
win = QWidget()

form = QFormLayout()

line1 = QLineEdit()
line2 = QLineEdit()
btn1 = QPushButton("주시오")

form.addRow("이름 : ", line1)
form.addRow("경력직 \n희망 연봉 : ",line2)
form.addRow(btn1)

def msg() :
    
    mbox = QMessageBox() #메세지 박스로 띄워줌.
    sal = int(line2.text()) * 3
    mbox.setText(line1.text() + "님, 연봉을 "+ str(sal)  +"로 채용합니다.") # 메세지 박스에 들어갈 텍스트
    
    mbox.exec() # 메시지 박스는 exec로 실행

btn1.clicked.connect(msg)

win.setLayout(form)
win.show()
app.exec()