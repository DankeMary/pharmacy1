// pharmacy.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include "PharmacyDataBase.h"
#include "HelpUtils.h"
#include "MenuUtils.h"
#include <iostream>

int main()
{
	int option = 0;

	while (option != 0)
	{
		mainMenu();
		option = getInt(option, 0, 5);
		switch (option)
		{
		case 1://Загрузить список
			printTargetMenu();
			option = getInt(option, 0, 2);
			switch (option) 
			{
				case 1:

					break;
				case 2:

					break;
				case 0:
					break;
			}
			break;
		case 2://Вывести список
			printTargetMenu();
			option = getInt(option, 0, 2);
			switch (option) 
			{
				case 1:

					break;
				case 2:

					break;
				case 0:
					break;
			}
			break;
		case 3://Поиск
			searchTypeMenu();
			option = getInt(option, 0, 2);
			switch (option) 
			{
				case 1://Простой
				
					break;
				case 2://Бинарный
				
					break;
				case 0:
					break;
			}
			break;
		case 4: //Добавить

			break;
		case 5://Выборка
			findMenu();
			option = getInt(option, 0, 3);
			switch (option)
			{
				case 1://По номеру аптеки

					break;
				case 2://По названию лекарства

					break;
				case 3://По дате поступления

					break;
				case 0:
					break;
			}
			break;
		case 0: //Выход
			break;
		}
	}

    return 0;
}

