#pragma once
#include <string>
#include "Med.h"
#include "decimal.h"

using namespace std;

string skipFieldsNames(istream &is, string fieldName);
string boolToString(bool b);
bool boolFromString(string str);
Date dateFromString(string str); 
string getFileName(bool input);
string getString();
int getInt(int basic, int min = INT_MIN, int max = INT_MAX);
dec::decimal<2> getPrice(dec::decimal<2> basic, dec::decimal<2> min = dec::decimal_cast<2>(DEC_MIN_INT64), dec::decimal<2> max = dec::decimal_cast<2>(DEC_MAX_INT64));
Date getDate(Date basic);
Med getMed(int number = -1);
Med getMed(Med basicMed, int number = -1);