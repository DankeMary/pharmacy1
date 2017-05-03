#include "stdafx.h"
#include "HelpUtils.h"
#include "Med.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


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

void printMainMenu() {
	std::cout << "\n" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "������� ����:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << " 1-��������� ������" << std::endl;
	std::cout << " 2-������� ������" << std::endl;
	std::cout << " 3-�����" << std::endl;
	std::cout << " 4-��������" << std::endl;
	std::cout << " 5-�������" << std::endl;
	std::cout << " 0-�����" << std::endl;
	std::cout << "\n" << std::endl;
	
}

void printMenuConsoleFile() {
	std::cout << "\n" << std::endl;
	std::cout << " 1-�������" << std::endl;
	std::cout << " 2-����" << std::endl;
	std::cout << " 0-�����" << std::endl;
	std::cout << "\n" << std::endl;
}

void printMenuFind() {
	std::cout << "\n" << std::endl;
	std::cout << " 1-�� ������ ������" << std::endl;
	std::cout << " 2-�� �������� ���������" << std::endl;
	std::cout << " 3-�� ���� �����������" << std::endl;
	std::cout << " 0-�����" << std::endl;
	std::cout << "\n" << std::endl;
}

void printSearchTypeMenu() {
	std::cout << "\n" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "��� ������:" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << " 1-��������" << std::endl;
	std::cout << " 2-��������" << std::endl;
	std::cout << " 0-�����" << std::endl;
	std::cout << "\n" << std::endl;
}

void printActionMenu() {
	std::cout << "\n" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "�������� � �������:" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << " 1-������" << std::endl;
	std::cout << " 2-��������������" << std::endl;
	std::cout << " 3-��������" << std::endl;
	std::cout << " 0-�����" << std::endl;	
	std::cout << "\n" << std::endl;
}





