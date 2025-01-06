#include "Manager.h"


Manager::Manager(char nume[],char functie[], int oraInceput, int oraFinal)
{
	setAll(nume, functie, oraInceput, oraFinal);
}


double Manager::calculeazaSalariu()//POLIMORFISM
{
	int oreLucrate = getOraFinal() - getOraInceput();
	if (oreLucrate < 0) {
		oreLucrate += 24; 
	}
	double salariuBaza = oreLucrate * 30.0; // 30 lei ora pentru manageri
	return salariuBaza; // adaugam bonusul lunar
}

Manager::~Manager()
{
	cout << "Destructorul Manager a fost apelat" << endl;
}
