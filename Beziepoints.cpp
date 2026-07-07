 #include "BeziePoints.h"

QPointF BeziePoints(QPointF& P0,QPointF& P1,QPointF& P2, double t){

    double x = (1-t)*(1-t)*P0.x() + 2*(1-t)*t*P1.x() + t*t*P2.x();
    double y= (1-t)*(1-t)*P0.y() + 2*(1-t)*t*P1.y() + t*t*P2.y();

    return QPointF(x, y);
}