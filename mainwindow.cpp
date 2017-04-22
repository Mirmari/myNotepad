#include "mainwindow.h"
#include <QImage>
#include <QToolBar>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QColorDialog>
#include <QFontDialog>

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
    initVar();
    nColor = Qt::black;

}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Text Files (*.txt)"));

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox mes;
       mes.setText("Incorrect open!");
       mes.exec();
    }
    QTextStream in(&file);
    pTxt->setText(in.readAll());
    file.close();

}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
       QMessageBox mes;
       mes.setText("Incorrect save!");
       mes.exec();
    }
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
    QImage clear("clear.png");
    QImage coursive("coursive.png");
    QImage strikeOut("strikeOut.png");
    QImage bold("fat.png");
    QImage sizeText("size.png");
    QImage colorFont("typeFont.png");
    QImage normal("normal.png");
    QToolBar *pTool = new QToolBar("Menu",this);
    pTool->setAllowedAreas( Qt::LeftToolBarArea|Qt::TopToolBarArea);
    pTool->setIconSize(QSize(40,40));
    pTool->addAction(QPixmap::fromImage(normal),"Normal text",this, SLOT(setNormal()));
    pTool->addAction(QPixmap::fromImage(coursive), "Italic",this, SLOT(setCoursive()));
    pTool->addAction(QPixmap::fromImage(bold),"Bolt",this,SLOT(setBold()));
    pTool->addAction(QPixmap::fromImage(strikeOut),"Strike Out",this,SLOT(setStrikeOut()));
    pTool->addAction(QPixmap::fromImage(sizeText),"Set Font",this, SLOT(setStyleFont()));
    pTool->addAction(QPixmap::fromImage(colorFont),"Set Color",this, SLOT(setColorFont()));
    pTool->addAction(QPixmap::fromImage(clear), "Clear",this,SLOT(clear()));

    return pTool;
}

void MainWindow::initVar()
{
     flag = true;

}


void MainWindow::setNormal()
{

    font.setStyle(QFont::StyleNormal);
    pTxt->setCurrentFont(font);
}

void MainWindow::setBold()
{

    flag =!flag;
    (flag)?pTxt->setFontWeight(QFont::Bold):pTxt->setFontWeight(QFont::Normal);

}

void MainWindow::setCoursive()
{
    flag =!flag;
    (flag)?font.setStyle(QFont::StyleItalic):font.setStyle(QFont::StyleNormal);
    pTxt->setCurrentFont(font);
}

void MainWindow::setStrikeOut()
{
    flag =!flag;
    (flag)?font.setStrikeOut(true):font.setStrikeOut(false);
    pTxt->setCurrentFont(font);
}

void MainWindow::setColorFont()
{
    nColor = QColorDialog::getColor();
    pTxt->setTextColor(nColor);
}

void MainWindow::setStyleFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    pTxt->setFont(font);
}

void MainWindow::clear()
{
    pTxt->clear();
}
