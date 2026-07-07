#include "Circle.h"
#include "cmath"

QPointF CirclePoints(double r, double t){

    double x = r*std::cos(t);
    double y = r*std::sin(t);


    return QPointF(x, y);


}