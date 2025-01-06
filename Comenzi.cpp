#include "Comenzi.h"

void Comenzi::setAll(char numeClient[], char produseComandate[30][30], float costTotal)
{
    strcpy(this->numeClient, numeClient);  
    for (int i = 0; i < 30; ++i) {
        strcpy(this->produseComandate[i], produseComandate[i]);  
    }
    this->costTotal = costTotal;  
}

char* Comenzi::getNumeClient()
{
    return this->numeClient;
}

char** Comenzi::getProduseComandate()
{
	return (char**)produseComandate;
}

double Comenzi::getCostTotal()
{
	return this->costTotal;
}
