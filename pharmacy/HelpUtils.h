#pragma once
#include <string>
#include "Med.h"

using namespace std;

string skipFieldsNames(istream &is);
string boolToString(bool b);
bool boolFromString(string str);
Date dateFromString(string str); 
string getFileName(bool input);
string getString();
int getInt(int basic, int min = INT_MIN, int max = INT_MAX);
double getDouble(double basic, double min = DBL_MIN, double max = DBL_MAX);
Med getMed(int number = -1);
Med getMed(Med basicMed, int number = -1);