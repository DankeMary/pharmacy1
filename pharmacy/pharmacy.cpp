// pharmacy.cpp: определяет точку входа для консольного приложения.
//
/*11. Запись о лекарственном препарате содержит поля: номер аптеки, название лекарства, 
количество упаковок, наличие, стоимость одной упаковки, дата поступления в аптеку, 
срок хранения. Поиск по номеру аптеки, наименованию препарата, дате поступления. 
Результатом должна быть консольная программа с текстовым меню. Программа должна содержать
шаблонный класс для управления данными согласно заданию. Для хранения данных необходимо 
выбрать оптимальный с точки зрения задания контейнер. 

Лактионова Мария, 2 курс, 9 группа*/

#include "stdafx.h"
#include "PharmacyDataBase.h"
#include "HelpUtils.h"
#include "MenuUtils.h"
#include <iostream>
#include <string>
#include "Med.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	int option = -1;
	PharmacyDataBase dataBase = PharmacyDataBase();
	PharmacyDataBase subSet = PharmacyDataBase();
	Med med;
	string fileName, str;
	Date date;
	bool inputFile, simpleSearch, found;
	vector<Med>::iterator it;

	while (option != 0)
	{
		mainMenu();
		option = getInt(option, 0, 5);
		found = false;
		//ХРЕНОВО РАБОТАЕТ!!!!!!!!!!!!!!
		//ж
		if ( ((option != 1) && (option != 0) || (fileName != "") && (option != 4)) && dataBase.isEmpty())
			cout << "База данных пуста!" << endl;
		else
		{
			switch (option)
			{
				Исправить условие!
			case 1://Загрузить список
				printTargetMenu();
				option = getInt(option, 0, 2);
				switch (option)
				{
				case 1:
					consoleInput(dataBase);
					break;
				case 2:
					inputFile = true;
					fileName = getFileName(inputFile);
					dataBase.getFromFile(fstream(fileName, ios::in));
					break;
				case 0:
					option = 1;
					break;
				}
				break;
			case 2://Вывести список
				printTargetMenu();
				option = getInt(option, 0, 2);
				switch (option)
				{
				case 1:
					cout << "\n";
					consoleOutput(dataBase);
					break;
				case 2:
					inputFile = false;
					fileName = getFileName(inputFile);
					dataBase.fileOutput(fstream(fileName, ios::out));
					break;
				case 0:
					option = 2;
					break;
				}
				break;
			case 3://Поиск
				searchTypeMenu();
				option = getInt(option, 0, 2);

				switch (option)
				{
				case 1://Простой
					simpleSearch = true;
					break;
				case 2://Бинарный
					simpleSearch = false;
					break;
				case 0:
					option = 3;
					break;
				}
				if (option != 3)
				{
					findMenu();
					option = getInt(option, 0, 3);
					switch (option)
					{
					case 1://По номеру аптеки
						cout << "Введите номер аптеки" << endl;
						if (simpleSearch)
							found = dataBase.searchFarmNum(getInt(0, 1), it);
						else
							found = dataBase.binarySearchFarmNum(getInt(0, 1), it);
						break;
					case 2://По названию лекарства
						cout << "Введите название лекарства" << endl;
						if (simpleSearch)
							found = dataBase.searchName(getString(), it);
						else
							found = dataBase.binarySearchName(getString(), it);
						break;
					case 3: //По дате поступления
						cout << "Введите дату поступления" << endl;
						//getline(cin, str);
						date = getDate(Date());
						//date.getDate();
						//date = dateFromString(str);
						if (simpleSearch)
							found = dataBase.searchArrival(date, it);
						else
							found = dataBase.binarySearchArrival(date, it);
						break;
					case 0:
						option = 4;
						break;
					}
					if ((option != 4) && found) {
						cout << "Запись найдена\n";
						actionsMenu();
						option = getInt(option, 0, 3);
						while (option != 0)
						{
							switch (option) {
							case 1:
								cout << *it;
								break;
							case 2:
								changeMed(it);
								break;
							case 3:
								dataBase.remove(it);
								cout << "Запись была удалена" << endl;
								option = 0;
								break;
							case 0:
								option = 0;
								break;
							}
							if (option != 0)
							{
								actionsMenu();
								option = getInt(option, 0, 3);
							}
						}
					}
					else if (!found &&  option != 0)
						cout << "Запись не найдена!\n";
					option = 3;
				}
				break;
			case 4: //Добавить
				med = getMed();
				dataBase.addItem(med);
				break;
			case 5://Выборка
				findMenu();
				option = getInt(option, 0, 3);
				switch (option)
				{
				case 1://По номеру аптеки
					cout << "Введите номер аптеки" << endl;
					subSet = dataBase.getSetFarmNum(getInt(0, 1));
					break;
				case 2://По названию лекарства
					cout << "Введите название лекарства" << endl;
					subSet = dataBase.getSetName(getString());
					break;
				case 3://По дате поступления
					cout << "Введите дату поступления" << endl;
					//getline(cin, str);
					//date = dateFromString(str);
					date = getDate(Date());
					subSet = dataBase.getSetDate(date);
					break;
				case 0:
					option = 5;
					break;
				}
				if (option != 5)
				{
					cout << "\nКол-во найденных записей: " << subSet.size() << endl;
					if (!subSet.isEmpty())
					{
						printTargetMenu();
						option = getInt(option, 0, 2);
						switch (option)
						{
						case 1:							
							consoleOutput(subSet);
							break;
						case 2:
							inputFile = false;
							fileName = getFileName(inputFile);
							subSet.fileOutput(fstream(fileName, ios::out));
							break;
						case 0:
							break;
						}
					}
					else {
						cout << "Искомые записи не найдены!" << endl;
					}
				}

				break;
			case 0: //Выход
				break;
			}
		}
	}

    return 0;
}

