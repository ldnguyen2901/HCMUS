#include "Quadrangle.h"

/*--------------------------------------------*
 *					Quadrangle				  *
 *--------------------------------------------*/
Point _Quadrangle::pointsDefault_Quadra[4] = { Point(100,500), Point(50,150), Point(150,200), Point(200,300) };
/*--------------------------------------------*
 *					Trazape 				  *
 *--------------------------------------------*/
 //Point _Trapezoid::pointsDefault_Tra[4] = { Point(50,100), Point(150,100), Point(250,250), Point(50,250) };
_Trapezoid::_Trapezoid(Point p[4])
{
    if (check(p))
        for (int i = 0; i < 4; i++)
            points[i] = p[i];
    else
    {
        delete[] points;
        points = new Point[vertices = 0];
    }
}

void _Trapezoid::setPoints(double x1, double y, double x2, double se, double le, double h)
{
    points[0] = Point(x1, y);
    points[1] = Point(x1 + se, y);
    points[2] = Point(x2 + le, y + h);
    points[3] = Point(x2, y + h);
}

bool _Trapezoid::check(Point p[4]) const
{
    Point vt1, vt2;
    double dx, dy;
    vt1 = p[0].setVector(p[1]);
    vt2 = p[3].setVector(p[2]);
    if (vt1.getX() != 0 && vt2.getX() != 0)
        dx = vt1.getX() / vt2.getX();
    else
        dx = 0;
    if (vt1.getY() != 0 && vt2.getY() != 0)
        dy = vt1.getY() / vt2.getY();
    else dy = 0;
    return (dx == dy || dx == 0 || dy == 0);
}

/*--------------------------------------------*
 *					Parallelogram			  *
 *--------------------------------------------*/

_Parallelogram::_Parallelogram(Point p[4])
{
    if (check(p))
        for (int i = 0; i < 4; i++)
            points[i] = p[i];
    else
    {
        delete[] points;
        points = new Point[vertices = 0];
    }
}

bool _Parallelogram::check(Point p[4]) const
{
    Point vt[4];
    Point d[2];
    double x, y;
    for (int i = 0; i < 4; i++)
        vt[i] = p[i].setVector(p[(i + 1) % 4]);
    for (int i = 0; i < 2; i++)
    {
        if (vt[i].getX() != 0 && vt[i + 2].getX() != 0)
            x = vt[i].getX() / vt[i + 2].getX();
        else
            x = 0;
        if (vt[i].getY() != 0 && vt[i + 2].getY() != 0)
            y = vt[i].getY() / vt[i + 2].getY();
        else
            y = 0;
        d[i].set(x, y);
    }
    return ((d[0].getX() == d[0].getY() || d[0].getX() == 0 || d[0].getY() == 0) && (d[1].getX() == d[1].getY() || d[1].getX() == 0 || d[1].getY() == 0));
}

/*--------------------------------------------*
 *					Rectangle 				  *
 *--------------------------------------------*/

_Rectangle::_Rectangle(Point p[4])
{
    if (check(p))
        for (int i = 0; i < 4; i++)
            points[i] = p[i];
    else
    {
        delete[] points;
        points = new Point[vertices = 0];
    }
}

//void _Rectangle::scale(double s)
//{
//    upperLeftPoint.move()
//}

bool _Rectangle::check(Point p[4]) const
{
    Point vt[4];
    double a[3];
    for (int i = 0; i < 4; i++)
        vt[i] = p[i].setVector(p[(i + 1) % 4]);
    for (int i = 0; i < 3; i++)
    {
        a[i] = vt[i].getX() * vt[(i + 1) % 4].getX() + vt[i].getY() * vt[(i + 1) % 4].getY();
    }
    return (a[0] == a[1] && a[1] == a[2] && a[2] == 0);
}


//void _Rectangle::set(double x, double y)
//{
//	for (int i = 0; i < vertices; i++)
//		points[i] = Point(x, y);
//}
//
//void _Rectangle::set2(double x2, double y2)
//{
//	double x1 = points[0].getX(), y1 = points[0].getY();
//	points[2] = Point(x2, y2);
//	points[1] = Point(x2, y1);
//	points[3] = Point(x1, y2);
//}
//
//int FindRectangle(_Rectangle ar[], int n, double x, double y)
//{
//	for (int i = n - 1; i >= 0; i--)
//		if (ar[i].isInside(x, y))
//			return i;
//	return -1;
//}

/*--------------------------------------------*
 *					Square   				  *
 *--------------------------------------------*/

_Square::_Square(Point p[4])
{
    if (check(p))
        for (int i = 0; i < 4; i++)
            points[i] = p[i];
    else
    {
        delete[] points;
        points = new Point[vertices = 0];
    }
}

bool _Square::check(Point p[4]) const
{
    Point vt1, vt2;
    double d1, d2;
    double d;
    vt1 = p[0].setVector(p[2]);
    vt2 = p[1].setVector(p[3]);
    d1 = p[0].distance(p[2]);
    d2 = p[1].distance(p[3]);
    d = vt1.getX() * vt2.getX() + vt1.getY() * vt2.getY();
    return (d == 0 && d1 == d2);
}


