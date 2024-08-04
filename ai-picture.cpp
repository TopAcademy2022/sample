#include "ai-picture.h"

AIPicture::AIPicture(QWidget* mainWindow, QObject *parent)
    : QObject{parent}
{
    this->_mainWindow = mainWindow;
}

void AIPicture::ShowWindow()
{
    QDialog* _dialog = new QDialog(this->_mainWindow);
    _dialog->show();
}
