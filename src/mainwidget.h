#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

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

private:
    Ui::MainWidget *ui;


};

#endif // MAINWIDGET_H
