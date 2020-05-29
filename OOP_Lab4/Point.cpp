#include <iostream>
#include "Point.h"
#include "CheckInput.h"
using namespace std;

void Point::ReadPointFromConsole()
{
	cout << "������� �: ";
	CheckInput::CheckInputDouble(&this->X);

	cout << "\n������� Y: ";
	CheckInput::CheckInputDouble(&this->Y);
}

void Point::WritePointFromConsole()
{
	cout << "X: " << this->X << endl;
	cout << "Y: " << this->Y << endl;
}

Point::Point()
{
}

Point::Point(double X, double Y)
{
	this->X = X;
	this->Y = Y;
}