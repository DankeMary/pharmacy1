#pragma once
#include "Med.h"


class FarmNumPredicate{
protected:
	int fFarmNum;

public:
	FarmNumPredicate();
	FarmNumPredicate(int aFarmNum);
	bool operator() (Med med);
	bool operator() (Med med1, Med med2);
};

