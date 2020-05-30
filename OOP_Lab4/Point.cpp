#include <iostream>
#include "Point.h"
#include "CheckInput.h"
using namespace std;

void Point::ReadPointFromConsole(double X, double Y)
{
	this->X = X;
	this->Y = Y;
	/*cout << "Введите Х: ";
	CheckInput::CheckInputDouble(&this->X);

	cout << "\nВведите Y: ";
	CheckInput::CheckInputDouble(&this->Y);*/
}

double Point::GetX()
{
	return X;
}

double Point::GetY()
{
	return Y;
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
	ReadPointFromConsole(X, Y);
}