#ifndef CONSOLE_H
#define CONSOLE_H
#include "items.h"
#include "qevent.h"
#include "qobjectdefs.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDir>
#include "qwidget.h"
#include <qtermwidget5/qtermwidget.h>
class console : public Item{
    Q_OBJECT
public:
    Q_INVOKABLE console(QWidget *parent = nullptr,QString Url=QDir::currentPath());
    static int typeId;
    //QString local_url();
    QString name() const;
    ~console();
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
    QPushButton *enter;
    QPushButton *exit;
    QHBoxLayout *top;
    QTermWidget *center;

    QLineEdit *url;
    //bool eventFilter(QObject *object,QEvent *event);
    bool status;

private slots:
    void hide_title(QKeyEvent *key);
    void close();
    void change_the_location();
    void change_the_title();
};
#endif // CONSOLE_H
