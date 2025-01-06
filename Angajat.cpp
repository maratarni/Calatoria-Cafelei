#include "Angajat.h"

void Angajat::setAll(char nume[], char functie[], int oraInceput, int oraFinal)
{
	strcpy(this->nume, nume);
	strcpy(this->functie, functie);
	this->oraInceput = oraInceput;
	this->oraFinal = oraFinal;
}

char* Angajat::getNume()
{
	return this->nume;
}

char* Angajat::getFunctie()
{
	return this->functie;
}

int Angajat::getOraInceput()
{
	return this->oraInceput;
}
int Angajat::getOraFinal()
{
	return this->oraFinal;
}

void Angajat::setSalariu(double salariu)//POLIMORFISM
{
	salariu = this->calculeazaSalariu();
	this->salariu = salariu;
}

int Angajat::getSalariu()
{
	return this->salariu;
}
