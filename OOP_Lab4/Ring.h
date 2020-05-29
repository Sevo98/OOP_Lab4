#pragma once
#include "Point.h"

class Ring
{
	static int AllRingsCount;
	double _outerRadius, _innerRadius;
	Point _center;
	void AssertOnPositiveValue(double outerRadius, double innerRadius);
public:
	void ReadRingFromConsole(Point center, double outerRadius, double innerRadius);
	void WriteRingFromConsole();
	static int GetAllRingsCount();

	Ring();
	Ring(Point center, double outerRadius, double innerRadius);
	~Ring();

	double GetArea();
};

void DemoRing();