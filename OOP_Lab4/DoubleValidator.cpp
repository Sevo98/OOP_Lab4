#include <iostream>
#include "DoubleValidator.h"
using namespace std;


bool DoubleValidator::IsValuePositive(double value)
{
	if (value > 0)
	{
		return true;
	} else return false;
}

bool DoubleValidator::IsValueInRange(double value, double min, double max)
{
	if (min < value < max)
	{
		return true;
	} else return false;
}

void DoubleValidator::AssertPositiveValue(double value)
{
	try
	{
		if (IsValuePositive(value) == false)
		{
			throw exception("�������� �������������!");
		}
	}
	catch (const std::exception&)
	{
		cout << "�������� �������������!" << endl;
	}
}

void DoubleValidator::AssertValueInRange(double value, double min, double max)
{
	try
	{
		if (IsValueInRange(value, min, max) == false)
		{
			throw exception("�������� �� ������������� ����������� ���������!");
		}
	}
	catch (const std::exception&)
	{
		cout << "�������� �� ������������� ����������� ���������!" << endl;
	}
}
