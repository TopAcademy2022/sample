#include "ai-picture.h"

void AIPicture::GetGeneratedPictureUrl(QString textForGeneration)
{
    QNetworkRequest reqToAPIGenerator = QNetworkRequest(QUrl("https://api.limewire.com/api/image/generation"));
    reqToAPIGenerator.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    reqToAPIGenerator.setRawHeader("X-Api-Version", "1.0");
    reqToAPIGenerator.setRawHeader("Accept", "application/json");
    reqToAPIGenerator.setRawHeader("Authorization", "Bearer lmwr_sk_EtNWniOCno_jTCnRQabz4cCPaWQ7MmngaaRuUEma35pZjPJu");

    QJsonObject requestText = QJsonObject();
    requestText.insert("prompt", textForGeneration);
    requestText.insert("aspect_ratio", "1:1");

    QJsonDocument jsonDoc = QJsonDocument(requestText);

    this->_networkManager->post(reqToAPIGenerator, jsonDoc.toJson());
}

AIPicture::AIPicture(QWidget* mainWindow, QObject *parent)
    : QObject{parent}
{
    this->_mainWindow = mainWindow;
    this->_networkManager = new QNetworkAccessManager(this);

    QObject::connect(this->_networkManager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply)
        {
            if (reply->error())
            {
                qDebug() << reply->errorString();
                qDebug() << reply->readAll();
                return;
            }

            QJsonObject resultJson = QJsonDocument::fromJson(reply->readAll()).object();
            qDebug() << resultJson["asset_url"].toString();
        }
    );
}

void AIPicture::ShowWindow()
{
    QDialog* _dialog = new QDialog(this->_mainWindow);
    _dialog->show();

    this->GetGeneratedPictureUrl("One student in teacher class");
}
