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

std::ostream& operator<<(std::ostream &os, const Date &date)
{
	os << date.day << "." << date.month << "." << date.year;
	return os;
}

std::istream& operator>>(std::istream &is, Date &date) {
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
	cout << "������� ����� ������: ";
	getline(cin, str);
	farmNum = stoi(str);

	cout << "������� �������� ���������: ";
	getline(cin, name);

	cout << "������� ���������� �������� ";
	getline(cin, str);
	quantity = stoi(str);

	cout << "������� �� ��������� � �������? + : ��; - : ��� : ";
	getline(cin, str);
	available = boolFromString(str);

	cout << "������� ��������� 1 ��������: ";
	getline(cin, str);
	price =  stod(str);

	cout << "������� ���� ����������� � ������ ";
	arrival.getDate();

	cout << "������� ���� ��������: ";
	getline(cin, str);
	shelfLife = stoi(str);
}

std::ostream& operator<<(std::ostream &os, const Med &med) {
	os << "����� ������: "<< med.farmNum << "\n" <<
		"�������� ���������: " << med.name << "\n" <<
		"����������: " << med.quantity << "\n" <<
		"�������: " << boolToString(med.available) << "\n" <<
		"����: " << med.price << "\n" <<
		"���� �����������: " << med.arrival << "\n" << // �� �� �� ���������� ��������� ��������
		"���� ��������: " << med.shelfLife << "(���.)" << "\n";
	return os;
}


std::istream& operator>>(std::istream &is, Med &med) {
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
	catch (const std::exception& e)
	{
	};
	return is;
}




