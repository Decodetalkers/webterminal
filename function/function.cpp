#include "function.h"
QString output::shell(QString shell){
    FILE * fp;
    int res;
    QString  pword;
    char resultStr[100] = {"0"}; //define MAX_USB_NUM 3
    char* ch; QByteArray ba = shell.toLatin1(); ch=ba.data();
    //执行预先设定的命令，并读出该命令的标准输出
     fp = popen(ch, "r");
     if(!fp)
     {
        perror("popen fail");
        printf("popen error: %s/n", strerror(errno));
        return "";
     }

       /* 循环读管道 #define MAX_USB_NUM 3  */
       while(fgets(resultStr, 3, fp) ){pword+=QString(QLatin1String(resultStr));}
       /*等待命令执行完毕并关闭管道及文件指针*/
       res = pclose(fp);
       if ( res == -1 || pword=="")
       {
           //printf("close popen file pointer fp error!\n");
           return "";
       }
       else
       {
           //printf("popen res is :%d\n", res);
           return pword;

       }

}
