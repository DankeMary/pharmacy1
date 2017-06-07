 // pharmacy.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*11. ������ � ������������� ��������� �������� ����: ����� ������, �������� ���������, 
���������� ��������, �������, ��������� ����� ��������, ���� ����������� � ������, 
���� ��������. ����� �� ������ ������, ������������ ���������, ���� �����������. 
����������� ������ ���� ���������� ��������� � ��������� ����. ��������� ������ ���������
��������� ����� ��� ���������� ������� �������� �������. ��� �������� ������ ���������� 
������� ����������� � ����� ������ ������� ���������. 

���������� �����, 2 ����, 9 ������*/

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
				cout << "������ ����� (������ ������)! ��������� ����" << endl;
			else
				ok = true;
		} while (!ok);

		switch (option)
		{
			case 1:// ��������� ������
				printTargetMenu();
				ok = false;
				do
				{
					option = getInt(-1, 0, 2);
					if (option == -1)
						cout << "������ ����� (������ ������)! ��������� ����" << endl;
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
							cout << "������ ����� (������ ������)! ��������� ����" << endl;
						else
							ok = true;
					} while (!ok);

					found = false;

					if ((option != 3) && dataBase.isEmpty())
						cout << "���� ������ �����!" << endl;
					else
					{
						ok = false;
						switch (option)
						{				
							case 1://������� ������
								printTargetMenu();
								do
								{
									option = getInt(-1, 0, 2);
									if (option == -1)
										cout << "������ ����� (������ ������)! ��������� ����" << endl;
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
							case 2://�����
								searchTypeMenu();
								do
								{
									option = getInt(-1, 0, 2);
									if (option == -1)
										cout << "������ ����� (������ ������)! ��������� ����" << endl;
									else
										ok = true;
								} while (!ok);

								switch (option)
								{
									case 1://�������
										simpleSearch = true;
										break;
									case 2://��������
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
											cout << "������ ����� (������ ������)! ��������� ����" << endl;
										else
											ok = true;
									} while (!ok);

									ok = false;

									switch (option)
									{
										case 1://�� ������ ������
											cout << "������� ����� ������" << endl;											
											do
											{
												helpInt = getInt(-1, 1);
												if (helpInt == -1)
													cout << "������ ����� (������ ������)! ��������� ����" << endl;
												else
													ok = true;
											} while (!ok);

											if (simpleSearch)
												found = dataBase.searchFarmNum(helpInt, it);
											else
												found = dataBase.binarySearchFarmNum(helpInt, it);
											break;
										case 2://�� �������� ���������
											cout << "������� �������� ���������" << endl;
											do
											{
												helpString = getString();
												if (helpString == "")
													cout << "������ ����� (������ ������)! ��������� ����" << endl;
												else 
													ok = true;
											} while (!ok);

											if (simpleSearch)
												found = dataBase.searchName(helpString, it);
											else
												found = dataBase.binarySearchName(helpString, it);
											break;
										case 3: //�� ���� �����������
											cout << "������� ���� �����������" << endl;
											do
											{
												date = getDate(Date(1,1,1969));
												if (date == Date(1,1,1969))
													cout << "������ ����� (������ ������)! ��������� ����" << endl;
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
										cout << "������ �������\n";
										ok = false;
										actionsMenu();
										do
										{
											option = getInt(-1, 0, 3);
											if (option == -1)
												cout << "������ ����� (������ ������)! ��������� ����" << endl;
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
												cout << "������ ���� �������" << endl;
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
														cout << "������ ����� (������ ������)! ��������� ����" << endl;
													else
														ok = true;
												} while (!ok);
											}
										}
									}
									else if (!found &&  option != 0)
										cout << "������ �� �������!\n";
									option = 3;
								}
								break;
							case 3: //��������
								med = getMed();
								dataBase.addItem(med);
								break;
							case 4://�������
								findMenu();
								do
								{
									option = getInt(-1, 0, 3);
									if (option == -1)
										cout << "������ ����� (������ ������)! ��������� ����" << endl;
									else
										ok = true;
								} while (!ok);

								ok = false;

								switch (option)
								{
									case 1://�� ������ ������
										cout << "������� ����� ������" << endl;
										do
										{
											helpInt = getInt(-1, 1);
											if (helpInt == -1)
												cout << "������ ����� (������ ������)! ��������� ����" << endl;
											else
												ok = true;
										} while (!ok);

										subSet = dataBase.getSetFarmNum(helpInt);
										break;
									case 2://�� �������� ���������
										cout << "������� �������� ���������" << endl;
										do
										{
											helpString = getString();
											if (helpString == "")
												cout << "������ ����� (������ ������)! ��������� ����" << endl;
											else
												ok = true;
										} while (!ok);

										subSet = dataBase.getSetName(helpString);
										break;
									case 3://�� ���� �����������
										cout << "������� ���� �����������" << endl;
										do
										{
											date = getDate(Date(1,1,1969));
											if (date == Date(1,1,1969))
												cout << "������ ����� (������ ������)! ��������� ����" << endl;
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
										cout << "\n���-�� ��������� �������: " << subSet.size() << endl;
										printTargetMenu();
										ok = false;
										do
										{
											option = getInt(-1, 0, 2);
											if (option == -1)
												cout << "������ ����� (������ ������)! ��������� ����" << endl;
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
										cout << "������� ������ �� �������!" << endl;
									}
								}
								break;
							case 0: //�����
								break;
						}
					}
				}
				option = 1;
				break;
			case 0://����� �� ���������
				break;
		}
	}

    return 0;
}

