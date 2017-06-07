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
	bool ok = false;
	int helpInt;
	string helpString;
	while (option != 0)
	{
		introMenu();
		ok = false;
		do
		{
			option = getInt(-1, 0, 1);
			if (option == -1)
				cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
			else
				ok = true;
		} while (!ok);

		switch (option)
		{
			case 1:// Загрузить список
				printTargetMenu();
				ok = false;
				do
				{
					option = getInt(-1, 0, 2);
					if (option == -1)
						cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
					else
						ok = true;

				} while (!ok);

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
						break;
				}

				while (option != 0)
				{
					mainMenu();
					ok = false;
					do
					{
						option = getInt(-1, 0, 4);
						if (option == -1)
							cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
						else
							ok = true;
					} while (!ok);

					found = false;

					if ((option != 3) && dataBase.isEmpty())
						cout << "База данных пуста!" << endl;
					else
					{
						ok = false;
						switch (option)
						{				
							case 1://Вывести список
								printTargetMenu();
								do
								{
									option = getInt(-1, 0, 2);
									if (option == -1)
										cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
									else
										ok = true;
								} while (!ok);
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
							case 2://Поиск
								searchTypeMenu();
								do
								{
									option = getInt(-1, 0, 2);
									if (option == -1)
										cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
									else
										ok = true;
								} while (!ok);

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
									ok = false;
									do
									{
										option = getInt(-1, 0, 3);
										if (option == -1)
											cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
										else
											ok = true;
									} while (!ok);

									ok = false;

									switch (option)
									{
										case 1://По номеру аптеки
											cout << "Введите номер аптеки" << endl;											
											do
											{
												helpInt = getInt(-1, 1);
												if (helpInt == -1)
													cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
												else
													ok = true;
											} while (!ok);

											if (simpleSearch)
												found = dataBase.searchFarmNum(helpInt, it);
											else
												found = dataBase.binarySearchFarmNum(helpInt, it);
											break;
										case 2://По названию лекарства
											cout << "Введите название лекарства" << endl;
											do
											{
												helpString = getString();
												if (helpString == "")
													cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
												else 
													ok = true;
											} while (!ok);

											if (simpleSearch)
												found = dataBase.searchName(helpString, it);
											else
												found = dataBase.binarySearchName(helpString, it);
											break;
										case 3: //По дате поступления
											cout << "Введите дату поступления" << endl;
											do
											{
												date = getDate(Date(1,1,1969));
												if (date == Date(1,1,1969))
													cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
												else
													ok = true;
											} while (!ok);

											if (simpleSearch)
												found = dataBase.searchArrival(date, it);
											else
												found = dataBase.binarySearchArrival(date, it);
											break;
										case 0:
											option = 0;
											found = false;
											break;
									}
									if (found) {
										cout << "Запись найдена\n";
										ok = false;
										actionsMenu();
										do
										{
											option = getInt(-1, 0, 3);
											if (option == -1)
												cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
											else
												ok = true;
										} while (!ok);

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
												ok = false;
												actionsMenu();
												do
												{
													option = getInt(-1, 0, 3);
													if (option == -1)
														cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
													else
														ok = true;
												} while (!ok);
											}
										}
									}
									else if (!found &&  option != 0)
										cout << "Запись не найдена!\n";
									option = 3;
								}
								break;
							case 3: //Добавить
								med = getMed();
								dataBase.addItem(med);
								break;
							case 4://Выборка
								findMenu();
								do
								{
									option = getInt(-1, 0, 3);
									if (option == -1)
										cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
									else
										ok = true;
								} while (!ok);

								ok = false;

								switch (option)
								{
									case 1://По номеру аптеки
										cout << "Введите номер аптеки" << endl;
										do
										{
											helpInt = getInt(-1, 1);
											if (helpInt == -1)
												cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
											else
												ok = true;
										} while (!ok);

										subSet = dataBase.getSetFarmNum(helpInt);
										break;
									case 2://По названию лекарства
										cout << "Введите название лекарства" << endl;
										do
										{
											helpString = getString();
											if (helpString == "")
												cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
											else
												ok = true;
										} while (!ok);

										subSet = dataBase.getSetName(helpString);
										break;
									case 3://По дате поступления
										cout << "Введите дату поступления" << endl;
										do
										{
											date = getDate(Date(1,1,1969));
											if (date == Date(1,1,1969))
												cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
											else
												ok = true;
										} while (!ok);
										subSet = dataBase.getSetDate(date);
										break;
									case 0:
										option = 5;
										break;
								}
								if (option != 5)
								{									
									if (!subSet.isEmpty())
									{
										cout << "\nКол-во найденных записей: " << subSet.size() << endl;
										printTargetMenu();
										ok = false;
										do
										{
											option = getInt(-1, 0, 2);
											if (option == -1)
												cout << "Ошибка ввода (пустая строка)! Повторите ввод" << endl;
											else
												ok = true;
										} while (!ok);

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
												option = -1;
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
				option = 1;
				break;
			case 0://Выход из программы
				break;
		}
	}

    return 0;
}

