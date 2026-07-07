#ifndef PARABOLPOINTS_H
#define PARABOLPOINTS_H

#include <QPointF>
///
/// \brief parabolPoints Расчет точек для параболы
/// \param a  это параметр, который определяет форму и ориентацию кривой
/// \param t параметр, который изменяется на всей числовой прямой
/// \return координаты x y  точки на кривой
///
QPointF parabolPoints(double a, double t);

#endif // PARABOLPOINTS_H
