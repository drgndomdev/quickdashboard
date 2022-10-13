#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWebEngineView>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView *view = new QWebEngineView(parent);
    view->setUrl(QUrl("qrc:/templates/stocks.html"));
//    view->load(QUrl("https://www.google.com"));
//    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

