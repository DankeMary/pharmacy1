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
	cout << "������� ��� �����: ";
	getline(cin, name);
	while (name == "")
	{
		cout << "��� ����� �� ������ ���� ������! ��������� ����";
		getline(std::cin, name);
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
					cout << "�������� ��� ����������� ��������� ( " << min << " ... " << max << " ) ��������� ���� " << endl;					
				} else return num;
			}
		}
		catch (exception) {
			cout << "������ �������� ������! ��������� ����" << endl;
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
					cout << "�������� ��� ����������� ��������� ( " << min << " ... " << max << " ) ��������� ���� " << endl;
				}
				else return num;
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


Car inputCar(int number) {
	std::string ownerFullName, firstName, secondName, lastName;
	int modelCode;
	std::string modelName;
	int octaneRating;
	int power;
	double tankVolume;
	double fullness;
	double oilVolume;

	std::cout << "Car" + (number != -1 ? ": " + std::to_string(number) : "") << std::endl;

	std::cout << "Enter values\n";

	std::cout << "Owner:\n";
	lastName = inputString("Last name:\t");
	firstName = inputString("First name:\t");
	secondName = inputString("Second name:\t");
	ownerFullName = lastName + " " + firstName + " " + secondName;

	modelCode = inputInt("Code of Model: ");
	modelName = inputString("Model name\t");
	octaneRating = inputInt("Octane Rating: ");
	power = inputInt("Power of engine: ");
	tankVolume = inputDouble("Tank Volume: ");
	fullness = inputDouble("Fullness of tank: ");
	oilVolume = inputDouble("Oil Volume: ");

	return Car(ownerFullName, modelCode, modelName, octaneRating, power, tankVolume, fullness, oilVolume);
}





