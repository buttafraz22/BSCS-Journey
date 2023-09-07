import sys
from PyQt5.uic import loadUi
from PyQt5.QtWidgets import *

class MainWindow(QMainWindow):
    def__init__(self):
        super(MainWindow, self).__init__()
        loadUi('P2UI.ui',self)
app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec_())
