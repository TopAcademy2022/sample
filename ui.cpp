#include "ui.h"

UI::UI(QWidget* widget)
{
    this->_mainWindow = widget;

    this->_openFile = new QPushButton("Open file", this->_mainWindow);
    this->_openFile->move(850, 650);
    this->_openFile->show();

    connect(this->_openFile, SIGNAL(clicked()), this, SLOT(OpenFileClick()));

    this->_dialogWindow = new QFileDialog(this->_mainWindow);
    connect(this, &UI::ImageSelected, this, &UI::FileOpened);

    this->_image = new QLabel(this->_mainWindow);
    this->_image->setBackgroundRole(QPalette::Base);
    this->_image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    this->_imageSource = new QPixmap(QSize(800, 600));
    this->_imageSource->fill();

    this->_image->setPixmap(*this->_imageSource);
    this->_image->show();

    this->_imagePath = new QString();
}

void UI::OpenFileClick()
{
    this->_dialogWindow->setNameFilter("Images (*.png *.jpg)");
    *this->_imagePath = this->_dialogWindow->getOpenFileName();
    emit this->ImageSelected();
}

void UI::FileOpened()
{
    QImageReader* reader = new QImageReader(*this->_imagePath);
    *this->_imageSource = QPixmap::fromImage(reader->read());

    this->_image->setPixmap(*this->_imageSource);
    this->_image->resize(this->_image->pixmap().size());
}
