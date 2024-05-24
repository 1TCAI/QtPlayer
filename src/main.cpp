#include "mainwid.h"
#include <QApplication>
#include <QFontDatabase>
#include <QDebug>

#undef main //由于 SDL 库中的 SDL_main.h 文件中定义了一个名为 main 的宏，这与你的程序中的 main 函数产生了冲突。
int main(int argc, char *argv[])
{
//    qDebug() << "123";
    QApplication a(argc, argv);
    
    //使用第三方字库，用来作为UI图片 ://res/fa-solid-900.ttf
    QFontDatabase::addApplicationFont("://res/fontawesome-webfont.ttf");
    //QFontDatabase::addApplicationFont("://res/fa-solid-900.ttf");

    MainWid w;
    if (w.Init() == false)
    {
        return -1;
    }
    w.show();

    return a.exec();
}
