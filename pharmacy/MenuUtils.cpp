#include "stdafx.h"
#include "MenuUtils.h"
#include <iostream>

using namespace std;

void introMenu() {
	cout << "\n" << endl;
	cout << " 1-Загрузить список" << endl;
	cout << " 0-Выход" << endl;
	cout << "\n" << endl;
}
void mainMenu() {
	cout << "\n" << endl;
	cout << "Главное меню:" << endl;
	cout << " 1-Вывести список" << endl;
	cout << " 2-Поиск" << endl;
	cout << " 3-Добавить" << endl;
	cout << " 4-Выборка" << endl;
	cout << " 0-Выход" << endl;
	cout << "\n" << endl;

}

void printTargetMenu() {
	cout << "\n" << endl;
	cout << " 1-Консоль" << endl;
	cout << " 2-Файл" << endl;
	cout << " 0-Выход" << endl;
	cout << "\n" << endl;
}

void findMenu() {
	cout << "\n" << endl;
	cout << " 1-По номеру аптеки" << endl;
	cout << " 2-По названию лекарства" << endl;
	cout << " 3-По дате поступления" << endl;
	cout << " 0-Выход" << endl;
	cout << "\n" << endl;
}

void searchTypeMenu() {
	cout << "\n" << endl;
	cout << "Поиск:" << endl;
	cout << " 1-Линейный" << endl;
	cout << " 2-Бинарный" << endl;
	cout << " 0-Выход" << endl;
	cout << "\n" << endl;
}

void actionsMenu() {
	cout << "\n" << endl;
	cout << "Действия с записью:" << endl;
	cout << " 1-Печать" << endl;
	cout << " 2-Редактирование" << endl;
	cout << " 3-Удаление" << endl;
	cout << " 0-Выход" << endl;
	cout << "\n" << endl;
}