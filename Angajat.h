#pragma once

#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#pragma warning (disable : 4996)

using namespace std;

class Angajat
{
private://INCAPSULARE
	char nume[50]="";
	char functie[20]="";
	int oraInceput=0, oraFinal=0;
	double salariu=0;

public:
	void setAll(char nume[], char functie[], int oraInceput,int oraFinal);
	char* getNume();
	char* getFunctie();
	int getOraInceput();
	int getOraFinal();
	virtual double calculeazaSalariu() = 0; //FUNCTIE VIRTUALA=ABSTRACTIZARE
	virtual ~Angajat() {} // DESTRUCTOR
	void setSalariu(double salariu);
	int getSalariu();
};

