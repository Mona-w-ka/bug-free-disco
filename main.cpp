#include <QApplication>
#include "qcustomplot.h"
#include "setup.h"
#include <QDebug>
int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    QCustomPlot plot;
    setupPlot(&plot);
    plot.show();
    qDebug() << "Версия QCustomPlot:" << QCUSTOMPLOT_VERSION_STR;
    return application.exec();
}