#pragma once
#include "pch.h"
#include "Point.h"
class Operation {
public:
	virtual double getLength() = NULL;
	virtual void move(long dx, long dy) = NULL;
	virtual void zoom(double d) = NULL;
	virtual void draw(HDC hdc) = NULL;
};