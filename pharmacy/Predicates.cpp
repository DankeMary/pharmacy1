#include "stdafx.h"
#include "Predicates.h"

FarmNumPredicate::FarmNumPredicate() {}
FarmNumPredicate::FarmNumPredicate(int aFarmNum)
{
	fFarmNum = aFarmNum;
}

bool FarmNumPredicate::operator() (Med med) {
	return fFarmNum == med.farmNum;
}

bool FarmNumPredicate::operator() (Med med1, Med med2) {
	return med1.farmNum == med2.farmNum;
}
