#ifndef AIPICTURE_H
#define AIPICTURE_H

#include <QObject>
#include <QDialog>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include "dialog-ai.h"

class AIPicture : public QObject
{
    Q_OBJECT
private:
    QWidget* _mainWindow;

    QNetworkAccessManager* _networkManager;

    DialogAI* _dialogAI;

    void GetGeneratedPictureUrl(QString textForGeneration);

    void ClosedWindow(char* text);
public:
    explicit AIPicture(QWidget* mainWindow, QObject *parent = nullptr);

public slots:
    void ShowWindow();
};

#endif // AIPICTURE_H
