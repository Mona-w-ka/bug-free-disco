#include <QApplication>
#include "qcustomplot.h"
#include "ParabolPoints.h"
#include "BeziePoints.h"
#include "Circle.h"

void setupPlot(QCustomPlot *plot){

    QVector<QPointF> controlPoints = {{1, 1}, {2, 3}, {4, 3}};

    plot->setMinimumSize(500, 500);
    QCPCurve *bezieCurve  = new QCPCurve(plot->xAxis, plot->yAxis);

    /// \param cnt количество точек на для построения кривой
    const int cnt = 100;

    QVector<QCPCurveData> curveDataBezie(cnt);

    for (int i = 0; i<cnt; i++){ //вычисление и запись 100 точек для построения кривой Безье
        double t = (double)i/(cnt-1);
        /// \param tochka точка на кривой
        QPointF tochka = BeziePoints(controlPoints[0], controlPoints[1], controlPoints[2], t);
        curveDataBezie[i] = QCPCurveData(t, tochka.x(), tochka.y());
    }

    QCPGraph *polygon = plot->addGraph(); //создание управляющего полигона для кривой Безье
    polygon->setPen(QPen(Qt::red, 2, Qt::DashLine));
    polygon->setScatterStyle(QCPScatterStyle::ssCircle);
    //====контрольные точки
    polygon->addData(1, 1);
    polygon->addData(2, 3);
    polygon->addData(4, 3);

    polygon->setName("Управляющий полигон");
    bezieCurve->setName("Квадратичная Кривая");
    bezieCurve->data()->set(curveData, true);
    bezieCurve->setPen(QPen(Qt::black, 2));

    plot->legend->setVisible(true);//визуализация легенды


    QCPCurve *parabol  = new QCPCurve(plot->xAxis, plot->yAxis);
    QVector<QCPCurveData> curveDataParabol(cnt);

    const double a = 10.0;
    for (int i = 0; i < cnt; i++){ //вычисление и запись 100 точек для построения параболы
        double t = (double)i/(cnt-1)*2-1;

        QPointF tochka = parabolPoints(a, t);
        curveDataParabol[i] = QCPCurveData(t, tochka.x(), tochka.y());
    }

    parabol->data()->set(curveDataParabol, true);
    parabol->setPen(QPen(Qt::darkMagenta, 2));
    parabol->setName("Парабола");

    QCPCurve *circle  = new QCPCurve(plot->xAxis, plot->yAxis);
    QVector<QCPCurveData> curveDataCircle(cnt);

    double r = 2.0;
    for (int i = 0; i < cnt; i++){ //вычисление и запись 100 точек для построения
        double t = (double)i/(cnt-1)*2*M_PI;
        QPointF tochka = CirclePoints(r, t);
        curveDataCircle[i] = QCPCurveData(t, tochka.x(), tochka.y());
    }
    circle->data()->set(curveDataCircle, true);
    circle->setPen(QPen(Qt::green, 2));


    plot->replot();
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); //вкл интерактивный режим(мышкой двигать)
}