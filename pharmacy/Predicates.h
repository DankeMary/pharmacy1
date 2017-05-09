#pragma once
#include "Med.h"
#include <string>

//using namespace std;

class FarmNumPredicate{
	protected:
		int fFarmNum;

	public:
		FarmNumPredicate();
		FarmNumPredicate(int aFarmNum);
		bool operator() (Med med);
		bool operator() (Med med1, Med med2);
};

class NamePredicate {
	protected: //????
		std::string fName;
	public:
		NamePredicate();
		NamePredicate(std::string aName);
		bool operator() (Med med);
		bool operator() (Med med1, Med med2);
};

class QuantityPredicate {
protected:
	int fQuantity;
public:
	QuantityPredicate();
	QuantityPredicate(int aQuantity);
	bool operator() (Med med);
	bool operator() (Med med1, Med med2);
};

class AvailablePredicate {
protected:
	bool fAvailable;
public:
	AvailablePredicate();
	AvailablePredicate(bool aAvailable);
	bool operator() (Med med);
	bool operator() (Med med1, Med med2);
};

class PricePredicate {
protected:
	double fPrice;
public:
	PricePredicate();
	PricePredicate(double aPrice);
	bool operator() (Med med);
	bool operator() (Med med1, Med med2);
};

class ArrivalPredicate {
protected:
	Date fArrival;
public:
	ArrivalPredicate();
	ArrivalPredicate(Date aArrival);
	bool operator() (Med med);
	bool operator() (Med med1, Med med2);
};

class ShelfPredicate {
protected:
	int fShelfLife;
public:
	ShelfPredicate();
	ShelfPredicate(int aShelfLife);
	bool operator() (Med med);
	bool operator() (Med med1, Med med2);
};