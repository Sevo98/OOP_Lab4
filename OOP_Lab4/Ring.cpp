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
		cout << "������� ���������� ������ "<< i+1 <<"-�� ������: ";
		CheckInput::CheckInputDouble(&innerRadius);
		cout << "\n������� ������� ������  " << i + 1 << "-�� ������:";
		CheckInput::CheckInputDouble(&outerRadius);

		Point point;
		cout << "\n������� �����  " << i + 1 << "-�� ������: " << endl;
		point.ReadPointFromConsole();
		rings[i] = Ring(point, outerRadius, innerRadius);
		rings[i].WriteRingFromConsole();
		double area;
		area = rings[i].GetArea();
		cout << "�������  " << i + 1 << "-�� ������: " << area << endl;
	}
}