#include "stdafx.h"
#include "PharmacyDataBase.h"


void consoleInput(PharmacyDataBase &cont) {
	cont.clear();
	Med med;
	int choice = 1;
	while (choice == 1)
	{
		try {
			med = getMed();
			cout << "Ввести новую запись? 1 - Да, 0 - Нет" << endl;
			choice = getInt(0, 0, 1);
		}
		catch (const char*) {
			return;
		}
		cont.addItem(med);
	}
}

void consoleOutput(PharmacyDataBase &cont) {
		copy(cont.begin(), cont.end(), ostream_iterator<Med>(cout, "\n"));
}

void changeMed(vector<Med>::iterator &it) {
	*it = getMed(*it);
}


