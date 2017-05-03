#pragma once
#include <string>
#include "Med.h"

using namespace std;

string skipFieldsNames(istream &is);
string boolToString(bool b);
bool boolFromString(string str);
Date dateFromString(string str); 
void printMainMenu();
void printMenuConsoleFile();
void printMenuFind();
void printSearchTypeMenu();
void printActionMenu();