#ifndef SPLIT_WEB 
#define SPLIT_WEB

#include <QHBoxLayout>
#include <QSplitter>
#include "qobjectdefs.h"
#include "qsplitter.h"
#include "webview.h"
#include "widgets/items.h"
class SplitWeb : public QSplitter 
{
    Q_OBJECT
public:
    SplitWeb(QWidget *parent = nullptr, Item *item=new an_webview());
    virtual ~SplitWeb();
    void add();
signals:
    void check();
    void check_v();
private:
    //an_webview *a;
    //QSplitter *pRight;
    //QTermWidget *console;
    QSplitter *inner;
    Item *item;
    int index;
    int index_v;

private slots:
    //if is not say the url, it is baidu.
    void splitt(QString Url);
    void splitt_v(QString Url);
    void check_to_close();
    void check_to_close_v();
};
#endif // SPLIT_WEB
