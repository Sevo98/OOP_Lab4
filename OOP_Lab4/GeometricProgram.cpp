#include <iostream>
#include <Windows.h>
#include "Ring.h"
#include "RectangleClass.h"
#include "CollisionManager.h"
#include "GeometricProgram.h"
#include "Ring.h"
#include "CheckInput.h"
#include "DoubleValidator.h"
using namespace std;

void GeometricProgram::DemoCollision()
{
	RectangleClass rectangle1, rectangle2;
	rectangle1.ReadRectanglesFromConsole();
	rectangle2.ReadRectanglesFromConsole();

	switch (CollisionManager::IsCollision(rectangle1, rectangle2))
	{
	case true: cout << "Прямоугольники пересекаются" << endl; break;

	case false: cout << "Прямоугольники не пересекаются" << endl; break;
	}

	Point point1, point2;
	point1 = Point(4, 4);
	point2 = Point(5, 5);

	Ring ring1, ring2;
	ring1 = Ring(point1, 10, 7);
	ring2 = Ring(point2, 5, 4);

	switch (CollisionManager::IsCollision(ring1, ring2))
	{
	case true: cout << "Кольца  пересекаются" << endl; break;

	case false: cout << "Кольца не пересекаются" << endl; break;
	}
}

void GeometricProgram::DemoRectangleWithPoint()
{
	RectangleClass rect;
	rect.DemoRectangleWithPoint();
}

void GeometricProgram::DemoRing()
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
		cout << "Введите внутренний радиус " << i + 1 << "-го кольца: ";
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
