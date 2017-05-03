#include "stdafx.h"
#include "HelpUtils.h"
#include "Med.h"
#include <string>
#include <iostream>

using namespace std;


string skipFieldsNames(istream &is)
{
	string str;
	is >> str;
	while ((str.find(":") != -1) || str == "\t" || str == "\n" || str == " ")
	{
		is >> str;
	} 
	return str;
}

string boolAsString(bool b)
{
	return b ? "+": "-";
}

bool boolFromString(string str)
{
	if (str.find("+") != -1) 
		return true;
	else return false;
}

Date dateFromString(string str)
{
	Date date = Date();
	int i = 0;
	while (str[i] == ' ' || i < str.length())
	{
		i++;
	}
	date.day = stod(str.substr(i, 2));
	i += 3;
	date.month = stod(str.substr(i, 2));
	i += 3;
	date.year = stod(str.substr(i, 4));
	return date;
}
