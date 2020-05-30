#pragma once
#include "RectangleClass.h"
#include "Ring.h"
static class CollisionManager
{
public:
	static bool IsCollision(RectangleClass firstRectangle, RectangleClass secondRectangle);
	static bool IsCollision(Ring firstRing, Ring secondRing);
};