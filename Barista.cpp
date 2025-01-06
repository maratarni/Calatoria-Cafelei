#include "Barista.h"

Barista::Barista(char nume[], char functie[], int oraInceput, int oraFinal) {
	setAll(nume, functie, oraInceput, oraFinal);
}

double Barista::calculeazaSalariu()//POLIMORFISM
{
	int oreLucrate = this->getOraFinal() - this->getOraInceput(); // Diferenta intre ore
	if (oreLucrate < 0) { // Daca ora de finalizare este mai mica decat cea de început
		oreLucrate += 24; // Adaugam 24 pentru o zi completa
	}
	double salariuBaza = oreLucrate * 20.0; // Presupunem 20 lei/ora
	return salariuBaza;
}

Barista::~Barista()
{
	//nu trebuie adaugat nimic pentru ca el are rolul de a distruge,putem pune un mesaj 
	cout << "Destructorul Barista a fost apelat." << endl;
}

