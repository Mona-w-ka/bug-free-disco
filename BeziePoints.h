#ifndef BEZIEPOINTS_H
#define BEZIEPOINTS_H

#include <QPointF>
///
/// \brief BeziePoints Рачет точек для кривой Безье второго порядка
/// \param P0 Первая контрольная точка
/// \param P1 Вторая контрольная точка
/// \param P2 Третья контрольная точка
/// \param t Параметр изменяющийся от 0 до 1
/// \return координаты x y  точки на кривой
///
QPointF BeziePoints(QPointF& P0,QPointF& P1,QPointF& P2, double t);

#endif // BEZIEPOINTS_H

