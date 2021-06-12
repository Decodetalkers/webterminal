#include "widgets/split_web.h"
#include "qboxlayout.h"
#include "qdebug.h"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qsplitter.h"
#include "qwidget.h"
#include "qwindow.h"
#include "widgets/items.h"
#include <QLayout>
#include <QApplication>
#include <QWindow>
#include "items.h"
#include <QMetaType>
//#include <qtermwidget5/qtermwidget.h>
SplitWeb::SplitWeb(QWidget *parent,Item *item):
    QSplitter(Qt::Horizontal ,parent),
    index(1),
    index_v(1)
    //pRight(new QSplitter(Qt::Horizontal,this))
{
    //QHBoxLayout *center = new QHBoxLayout(scene);
    inner = new QSplitter(Qt::Vertical);
    this->item=item;
    inner->addWidget(item);
    addWidget(inner);
    //connect the split button to give_url
    //connect(a->outside ,SIGNAL(clicked()),
    //        a,SLOT(give_url()));
    //because give_url call the get_the_url,so connect get_the_url to split.
    connect(item,SIGNAL(get_the_url(QString)),
            this,SLOT(splitt(QString)));
    connect(item,SIGNAL(get_the_url_v(QString)),
            this,SLOT(splitt_v(QString)));

    connect(item,SIGNAL(check()),
            this,SLOT(check_to_close()));
    connect(item,SIGNAL(check()),
            this,SLOT(check_to_close_v()));
    //qDebug()<<index;

}
SplitWeb::~SplitWeb(){
    //inner->deleteLater();
    QWidget *w;
    while (this->count() > 0) {
        //qDebug()<<this->count();
        w = widget(0);
        w->setParent(nullptr);
        w->deleteLater();
    }
}
void SplitWeb::check_to_close(){
    index=index-1;
    //qDebug()<<"index = "<<index;
    //qDebug()<<"index_v = "<<index_v;
    if(index==0){
        //qDebug()<<"sfdsf";
        emit check();
        QWidget *w;
        //emit check();
        //if(inner->count()>0){
        //    w = inner->widget(0);
        //    w->setParent(nullptr);
        //    w->deleteLater();
        //}

        while (this->count() >0) {
            //qDebug()<<this->count();
            w = widget(0);
            w->setParent(nullptr);
            w->deleteLater();
        }
    }
    //widget(count()-1)->hide();

}
/*
 * here should not emit signals, or it will be minus
 */
void SplitWeb::check_to_close_v(){
    index_v=index_v-1;
    //qDebug()<<"index_v = "<<index_v;
    if(index_v==0){
        //qDebug()<<"ssss";
        //emit check();
        QWidget *w;
        //emit check();
        //if(inner->count()>0){
        //    w = inner->widget(0);
        //    w->setParent(nullptr);
        //    w->deleteLater();
        //}

        while (inner->count() >0) {
            //qDebug()<<this->count();
            w = inner->widget(0);
            w->setParent(nullptr);
            w->deleteLater();
        }
    }
    //widget(count()-1)->hide();

}
void SplitWeb::splitt(QString Url){
    //qDebug()<<url;
    //qDebug()<<this->item->local_url();
    //Item *input2;
    //if(this->item->name()=="an_webview")
    //{
    //   input2=new an_webview(nullptr,this->item->local_url());
    //}
    //else{
    //   input2=new an_webview(nullptr,this->item->local_url());
    //}
    /*
     * old function ,relay on if else
     */
    char* input;
    QByteArray ba = this->item->name().toLatin1();
    input=ba.data();
    /*
     * change to char*
     */
    int type = QMetaType::type(input);
    const QMetaObject *metaObj = QMetaType::metaObjectForType(type);
    QObject *obj = metaObj->newInstance(Q_ARG(QWidget*, nullptr),Q_ARG(QString, Url));
    /*
     * get the construct
     */
    Item *input2 = qobject_cast<Item*>(obj);
    SplitWeb *temp = new SplitWeb(this,input2);
    index = index+1;
    connect(temp,SIGNAL(check()),
            this,SLOT(check_to_close()));

    insertWidget(0, temp);
    //connect(temp->a->outside ,SIGNAL(clicked()),
    //        temp->a,SLOT(give_url()));
    //connect(temp->a,SIGNAL(get_the_url(QString)),
    //        temp,SLOT(splitt(QString)));
}
void SplitWeb::splitt_v(QString Url){
    //qDebug()<<url;
    //qDebug()<<this->item->local_url();
    //Item *input2;
    //if(this->item->name()=="an_webview")
    //{
    //   input2=new an_webview(nullptr,this->item->local_url());
    //}
    //else{
    //   input2=new an_webview(nullptr,this->item->local_url());
    //}
    /*
     * old function ,relay on if else
     */
    char* input;
    QByteArray ba = this->item->name().toLatin1();
    input=ba.data();
    /*
     * change to char*
     */
    int type = QMetaType::type(input);
    const QMetaObject *metaObj = QMetaType::metaObjectForType(type);
    QObject *obj = metaObj->newInstance(Q_ARG(QWidget*, nullptr),Q_ARG(QString, Url));
    /*
     * get the construct
     */
    Item *input2 = qobject_cast<Item*>(obj);
    index+=1;
    index_v+=1;
    qDebug()<<index;
    SplitWeb *temp = new SplitWeb(this,input2);
    connect(temp,SIGNAL(check()),
            this,SLOT(check_to_close()));
    connect(temp,SIGNAL(check()),
            this,SLOT(check_to_close_v()));
    inner->insertWidget(0, temp);
    //connect(temp->a->outside ,SIGNAL(clicked()),
    //        temp->a,SLOT(give_url()));
    //connect(temp->a,SIGNAL(get_the_url(QString)),
    //        temp,SLOT(splitt(QString)));
}

void SplitWeb::add(){
    index+=1;
}
