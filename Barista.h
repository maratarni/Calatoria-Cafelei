#pragma once
#include "Angajat.h"
//CLASA
class Barista:public Angajat//MOSTENIRE
{
public:
	Barista(char nume[], char functie[], int oraInceput, int oraFinal);//CONSTRUCTOR
	double calculeazaSalariu() override;//metoda virtuala
	~Barista();//DESTRUCTOR
};

