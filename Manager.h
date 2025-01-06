#pragma once
#include "Angajat.h"
//CLASA
class Manager : public Angajat {//MOSTENIRE
public:
    Manager(char nume[], char functie[], int oraInceput, int oraFinal);//CONSTRUCTOR
    void setEventimente(int evenimeteGestionate);
    double calculeazaSalariu() override; // Suprascrie metoda de calcul salariu
    ~Manager(); // DESTRUCTOR
};

