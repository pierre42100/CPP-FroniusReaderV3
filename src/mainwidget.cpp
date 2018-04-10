#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{

    //Setup UI
    ui->setupUi(this);

    //Create brackground refresh
    m_refresh = new BackgroundRefresh;

    //Make connections
    QObject::connect(m_refresh, &BackgroundRefresh::new_solar_prod, this, &MainWidget::setSolarProd);
    QObject::connect(m_refresh, &BackgroundRefresh::new_edf_prod, this, &MainWidget::setEDFprod);
    QObject::connect(m_refresh, &BackgroundRefresh::log_message, this, &MainWidget::logMessage);

    //Launch refresh
    m_refresh->refresh();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::setSolarProd(int prod)
{
    ui->solar_value->setText(QString::number(prod));
}

void MainWidget::setEDFprod(int prod)
{
    ui->edf_value->setText(QString::number(prod));
}

void MainWidget::logMessage(const QString &message)
{
    ui->status->setText(message);
}
