#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMenu *pMenu;
    QMenuBar *pMenuBar;
    QTextEdit *pTxt;
    QMessageBox *pMsbox;
//    QToolBar *pTool;


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QToolBar *createToolBar();
public slots:
    void openFile();
    void saveFile();
    void closeProg();

};

#endif // MAINWINDOW_H
