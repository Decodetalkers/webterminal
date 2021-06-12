#include "new_app.h"
#include "function/function.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <QWindow>
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QJsonObject>
#include <QJsonDocument>
using namespace output;
int app::typeId = qRegisterMetaType<app*>();
app::app(QWidget *parent,QString Url): 
    Item(parent),
    web(new QVBoxLayout(this))
{
    QString winid,winname;
    //int i=Url.indexOf("Window id: ")+11;
    //int a=Url.indexOf("\" Absolute")-20;
    //int b=Url.indexOf("Width: ");
    //int c=Url.indexOf(" Height: ");
    //int d=Url.indexOf(" Depth: ");
    QJsonDocument jsonDocument = QJsonDocument::fromJson(Url.toLocal8Bit());
    QJsonObject rootObj = jsonDocument.object();
    winid=rootObj.value("winid").toString();
    winname=rootObj.value("winname").toString();
    //qDebug()<<winid;
    win = QWindow::fromWinId(winid.toInt(NULL,16));
    center = QWidget::createWindowContainer(win,NULL,Qt::FramelessWindowHint);
    QString w=rootObj.value("w").toString();
    QString h=rootObj.value("h").toString();
    topwindow=rootObj.value("mainwindow").toInt();
    wpos = QPoint(w.toInt(),h.toInt());
    url = new QLineEdit();
    url->setText(winname);
    url->setDisabled(true);    
    exit = new QPushButton();
    exit->setText("关闭");
    outside = new QPushButton();
    outside->setText("分屏");
    outside_v = new QPushButton();
    outside_v->setText("分屏V");

    top=new QHBoxLayout(); 
    top->addWidget(url);
    top->addWidget(exit);
    top->addWidget(outside);
    top->addWidget(outside_v);
    web->addLayout(top);
    web->addWidget(center);
    connect(this->exit,SIGNAL(clicked()),
            this,SLOT(close()));
    connect(this->outside,SIGNAL(clicked()),
            this,SLOT(give_url()));
    connect(this->outside_v,SIGNAL(clicked()),
            this,SLOT(give_url_v()));

    connect(this->center,SIGNAL(windowTitleChanged(QString)),
            this,SLOT(change_title(QString)));
}
void app::change_title(QString title){
    url->setText(title);

}
app::~app(){
    QDesktopWidget *screenResolution = QApplication::desktop();
    int center_y = screenResolution->height()/2 - wpos.y()/2;
    int center_x = screenResolution->width()/2 - wpos.x()/2;
    QScreen *screen = qApp->primaryScreen();
    int dpiVal = screen->logicalDotsPerInch();
    //qDebug()<<dpiVal;
    float i;
    switch (dpiVal) {
        case 96:
            i=1;
            break;
        case 120:
            i=1.25;
            break;
        case 144:
            i=1.5;
            break;
        case 192:
            i=2;
            break;
        default:
            i=1;
            break;
    }
    win->setGeometry(center_y,center_x,wpos.x()/i,wpos.y()/i);
    win->setParent(NULL);
    center->setParent(NULL);
    win->show();

    emit check();
}
void app::give_url(){
    //QString output=shell("xwininfo");
    //output=output.simplified();
    //int i=output.indexOf("Window id: ")+11;
    //QString winid = output.mid(i,9);
    //qDebug()<<winid.toInt(NULL,16)<<" "<<MainWindow::winId();
    QString output=shell("xwininfo");
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
    QString number=QString("%1").arg(topwindow);
    QString input = "{\"winid\":\""+winid+"\","+
                    "\"winname\":\""+winname+"\","+
                    "\"w\":\""+w+"\","+
                    "\"h\":\""+h+"\","+
                    "\"mainwindow\":"+number+
                    +"}";

    if(winid.toInt(NULL,16)==topwindow)
    {
        //qDebug()<<"ss";
        return;
    }

    //qDebug()<<output;
    emit get_the_url(input);
}
void app::give_url_v(){
    QString output=shell("xwininfo");
    output=output.simplified();
    //qDebug()<<output;
    emit get_the_url_v(output);
}
QString app::name() const{
    return "app*";
}
void app::close() {
    delete this;
}
