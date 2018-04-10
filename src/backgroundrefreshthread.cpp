/**
 * Background refresh thread - Source file
 *
 * @author Pierre HUBERT
 */

#include "backgroundrefreshthread.h"
#include "config.h"


BackgroundRefreshThread::BackgroundRefreshThread() : QThread()
{

}

void BackgroundRefreshThread::run()
{
    while(true){
        refresh();
        sleep(REFRESH_INTERVAL);
    }
}

void BackgroundRefreshThread::refresh()
{
    //Debug URL : http://devweb.local/playground/fronius_prod_files/v3/file
    qDebug("Refresh prod values");
}
