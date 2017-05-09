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
		bool binarySearchAvailable(int aAvailable, vector<Med>::iterator &it) {
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
};

