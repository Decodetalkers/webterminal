#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QSplitter>
#include <qtermwidget5/qtermwidget.h>
#include "qevent.h"
#include "qobjectdefs.h"
#include "widgets/webview.h"
#include "widgets/split_web.h"
#include "widgets/console.h"
#include "widgets/new_app.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void finished();
private:
    QSplitter *pRight;
    SplitWeb *Console;
    bool status;
private slots:
    void newweb();
    void newterminal();
    void newapp();
    void setFullscreen();
    void closeEvent(QCloseEvent *event);
    void done();

};
#endif // MAINWINDOW_H
