#include "ParabolPoints.h"

QPointF parabolPoints(double a, double t){

    double x = t;
    double y = a*t*t;

    return QPointF(x, y);

}