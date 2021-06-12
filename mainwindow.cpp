#include "mainwindow.h"
#include "qboxlayout.h"
#include "qevent.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include "qwindow.h"
#include <QLayout>
#include <QApplication>
#include <QWindow>
#include <QVBoxLayout>
#include <qtermwidget5/qtermwidget.h>
#include <QProcess>
#include <QMessageBox>
#include "function/function.h"
#include "widgets/console.h"
#include "widgets/split_web.h"
#include <QTimer>
using namespace output;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    pRight(new QSplitter(Qt::Horizontal,this))
{
    QTimer *check = new QTimer(this);
    check->start(1000/3);
    connect(check,SIGNAL(timeout()),
            this,SLOT(done()));
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
    connect(app ,SIGNAL(clicked()),
            this,SLOT(newapp()));
    QVBoxLayout *buttons = new QVBoxLayout(left);
    buttons->addWidget(web);
    buttons->addWidget(terminal);
    buttons->addWidget(app);
    left->setFixedWidth(100);
    pRight->addWidget(left);
    Console = new SplitWeb(this,new console());

    pRight->addWidget(Console);
    //QString id = "0x3a00024";
    //WId wid = WId(id.toInt(NULL,16));
    //QWindow *win = QWindow::fromWinId(wid);
    //pRight->addWidget(QWidget::createWindowContainer(win,NULL,Qt::FramelessWindowHint));
    //pRight->addWidget(new SplitWeb(this));
    setCentralWidget(pRight);
}
MainWindow::~MainWindow(){
    delete pRight;
    qDebug()<<"exit";
}
void MainWindow::newweb(){
    SplitWeb *temp = new SplitWeb(this);
    connect(temp,SIGNAL(check()),
            Console,SLOT(check_to_close()));
    Console->addWidget(temp);
    Console->add();
}
void MainWindow::newterminal(){
    SplitWeb *temp =  new SplitWeb(this,new console());
    connect(temp,SIGNAL(check()),
            Console,SLOT(check_to_close()));
    Console->addWidget(temp);
    Console->add();
}
void MainWindow::newapp(){


    QString output;
    output=shell("xwininfo");
    output=output.simplified();
    SplitWeb* temp = new SplitWeb(this,new app(nullptr,output));
    connect(temp,SIGNAL(check()),
            Console,SLOT(check_to_close()));
    Console->addWidget(temp);
    Console->add();

}
void MainWindow::closeEvent(QCloseEvent* event){
    auto f = [] (QCloseEvent* event ,SplitWeb* Console, QWidget *temmp){
        auto temp = QMessageBox::information(temmp, "tooltip", QString::fromLocal8Bit("你是否要关闭?"), QMessageBox::Yes | QMessageBox::No);
        if (temp == QMessageBox::Yes)
        {
            // 接受了 要关闭这个窗口的事件. accept和ignore只是作为一个标志.
            Console->deleteLater();
            event->ignore();
        }
        else
        {
            //忽略了 要关闭这个窗口的事件.当前窗口就不会被关闭.
            event->ignore();
        }
    };
    f(event,Console,this);
}
void MainWindow::done(){
    if(pRight->count()==1){
        exit(0);
    }
}
