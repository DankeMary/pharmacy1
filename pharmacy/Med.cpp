#include "stdafx.h"
#include "Med.h"
#include <iostream>
#include <string>

using namespace std;

//class Med and Med Utils
Med::Med() 
{
	farmNum = 0;
	name = "";
	quantity = 0;
	available = '-';
	price = 0.0;
	arrival = Date();
	shelfLife = 0;	
}
Med::Med(int farmNumTag, string nameTag, int quantTag, char availTag, double priceTag, Date arriveTag, int lifeTag)
{
	this->farmNum = farmNumTag;
	this->name = nameTag;
	this->quantity = quantTag;
	this->available = availTag;
	this->price = priceTag;
	this->arrival = Date(); //???
	this->arrival = arriveTag;
	this->shelfLife = lifeTag;
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
	cout << "Введите номер аптеки: ";
	cin >> farmNum;

	cout << "Введите название лекарства: ";
	cin >> name;

	cout << "Введите количество упаковок ";
	cin >> quantity;

	cout << "Имеется ли лекарство в наличии? 1 - да, 0 - нет : ";
	cin >> available;

	cout << "Введите стоимость 1 упаковки: ";
	cin >> price;

	cout << "Введите дату поступления в аптеку ";
	arrival.getDate();

	cout << "Введите срок хранения: ";
	cin >> shelfLife;
}

std::ostream& operator<<(std::ostream &os, const Med &med) {
	os << "Номер аптеки: "<< med.farmNum << "\n" <<
		"Название лекарства: " << med.name << "\n" <<
		"Количество: " << med.quantity << "\n" <<
		"Наличие: " << med.available << "\n" <<
		"Цена: " << med.price << "\n" <<
		"Дата поступления: " << med.arrival << "\n" <<
		"Срок хранения: " << med.shelfLife << "(мес.)" << "\n";
	return os;
}


std::istream& operator>>(std::istream &is, Med &med) {
	try
	{
		cin >> med.farmNum;
		cin >> med.name;
		cin >> med.quantity;
		cin >> med.available;
		cin >> med.price;
		cin >> med.arrival;
		cin >> med.shelfLife;
	}
	catch (const std::exception& e)
	{
	};
	return is;
}


//class Date and Date Utils
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

void Date::getDate() {
	/*d.day = 0;
	d.month = 0;
	d.year = 0;*/
	cout << "Введите день: ";
	while (day < 1 || day > 30)
	{
		cin >> day;
		if (day < 1 || day > 30)
			cout << "Ошибка! Повторите ввод" << endl;
	}

	cout << "Введите месяц: ";
	while (month < 1 || month > 12)
	{
		cin >> month;
		if (month < 1 || month > 12)
			cout << "Ошибка! Повторите ввод" << endl;
	}

	cout << "Введите год: ";
	while (year < 1970 || year > 2020)
	{
		cin >> year;
		if (year < 1900 || year > 2020)
			cout << "Ошибка! Повторите ввод" << endl;
	}
}
std::ostream& operator<<(std::ostream &os, const Date &date)
{
	os << date.day << "." << date.month << "." << date.year;
}

std::istream& operator>>(std::istream &is, Date &date) {
	char symb;
	cin >> date.day >> symb >> date.month >> symb >> date.year;
}
