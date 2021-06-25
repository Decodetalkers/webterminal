#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <QObject>
using namespace std;
namespace output {
    QString shell(QString shell);
    void Message(QString Title="hello world", QString Message="This is an example",QString Type="dialog-information");
}
#endif // FUNCTION_H
