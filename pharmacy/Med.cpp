#include "stdafx.h"
#include "Med.h"
#include "HelpUtils.h"
#include <iostream>
#include <string>

using namespace std;

//class Date and Date Utils
Date::Date()
{
	day = 1;
	month = 1;
	year = 1970;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

bool Date::operator==(const Date& other) const
{
	return (this->year == other.year) && (this->month == other.month) && (this->day == other.day);
}
bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}

bool operator<(const Date& other, const Date& other2)
{
	if (other.year < other2.year)
		return true;

	if (other.year > other2.year)
		return false;

	if (other.month < other2.month)
		return  true;

	if (other.month > other2.month)
		return false;

	if (other.day < other2.day)
		return true;

	return false;
}

ostream& operator<<(ostream &os, const Date &date)
{
	if (date.day < 10)
	{
		os << "0" << date.day << ".";
	}
	else 
		os << date.day << ".";
	if (date.month < 10)
	{
		os << "0" << date.month << ".";
	}
	else
		os << date.month << ".";
	os << date.year;
	return os;
}

istream& operator>>(istream &is, Date &date) {
	char symb;
	cin >> date.day >> symb >> date.month >> symb >> date.year;
	return is;
}

//class Med and Med Utils
Med::Med() 
{
	farmNum = 0;
	name = "";
	quantity = 0;
	available = false;
	price = 0.0;
	arrival = Date();
	shelfLife = 0;	
}
Med::Med(int farmNumTag, string nameTag, int quantTag, bool availTag, dec::decimal<2> priceTag, Date arriveTag, int lifeTag)
{
	this->farmNum = farmNumTag;
	name = nameTag;
	quantity = quantTag;
	available = availTag;
	price = priceTag;
	arrival = arriveTag;
	shelfLife = lifeTag;
}


Med::~Med()
{
}

bool Med::operator==(const Med& other) const {
	return this->name == other.name;
}

bool Med::operator!=(const Med& other) const {
	return !(*this == other);
}

ostream &operator<<(ostream &os, const Med &med) {
	os << "Номер аптеки: "<< med.farmNum << "\n" <<
		"Название лекарства: " << med.name << "\n" <<
		"Количество: " << med.quantity << "\n" <<
		"Наличие: " << boolToString(med.available) << "\n" <<
		"Цена: " << dec::toString(med.price) << "\n" <<
		"Дата поступления: " << med.arrival << "\n" << 
		"Срок хранения: " << med.shelfLife << "\n";
	return os;
}

istream& operator>>(istream &is, Med &med) {
	try
	{
		med.farmNum = stoi(skipFieldsNames(is));
		med.name = skipFieldsNames(is);
		med.quantity = stoi(skipFieldsNames(is));
		med.available = boolFromString(skipFieldsNames(is));
		dec::fromString(skipFieldsNames(is), med.price);
		med.arrival = dateFromString(skipFieldsNames(is));
		med.shelfLife = stoi(skipFieldsNames(is));
	}
	catch (const exception& e)
	{
	};
	return is;
}




