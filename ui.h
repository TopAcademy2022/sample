#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QImageReader>
#include <QObject>

// For UI init
class UI : public QObject
{
    Q_OBJECT
private:
    QWidget* _mainWindow;

    QPushButton* _openFile;

    QFileDialog* _dialogWindow;

    QLabel* _image;

    QPixmap* _imageSource;

    QString* _imagePath;

public:
    UI(QWidget* widget);

private slots:
    void OpenFileClick();

    void FileOpened();

signals:
    void ImageSelected();
};

#endif // UI_H
