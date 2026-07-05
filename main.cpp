#include <QApplication>
#include "qcustomplot.h"

QPointF points(QPointF& P0,QPointF& P1,QPointF& P2, double t){

    double x = (1-t)*(1-t)*P0.x() + 2*(1-t)*t*P1.x() + t*t*P2.x();
    double y= (1-t)*(1-t)*P0.y() + 2*(1-t)*t*P1.y() + t*t*P2.y();

    return QPointF(x, y);
}

QPointF parabolPoints(double o, double t){

    double x = t;
    double y = o*t*t;

    return QPointF(x, y);

}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QVector<QPointF> cpoints = {{1, 1}, {2, 3}, {4, 3}};


    QCustomPlot Bezie;
    Bezie.setMinimumSize(500, 500);
   // Bezie.addGraph();
    QCPCurve *bezie  = new QCPCurve(Bezie.xAxis, Bezie.yAxis);

    int cnt = 100;
    QVector<QCPCurveData> curveData(cnt);

    for (int i = 0; i<cnt; i++){
        double t = (double)i/(cnt-1);
        QPointF tochka = points(cpoints[0], cpoints[1], cpoints[2], t);
        curveData[i] = QCPCurveData(t, tochka.x(), tochka.y());


    }
    QCPGraph *polygon = Bezie.addGraph();
    polygon->setPen(QPen(Qt::red, 2, Qt::DashLine));
    polygon->setScatterStyle(QCPScatterStyle::ssCircle);
    polygon->addData(1, 1);
    polygon->addData(2, 3);
    polygon->addData(4, 3);
    polygon->setName("Управляющий полигон");
    bezie->data()->set(curveData, true);
    bezie->setPen(QPen(Qt::black, 2));

    Bezie.legend->setVisible(true);
    bezie->setName("Квадратичная Кривая");

    QCPCurve *parabol  = new QCPCurve(Bezie.xAxis, Bezie.yAxis);
    QVector<QCPCurveData> curveData2(cnt);

    double o = 10.0;
    for (int i = 0; i < cnt; i++){
        double t = (double)i/(cnt-1)*2-1;

        QPointF tochka = parabolPoints(o, t);
        curveData2[i] = QCPCurveData(t, tochka.x(), tochka.y());


    }
    parabol->data()->set(curveData2, true);
    parabol->setPen(QPen(Qt::darkMagenta, 2));
    parabol->setName("Парабола");
    Bezie.replot();
    Bezie.show();
    Bezie.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    return a.exec();
}