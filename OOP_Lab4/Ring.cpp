#include <iostream>
#include "Ring.h"
#include "CheckInput.h"
using namespace std;

void Ring::ReadRingFromConsole(Point center, double outerRadius, double innerRadius)
{
	if (true)
	{
		try
		{
			if (outerRadius <= 0 || innerRadius <= 0)
			{
				throw exception("Радиус должен быть вещественным положительным числом!");
			}

		}
		catch (const std::exception&)
		{
			cout << "Радиус должен быть вещественным положительным числом!" << endl;
		}

		try
		{
			if (outerRadius < innerRadius)
			{
				throw exception("Внутренний радиус не может быть больше внешнего!");
			}

		}
		catch (const std::exception&)
		{
			cout << "Внутренний радиус не может быть больше внешнего!" << endl;
		}
	}

	this->_center = center;
	this->_outerRadius = outerRadius;
	this->_innerRadius = innerRadius;
}

void Ring::WriteRingFromConsole()
{
	cout << "Внешний радиус кольца: " << this->_innerRadius << endl;
	cout << "Внутренний радиус кольца: " << this->_outerRadius << endl;
	this->_center.WritePointFromConsole();
}

double Ring::GetArea()
{
	double Area;
	Area = (3.1415 * this->_outerRadius - 3.1415 * this->_innerRadius);
	return Area;
}


Ring::Ring()
{
}

Ring::Ring(Point center, double outerRadius, double innerRadius)
{
	ReadRingFromConsole(center, outerRadius, innerRadius);
}

void DemoRing()
{
	const int countRings = 3;
	Ring rings[countRings];

	for (int i = 0; i < countRings; i++)
	{
		double innerRadius, outerRadius;
		cout << "Введите внутренний радиус "<< i+1 <<"-го кольца: ";
		CheckInput::CheckInputDouble(&innerRadius);
		cout << "\nВведите внешний радиус  " << i + 1 << "-го кольца:";
		CheckInput::CheckInputDouble(&outerRadius);

		Point point;
		cout << "\nВведите центр  " << i + 1 << "-го кольца: " << endl;
		point.ReadPointFromConsole();
		rings[i] = Ring(point, outerRadius, innerRadius);
		rings[i].WriteRingFromConsole();
		double area;
		area = rings[i].GetArea();
		cout << "Площадь  " << i + 1 << "-го кольца: " << area << endl;
	}
}