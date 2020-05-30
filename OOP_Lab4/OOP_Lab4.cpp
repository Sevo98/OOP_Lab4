#include <iostream>
#include <Windows.h>
#include "Ring.h"
#include "RectangleClass.h"
#include "CollisionManager.h"
using namespace std;

void DemoCollision();

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");
	
	DemoCollision();
	
	RectangleClass rect;
	rect.DemoRectangleWithPoint();
    DemoRing();
}

void DemoCollision()
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