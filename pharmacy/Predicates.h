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

