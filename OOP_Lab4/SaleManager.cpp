#include <iostream>
#include "SaleManager.h"
using namespace std;

bool SaleManager::IsOldProduct(Product* product)
{
	if (product->GetReceiptYear() < 2020)
	{
		return true;
	}
    return false;
}

int SaleManager::ChangeSaleCost(Product* product, int sale)
{
	int newPrice = product->GetPrice() - product->GetPrice()/100 * sale;
    return newPrice;
}

void SaleManager::ProductsCount(Product* products, int productsCount, int sale)
{
	for (int i = 0; i < productsCount; i++)
	{
		if (IsOldProduct(&products[i]) == true)
		{
			int newPrice = ChangeSaleCost(&products[i], sale);
			products[i] = Product(products[i].GetName(), newPrice, products[i].GetReceiptYear());
		}
	}
}
