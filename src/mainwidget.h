#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "backgroundrefresh.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:

    /**
     * Set solar production
     * @param prod The production value
     */
    void setSolarProd(int prod);

    /**
     * Update EDF production
     * @param prod The production value
     */
    void setEDFprod(int prod);

    /**
     * Log a message
     * @param message The message to log
     */
    void logMessage(const QString &message);

    /**
     * When the download is finished
     */
    void downloadFinished();

private:

    //The UI
    Ui::MainWidget *ui;

    //Refresh thread
    BackgroundRefresh *m_refresh;
};

#endif // MAINWIDGET_H
