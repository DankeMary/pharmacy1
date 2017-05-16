#include "stdafx.h"
#include "Med.h"
#include "HelpUtils.h"
#include <iostream>
#include <string>

using namespace std;

//class Date and Date Utils
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

void Date::getDate() {
	string str;
	cout << "Введите день: ";
	while (day < 1 || day > 30)
	{
		getline(cin, str);
		day = stoi(str);
		if (day < 1 || day > 30)
			cout << "Ошибка! Повторите ввод" << endl;
	}

	cout << "Введите месяц: ";
	while (month < 1 || month > 12)
	{
		getline(cin, str);
		month = stoi(str);
		if (month < 1 || month > 12)
			cout << "Ошибка! Повторите ввод" << endl;
	}

	cout << "Введите год: ";
	while (year < 1970 || year > 2020)
	{
		getline(cin, str);
		year = stoi(str);
		if (year < 1900 || year > 2020)
			cout << "Ошибка! Повторите ввод" << endl;
	}
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
	else
		if (other.year > other2.year)
			return false;
		else
			if (other.month < other2.month)
				return  true;
			else
				if (other.month > other2.month)
					return false;
				else
					if (other.day < other2.day)
						return true;
					else
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
Med::Med(int farmNumTag, string nameTag, int quantTag, bool availTag, double priceTag, Date arriveTag, int lifeTag)
{
	this->farmNum = farmNumTag;
	name = nameTag;
	quantity = quantTag;
	available = availTag;
	price = priceTag;
	//arrival = Date(); //???
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

void Med::getData()
{
	string str;
	cout << "Введите номер аптеки: ";
	getline(cin, str);
	farmNum = stoi(str);

	cout << "Введите название лекарства: ";
	getline(cin, name);

	cout << "Введите количество упаковок ";
	getline(cin, str);
	quantity = stoi(str);

	cout << "Имеется ли лекарство в наличии? + : да; - : нет : ";
	getline(cin, str);
	available = boolFromString(str);

	cout << "Введите стоимость 1 упаковки: ";
	getline(cin, str);
	price =  stod(str);

	cout << "Введите дату поступления в аптеку ";
	arrival.getDate();

	cout << "Введите срок хранения: ";
	getline(cin, str);
	shelfLife = stoi(str);
}

ostream &operator<<(ostream &os, const Med &med) {
	os << "Номер аптеки: "<< med.farmNum << "\n" <<
		"Название лекарства: " << med.name << "\n" <<
		"Количество: " << med.quantity << "\n" <<
		"Наличие: " << boolToString(med.available) << "\n" <<
		"Цена: " << med.price << "\n" <<
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
		med.price = stod(skipFieldsNames(is));
		med.arrival = dateFromString(skipFieldsNames(is));
		med.shelfLife = stoi(skipFieldsNames(is));
	}
	catch (const exception& e)
	{
	};
	return is;
}




