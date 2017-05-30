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

Med getMed(int number) 
{
	string name, str;
	int farmNum, quantity, shelfLife;
	double price;
	bool available;
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
	price = getDouble(0.0, 0);

	cout << "Дата прибытия: " << endl;
	arrival.getDate();

	cout << "Срок хранения: " << endl;
	shelfLife = getInt(0, 1);
	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}

Med getMed(Med basicMed, int number)
{
	string name, str;
	int farmNum, quantity, shelfLife;
	double price;
	bool available;
	Date arrival;

	cout << "Лекарство";
	if (number != -1)
	{
		cout << " №" << number;
	}
	cout << endl;

	cout << "Номер аптеки: " << endl;
	farmNum = getInt(basicMed.farmNum, 1);

	cout << "Название: " << endl;
	name = getString();
	if (name == "")
		name = basicMed.name;

	cout << "Количество: " << endl;
	quantity = getInt(basicMed.quantity, 0);

	/*cout << "Наличие (+/-): " << endl;
	getline(cin, str);
	if (str == "")
		available = basicMed.available;
	else
		available = boolFromString(str);*/
	available = quantity > 0;

	cout << "Цена: " << endl;
	price = getDouble(basicMed.price, 0);

	cout << "Дата прибытия: " << endl;
	getline(cin, str);
	if (str == "")
		arrival = basicMed.arrival;
	else
		arrival = dateFromString(str);

	cout << "Срок хранения: " << endl;
	shelfLife = getInt(basicMed.shelfLife, 1);

	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}
 








