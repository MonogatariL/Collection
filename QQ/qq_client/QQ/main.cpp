#include "qq_main_menu.h"
#include "qq_list.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qq_main_menu w;
    w.show();
    return a.exec();
}
