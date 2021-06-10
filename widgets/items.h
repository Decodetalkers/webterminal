#ifndef ITEM_H
#define ITEM_H

#include "qwidget.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <iostream>
class Item : public QWidget
{
    Q_OBJECT
public:
    Item(QWidget *parent = 0);
    virtual QString local_url()=0;
    virtual QString name() const =0;
signals:
    QString get_the_url(QString);
};
#endif // ITEM_H
