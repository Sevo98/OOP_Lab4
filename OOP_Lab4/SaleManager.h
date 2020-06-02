#pragma once
#include "Product.h"
using namespace std;

static class SaleManager
{
	static bool IsOldProduct(Product* product);
	static int ChangeSaleCost(Product* product, int sale);
public:
	static void ProductsCount(Product* products, int productsCount, int sale);
};

