#include <iostream>
#include "RectangleClass.h"
#include "CheckInput.h"
#include "DoubleValidator.h"
using namespace std;

void RectangleClass::ReadRectanglesFromConsole()
{
	cout << "Задать значения самостоятельно или программно? \n1. Самостоятельно\n2. Программно" << endl;
	int Switch;
	cin >> Switch;
	switch (Switch)
	{
	case 1:
	{
		bool CheckLength = false;
		while (CheckLength == false)
		{
			cout << "Введите длину прямоугольника: ";
			double Length;
			CheckInput::CheckInputDouble(&Length);
			DoubleValidator::AssertPositiveValue(Length);
			this->Length = Length;
			CheckLength = true;
		}

		bool CheckWidth = false;
		while (CheckWidth == false)
		{
			cout << "\nВведите ширину прямоугольника: ";
			double Width;
			CheckInput::CheckInputDouble(&Width);
			DoubleValidator::AssertPositiveValue(Width);
			this->Width = Width;
			CheckWidth = true;
		
		}

		cout << "Введите координаты центра прямоугольника:" << endl;
		double X, Y;
		cout << "Введите X: ";
		CheckInput::CheckInputDouble(&X);
		cout << "\nВведите Y: ";
		CheckInput::CheckInputDouble(&Y);
		point = Point(X, Y);
	} break;

	case 2:
	{
		double max = 1000.45654;
		double min = -1000.45654;
		double X, Y;
		this->Length = (double)(rand()) / RAND_MAX * max;
		this->Width = (double)(rand()) / RAND_MAX * max;
		X = (double)(rand()) / RAND_MAX * (max - min);
		Y = (double)(rand()) / RAND_MAX * (max - min);
		point = Point(X, Y);
	} break;
	}
}

void RectangleClass::WriteRectanglesFromConsole()
{
	this->point.WritePointFromConsole();
	cout << "\nLength = " << this->Length << "; Width = " << this->Width << endl;
}

void RectangleClass::DemoRectangleWithPoint()
{
	this->ReadRectanglesFromConsole();
	this->WriteRectanglesFromConsole();
}

double RectangleClass::GetLength()
{
	return Length;
}

double RectangleClass::GetWidth()
{
	return Width;
}

double RectangleClass::GetPointX()
{
	return this->point.GetX();
}

double RectangleClass::GetPointY()
{
	return this->point.GetY();
}
