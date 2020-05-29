#pragma once
class Point
{
	double X;
	double Y;
	void ReadPointFromConsole(double X, double Y);
public:
	
	void WritePointFromConsole();
	
	Point();
	Point(double X, double Y);
};

