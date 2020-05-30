#pragma once
class Point
{
	double X;
	double Y;
	void ReadPointFromConsole(double X, double Y);
public:
	
	double GetX();
	double GetY();
	void WritePointFromConsole();
	
	Point();
	Point(double X, double Y);
};

