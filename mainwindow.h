#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QSplitter>
#include <qtermwidget5/qtermwidget.h>
#include "qobjectdefs.h"
#include "widgets/webview.h"
#include "widgets/split_web.h"
#include "widgets/console.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSplitter *pRight;
private slots:
    void newweb();
    void newterminal();

};
#endif // MAINWINDOW_H
