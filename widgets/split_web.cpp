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
    QSplitter(Qt::Horizontal ,parent)
    //pRight(new QSplitter(Qt::Horizontal,this))
{
    //QHBoxLayout *center = new QHBoxLayout(scene);
    this->item=item;
    addWidget(this->item);
    //connect the split button to give_url
    //connect(a->outside ,SIGNAL(clicked()),
    //        a,SLOT(give_url()));
    //because give_url call the get_the_url,so connect get_the_url to split.
    connect(item,SIGNAL(get_the_url(QString)),
            this,SLOT(splitt()));

}
SplitWeb::~SplitWeb(){
    delete this;
}
void SplitWeb::splitt(){
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
    QObject *obj = metaObj->newInstance(Q_ARG(QWidget*, nullptr),Q_ARG(QString, this->item->local_url()));
    /*
     * get the construct
     */
    Item *input2 = qobject_cast<Item*>(obj);
    //qDebug()<<input2->name();
    SplitWeb *temp = new SplitWeb(this,input2);
    insertWidget(0, temp);
    //connect(temp->a->outside ,SIGNAL(clicked()),
    //        temp->a,SLOT(give_url()));
    //connect(temp->a,SIGNAL(get_the_url(QString)),
    //        temp,SLOT(splitt(QString)));
}
