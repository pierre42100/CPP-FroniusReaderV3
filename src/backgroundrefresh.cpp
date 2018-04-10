/**
 * Background refresh thread - Source file
 *
 * @author Pierre HUBERT
 */

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>

#include "backgroundrefresh.h"
#include "config.h"


BackgroundRefresh::BackgroundRefresh() : QObject()
{

}

void BackgroundRefresh::error(QNetworkReply::NetworkError *)
{
    reply->deleteLater();
    reply = NULL;
    refresh();
}

void BackgroundRefresh::httpFinished()
{
    emit log_message("Download finished !");

    //Read data
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object()["Body"].toObject()["Data"].toObject()["Site"].toObject();

    emit new_solar_prod(obj["P_PV"].toInt());
    emit new_edf_prod(obj["P_Grid"].toDouble());


    if(reply->error() != QNetworkReply::NoError){
        log_message(reply->errorString());
        emit new_solar_prod(-1);
        emit new_edf_prod(-1);
    }

    reply->deleteLater();

    emit download_finished();
}

void BackgroundRefresh::httpReadyRead()
{
    data.append(reply->readAll());
    emit log_message("Received data!");
}

void BackgroundRefresh::refresh()
{
    //Debug URL : http://devweb.local/playground/fronius_prod_files/v3/file
    emit log_message("Send request to server");

    QUrl newURL = QUrl::fromUserInput("http://devweb.local/playground/fronius_prod_files/v3/file");

    if(!newURL.isValid()){
        qFatal("Invalid URL!");
        return;
    }

    data = QByteArray();

    //Create the request and get the reply
    reply = qnam.get(QNetworkRequest(newURL));
    QObject::connect(reply, &QNetworkReply::finished, this, &BackgroundRefresh::httpFinished);
    QObject::connect(reply, &QNetworkReply::readyRead, this, &BackgroundRefresh::httpReadyRead);
    //QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));

}
