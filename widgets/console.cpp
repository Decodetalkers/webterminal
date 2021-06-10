#include "console.h"
#include "qboxlayout.h"
#include "qlineedit.h"
#include "widgets/items.h"
#include <QApplication>
int console::typeId = qRegisterMetaType<console*>();
console::console(QWidget *parent,QString Url):  Item(parent),
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
    top=new QHBoxLayout();
    center = new QTermWidget();
    QFont font = QApplication::font();
    font.setFamily("Monospace");
    font.setPointSize(12);

    center->setTerminalFont(font);
    center->setScrollBarPosition(QTermWidget::ScrollBarRight);
    center->setColorScheme("BreezeModified");
    top->addWidget(url);
    top->addWidget(enter);
    top->addWidget(exit);
    top->addWidget(outside);
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
}
void console::close(){
    delete this;
}
QString console::local_url(){
    return center->workingDirectory();
}
void console::give_url(){
    emit get_the_url(url->text());
    //connect to the solt
}
void console::change_the_location(){
    url->setText(center->workingDirectory());
    url->setCursorPosition(0);
}
void console::change_the_title(){
    url->setText(center->workingDirectory());
    url->setCursorPosition(0);
}

QString console::name() const{
    return "console*";
}

