#include "stdafx.h"
#include "Med.h"


Med::Med() 
{
	farmNum = 0;
	name = "";
	quantity = 0;
	available = false;
	price = 0.0;
	arrival.day = 0;
	arrival.month = 0;
	arrival.year = 0;
	shelfLife = 0;	
}
Med::Med(int farmNumTag, std::string nameTag, int quantTag, bool availTag, double priceTag, Date arriveTag, int lifeTag)
{
	farmNum = farmNumTag;
	name = nameTag;
	quantity = quantTag;
	available = availTag;
	price = priceTag;
	arrival.day = arriveTag.day;
	arrival.month = arriveTag.month;
	arrival.year = arriveTag.year;
	shelfLife = lifeTag;
}


Med::~Med()
{
}

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}