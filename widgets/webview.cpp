#include "webview.h"
#include "qboxlayout.h"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qwebengineview.h"
#include "qwidget.h"
int an_webview::typeId = qRegisterMetaType<an_webview*>();
an_webview::an_webview(QWidget *parent,QString Url):
    Item(parent),
    web(new QVBoxLayout(this))
{
    url=new QLineEdit();
    url->setText(Url);
    url->setCursorPosition(0);
    enter = new QPushButton();
    enter->setText("进入");
    exit = new QPushButton();
    exit->setText("关闭");
    outside = new QPushButton();
    outside->setText("分屏");
    outside_v = new QPushButton();
    outside_v->setText("分屏V");
    top=new QHBoxLayout();
    center = new my_webengine();
    center->setUrl(QUrl(Url));
    top->addWidget(url);
    top->addWidget(enter);
    top->addWidget(exit);
    top->addWidget(outside);
    top->addWidget(outside_v);
    web->addLayout(top);
    web->addWidget(center);
    connect(this->enter,SIGNAL(clicked()),
            this,SLOT(connect_to_internet()));
    connect(this->exit,SIGNAL(clicked()),
            this,SLOT(close()));
    connect(this->center,SIGNAL(urlChanged(QUrl)),
            this,SLOT(newurl(QUrl)));
    connect(this->outside,SIGNAL(clicked()),
            this,SLOT(give_url()));
    connect(this->outside_v,SIGNAL(clicked()),
            this,SLOT(give_url_v()));
}

void an_webview::connect_to_internet(){
    center->load(QUrl(url->text()));
}
void an_webview::close(){
    delete this;

}
/*
 * Make the solt
 */
void an_webview::give_url(){
    emit get_the_url(url->text());
    //connect to the solt
}
void an_webview::give_url_v(){
    emit get_the_url_v(url->text());
    //connect to the solt
}
//QString an_webview::local_url(){
//    return url->text();
//}
//When the url is changed, the text also change
void an_webview::newurl(QUrl URL){
    //qDebug()<<"test";
    center->load(URL);
    url->setText(URL.toString());
    url->setCursorPosition(0);
    //everytime the url is changed, the cursor come to the front.
}
QString an_webview::name() const{
    return "an_webview*";
}
an_webview::~an_webview(){
    //qDebug()<<"it is delete";
    emit check();
}
