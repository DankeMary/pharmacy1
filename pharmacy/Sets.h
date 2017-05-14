#pragma once
#include "Med.h"
#include <vector>

class FarmNumSet
{
	public:
		vector<Med> *set;
		int farmNum;

		FarmNumSet(int aFarmNum)
		{
			farmNum = aFarmNum;
			set = new vector<Med>();
		}
		void operator()(Med med) {
			if (farmNum == med.farmNum)
				set->push_back(med);
		}
		vector<Med> getSet()
		{
			return *set;
		}

};

class NameSet
{
public:
	vector<Med> *set;
	string name;

	NameSet(string aName)
	{
		name = aName;
		set = new vector<Med>();
	}
	void operator()(Med med) {
		if (name == med.name)
			set->push_back(med);
	}
	vector<Med> getSet()
	{
		return *set;
	}

};

class QuantitySet
{
public:
	vector<Med> *set;
	int quantity;

	QuantitySet(int aQuantity)
	{
		quantity = aQuantity;
		set = new vector<Med>();
	}

	void operator()(Med med) {
		if (quantity == med.quantity)
			set->push_back(med);
	}
	vector<Med> getSet()
	{
		return *set;
	}

};

class AvailableSet
{
public:
	vector<Med> *set;
	bool available;

	AvailableSet(bool aAvailable)
	{
		available = aAvailable;
		set = new vector<Med>();
	}
	void operator()(Med med) {
		if (available == med.available)
			set->push_back(med);
	}
	vector<Med> getSet()
	{
		return *set;
	}

};

class PriceSet
{
public:
	vector<Med> *set;
	double price;

	PriceSet(double aPrice)
	{
		price = aPrice;
		set = new vector<Med>();
	}

	void operator()(Med med) {
		if (price == med.price)
			set->push_back(med);
	}
	vector<Med> getSet()
	{
		return *set;
	}

};

class DateSet
{
public:
	vector<Med> *set;
	Date arrival;

	DateSet(Date aDate)
	{
		arrival = aDate;
		set = new vector<Med>();
	}

	void operator()(Med med) {
		if (arrival == med.arrival)
			set->push_back(med);
	}
	vector<Med> getSet()
	{
		return *set;
	}

};

class ShelfSet
{
public:
	vector<Med> *set;
	int shelf;

	ShelfSet(int aShelf)
	{
		shelf = aShelf;
		set = new vector<Med>();
	}
	void operator()(Med med) {
		if (shelf == med.shelfLife)
			set->push_back(med);
	}
	vector<Med> getSet()
	{
		return *set;
	}

};


