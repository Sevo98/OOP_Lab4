#pragma once
class Point
{
	double X;
	double Y;
public:
	void ReadPointFromConsole();
	void WritePointFromConsole();
	
	Point();
	Point(double X, double Y);
};

