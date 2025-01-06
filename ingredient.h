#pragma once
#include<iostream>
#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#pragma warning (disable : 4996)
//INCAPSULARE
using namespace std;
class ingredient
{
private:
	char nume[20];
	double cantitate;
public:
	void setAll(char nume[], double cantitate);
	char* getNume();
	void setCantitate(double cantitate);
	double getCantitate();
	void adauga(double cantitateAdaugata);
	void elimina(double cantitateEliminata);
};

