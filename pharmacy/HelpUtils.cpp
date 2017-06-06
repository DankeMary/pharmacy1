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
	else 
		return false;
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
	cout << "������� ��� �����: ";
	getline(cin, name);
	while (name == "")
	{
		cout << "��� ����� �� ������ ���� ������! ��������� ����" << endl;
		getline(cin, name);
	}
	if (input) 
	{		
		f.open(name);
		while (!f.is_open() && name != "") {
			cout << "���� �� ������! ��������� ����" << endl;
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
				/*try
				{*/
					num = stoi(str);
					if (num < min || num > max)
					{
						cout << "�������� ��� ����������� ��������� ( " << min << " ... " << max << " ) ��������� ���� " << endl;
					}
					else
						return num;
				/*}
				catch (...)
				{
					cout << "������ �������� ������! ��������� ����" << endl;
				}*/
			}
		}
		catch (exception) {
			cout << "������ �������� ������! ��������� ����" << endl;
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
		case '.':
			sign = -1;
			break;
		default: 			
			break;
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
	if (str == "")
		return basic;
	else
		if (checkPrice(str))
		{
			dec::fromString(str, price);
			return price;
		}
		else do
		{
			cout << "������ �����! ��������� ����" << endl;
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

	bool emptyStr = false;
	if (basic < Date())
		emptyStr = true;

	date.day = 0;
	date.month = 0;
	date.year = 1900;
	cout << "������� ���: ";
	while (date.year < 1970 || date.year > 2020)
	{
		try

		{
			getline(cin, str);
			if ((str == "") && !emptyStr)
				date.year = basic.year;
			else
				if ((str == "") && emptyStr)
					cout << "������! ������ ������. ��������� ����" << endl;
				else
				{
					date.year = stoi(str);
					if (date.year < 1970 || date.year > 2020)
						cout << "������! ��������� ����" << endl;
				}
		}
		catch (exception)
		{
			cout << "������ �������� ������! ��������� ����" << endl;
		}
	}

	cout << "������� �����: ";
	while (date.month < 1 || date.month > 12)
	{
		try
		{
			getline(cin, str);
			if ((str == "") && !emptyStr)
				date.month = basic.month;
			else
				if ((str == "") && emptyStr)
					cout << "������! ������ ������. ��������� ����" << endl;
				else
				{
					date.month = stoi(str);

					if (date.month < 1 || date.month > 12)
						cout << "������! ��������� ����" << endl;
				}
		}
		catch (exception)
		{
			cout << "������ �������� ������! ��������� ����" << endl;
		}
	}

	cout << "������� ����: ";
	while (!stop)
	{
		try
		{
			getline(cin, str);
			if ((str == "") && !emptyStr)
			{
				date.day = basic.day;
				stop = true;
			}
			else
				if ((str == "") && emptyStr)
					cout << "������! ������ ������. ��������� ����" << endl;
				else
				{
					date.day = stoi(str);
					switch (date.month) {
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						if (date.day < 1 || date.day > 31)
							cout << "������! ��������� ����" << endl;
						else
							stop = true;
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						if (date.day < 1 || date.day > 30)
							cout << "������! ��������� ����" << endl;
						else
							stop = true;
						break;
					case 2:
						if (date.day < 1 || date.day > 28)
							cout << "������! ��������� ����" << endl;
						else
							stop = true;
						break;
					}
				}
		}
		catch (exception)
		{
			cout << "������ �������� ������!��������� ����" << endl;
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

	cout << "���������" << endl;

	ok = false;
	cout << "����� ������: "<< endl;
	do
	{
		farmNum = getInt(-1, 1);
		if (farmNum == -1)
			cout << "������ ����� (������ ������)! ��������� ����" << endl;
		else
			ok = true;
	} while (!ok);

	ok = false;
	cout << "��������: " << endl;
	do
	{
		name = getString();
		if (name == "")
			cout << "������ ����� (������ ������)! ��������� ����" << endl;
		else
			ok = true;
	} while (!ok);

	ok = false;
	cout << "����������: " << endl;
	do
	{
		quantity = getInt(-1, 0);
		if (quantity == -1)
			cout << "������ ����� (������ ������)! ��������� ����" << endl;
		else
			ok = true;
	} while (!ok);

	available = quantity > 0;

	ok = false;
	cout << "����: " << endl;
	do
	{
		price = getPrice(dec::decimal_cast<2>(-1), dec::decimal_cast<2>(0));
		if (price == dec::decimal_cast<2>(-1))
			cout << "������ ����� (������ ������)! ��������� ����" << endl;
		else
			ok = true;
	} while (!ok);

	
	cout << "���� ��������: " << endl;
	arrival = getDate(Date(1, 1, 1969));
		
	ok = false;
	cout << "���� ��������: " << endl;
	do
	{
		shelfLife = getInt(-1, 1);
		if(shelfLife == -1)
			cout << "������ ����� (������ ������)! ��������� ����" << endl;
		else
			ok = true;
	} while (!ok);

	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}

Med getMed(Med basicMed, int number)
{
	string name, str;
	int farmNum, quantity, shelfLife;
	dec::decimal<2> price;
	bool available, ok;
	Date arrival;

	cout << "���������" << endl;

	cout << "����� ������ ("<< basicMed.farmNum << "): " << endl;
	farmNum = getInt(basicMed.farmNum, 1);

	cout << "�������� (" << basicMed.name << "): " << endl;
	name = getString();
	if (name == "")
		name = basicMed.name;

	cout << "���������� (" << basicMed.quantity << "): " << endl;
	quantity = getInt(basicMed.quantity, 0);

	available = quantity > 0;

	ok = false;
	cout << "���� (" << basicMed.price << "): " << endl;
	
	price = getPrice(basicMed.price, dec::decimal_cast<2>(0));
	

	cout << "���� �������� (" << basicMed.arrival << "): " << endl;
	arrival = getDate(basicMed.arrival);

	cout << "���� �������� (" << basicMed.shelfLife << "): " << endl;
	shelfLife = getInt(basicMed.shelfLife, 1);

	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}









