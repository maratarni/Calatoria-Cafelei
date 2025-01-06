#include "Produse.h"

void Produse::setAll(char nume[], double pret)
{
	strcpy(this->nume, nume);
	this->pret= pret;
}

char* Produse::getNume()
{
	return this->nume;
}

double Produse::getPret()
{
    return this->pret;
}

void Produse::adauga(double pret)
{
	this->pret = this->pret + pret;
}

void Produse::elimina(double pretscazut)
{
    try
    {
        if (pretscazut <= pret) {
            this->pret -= pretscazut;
        }
        else {
            throw runtime_error("Cantitate insuficienta");
        }
    }
    catch (const runtime_error& e)
    {
        cout << "Am cumparat cantitatea suficienta";
        cout << e.what() << endl; // Afiseaza mesajul de eroare
        double cantitateNecesara = pretscazut - this->pret;
        adauga(cantitateNecesara); // Completeaza cantitatea
        this->pret = 0; // Seteazs cantitatea la zero
    }
}
