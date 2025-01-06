#include "Evenimente.h"

char* Evenimente::getNume()
{
	return this->nume;
}

double Evenimente::getCost()
{
	return this->cost;
}

void Evenimente::setNume(char nume[])
{
	strcpy(this->nume, nume);
}
void Evenimente::setCost(double cost)
{
	this->cost = cost;
}
