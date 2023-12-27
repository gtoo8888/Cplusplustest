#include "mywidget.h"
#include <QApplication>//包含一个应用程序类的头文件

// main程序入口argc命令行变量的数量argv命令行变量的数组
int main(int argc, char *argv[])
{
    //a应用程序对象，在Qt中，应用程序对象有且仅有一个
    QApplication a(argc, argv);
    //窗口对象mywidget父类-> owidget
    myWidget w;
    //窗口对象默认不会显示，必须要调用show方法显示窗口
    w.show();

    //让应用程序对象进入消息循环
    return a.exec();

    while(true);
}
