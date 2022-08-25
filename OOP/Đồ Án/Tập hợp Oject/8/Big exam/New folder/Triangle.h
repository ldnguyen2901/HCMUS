#pragma once
#include "Polygon.h"

class _Triangle : public _Polygon
{
public:
	static Point pointsDefault_Tri[3];
	_Triangle(Point* p = pointsDefault_Tri) : _Polygon(3, p) {}
	~_Triangle() {}
};
