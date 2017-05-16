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
		cout << "��� ����� �� ������ ���� ������! ��������� ����";
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
				num = stoi(str);
				if (num < min || num > max) 
				{
					cout << "�������� ��� ����������� ��������� ( " << min << " ... " << max << " ) ��������� ���� " << endl;					
				} else 
					return num;
			}
		}
		catch (exception) {
			cout << "������ �������� ������! ��������� ����" << endl;
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
					cout << "�������� ��� ����������� ���������. ��������� ���� " << endl;
				}
				else 
					return num;
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

Med getMed(int number) 
{
	string name, str;
	int farmNum, quantity, shelfLife;
	double price;
	bool available;
	Date arrival;

	cout << "���������";
	if (number != -1)
	{
		cout << " �" << number;
	}
	cout << endl;

	cout << "����� ������: "<< endl;
	farmNum = getInt(0);

	cout << "��������: " << endl;
	name = getString();

	cout << "����������: " << endl;
	quantity = getInt(0);
	/*
	cout << "������� (+/-): " << endl;
	getline(cin, str);
	available = boolFromString(str);*/
	available = quantity > 0;

	cout << "����: " << endl;
	price = getDouble(0.0);

	cout << "���� ��������: " << endl;
	getline(cin, str);
	arrival = dateFromString(str);

	cout << "���� ��������: " << endl;
	shelfLife = getInt(0);
	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}

Med getMed(Med basicMed, int number)
{
	string name, str;
	int farmNum, quantity, shelfLife;
	double price;
	bool available;
	Date arrival;

	cout << "���������";
	if (number != -1)
	{
		cout << " �" << number;
	}
	cout << endl;

	cout << "����� ������: " << endl;
	farmNum = getInt(basicMed.farmNum);

	cout << "��������: " << endl;
	name = getString();
	if (name == "")
		name = basicMed.name;

	cout << "����������: " << endl;
	quantity = getInt(basicMed.quantity);

	/*cout << "������� (+/-): " << endl;
	getline(cin, str);
	if (str == "")
		available = basicMed.available;
	else
		available = boolFromString(str);*/
	available = quantity > 0;

	cout << "����: " << endl;
	price = getDouble(basicMed.price);

	cout << "���� ��������: " << endl;
	getline(cin, str);
	if (str == "")
		arrival = basicMed.arrival;
	else
		arrival = dateFromString(str);

	cout << "���� ��������: " << endl;
	shelfLife = getInt(basicMed.shelfLife);

	return Med(farmNum, name, quantity, available, price, arrival, shelfLife);
}
 








