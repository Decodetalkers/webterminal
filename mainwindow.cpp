#include "mainwindow.h"
#include "qboxlayout.h"
#include "qevent.h"
#include "qicon.h"
#include "qjsonobject.h"
#include "qobjectdefs.h"
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
#include <QStyleFactory>
#include <QJsonObject>
#include <QJsonDocument>
using namespace output;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    pRight(new QSplitter(Qt::Horizontal,this)),
    status(false),
    icon(1)
{
    QTimer *check = new QTimer(this);
    //qDebug()<<QStyleFactory::keys();
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    check->start(1000/3);
    connect(check,SIGNAL(timeout()),
            this,SLOT(done()));
    QTimer *check2 = new QTimer(this);
#ifdef QT_NO_DEBUG
    check2->start(3000/3);
    setWindowIcon(QIcon(":/icons/yousaki.jpg"));
#else
    check2->start(1000/3);
    setWindowIcon(QIcon(":/icons/1.png"));
#endif
    connect(check2,SIGNAL(timeout()),
            this,SLOT(changeicon()));
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
    QPushButton *fullscreen = new QPushButton("全屏");
    connect(fullscreen ,SIGNAL(clicked()),
            this,SLOT(setFullscreen()));
    QVBoxLayout *buttons = new QVBoxLayout(left);
    buttons->addWidget(web);
    buttons->addWidget(terminal);
    buttons->addWidget(app);
    buttons->addWidget(fullscreen);
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
    //QApplication::setStyle(QStyleFactory::create("Windows"));
}
void MainWindow::newapp(){


    QString output;
    output=shell("xwininfo");
    output=output.simplified();
    int i=output.indexOf("Window id: ")+11;
    int a=output.indexOf("\" Absolute")-20;
    int b=output.indexOf("Width: ");
    int c=output.indexOf(" Height: ");
    int d=output.indexOf(" Depth: ");
    QString winid = output.mid(i,9);
   
    QString winname=output.mid(i+11,a-i+9);
    QString w=output.mid(b+7,c-b-7);
    QString h=output.mid(c+9,d-c-9);
    QString number=QString("%1").arg((int)MainWindow::winId());
    QString input = "{\"winid\":\""+winid+"\","+
                    "\"winname\":\""+winname+"\","+
                    "\"w\":\""+w+"\","+
                    "\"h\":\""+h+"\","+
                    "\"mainwindow\":"+number+
                    +"}";
    //QJsonDocument jsonDocument = QJsonDocument::fromJson(test.toLocal8Bit());
    //QJsonObject rootObj = jsonDocument.object();
    //qDebug()<<rootObj.value("winid").toString();
    //qDebug()<<rootObj.value("winname").toString();
    //qDebug()<<rootObj.value("w").toString();
    //qDebug()<<rootObj.value("h").toString();
    //qDebug()<<rootObj.value("mainwindow").toInt();
    
   
    //qDebug()<<winid.toInt(NULL,16)<<" "<<MainWindow::winId();
    if(winid.toInt(NULL,16)==(int)MainWindow::winId())
    {
        //qDebug()<<"ss";
        return;
    }
    SplitWeb* temp = new SplitWeb(this,new app(nullptr,input));
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
void MainWindow::setFullscreen(){
    if(status){
        showNormal();
        status=!status;
    } else {
        showFullScreen();
        status=!status;
    }
}
void MainWindow::changeicon(){
#ifdef QT_NO_DEBUG
    if(icon==1){
        setWindowIcon(QIcon(":/icons/yousaki2.jpeg"));
        icon=2;
    }else if(icon==2){
        setWindowIcon(QIcon(":/icons/yousaki3.jpeg"));
        icon=3;
    }else if(icon==3){
        setWindowIcon(QIcon(":/icons/firewalldrogron.jpeg"));
        icon=4;
    }else if (icon==4) {
        setWindowIcon(QIcon(":/icons/youxie.jpeg"));
        icon=5;
    }else{
        setWindowIcon(QIcon(":/icons/liuxingdrogon.jpeg"));
        icon=1;
    }
    //icon = !icon;
#else
    QString number=QString("%1").arg(icon);
    QString frame = ":/icons/"+number+".png";
    setWindowIcon(QIcon(frame));
    if(icon<35)
        icon+=1;
    else
        icon=1;
#endif
}
