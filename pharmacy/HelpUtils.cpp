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
	while (str[i] == ' ' || i < str.length())
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
	is >> str;
	while ((str.find(":") != -1) || str == "\t" || str == "\n" || str == " ")
	{
		is >> str;
	}
	return str;
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
		getline(std::cin, name);
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


int getInt(int min, int max) 
{
	int num;
	string str;
	while (true)
	{
		try {
			getline(cin, str);
			if (str == "")
				return min - 1;
			else
			{
				num = stoi(str);
				if (num < min || num > max) 
				{
					cout << "Значение вне допустимого диапазона ( " << min << " ... " << max << " ) Повторите ввод " << endl;					
				} else return num;
			}
		}
		catch (exception) {
			cout << "Введен неверный символ! Повторите ввод" << endl;
		}
	}
	
}

double getDouble(double min, double max)
{
	double num;
	string str;
	while (true)
	{
		try {
			getline(cin, str);
			if (str == "")
				return min - 1;
			else
			{
				num = stod(str);
				if (num < min || num > max)
				{
					cout << "Значение вне допустимого диапазона ( " << min << " ... " << max << " ) Повторите ввод " << endl;
				}
				else return num;
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
 








