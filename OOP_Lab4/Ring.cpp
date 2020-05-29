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
				throw exception("������ ������ ���� ������������ ������������� ������!");
			}

		}
		catch (const std::exception&)
		{
			cout << "������ ������ ���� ������������ ������������� ������!" << endl;
		}

		try
		{
			if (outerRadius < innerRadius)
			{
				throw exception("���������� ������ �� ����� ���� ������ ��������!");
			}

		}
		catch (const std::exception&)
		{
			cout << "���������� ������ �� ����� ���� ������ ��������!" << endl;
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
	cout << "������� ������ ������: " << this->_innerRadius << endl;
	cout << "���������� ������ ������: " << this->_outerRadius << endl;
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
	cout << "��������: " << Ring::AllRingsCount << endl;
}

void DemoRing()
{

	cout << "���������� ����� �� ������ ������������: " << Ring::GetAllRingsCount() << endl;

	Ring* ring = new Ring(Point(25.0, 25.0), 10.0, 5.0);
	cout << "���������� ����� ����� ������ ������������: " << Ring::GetAllRingsCount() << endl;

	delete ring;
	cout << "���������� ����� ����� ������ �����������: " << Ring::GetAllRingsCount() << endl;

	const int countRings = 3;
	Ring rings[countRings];

	for (int i = 0; i < countRings; i++)
	{
		double innerRadius, outerRadius;
		cout << "������� ���������� ������ "<< i+1 <<"-�� ������: ";
		CheckInput::CheckInputDouble(&innerRadius);
		cout << "\n������� ������� ������  " << i + 1 << "-�� ������:";
		CheckInput::CheckInputDouble(&outerRadius);

		Point point;
		cout << "\n������� �����  " << i + 1 << "-�� ������: " << endl;
		double X, Y;
		cout << "������� X: ";
		CheckInput::CheckInputDouble(&X);
		cout << "\n������� Y: ";
		CheckInput::CheckInputDouble(&Y);

		point = Point(X, Y);
		
		rings[i] = Ring(point, outerRadius, innerRadius);
		cout << "������: " << Ring::GetAllRingsCount() << endl;
		rings[i].WriteRingFromConsole();
		double area;
		area = rings[i].GetArea();
		cout << "�������  " << i + 1 << "-�� ������: " << area << endl;
	}
}