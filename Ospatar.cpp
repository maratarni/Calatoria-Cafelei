#pragma once
#include "Ospatar.h"

Ospatar::Ospatar(char nume[], char functie[], int oraInceput, int oraFinal)
{
    setAll(nume, functie, oraInceput, oraFinal);
}

double Ospatar::calculeazaSalariu()//POLIMORFISM
{
    int oreLucrate = getOraFinal() - getOraInceput();
    if (oreLucrate < 0) {
        oreLucrate += 24; // daca ora de final<ora de inceput
    }
    double salariuBaza = oreLucrate * 18.0; // 18 lei pt ospatari ora de lucru
    return salariuBaza; // salariu include si bacsisurile
}

Ospatar::~Ospatar()
{
    //cout << "Destructorul Ospatar a fost apelat"<<endl;
}
