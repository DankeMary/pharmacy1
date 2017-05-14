// pharmacy.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	PharmacyDataBase<> dataBase = PharmacyDataBase<>();
	Med med;
	string fileName;
	bool inputFile;
	while (option != 0)
	{
		mainMenu();
		option = getInt(option, 0, 5);
		switch (option)
		{
		case 1://��������� ������
			printTargetMenu();
			option = getInt(option, 0, 2);
			switch (option) 
			{
				case 1:
					dataBase.getFromConsole();
					break;
				case 2:
					inputFile = true;
					fileName = getFileName(inputFile);
					dataBase.getFromFile(fileName);
					break;
				case 0:
					break;
			}
			break;
		case 2://������� ������
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
		case 3://�����
			searchTypeMenu();
			option = getInt(option, 0, 2);
			switch (option) 
			{
				case 1://�������
				
					break;
				case 2://��������
				
					break;
				case 0:
					break;
			}
			break;
		case 4: //��������
			med = getMed();
			dataBase.addItem(med);
			break;
		case 5://�������
			findMenu();
			option = getInt(option, 0, 3);
			switch (option)
			{
				case 1://�� ������ ������

					break;
				case 2://�� �������� ���������

					break;
				case 3://�� ���� �����������

					break;
				case 0:
					break;
			}
			break;
		case 0: //�����
			break;
		}
	}

    return 0;
}

