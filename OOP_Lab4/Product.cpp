#include <iostream>
#include "Product.h"

void Product::SetProduct(string name, int price, int receiptYear)
{
	try
	{
		if (price < 0)
		{
			throw exception("���� ������ ���� ������ 0!");
		}

	}
	catch (const std::exception&)
	{
		cout << "���� ������ ���� ������ 0!" << endl;
		system("pause");
	}

	this->_name = name;
	this->_price = price;
	this->_receiptYear = receiptYear;
}

void Product::GetProduct()
{
	cout << "�������: " << this->_name << endl;
	cout << "����: " << this->_price << endl;
	cout << "��� �������: " << this->_receiptYear << endl;
}

string Product::GetName()
{
	return this->_name;
}

int Product::GetPrice()
{
	return this->_price;
}

int Product::GetReceiptYear()
{
	return this->_receiptYear;
}

Product::Product()
{
}

Product::Product(string name, int price, int receiptYear)
{
	SetProduct(name, price, receiptYear);
}
