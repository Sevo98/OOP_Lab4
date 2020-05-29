#pragma once
#include "Point.h"
class Ring
{
	double _outerRadius, _innerRadius;
	Point _center;
public:
	void ReadRingFromConsole(Point center, double outerRadius, double innerRadius);
	void WriteRingFromConsole();

	Ring();
	Ring(Point center, double outerRadius, double innerRadius);

	double GetArea();
};

void DemoRing();