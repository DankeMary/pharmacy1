#pragma once
#include "Med.h"

class FarmNumComparator
{
	public:
		bool operator() (Med m1, Med m2)
		{
			return m1.farmNum < m2.farmNum;
		}
};

class NameComparator
{
	public:
		bool operator() (Med m1, Med m2)
		{
			return m1.name < m2.name;
		}
};
class ArrivalComparator
{
public:
	bool operator() (Med m1, Med m2)
	{
		return m1.arrival < m2.arrival;
	}
};
/*
class QuantityComparator
{
	public:
		bool operator() (Med m1, Med m2)
		{
			return m1.quantity < m2.quantity;
		}
};
class AvailableComparator
{
public:
	bool operator() (Med m1, Med m2)
	{
		return m1.available < m2.available;
	}
};

class PriceComparator
{
public:
	bool operator() (Med m1, Med m2)
	{
		return m1.price < m2.price;
	}
};
*/

/*
class ShelfComparator
{
public:
	bool operator() (Med m1, Med m2)
	{
		return m1.shelfLife < m2.shelfLife;
	}
};*/
