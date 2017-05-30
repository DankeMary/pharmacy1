#include "stdafx.h"
#include "PharmacyDataBase.h"


void consoleInput(PharmacyDataBase &cont) {
	cont.clear();
	Med med;
	while (true)
	{
		try {
			med = getMed();
		}
		catch (const char*) {
			return;
		}

		cont.addItem(med);
	}
}

void consoleOutput(PharmacyDataBase &cont) {
	/*if (cont.isEmpty()) {
		cout << "База данных пуста!" << endl;
	}
	else {*/
		copy(cont.begin(), cont.end(), ostream_iterator<Med>(cout, "\n"));
	//}
}

void changeMed(vector<Med>::iterator &it) {
	*it = getMed(*it);
}


