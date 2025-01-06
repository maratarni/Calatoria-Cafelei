#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Produse.h"
#include <cstring>
using namespace std;
//INCAPSULARE
class Evenimente
{
private:
	char nume[50];
	double cost;
public:
	char* getNume();
	double getCost();
	void setNume(char nume[]);
	void setCost(double cost);
};

