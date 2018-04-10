/**
 * Background refresh thread - Header file
 *
 * @author Pierre HUBERT
 */

#ifndef BACKGROUNDREFRESHTHREAD_H
#define BACKGROUNDREFRESHTHREAD_H

#include <QObject>
#include <QThread>

class BackgroundRefreshThread : public QThread
{
    Q_OBJECT

public:
    BackgroundRefreshThread();

    void run() override;

private:

    /**
     * Fetch the new values from the server
     */
    void refresh();


};

#endif // BACKGROUNDREFRESHTHREAD_H
