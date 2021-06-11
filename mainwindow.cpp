#include "mainwindow.h"
#include "qboxlayout.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include "qwindow.h"
#include <QLayout>
#include <QApplication>
#include <QWindow>
#include <QVBoxLayout>
#include <qtermwidget5/qtermwidget.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    pRight(new QSplitter(Qt::Horizontal,this))
{
   // console = new QTermWidget();
   // QFont font = QApplication::font();
   // font.setFamily("Monospace");
   // font.setPointSize(12);

   // console->setTerminalFont(font);
   // console->setScrollBarPosition(QTermWidget::ScrollBarRight);
   // console->setColorScheme("BreezeModified");
    //This is for use terminal when view the web

    //pRight->addWidget(a);
    //connect the split button to give_url
    //connect(a->outside ,SIGNAL(clicked()),
    //        a,SLOT(give_url()));
    //because give_url call the get_the_url,so connect get_the_url to split.
    //connect(a,SIGNAL(get_the_url(QString)),
    //        this,SLOT(split(QString)));
    //Split_web *b = new Split_web();
    //pRight->addWidget(b);
    //pRight->addWidget(b);
    //connect(b->outside ,SIGNAL(clicked()),
    //        b,SLOT(give_url()));
    //connect(b,SIGNAL(get_the_url(QString)),
    //        this,SLOT(split(QString)));
    //set the pRight to the center
    QWidget *left = new QWidget();
    QPushButton *web = new QPushButton("网页");
    connect(web ,SIGNAL(clicked()),
            this,SLOT(newweb()));
    QPushButton *terminal = new QPushButton("终端");
    connect(terminal ,SIGNAL(clicked()),
            this,SLOT(newterminal()));
    QPushButton *app = new QPushButton("应用");
    QVBoxLayout *buttons = new QVBoxLayout(left);
    buttons->addWidget(web);
    buttons->addWidget(terminal);
    buttons->addWidget(app);
    left->setFixedWidth(100);
    pRight->addWidget(left);
    pRight->addWidget(new SplitWeb(this,new console()));
    //QString id = "0x3a00024";
    //WId wid = WId(id.toInt(NULL,16));
    //QWindow *win = QWindow::fromWinId(wid);
    //pRight->addWidget(QWidget::createWindowContainer(win,NULL,Qt::FramelessWindowHint));
    //pRight->addWidget(new SplitWeb(this));
    setCentralWidget(pRight);
}
MainWindow::~MainWindow(){
}
void MainWindow::newweb(){
    pRight->addWidget(new SplitWeb(this));
}
void MainWindow::newterminal(){
    pRight->addWidget(new SplitWeb(this,new console()));
}
