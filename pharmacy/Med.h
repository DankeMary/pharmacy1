#pragma once
#include <string>

using namespace std;

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

class Date {
public:
	int day;
	int month;
	int year; 
	Date();
	void getDate();
};

