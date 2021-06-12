#include "console.h"
#include "qcoreevent.h"
#include "qevent.h"
#include "qnamespace.h"
#include <QApplication>
#include <QDebug>
int console::typeId = qRegisterMetaType<console*>();
console::console(QWidget *parent,QString Url):  
    Item(parent),
    web(new QVBoxLayout(this)),
    status(true)
    //isfull(false)
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
    center = new QTermWidget();
    QFont font = QApplication::font();
    font.setFamily("Monospace");
    font.setPointSize(12);

    center->setTerminalFont(font);
    center->setScrollBarPosition(QTermWidget::ScrollBarRight);
    center->setColorScheme("BreezeModified");
    center->changeDir(url->text());
    center->sendText("export TERM=xterm\n");
    top->addWidget(url);
    top->addWidget(enter);
    top->addWidget(exit);
    top->addWidget(outside);
    top->addWidget(outside_v);
    web->addLayout(top);
    web->addWidget(center);
    connect(this->enter,SIGNAL(clicked()),
            this,SLOT(change_the_location()));
    connect(this->exit,SIGNAL(clicked()),
            this,SLOT(close()));
    connect(this->center,SIGNAL(titleChanged()),
            this,SLOT(change_the_title()));
    connect(this->outside,SIGNAL(clicked()),
            this,SLOT(give_url()));
    connect(this->outside_v,SIGNAL(clicked()),
            this,SLOT(give_url_v()));
    connect(this->center,SIGNAL(finished()),
            this,SLOT(close()));
    connect(this->center,SIGNAL(termKeyPressed(QKeyEvent *)),
            this,SLOT(hide_title(QKeyEvent *)));
    // It is the solt of qtermwidget, you can get it through the header.
    //When the terminal break, delete the class
}
void console::close(){
    delete this;

}
//QString console::local_url(){
//    return center->workingDirectory();
//}
void console::give_url(){
    emit get_the_url(url->text());
    //connect to the solt
}
void console::give_url_v(){
    emit get_the_url_v(url->text());
    //connect to the solt
}
void console::change_the_location(){
    center->changeDir(url->text());
}
void console::change_the_title(){
    url->setText(center->workingDirectory());
    url->setCursorPosition(0);
}

QString console::name() const{
    return "console*";
}
console::~console(){
    //qDebug()<<"close";
    emit check();
}

void console::hide_title(QKeyEvent *key){
    switch(key->key()){
        case Qt::Key_F2:
            if(status){
                url->hide();
                enter->hide();
                exit->hide();
                outside->hide();
                outside_v->hide();
                status=!status;
            } else {
                url->show();
                enter->show();
                outside->show();
                outside_v->show();
                exit->show();
                status=!status;
            }
            break;
        //case Qt::Key_F11:
        //    if(!isfull){
        //        setWindowFlag(Qt::Window);
        //        showFullScreen();
        //        isfull=!isfull;
        //    }else{
        //        setWindowFlag(Qt::CoverWindow);
        //        showNormal();
        //        //setWindowFlag(Qt::SubWindow);
        //        isfull=!isfull;
        //    }
        //    break;
        default:
            break;
    };

}
