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
			mainV = std::vector<T>();
		}
		~PharmacyDataBase()
		{

		}
		void addItem(T item)
		{
			mainV.push_back(item);
		}
};

