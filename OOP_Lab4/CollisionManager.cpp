#include <iostream>
#include "CollisionManager.h"
#include <math.h>
#include "RectangleClass.h"
using namespace std;

bool CollisionManager::IsCollision(RectangleClass firstRectangle, RectangleClass secondRectangle)
{
	double dX = abs(firstRectangle.GetPointX() - secondRectangle.GetPointX());
	double dY = abs(firstRectangle.GetPointY() - secondRectangle.GetPointY());
	double dWidth = abs(firstRectangle.GetWidth() - secondRectangle.GetWidth()) / 2;
	double dLenght = abs(firstRectangle.GetLength() - secondRectangle.GetLength()) / 2;

	if (dX < dWidth && dY < dLenght)
	{
		return true;
	}
    return false;
}

bool CollisionManager::IsCollision(Ring firstRing, Ring secondRing)
{
	double dX = abs(firstRing.GetPointX() - secondRing.GetPointX());
	double dY = abs(firstRing.GetPointY() - secondRing.GetPointY());
	double C = sqrt(pow(dX, 2) + pow(dY, 2));
	if (C < (firstRing.GetOuterRadius() + secondRing.GetOuterRadius()))
	{
		return true;
	}
    return false;
}