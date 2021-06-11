/*
 * This is a part of webview 
 */
#ifndef WEBVIEW_H
#define WEBVIEW_H

#include "qboxlayout.h"
#include "qlineedit.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qwebengineview.h"
#include "qwidget.h"
#include "my_webengine.h"
#include "items.h"
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSplitter>
class an_webview : public Item{
    Q_OBJECT
public:
    Q_INVOKABLE explicit an_webview(QWidget *parent = nullptr,QString Url="https://www.google.com");
    static int typeId;
    ~an_webview();

    QString name() const;
signals:
    QString get_the_url(QString);
    void check();
public slots:
    void give_url();


private:
    QPushButton *outside;
    QVBoxLayout *web;
    QPushButton *enter;
    QPushButton *exit;
    QHBoxLayout *top;
    my_webengine *center;

    QLineEdit *url;

private slots:
    void connect_to_internet();
    void close();
    void newurl(QUrl URL);


};

#endif
