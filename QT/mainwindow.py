from PyQt5.QtWidgets import *

app = QApplication([])
app.setApplicationName("ok ok ok")

win = QMainWindow()
main = QWidget()

status = win.statusBar()
status.showMessage("OK")


main.resize(600,600)

label = QLabel("HUHUHU", main)
btn = QPushButton("ok",main)
btn.move(100,100)

win.setCentralWidget(main)
win.show()
app.exec()