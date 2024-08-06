#ifndef AIPICTURE_H
#define AIPICTURE_H

#include <QObject>
#include <QDialog>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>

class AIPicture : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager* _networkManager;

    void GetGeneratedPictureUrl(QString textForGeneration);

public:
    explicit AIPicture(QWidget* mainWindow, QObject *parent = nullptr);

    QWidget* _mainWindow;

public slots:
    void ShowWindow();
};

#endif // AIPICTURE_H
