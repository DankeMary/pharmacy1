#pragma once
#include <vector>


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

};

