#pragma once
#include <vector>
#include "Med.h"

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
		void addItem(T item)
		{
			mainV.push_back(item);
		}

		bool findItem(T item) {
			vector<T>::iterator it = find(mainV.begin(), mainV.end(), item);
			return it != mainV.end();
		}

		bool findItem(T item, random_access_iterator_tag &it) {
			it = find(mainV.begin(), mainV.end(), item);
			return it != mainV.end();
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
		bool searchQuantity(int aQuantity, vector<Med>::iterator &it) {
			QuantityPredicate pred = QuantityPredicate(aQuantity);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}
		bool searchAvailable(bool aAvailable, vector<Med>::iterator &it) {
			AvailablePredicate pred = AvailablePredicate(aAvailable);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}
		bool searchPrice(double aPrice, vector<Med>::iterator &it) {
			PricePredicate pred = PricePredicate(aPrice);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}
		bool searchArrival(Date aArrival, vector<Med>::iterator &it) {
			ArrivalPredicate pred = ArrivalPredicate(aArrival);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}
		bool searchShelfLife(int aShelf, vector<Med>::iterator &it) {
			ShelfPredicate pred = ShelfPredicate(aShelf);
			it = find_if(mainV.begin(), mainV.end(), pred);
			return it != mainV.end();
		}


		bool binarySearchFarmNum(int aFarmNum, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			FarmNumComparator comp = FarmNumComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(aFarmNum, "", 0, false, 0.0, new Date(), 0);
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
			T med = Med(0, aName, 0, false, 0.0, new Date(), 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return med.name == it->name;
		}
		bool binarySearchQuantity(int aQuantity, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			QuantityComparator comp = QuantityComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(0, "", aQuantity, false, 0.0, new Date(), 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return med.quantity == it->quantity;
		}
		bool binarySearchAvailable(bool aAvailable, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			AvailableComparator comp = AvailableComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(0, "", 0, aAvailable, 0.0, new Date(), 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return  med.available == it->available;
		}
		bool binarySearchPrice(double aPrice, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			PriceComparator comp = PriceComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(0, "", 0, false, aPrice, new Date(), 0);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return  med.price == it->price;
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
		bool binarySearchShelfLife(int aShelf, vector<Med>::iterator &it) {
			if (mainV.begin() == mainV.end())
				return false;
			ShelfComparator comp = ShelfComparator();
			sort(mainV.begin(), mainV.end(), comp);
			T med = Med(0, "", 0, false, 0.0, new Date(), aShelf);
			it = lower_bound(mainV.begin(), mainV.end(), med, comp);
			if (it == mainV.end())
				return false;
			else
				return  med.shelfLife == it->shelfLife;
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
		void getSetQuantity(int aQuantity) {
			QuantitySet set = QuantitySet(aQuantity);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getSetAvailable(bool aAvailable) {
			AvailableSet set = AvailableSet(aAvailable);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getSetPrice(double aPrice) {
			PriceSet set = PriceSet(aPrice);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getSetDate(Date aDate) {
			DateSet set = DateSet(aDate);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
		}
		void getSetShelf(int aShelf) {
			ShelfSet set = ShelfSet(aShelf);
			for_each(mainV.begin(), mainV.end(), set);
			setV = set.getSet();
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
				cout << "Ошибка при открытии файла" << std::endl;
		}
		void saveSetToFile(string fileName) {
			fstream fout(fileName, ios::out);
			if (fout.is_open()) {
				copy(setV.begin(), setV.end(), ostream_iterator<T>(fout, "\n"));
				fout.close();
			}
			else
				cout << "Ошибка при открытии файла" << std::endl;
		}
};

