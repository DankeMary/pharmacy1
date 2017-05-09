#pragma once
#include <vector>
#include "Med.h"

using namespace std;

template <class T = Med>
class PharmacyDataBase
{
	private:
		vector<T> mainV;

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

};

