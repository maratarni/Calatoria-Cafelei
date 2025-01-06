#include "ingredient.h"

void ingredient::setAll(char nume[], double cantitate)
{
	strcpy(this->nume, nume);
	this->cantitate = cantitate;
}

char* ingredient::getNume()
{
	return this->nume;
}

void ingredient::setCantitate(double cantitate)
{
    this->cantitate = cantitate;
}

double ingredient::getCantitate()
{
	return this->cantitate;
}

void ingredient::adauga(double cantitateAdaugata)
{
	this->cantitate = this->cantitate + cantitateAdaugata;
}

void ingredient::elimina(double cantitateEliminata)
{
    try//EXCEPTIONS
    {
        if (cantitateEliminata <= cantitate) {
            this->cantitate -= cantitateEliminata;
        }
        else {
            throw runtime_error("Cantitate insuficienta");
        }
    }
    catch (const runtime_error& e)
    {
        cout << "Am cumparat cantitatea suficienta";
        cout << e.what() << endl; // Afiseaza mesajul de eroare
        double cantitateNecesara = cantitateEliminata - this->cantitate;
        adauga(cantitateNecesara); // Completeaza cantitatea
        this->cantitate = 0; // Seteazs cantitatea la zero
    }
}

