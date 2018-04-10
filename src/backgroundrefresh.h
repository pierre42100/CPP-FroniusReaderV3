/**
 * Background refresh thread - Header file
 *
 * @author Pierre HUBERT
 */

#ifndef BACKGROUNDREFRESHTHREAD_H
#define BACKGROUNDREFRESHTHREAD_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class BackgroundRefresh : public QObject
{
    Q_OBJECT

public:
    BackgroundRefresh();

    /**
     * Fetch the new values from the server
     */
    void refresh();


signals:
    /**
     * This signal is emitted when a new solar production value
     * is available
     *
     * @param value The new value
     */
    void new_solar_prod(int value);

    /**
     * This signal is emitted when a new EDF production value
     * is available
     *
     * @param value The new value
     */
    void new_edf_prod(int value);

    /**
     * Log a new message
     * @param message The message to log
     */
    void log_message(QString message);


private slots:

    void error(QNetworkReply::NetworkError *);
    void httpFinished();
    void httpReadyRead();


private:

    //Network access manager
    QNetworkAccessManager qnam;

    //Network reply
    QNetworkReply *reply;

    QByteArray data;
};

#endif // BACKGROUNDREFRESHTHREAD_H
