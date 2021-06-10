#include "my_webengine.h"
my_webengine::my_webengine(QWidget *parent):
    QWebEngineView(parent)
{
}
QWebEngineView *my_webengine::createWindow(__attribute__((unused)) QWebEnginePage::WebWindowType type){
    this->load(url_);
    return this;
}
void my_webengine::slot_LinkHovered(const QString& url){
    url_.setUrl(url);
}
