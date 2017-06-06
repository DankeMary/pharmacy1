#pragma once
#include <string>
#include "decimal.h"
//#include <ctime>

using namespace std;

class Date {
	public:
		int day;
		int month;
		int year;
		Date();
		Date(int d, int m, int y);
		friend bool operator<(const Date& other, const Date& other2);
		friend ostream& operator<<(ostream &os, const Date &date);
		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
};

class Med
{
	public:	
		int farmNum;
		string name;
		int quantity;
		bool available;
		dec::decimal<2> price; 
		Date arrival;
		int shelfLife;
		Med();
		Med(int farmNumTag, string nameTag, int quantTag, bool availTag, dec::decimal<2> priceTag, Date arriveTag, int lifeTag);
		~Med();
		
		bool operator==(const Med& other) const;
		bool operator!=(const Med& other) const;
};

ostream &operator<<(ostream &os, const Med &med);
istream& operator>>(istream &is, Med &med);


