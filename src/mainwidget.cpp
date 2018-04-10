#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{

    //Setup UI
    ui->setupUi(this);

    //Create worker thread
    m_refresh_thread = new BackgroundRefreshThread;
    m_refresh_thread->start();
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
