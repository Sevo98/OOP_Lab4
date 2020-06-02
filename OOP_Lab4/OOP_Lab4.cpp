#include <iostream>
#include <Windows.h>
#include "Ring.h"
#include "RectangleClass.h"
#include "CollisionManager.h"
#include "GeometricProgram.h"
#include "CheckInput.h"
#include "Product.h"
#include "SaleManager.h"
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
		cout << "Введите от 1 до 4" << endl;
		cout << "1. DemoCollision" << endl;
		cout << "2. DemoRectangleWithPoint" << endl;
		cout << "3. DemoRing" << endl;
		cout << "4. Индивидуальное задание" << endl;
		CheckInput::CheckInputInt(&number);
		switch (number)
		{
		case 1: test.DemoCollision(); break;
		case 2: test.DemoRectangleWithPoint(); break;
		case 3: test.DemoRing(); break;
		case 4: 
			{
			const int productsCount = 4;

			Product products[productsCount];
			for (int i = 0; i < productsCount; i++)
			{
				//cin.ignore(32767, '\n');
				string name;
				int price, receiptYear;
				cout << "Введите название продукта: ";
				getline(cin, name);
				cout << "Введите цену продукта: ";
				CheckInput::CheckInputInt(&price);
				cout << "Введите год выпуска продукта: ";
				CheckInput::CheckInputInt(&receiptYear);
				
				products[i] = Product(name, price, receiptYear);
			}

			for (int i = 0; i < productsCount; i++)
			{
				products[i].GetProduct();
			}

			cout << "Введите размер скидки на устаревшие товары в %: ";
			int sale;
			cin >> sale;
			SaleManager::ProductsCount(products, productsCount, sale);

			for (int i = 0; i < productsCount; i++)
			{
				products[i].GetProduct();
			}

			} break;
		}
	}
}