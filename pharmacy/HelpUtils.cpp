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

void printMainMenu() {
	std::cout << "\n" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Главное меню:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << " 1-Загрузить список" << std::endl;
	std::cout << " 2-Вывести список" << std::endl;
	std::cout << " 3-Поиск" << std::endl;
	std::cout << " 4-Добавить" << std::endl;
	std::cout << " 5-Выборка" << std::endl;
	std::cout << " 0-Выход" << std::endl;
	std::cout << "\n" << std::endl;
	
}

void printMenuConsoleFile() {
	std::cout << "\n" << std::endl;
	std::cout << " 1-Консоль" << std::endl;
	std::cout << " 2-Файл" << std::endl;
	std::cout << " 0-Выход" << std::endl;
	std::cout << "\n" << std::endl;
}

void printMenuFind() {
	std::cout << "\n" << std::endl;
	std::cout << " 1-По номеру аптеки" << std::endl;
	std::cout << " 2-По названию лекарства" << std::endl;
	std::cout << " 3-По дате поступления" << std::endl;
	std::cout << " 0-Выход" << std::endl;
	std::cout << "\n" << std::endl;
}

void printSearchTypeMenu() {
	std::cout << "\n" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "Вид поиска:" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << " 1-Линейный" << std::endl;
	std::cout << " 2-Бинарный" << std::endl;
	std::cout << " 0-Выход" << std::endl;
	std::cout << "\n" << std::endl;
}

void printActionMenu() {
	std::cout << "\n" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "Действия с записью:" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << " 1-Печать" << std::endl;
	std::cout << " 2-Редактирование" << std::endl;
	std::cout << " 3-Удаление" << std::endl;
	std::cout << " 0-Выход" << std::endl;	
	std::cout << "\n" << std::endl;
}





