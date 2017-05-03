#pragma once
#include "Med.h"

class FarmNumComparator
{
	public:
		bool operator() (Med m1, Med m2)
		{
			return m1.farmNum < m2.farmNum;
		}
};

class NameComparator
{
	public:
		bool operator() (Med m1, Med m2)
		{
			return m1.name < m2.name;
		}
};
