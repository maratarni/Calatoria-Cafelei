#pragma once
//bibliotecile de baza
#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#pragma warning (disable : 4996)
//INCAPSULARE
class Comenzi
{
private:
	char numeClient[50]="";
	char produseComandate[30][30] = {};
	float costTotal;
public:
	void setAll(char numeClient[], char produseComandate[30][30], float costTotal);
	char* getNumeClient();
	char** getProduseComandate();
	double getCostTotal();
};

