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

//QuantityPredicate
QuantityPredicate::QuantityPredicate() {}
QuantityPredicate::QuantityPredicate(int aQuantity)
{
	fQuantity = aQuantity;
}

bool QuantityPredicate::operator()(Med med) {
	return fQuantity == med.quantity;
}

bool QuantityPredicate::operator()(Med med1, Med med2) {
	return med1.quantity == med2.quantity;
}

//AvailablePredicate
AvailablePredicate::AvailablePredicate() {}
AvailablePredicate::AvailablePredicate(bool aAvailable)
{
	fAvailable = aAvailable;
}

bool AvailablePredicate::operator()(Med med) {
	return fAvailable == med.available;
}

bool AvailablePredicate::operator()(Med med1, Med med2) {
	return med1.available == med2.available;
}

//PricePredicate
PricePredicate::PricePredicate() {}
PricePredicate::PricePredicate(double aPrice)
{
	fPrice = aPrice;
}

bool PricePredicate::operator()(Med med) {
	return fPrice == med.price;
}

bool PricePredicate::operator()(Med med1, Med med2) {
	return med1.price == med2.price;
}

//ArrivalPredicate
ArrivalPredicate::ArrivalPredicate() {}
ArrivalPredicate::ArrivalPredicate(Date aArrival)
{
	fArrival = aArrival;
}

bool ArrivalPredicate::operator()(Med med) {
	return fArrival == med.arrival;
}

bool ArrivalPredicate::operator()(Med med1, Med med2) {
	return med1.arrival == med2.arrival;
}

