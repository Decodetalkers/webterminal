#ifndef MY_WEBENGINE_H
#define MY_WEBENGINE_H
#include "qobjectdefs.h"
#include "qwebengineview.h"
#include "qwidget.h"
#include <QWebEngineView>

class my_webengine : public QWebEngineView {
    Q_OBJECT
public:
    explicit my_webengine(QWidget *parent = nullptr);
protected:    
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;
private slots:
    void slot_LinkHovered(const QString& url);
private:
    QUrl url_;
};
#endif
