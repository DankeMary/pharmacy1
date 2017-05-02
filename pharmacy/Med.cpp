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