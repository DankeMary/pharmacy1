#include "stdafx.h"
#include "Predicates.h"
//#include <string>

//using namespace std;

//FarmNumPredicate
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

//NamePredicate
NamePredicate::NamePredicate() {}
NamePredicate::NamePredicate(std::string aName)
{
	fName = aName;
}

bool NamePredicate::operator()(Med med) {
	return fName == med.name;
}

bool NamePredicate::operator()(Med med1, Med med2) {
	return med1.name == med2.name;
}
