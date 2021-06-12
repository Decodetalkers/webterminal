#ifndef NEW_APP_H
#define NEW_APP_H
#include "items.h"
#include "qobjectdefs.h"
#include <QWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>

class app : public Item{
    Q_OBJECT
public:
    Q_INVOKABLE app(QWidget *parent = nullptr,QString Url="0x1234");
    static int typeId;
    QString name() const;
    ~app();
signals:
    QString get_the_url(QString);
    QString get_the_url_v(QString);
    void check();
public slots:
    void give_url();
    void give_url_v();
private:
    QPushButton *outside;
    QPushButton *outside_v;
    QVBoxLayout *web;
    QPushButton *exit;
    QHBoxLayout *top;
    QWidget *center;
    QWindow *win;
    QLineEdit *url;
    QPoint wpos;
private slots:
    void close();
    void change_title(QString title);
};

#endif // NEW_APP_H
