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
	~Med();
};

class Date {
public:
	int day;
	int month;
	int year; 
	Date();
	Date getDate();
};

