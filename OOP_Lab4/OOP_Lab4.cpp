#include <iostream>
#include <Windows.h>
#include "Ring.h"
#include "RectangleClass.h"
#include "CollisionManager.h"
#include "GeometricProgram.h"
#include "CheckInput.h"
using namespace std;


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");
	
	GeometricProgram test;

	while (true)
	{
		int number = 0;
		cout << "Введите от 1 до 3" << endl;
		cout << "1. DemoCollision" << endl;
		cout << "2. DemoRectangleWithPoint" << endl;
		cout << "3. DemoRing" << endl;
		CheckInput::CheckInputInt(&number);
		switch (number)
		{
		case 1: test.DemoCollision(); break;
		case 2: test.DemoRectangleWithPoint(); break;
		case 3: test.DemoRing(); break;
		}
	}
}