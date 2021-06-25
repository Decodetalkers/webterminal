#include <libnotify/notify.h>
#include "function.h"
void output::Message(QString Title,QString Message,QString Type)
{
	notify_init ("Hello World");
    char* title;
    char* message;
    char* type;
    title=Title.toLatin1().data();
    message=Message.toLatin1().data();
    type=Type.toLatin1().data();
	NotifyNotification * Hello = notify_notification_new (title, message, type);
	notify_notification_show (Hello, NULL);
	g_object_unref(G_OBJECT(Hello));
	notify_uninit();
}
