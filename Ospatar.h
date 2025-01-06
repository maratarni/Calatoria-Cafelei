#include "Angajat.h"
//CLASA
class Ospatar : public Angajat {///MOSTENIRE
public:

    Ospatar(char nume[], char functie[], int oraInceput, int oraFinal);//CONSTRUCTOR
    double calculeazaSalariu() override; // Suprascrie metoda de calcul salariu
    ~Ospatar(); // DESTRUCTOR
};

