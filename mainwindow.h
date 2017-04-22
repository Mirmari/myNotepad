#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QColor>
#include <QFont>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMenu *pMenu;
    QMenuBar *pMenuBar;
    QTextEdit *pTxt;
    QMessageBox *pMsbox;
//    QToolBar *pTool;
    QFont font;
    QColor nColor;
    bool flag;
    bool flagNd;


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QToolBar *createToolBar();
    void initVar();
public slots:
    void openFile();
    void saveFile();
    void closeProg();

    void setNormal();
    void setBold();
    void setCoursive();
    void setStrikeOut();
    void setColorFont();
    void setStyleFont();
    void clear();

};


#endif // MAINWINDOW_H
