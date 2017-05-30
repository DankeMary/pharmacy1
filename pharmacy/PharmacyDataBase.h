#pragma once
#include <vector>
#include "Med.h"
#include <fstream>
#include "Comparators.h"
#include "Predicates.h"
#include "HelpUtils.h"
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

template<class T>
class DataBase {
protected:
	vector<T> vect;
public:
	typedef _Vector_iterator<_Vector_val<_Simple_types<T>>> my_iterator;
	typedef _Vector_const_iterator<_Vector_val<_Simple_types<T>>> my_const_iterator;

	DataBase(int size) {
		vect = vector<T>(size);
	}

	DataBase() {
		vect = vector<T>();
	}

	void clear() {
		vect.clear();
	}

	~DataBase() {}

	my_const_iterator begin() {
		return vect.cbegin();
	}

	my_const_iterator end() {
		return vect.cend();
	}

	int size() {
		return vect.size();
	}

	bool isEmpty() {
		return vect.size() == 0;
	}

	bool addItem(T item) {
		if (!find(item)) {
			vect.push_back(item);
			return true;
		}

		return false;
	}

	void remove(my_iterator &it) {
		vect.erase(it);
	}


	bool find(T item) {
		return std::find(vect.begin(), vect.end(), item) != vect.end();
	}
	
	template<class Pred>
	bool find(Pred &pred, my_iterator &it) {
		my_iterator itTmp;
		itTmp = find_if(vect.begin(), vect.end(), pred);
		if (itTmp == vect.end()) return false;
		it = itTmp;
		return true;
	}
	
	template<class Comp>
	bool find(Comp &comp, T item, my_iterator &it) {
		my_iterator itTmp;
		sort(vect.begin(), vect.end(), comp);
		itTmp = lower_bound(vect.begin(), vect.end(), item, comp);
		if (itTmp == vect.end() || comp(item, *itTmp)) return false;
		it = itTmp;
		return true;
	}

	template<class Set>
	vector<T> findSubset(Set& set) {
		for_each(vect.begin(), vect.end(), set);
		return set.getSet();
	}
};


class PharmacyDataBase : public DataBase<Med> {
public:
	PharmacyDataBase() {}

	PharmacyDataBase(vector<Med>& _vect) {
		vect = _vect;
	}

	bool searchFarmNum(int aFarmNum, my_iterator &it) {
		return find(FarmNumPredicate(aFarmNum), it);
	}

	bool searchName(string aName, my_iterator &it) {
		return find(NamePredicate(aName), it);
	}

	bool searchArrival(Date aArrival, my_iterator &it) {
		return find(ArrivalPredicate(aArrival), it);
	}
	
	bool binarySearchFarmNum(int aFarmNum, my_iterator &it) {
		Med med = Med(aFarmNum, "", 0, false, 0.0, Date(), 0);
		return find(FarmNumComparator(), med, it);
	}

	bool binarySearchName(string aName, my_iterator &it) {
		Med med = Med(0, aName, 0, false, 0.0, Date(), 0);
		return find(NameComparator(), med, it);
	}

	bool binarySearchArrival(Date aArrival, my_iterator &it) {
		Med med = Med(0, "", 0, false, 0.0, aArrival, 0);
		return find(ArrivalComparator(), med, it);
	}

	PharmacyDataBase getSetFarmNum(int aFarmNum) {
		return PharmacyDataBase(findSubset(FarmNumSet(aFarmNum)));
	}

	PharmacyDataBase getSetName(string aName) {
		return PharmacyDataBase(findSubset(NameSet(aName)));
	}

	PharmacyDataBase getSetDate(Date aDate) {
		return PharmacyDataBase(findSubset(DateSet(aDate)));
	}


	void getFromFile(fstream& fin) {
		if (fin.is_open()) {
			istream_iterator<Med> is(fin);
			vect.clear();
			if (fin.eof()) return;
			Med med = *is++;
			while (!fin.fail() && !fin.eof()) {
				addItem(med);
				med = *is++;
			}
			addItem(med);
			fin.close();
		}
		else
			cout << "Файл не существует!" << endl;
	}

	void fileOutput(fstream& fout) {
		if (fout.is_open()) {
			copy(vect.begin(), vect.end(), ostream_iterator<Med>(fout, "\n"));
			fout.close();
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}

	void output(ostream_iterator<Med> os) {
		copy(vect.begin(), vect.end(), os);
	}
};

void consoleInput(PharmacyDataBase &cont);

void consoleOutput(PharmacyDataBase &cont);

void changeMed(vector<Med>::iterator &it);

