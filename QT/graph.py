from PyQt5.QtWidgets import *
from PyQt5.uic import *
import numpy as np
from matplotlib import pyplot as pp
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg
        
class MyApp(QMainWindow):
    def __init__(self):
        super().__init__()
        loadUi("graph.ui",self)
        
        # 객체 만들기 
        self.figure = pp.Figure()
        self.canvas = FigureCanvasQTAgg(self.figure)
        
        self.lay.addWidget(self.canvas)
        
        self.graph1 = self.figure.add_subplot(3,1,1)
        self.graph2 = self.figure.add_subplot(3,1,2)
        self.graph3 = self.figure.add_subplot(3,1,3)
        
    def slot1(self):
        self.graph1.plot([1,2,3,4],[5,5,4,6])
        self.canvas.draw()
        print("s1")
        
    def slot2(self):
        self.graph2.bar([1,2,3,4],[5,2,3,1])
        self.canvas.draw()
        print("s2")
    def slot3(self):
        n = 750
        x, y = np.random.rand(2,n)
        scale = 200.0 * np.random.rand(n)
        self.graph3.scatter(x, y, c='tab:blue', s=scale, label='tab:blue', arpha=0.3, edgecolors='none')
        self.canvas.draw()
        print("s3")
        
        
app = QApplication([])
win = MyApp()
win.show()
app.exec()
        
        
        
