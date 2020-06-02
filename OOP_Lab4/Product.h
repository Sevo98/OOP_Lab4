#pragma once
#include <string>
using namespace std;

class Product
{
	string _name;
	int _price;
	int _receiptYear;
public:
	void SetProduct(string name, int price, int receiptYear);
	void GetProduct();
	string GetName();
	int GetPrice();
	int GetReceiptYear();

	Product();
	Product(string name, int price, int receiptYear);

};

