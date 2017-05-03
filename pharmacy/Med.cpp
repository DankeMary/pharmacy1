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
	cout << "������� ����� ������: ";
	cin >> farmNum;

	cout << "������� �������� ���������: ";
	cin >> name;

	cout << "������� ���������� �������� ";
	cin >> quantity;

	cout << "������� �� ��������� � �������? 1 - ��, 0 - ��� : ";
	cin >> available;

	cout << "������� ��������� 1 ��������: ";
	cin >> price;

	cout << "������� ���� ����������� � ������ ";
	arrival.getDate();

	cout << "������� ���� ��������: ";
	cin >> shelfLife;
}

std::ostream& operator<<(std::ostream &os, const Med &med) {
	os << "����� ������: "<< med.farmNum << "\n" <<
		"�������� ���������: " << med.name << "\n" <<
		"����������: " << med.quantity << "\n" <<
		"�������: " << med.available << "\n" <<
		"����: " << med.price << "\n" <<
		"���� �����������: " << med.arrival << "\n" <<
		"���� ��������: " << med.shelfLife << "(���.)" << "\n";
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
	cout << "������� ����: ";
	while (day < 1 || day > 30)
	{
		cin >> day;
		if (day < 1 || day > 30)
			cout << "������! ��������� ����" << endl;
	}

	cout << "������� �����: ";
	while (month < 1 || month > 12)
	{
		cin >> month;
		if (month < 1 || month > 12)
			cout << "������! ��������� ����" << endl;
	}

	cout << "������� ���: ";
	while (year < 1970 || year > 2020)
	{
		cin >> year;
		if (year < 1900 || year > 2020)
			cout << "������! ��������� ����" << endl;
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
