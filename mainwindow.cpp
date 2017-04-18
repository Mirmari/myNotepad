#include "mainwindow.h"
#include <QImage>
#include <QToolBar>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    pTxt = new QTextEdit(this);
    pTxt->setGeometry(10,50,765,800);
    pMenu = new QMenu("Menu");
    pMenuBar = new QMenuBar;
    setMenuBar(pMenuBar);
    pMenu->addAction("&Open file",this,SLOT(openFile()));
    pMenu->addSeparator();
    pMenu->addAction("&Save file",this,SLOT(saveFile()));
    pMenu->addSeparator();
    pMenu->addAction("&Close program",this,SLOT(closeProg()));
    pMenuBar->addMenu(pMenu);
    addToolBar(Qt::TopToolBarArea,createToolBar());

}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Text Files (*.txt)"));

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
       QMessageBox mes;
       mes.setText("Incorrect open!");
       mes.exec();
    }
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in(&file);
    pTxt->setText(in.readAll());
    file.close();

}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
       QMessageBox mes;
       mes.setText("Incorrect save!");
       mes.exec();
    }
    file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&file);
        stream << pTxt->toPlainText();
        file.close();
        //coment


}

void MainWindow::closeProg()
{
    this->close();
}

QToolBar *MainWindow::createToolBar()
{
    QImage img("pic.jpg");
    QToolBar *pTool = new QToolBar("Menu",this);
    pTool->setAllowedAreas( Qt::LeftToolBarArea|Qt::TopToolBarArea);
    pTool->addAction(QPixmap::fromImage(img), "Free draw",this, SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this,SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this, SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this, SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this,SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this,SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this,SLOT(closeProg()));
    pTool->addAction(QPixmap::fromImage(img),"Free draw",this,SLOT(closeProg()));\
    pTool->addAction(QPixmap::fromImage(img), "Clear",this,SLOT(closeProg()));

    return pTool;
}
