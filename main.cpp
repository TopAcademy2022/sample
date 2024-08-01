#include "main-widget.h"

#include <QApplication>
#include "ui.h"
#include <QPixmap>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget mainWindow;
    mainWindow.show();

    UI ui = UI(&mainWindow);

    return a.exec();
}
