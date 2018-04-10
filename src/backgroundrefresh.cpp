/**
 * Background refresh thread - Source file
 *
 * @author Pierre HUBERT
 */

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDataStream>

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
    qInfo("Download finished !");

    emit log_message(data);
}

void BackgroundRefresh::httpReadyRead()
{
    data.append(reply->readAll());
    qInfo("Received data!");
}

void BackgroundRefresh::refresh()
{
    //Debug URL : http://devweb.local/playground/fronius_prod_files/v3/file
    qInfo("Refresh prod values");

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
