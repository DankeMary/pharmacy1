#include "stdafx.h"
#include "Med.h"
#include <iostream>

using namespace std;
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
Med::Med(int farmNumTag, std::string nameTag, int quantTag, bool availTag, double priceTag, Date arriveTag, int lifeTag)
{
	farmNum = farmNumTag;
	name = nameTag;
	quantity = quantTag;
	available = availTag;
	price = priceTag;
	arrival = Date(); //???
	arrival = arriveTag;
	shelfLife = lifeTag;
}


Med::~Med()
{
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