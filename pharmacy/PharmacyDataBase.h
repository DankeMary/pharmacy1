#pragma once
#include <vector>
#include "Med.h"
#include <fstream>
#include "Comparators.h"
#include "Predicates.h"
#include "Sets.h"
#include <string>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <functional>
#include <math.h>
#include <iostream>

using namespace std;

template <class T = Med>
class PharmacyDataBase
{
	private:
		vector<T> mainV;
		vector<T> setV;

	public:
		PharmacyDataBase()
		{
			mainV = vector<T>();
		}
		~PharmacyDataBase()
		{
		}
		bool addItem(T item)
		{
			if (!findItem(item)) 
			{
				mainV.push_back(item);
				return true;
			}
			return false;
		}
		bool emptyDataBase()
		{
			return mainV.empty();
		}
		bool findItem(T item) {
			vector<T>::iterator it = find(mainV.begin(), mainV.end(), item);
			return it != mainV.end();
		}

		bool findItem(T item, random_access_iterator_tag &it) {
			it = find(mainV.begin(), mainV.end(), item);
			return it != mainV.end();
		}	

		void changeItem(vector<Med>::iterator &it) {
			*it = getMed(*it);
		}

		void removeItem(vector<Med>::iterator it) {
			mainV.erase(it);
		}

		bool searchFarmNum(int aFarmNum, vector<Med>::iterator &it) {
			FarmNumPredicate pred = FarmNumPredicate(aFarmNum);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}
		bool searchName(string aName, vector<Med>::iterator &it) {
			NamePredicate pred = NamePredicate(aName);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}

		bool searchArrival(Date aArrival, vector<Med>::iterator &it) {
			ArrivalPredicate pred = ArrivalPredicate(aArrival);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}
		bool binarySearchFarmNum(int aFarmNum, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			FarmNumComparator comp = FarmNumComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(aFarmNum, "", 0, false, 0.0, Date(), 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return med.farmNum == it->farmNum;
		}
		bool binarySearchName(string aName, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			NameComparator comp = NameComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(0, aName, 0, false, 0.0, Date(), 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return med.name == it->name;
		}
		bool binarySearchArrival(Date aArrival, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			ArrivalComparator comp = ArrivalComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(0, "", 0, false, 0.0, aArrival, 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return  med.arrival == it->arrival;
		}
		void getSetFarmNum(int aFarmNum) {
			FarmNumSet set = FarmNumSet(aFarmNum);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getSetName(string aName) {
			NameSet set = NameSet(aName);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getSetDate(Date aDate) {
			DateSet set = DateSet(aDate);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getFromConsole() {
			mainV.clear();
			T med;
			int i = 1;
			int choice = 1;
			while (choice == 1) {
				try {
					med = getMed(i);
					cout << "Ввести новые данные : 1 - Да, 0 - Нет : ";
					choice = getInt(choice, 0, 1);
				}
				catch (exception) {
					return;
				}
				addItem(med);
				i++;
			}
		}
		void getFromFile(string fileName) {
			fstream fin(fileName, ios::in);
			if (fin.is_open()) {
				istream_iterator<T> is(fin);
				mainV.clear();
				T med = *is;
				addItem(med);
				while (!fin.eof()) {
					try
					{
						is++;
						med = *is;
						addItem(med);
					}
					catch (exception) 
					{
					};
				}
				fin.close();
			}
			else
				cout << "Файл не найден" << endl;
		}
		void printToConsole() {
			copy(mainV.begin(), mainV.end(), ostream_iterator<T>(cout, "\n"));
		}
		void printSetToConsole() {
			copy(setV.begin(), setV.end(), ostream_iterator<T>(cout, "\n"));
		}
		void saveToFile(string fileName) {
			fstream fout(fileName, ios::out);
			if (fout.is_open()) {
				copy(mainV.begin(), mainV.end(), ostream_iterator<T>(fout, "\n"));
				fout.close();
			}
			else
				cout << "Ошибка при открытии файла" << endl;
		}
		void saveSetToFile(string fileName) {
			fstream fout(fileName, ios::out);
			if (fout.is_open()) {
				copy(setV.begin(), setV.end(), ostream_iterator<T>(fout, "\n"));
				fout.close();
			}
			else
				cout << "Ошибка при открытии файла" << endl;
		}
};

