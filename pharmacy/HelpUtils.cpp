#include "stdafx.h"
#include "HelpUtils.h"
#include "Med.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


string boolToString(bool b)
{
	return b ? "+": "-";
}

bool boolFromString(string str)
{
	if (str.find("+") != -1) 
		return true;
	else return false;
}


int priceFromString(string str)
{
	if (str.find(".") == -1)
		return -1;
	int i = 0;
	while ((str[i] == ' ') && (i < str.length()))
	{
		i++;
	}
	if (str[i - 1] == ' ')
		return -1;

	int price = 0, smallPrice = 0;
	try
	{
		price = stoi(str.substr(i, str.find(".") - i));
		smallPrice = stoi(str.substr(str.find(".") + 1));
		if (smallPrice > 99)
			return -1;
		price *= 100;
		price += smallPrice;
		return price;
	}
	catch (const invalid_argument& ia) {
		return -1;
	}
}
string priceToString(int price)
{
	return (to_string(price / 100) + '.' + to_string(price % 100));
}

Date dateFromString(string str)
{
	Date date = Date();
	int i = 0;
	while ((str[i] == ' ') && (i < str.length()))
	{
		i++;
	}
	date.day = stoi(str.substr(i, 2));
	i += 3;
	date.month = stoi(str.substr(i, 2));
	i += 3;
	date.year = stoi(str.substr(i, 4));
	return date;
}


string skipFieldsNames(istream &is)
{
	string str;
	string substr = " ";
	getline(is, str);
	int index = str.find(":") ;
	if (index == -1)
		return "";
	else
	{
		while ((index <= str.length()) && (substr == " "))
		{
			index++;
			substr = str[index];
		}
		if (index > str.length())
			return "";
		else
		{
			substr = str.substr(index);
		}
			return str.substr(index);
	}
}


string getFileName(bool input)
{
	string name;
	fstream f;
	cout << "Введите имя файла: ";
	getline(cin, name);
	while (name == "")
	{
		cout << "Имя файла не должно быть пустым! Повторите ввод";
		getline(cin, name);
	}
	if (input) 
	{		
		f.open(name);
		while (!f.is_open() && name != "") {
			cout << "Файл не найден! Повторите ввод" << endl;
			getline(cin, name);
			f.open(name);
		};
		f.close();
	}
	return name;
}


int getInt(int basic, int min, int max)
{
	int num;
	string str;
	while (true)
	{
		try 
		{
			getline(cin, str);
			if (str == "")
				return basic;
			else
			{
				num = stoi(str);
				if (num < min || num > max) 
				{
					cout << "Значение вне допустимого диапазона ( " << min << " ... " << max << " ) Повторите ввод " << endl;					
				} else 
					return num;
			}
		}
		catch (exception) {
			cout << "Введен неверный символ! Повторите ввод" << endl;
		}
	}
	
}

double getDouble(double basic, double min, double max)
{
	double num;
	string str;
	while (true)
	{
		try {
			getline(cin, str);
			if (str == "")
				return basic;
			else
			{
				num = stod(str);
				if (num < min || num > max)
				{
					cout << "Значение вне допустимого диапазона. Повторите ввод " << endl;
				}
				else 
					return num;
			}
		}
		catch (exception) {
			cout << "Введен неверный символ! Повторите ввод" << endl;
		}
	}

}
string getString()
{
	string str;
	
	getline(cin, str);
	return str;
}

bool checkPrice(string str) {
	if (str.length() == 0) {
		return false;
	}
	size_t i = 0;
	while ((i < str.length()) && ((str[i] == ' ') || (str[i] == '	'))) {
		++i;
	}
	if (i >= str.length()) {
		return false;
	}
	int sign = 1;
	switch (str[i]) 
	{
		case '-': {
			sign = -1;
			++i;
			break;
		}
		case '+': {
			++i;
			break;
		}
		default: {
			break;
		}
	}
	if (sign == -1)
		return false;
	size_t j = i;
	bool result = j < str.length();
	int dot_number = 0;
	while ((j < str.length()) && (result)) {
		if (str[j] == '.') {
			++dot_number;
		}
		result = ((str[j] >= '0') && (str[j] <= '9')) || ((str[j] == '.') && (dot_number <= 1));
		++j;
	}

	while ((j < str.length()) && ((str[j] == ' ') || (str[j] == '	'))) {
		++j;
	}

	return (j == str.length()) && (result);
}
dec::decimal<2> getPrice(dec::decimal<2> basic, dec::decimal<2> min, dec::decimal<2> max)
{
	bool ok = false;
	string str;
	dec::decimal<2> price;

	str = getString();
	if (checkPrice(str))
	{
		dec::fromString(str, price);
		return price;
	}
	else do
	{
		cout << "Ошибка ввода! Повторите ввод" << endl;
		str = getString();
		if (checkPrice(str))
		{
			dec::fromString(str, price);
			ok = true;
			return price;
		}
	} while (!ok);
}
Date getDate(Date basic) {
	string str;
	Date date;
	bool stop = false;
	date.day = 0;
	date.month = 0;
	date.year = 1900;
	cout << "Введите год: ";
	while (date.year < 1970 || date.year > 2020)
	{
		getline(cin, str);
		if (str == "")
			date.year = basic.year;
		else
		{
			date.year = stoi(str);
			if (date.year < 1970 || date.year > 2020)
				cout << "Ошибка! Повторите ввод" << endl;
		}
	}

	cout << "Введите месяц: ";
	while (date.month < 1 || date.month > 12)
	{
		getline(cin, str);
		if (str == "")
			date.year = basic.year;
		else
		{
			date.month = stoi(str);

			if (date.month < 1 || date.month > 12)
				cout << "Ошибка! Повторите ввод" << endl;
		}
	}

	cout << "Введите день: ";
	while (!stop)
	{
		getline(cin, str);
		date.day = stoi(str);
		if (str == "")
			date.year = basic.year;
		switch (date.month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date.day < 1 || date.day > 31)
				cout << "Ошибка! Повторите ввод" << endl;
			else stop = true;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date.day < 1 || date.day > 30)
				cout << "Ошибка! Повторите ввод" << endl;
			else stop = true;
			break;
		case 2:
			if (date.day < 1 || date.day > 28)
				cout << "Ошибка! Повторите ввод" << endl;
			else stop = true;
			break;
		}
	}
	return date;
}

Med getMed(int number) 
{
	string name, str;
	int farmNum, quantity, shelfLife;
	dec::decimal<2> price;
	bool available, ok;
	Date arrival;

	cout << "Лекарство";
	if (number != -1)
	{
		cout << " №" << number;
	}
	cout << endl;

	cout << "Номер аптеки: "<< endl;
	farmNum = getInt(0, 1);

	cout << "Название: " << endl;
	name = getString();

	cout << "Количество: " << endl;
	quantity = getInt(0, 0);
	
	available = quantity > 0;

	cout << "Цена: " << endl;
	price = getPrice(dec::decimal_cast<2>(0), dec::decimal_cast<2>(0));
	
	cout << "Дата прибытия: " << endl;
	arrival = getDate(Date());

	cout << "Срок хранения: " << endl;
	shelfLife = getInt(0, 1);
	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}

Med getMed(Med basicMed, int number)
{
	string name, str;
	int farmNum, quantity, shelfLife;
	dec::decimal<2> price;
	bool available, ok;
	Date arrival;

	cout << "Лекарство";
	if (number != -1)
	{
		cout << " №" << number;
	}
	cout << endl;

	cout << "Номер аптеки ("<< basicMed.farmNum << "): " << endl;
	farmNum = getInt(basicMed.farmNum, 1);

	cout << "Название (" << basicMed.name << "): " << endl;
	name = getString();
	if (name == "")
		name = basicMed.name;

	cout << "Количество (" << basicMed.quantity << "): " << endl;
	quantity = getInt(basicMed.quantity, 0);

	available = quantity > 0;

	ok = false;
	cout << "Цена (" << basicMed.price << "): " << endl;
	str = getString();
	
	price = getPrice(basicMed.price, dec::decimal_cast<2>(0));
	

	cout << "Дата прибытия (" << basicMed.arrival << "): " << endl;
	arrival = getDate(basicMed.arrival);

	cout << "Срок хранения (" << basicMed.shelfLife << "): " << endl;
	shelfLife = getInt(basicMed.shelfLife, 1);

	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}
 








