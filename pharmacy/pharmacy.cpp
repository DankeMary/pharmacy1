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

					break;
				case 2:

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

			break;
		case 5://�������

			break;
		case 0: //�����
			break;
		}
	}

    return 0;
}

