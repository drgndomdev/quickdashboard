#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QWebEngineView>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Example");
    QApplication a(argc, argv);
    MainWindow w;
    QWebEngineView* view = w.findChild<QWebEngineView*>("webEngineView");
    QWebEngineView* view2 = w.findChild<QWebEngineView*>("stock_display_2");
    view->load(QUrl("qrc:/templates/stocks.html"));
//    view2->load(QUrl("qrc:/templates/MSFT_candlestick.html"));
//    w.resize(800, 600);
    w.show();
    return a.exec();
}
