#include <iostream>
#include "Ring.h"
#include "CheckInput.h"
using namespace std;

int Ring::AllRingsCount = 0;

void Ring::AssertOnPositiveValue(double outerRadius, double innerRadius)
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
}

void Ring::ReadRingFromConsole(Point center, double outerRadius, double innerRadius)
{
	AssertOnPositiveValue(outerRadius, innerRadius);

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

int Ring::GetAllRingsCount()
{
	return AllRingsCount;
}



double Ring::GetArea()
{
	double Area;
	Area = (3.1415 * this->_outerRadius - 3.1415 * this->_innerRadius);
	return Area;
}


Ring::Ring()
{
	Ring::AllRingsCount++;
}

Ring::Ring(Point center, double outerRadius, double innerRadius)
{
	Ring::AllRingsCount++;
	ReadRingFromConsole(center, outerRadius, innerRadius);
	
}

Ring::~Ring()
{
	Ring::AllRingsCount--;
	cout << "Осталось: " << Ring::AllRingsCount << endl;
}

void DemoRing()
{

	cout << "Количество колец до вызова конструктора: " << Ring::GetAllRingsCount() << endl;

	Ring* ring = new Ring(Point(25.0, 25.0), 10.0, 5.0);
	cout << "Количество колец после вызова конструктора: " << Ring::GetAllRingsCount() << endl;

	delete ring;
	cout << "Количество колец после вызова деструктора: " << Ring::GetAllRingsCount() << endl;

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
		double X, Y;
		cout << "Введите X: ";
		CheckInput::CheckInputDouble(&X);
		cout << "\nВведите Y: ";
		CheckInput::CheckInputDouble(&Y);

		point = Point(X, Y);
		
		rings[i] = Ring(point, outerRadius, innerRadius);
		cout << "Создан: " << Ring::GetAllRingsCount() << endl;
		rings[i].WriteRingFromConsole();
		double area;
		area = rings[i].GetArea();
		cout << "Площадь  " << i + 1 << "-го кольца: " << area << endl;
	}
}