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

private:
    //an_webview *a;
    //QSplitter *pRight;
    //QTermWidget *console;
    Item *item;

private slots:
    //if is not say the url, it is baidu.
    void splitt();
};
#endif // SPLIT_WEB
