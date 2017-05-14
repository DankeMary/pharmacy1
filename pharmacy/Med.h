#pragma once
#include <string>
//#include <ctime>

using namespace std;

class Date {
	public:
		int day;
		int month;
		int year;
		Date();
		void getDate();
		friend bool operator<(const Date& other, const Date& other2);
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
		double price;
		Date arrival;
		int shelfLife;
		Med();
		Med(int farmNumTag, string nameTag, int quantTag, bool availTag, double priceTag, Date arriveTag, int lifeTag);
		~Med();
		void getData();
		bool operator==(const Med& other) const;
		bool operator!=(const Med& other) const;
};

ostream &operator<<(ostream &os, const Med &med);
istream& operator>>(istream &is, Med &med);


