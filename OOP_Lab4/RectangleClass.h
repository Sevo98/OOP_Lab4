#pragma once
#include "Point.h"
class RectangleClass
{
	double Length;
	double Width;
	Point point;
public:
	void ReadRectanglesFromConsole();
	void WriteRectanglesFromConsole();
	void DemoRectangleWithPoint();
	
	double GetLength();
	double GetWidth();
	double GetPointX();
	double GetPointY();
};

