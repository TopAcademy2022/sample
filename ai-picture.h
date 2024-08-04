#ifndef AIPICTURE_H
#define AIPICTURE_H

#include <QObject>
#include <QDialog>

class AIPicture : public QObject
{
    Q_OBJECT
public:
    explicit AIPicture(QWidget* mainWindow, QObject *parent = nullptr);

    QWidget* _mainWindow;

public slots:
    void ShowWindow();
};

#endif // AIPICTURE_H
