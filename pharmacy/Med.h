#pragma once
#include <string>

class Med
{
public:	
	int farmNum;
	std::string name;
	int quantity;
	bool available;
	double price;
	Date arrival;
	int shelfLife;
	Med();
	Med(int farmNumTag, std::string nameTag, int quantTag, bool availTag, double priceTag, Date arriveTag, int lifeTag);
	void getData();
	~Med();
};

class Date {
public:
	int day;
	int month;
	int year; 
	Date();
	void getDate();
};

