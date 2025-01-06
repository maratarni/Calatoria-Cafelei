#pragma once
#include "Manager.h"
#include "Barista.h"
#include "Ospatar.h"
#include "Produse.h"
#include "Comenzi.h"
#include"Evenimente.h"
#include <string>
#include <vector>
#include<cstdio>
#include <iomanip>

class AngajatFactory {//DESIGN PATTERN-Abstract Factory
public:
	virtual ~AngajatFactory() = default;
	virtual Angajat* createAngajat( char nume[],char functie[], int oraInceput, int oraFinal) = 0;//ABSTRACTIZARE
};
class ConcreteAngajatFactory : public AngajatFactory {
public:
	Angajat* createAngajat(char nume[], char functie[], int oraInceput, int oraFinal) override {
		if (strcmp(functie, "Manager") == 0) {
			return new Manager(nume, functie, oraInceput, oraFinal);
		}
		else if (strcmp(functie, "Barista") == 0) {
			return new Barista(nume, functie, oraInceput, oraFinal);
		}
		else if (strcmp(functie, "Ospatar") == 0) {
			return new Ospatar(nume, functie, oraInceput, oraFinal);
		}
		return nullptr;
	}
};

void vectorAngajatiSiFunctii(ifstream& file, Angajat* a[], int& nr_angajati);
//aici implementam templates ca numai aici se poate
template <typename T>//TEMPLATE
void afisareAngajati(T angajati[], int nr_angajati) {
	for (int i = 0; i < nr_angajati; i++) {
		cout << "Nume: " << angajati[i]->getNume() << endl;
		cout << "Functie: " << angajati[i]->getFunctie() << endl;
		cout << "Ora Inceput: " << angajati[i]->getOraInceput() << ", Ora Final: " << angajati[i]->getOraFinal() << endl;
		cout << "Salariul: " << angajati[i]->calculeazaSalariu() << endl;
		cout << "--------------------------------" << endl;
	}
}
void stergereAngajati(Angajat* a[], int& nr_angajati, char limba[]);
void introducereAngajati(Angajat* a[], int& nr_angajati, char limba[]);
void scrieAngajatiInFisier(const char* numeFisier, Angajat* a[], int nr_angajati);
void citireIngrediente(ifstream& file, ingredient ingr[], int& nr_ingrediente);
void afisareIngrediente(ingredient ingr[], int nr_ingrediente, char limba[]);
void citireProduse(ifstream& file, Produse produse[], int& nr_produse);
void afisareProduse(Produse produse[], int nr_produse,char limba[]);
void scriereComenzi(ofstream& file, char nume[], double costTotal);
bool verificaSiActualizeaza(ingredient ingr[], int nr_ingrediente, const string& numeProdus,const vector<vector<string>>& produseSiIngrediente, char limba[]);//void scrieComandaInFisier(const string& numeFisier, const string& numeClient, const vector<string>& produse, float costTotal);
void verificareComenzi(ingredient ingr[], int nr_ingrediente, const char* numeProdus, int &sePoate, const char denumireOras[], char limba[]);
void adaugaProdus(Produse produse[], int& nr_produse, char nume[], double pret, const char* fileName, const char* fileName2, const char* fileName3,char limba[]);
void stergeProdus(Produse produse[], int& nr_produse, char nume[], const char* fileName, const char* fileName1);
double afisarePretProdus(Produse produse[], int nr_produse, char numeprodus[]);
void citireComenzi(ifstream& file, Comenzi comenzi[], int& nr_comenzi);
int clientFidel(Comenzi comenzi[], int nr_comenzi, char nume[]);
void adaugaEveniment(Evenimente evenimente[], int& nr_evenimente, Produse produse[], int nr_produse, ofstream& file, char limba[]);
void raportFinal(ifstream& file1, ifstream& file2,ofstream& file3, Produse produse[], int nr_produse, Angajat *a[], int nr_angajati, Comenzi comenzi[], int nr_comenzi, char limba[]);