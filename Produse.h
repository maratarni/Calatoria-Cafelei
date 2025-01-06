#pragma once
#include"ingredient.h"
//CLASA
//INCAPSULARE
class Produse
{
private:
	ingredient i[100];//inheritance has many ::: asa se numeste
	char nume[40];
	double pret;
public:
	void setAll(char nume[], double cantitate);
	char* getNume();
	double getPret();
	
	void adauga(double cantitateAdaugata);
	void elimina(double cantitateEliminata);
	//bla bla afisez si ma duc sa verific dupa
};

