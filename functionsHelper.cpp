#include"functionsHelper.h"
using namespace std;
void vectorAngajatiSiFunctii(ifstream& file, Angajat* a[], int& nr_angajati)
{
	ConcreteAngajatFactory factory;
	nr_angajati = 0;
	while (file.good())
	{
		char nume[30] = "";
		char functie[20] = "";
		int oraInceput = 0, oraFinal = 0;
		char line[101];
		file.getline(line, 101);
		//cout << line;
		char* p;
		int nr = 0;
		p = strtok(line, ",");
		while (p)
		{
			if (nr == 0)
				strcpy(nume, p);
			if (nr == 1)
			{
				strcpy(functie, p);
			}
			if (nr == 2)
				oraInceput = atoi(p);
			if (nr == 3)
				oraFinal = atoi(p);
			nr++;
			p = strtok(NULL, ", ");
		}

		Angajat* angajat = factory.createAngajat(nume, functie, oraInceput, oraFinal);
		if (angajat != nullptr) {
			angajat->setSalariu(angajat->calculeazaSalariu());
			a[nr_angajati++] = angajat;
		}
	}

}

void stergereAngajati(Angajat* a[], int& nr_angajati, char limba[]) {
	char nume[30];
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Introduceti numele angajatului de sters: ";
		cout << "Nume: ";
	}
	else
	{
		cout << "Enter the name of the employee to delete: ";
		cout << "Name: ";
	}

	cin.ignore();
	cin.getline(nume, 20);

	for (int i = 0; i < nr_angajati; i++) {
		if (strcmp(a[i]->getNume(), nume) == 0) {
			// Salvam detaliile angajatului de sters
			char* functie = a[i]->getFunctie();
			int oraInceput = a[i]->getOraInceput();
			int oraFinal = a[i]->getOraFinal();

			// Redistribuim orele catre ceilalti angajati cu aceeasi functie
			for (int j = 0; j < nr_angajati; j++) {
				if (j != i && strcmp(a[j]->getFunctie(), functie) == 0) {

					// Redistribuim orele: setam ora inceput minima si ora finala maxima
					a[j]->setAll(
						a[j]->getNume(),
						a[j]->getFunctie(),
						min(a[j]->getOraInceput(), oraInceput),
						max(a[j]->getOraFinal(), oraFinal)
					);
				}
			}

			// stergem angajatul din memorie
			delete a[i];

			// Mutam restul elementelor cu o pozitie inapoi
			for (int j = i; j < nr_angajati - 1; j++) {
				a[j] = a[j + 1];
			}

			nr_angajati--;
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Angajatul a fost sters cu succes.\n";
			}
			else
			{
				cout << "The employee was successfully deleted.\n";
			}
			return;
		}

	}
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Angajatul nu a fost gasit.\n";
		cout << "Introduceti un angajat valid.\n";
	}
	else
	{
		cout << "The employee was not found.\n";
		cout << "Enter a valid employee.\n";
	}


}

void introducereAngajati(Angajat* a[], int& nr_angajati, char limba[]) {
	char nume[20];
	char functie[20];
	int oraInceput, oraFinal;

	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
		cout << "Nume: ";
	}
	else {
		cout << "Name: ";
	}
	cin.ignore();
	cin.getline(nume, 20);

	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
		cout << "Functie (Manager/Barista/Ospatar): ";
	}
	else {
		cout << "Position (Manager/Barista/Waiter): ";
	}
	cin >> functie;

	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
		cout << "Ora inceput (0-24): ";
	}
	else {
		cout << "Start hour (0-24): ";
	}
	cin >> oraInceput;

	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
		cout << "Ora final (0-24): ";
	}
	else {
		cout << "End hour (0-24): ";
	}
	cin >> oraFinal;

	if (oraInceput < 0 || oraInceput > 24 || oraFinal < 0 || oraFinal > 24) {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
			cout << "Ore invalide!\n";
		}
		else {
			cout << "Invalid hours!\n";
		}
		return;
	}

	if (strcmp(functie, "Manager") == 0) {
		a[nr_angajati] = new Manager(nume, functie, oraInceput, oraFinal);
	}
	else if (strcmp(functie, "Barista") == 0) {
		a[nr_angajati] = new Barista(nume, functie, oraInceput, oraFinal);
	}
	else if (strcmp(functie, "Ospatar") == 0 || strcmp(functie, "Waiter") == 0) {
		a[nr_angajati] = new Ospatar(nume, functie, oraInceput, oraFinal);
	}
	else {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
			cout << "Functie invalida!\n";
		}
		else {
			cout << "Invalid position!\n";
		}
		return;
	}

	nr_angajati++;
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0) {
		cout << "Angajat adaugat cu succes.\n";
	}
	else {
		cout << "Employee added successfully.\n";
	}

}
void scrieAngajatiInFisier(const char* numeFisier, Angajat* a[], int nr_angajati) {
	ofstream f(numeFisier);  // Deschidem fisierul în modul scriere
	//if (!f.is_open()) {
	//	cout << "Nu s-a putut deschide fisierul pentru scriere.\n";
	//	return;
	//}

	// Scriem fiecare angajat în fisier
	for (int i = 0; i < nr_angajati; i++) {
		// Salvam numele, functia, ora de inceput si ora de final
		f << a[i]->getNume() << ","
			<< a[i]->getFunctie() << ","
			<< a[i]->getOraInceput() << ","
			<< a[i]->getOraFinal() << endl;
	}

	f.close();  // inchidem fisierul

}

void afisareIngrediente(ingredient ingr[], int nr_ingrediente, char limba[])
{
	cout << "--------------------------------" << endl;
	for (int i = 0; i < nr_ingrediente; i++) {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Nume: " << ingr[i].getNume() << endl;
			cout << "Cantitate: " << ingr[i].getCantitate() << endl;
		}
		else
		{
			cout << "Name: " << ingr[i].getNume() << endl;
			cout << "Quantity: " << ingr[i].getCantitate() << endl;
		}

	}
	cout << "--------------------------------" << endl;
}

void citireProduse(ifstream& file, Produse produse[], int& nr_produse)
{
	nr_produse = 0;
	char line[101];

	while (file.getline(line, 101)) // Citim fiecare linie
	{
		if (strlen(line) == 0) // Sarim peste liniile goale
			continue;

		char nume[30];
		double pret = 0;
		char* p = strtok(line, ",");
		int nr = 0;

		while (p)
		{
			if (nr == 0)
				strcpy(nume, p);
			else if (nr == 1)
				pret = strtod(p, NULL);

			nr++;
			p = strtok(NULL, ", ");
		}

		if (nr >= 2) // Asiguram ca avem atat numele, cat si cantitatea
		{
			produse[nr_produse++].setAll(nume, pret);
		}
	}
}

void afisareProduse(Produse produse[], int nr_produse, char limba[])
{
	cout << "--------------------------------" << endl;
	for (int i = 0; i < nr_produse; i++) {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Nume: " << produse[i].getNume() << endl;
			cout << "Pret: " << produse[i].getPret() << endl;
		}
		else
		{
			cout << "Name: " << produse[i].getNume() << endl;
			cout << "Quantity: " << produse[i].getPret() << endl;
		}
	}
	cout << "--------------------------------" << endl;
}

//AICI AM RAMAS
void adaugaProdus(Produse produse[], int& nr_produse, char nume[], double pret, const char* fileName, const char* fileName2, const char* fileName3, char limba[]) {

	produse[nr_produse].setAll(nume, pret);
	nr_produse++;

	ofstream file((string(fileName) + ".csv").c_str(), ios::app);
	if (file.is_open()) {
		file << nume << ", " << pret << "\n";
		file.close();
	}
	else {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cerr << "Eroare la deschiderea fisierului principal.";
		}
		else
		{
			cerr << "Error opening main file.";
		}

	}


	int nr_nevoie = 0;
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Cate ingrediente ai nevoie pentru acest produs? ";
	}
	else
	{
		cout << "How many ingredients do you need for this product?";
	}

	cin >> nr_nevoie;


	ofstream file1((string(fileName2) + ".csv").c_str(), ios::app);
	ofstream file2((string(fileName3) + ".csv").c_str(), ios::app);

	if (file1.is_open() && file2.is_open()) {
		char numeIngredient[30];
		double cantitate;

		file1 << nume << ", " << nr_nevoie << ", ";

		for (int i = 0; i < nr_nevoie; i++) {
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Introduceti ingredientul: ";
			}
			else
			{
				cout << "Enter the ingredient: ";
			}
			cin >> numeIngredient;

			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Introduceti cantitatea pentru " << numeIngredient << ": ";
			}
			else
			{
				cout << "Enter the quantity for " << numeIngredient << ": ";
			}

			cin >> cantitate;

			file1 << numeIngredient;
			file2 << numeIngredient << ", " << cantitate << "\n";

			if (i < nr_nevoie - 1) {
				file1 << ", ";
			}
		}

		file1 << "\n";
		file1.close();
		file2.close();
	}
	else {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cerr << "Eroare la deschiderea fisierului principal.";
		}
		else
		{
			cerr << "Error opening main file.";
		}
	}
}


void stergeProdus(Produse produse[], int& nr_produse, char nume[], const char* fileName, const char* fileName1) {
	// aici stergem din produseSiPreturi.csv
	int index = -1;
	for (int i = 0; i < nr_produse; i++) {
		if (strcmp(produse[i].getNume(), nume) == 0) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		for (int i = index; i < nr_produse - 1; i++) {
			produse[i] = produse[i + 1];
		}
		nr_produse--;

		ofstream file((string(fileName) + ".csv").c_str());
		if (file.is_open()) {
			for (int i = 0; i < nr_produse; i++) {
				file << produse[i].getNume() << "," << produse[i].getPret() << "\n";
			}
			file.close();
		}
	}

	// aici stergem din ingredienteleProduselor.csv
	ifstream fileIn((string(fileName1) + ".csv").c_str());
	ofstream tempFile("temp.csv"); // fisier temporar pentru a salva datele filtrate

	if (fileIn.is_open() && tempFile.is_open()) {
		string line;
		while (getline(fileIn, line)) {
			// Parcurge linia caracter cu caracter
			string produs;
			for (char ch : line) {
				if (ch == ',') break; // se opreste ela prima virgula
				produs += ch;
			}


			if (produs != nume) {
				tempFile << line << "\n";
			}
		}

		fileIn.close();
		tempFile.close();

		remove((string(fileName1) + ".csv").c_str());
		rename("temp.csv", (string(fileName1) + ".csv").c_str());
	}
}

double afisarePretProdus(Produse produse[], int nr_produse, char numeprodus[]) {
	for (int i = 0; i < nr_produse; i++) {
		if (strcmp(numeprodus, produse[i].getNume()) == 0) {
			return produse[i].getPret();
		}
	}
	return 0.0;
}

void citireComenzi(ifstream& file, Comenzi comenzi[], int& nr_comenzi)
{
	nr_comenzi = 0;
	char line[101];
	while (file.getline(line, 101))
	{

		if (strlen(line) == 0)
			continue;

		char nume[50] = "";
		char listaProduse[30][30] = { {0} };
		float costTotal = 0;

		char* p = strtok(line, ",");
		int nr = 0;
		int nrProduse = 0;

		while (p)
		{
			//eliminam spatiile 
			while (*p == ' ') p++;

			if (nr == 0) // Primul element este numele
			{
				strcpy(nume, p);
			}
			else if (p[strspn(p, "0123456789.")] == '\0')
			{
				costTotal = atof(p);
				break;
			}
			else // Este un produs
			{
				strcpy(listaProduse[nrProduse], p);
				nrProduse++;
			}

			nr++;
			p = strtok(NULL, ",");
		}

		comenzi[nr_comenzi].setAll(nume, listaProduse, costTotal);
		//cout << "Sunt in functie si afisez de aici ceva:";
		//cout << comenzi[nr_comenzi].getCostTotal() << endl;
		nr_comenzi++;
	}
}


int clientFidel(Comenzi comenzi[], int nr_comenzi, char nume[])
{
	int i;
	int nr = 0;
	for (i = 0; i < nr_comenzi; i++)
	{
		if (strcmp(nume, comenzi[i].getNumeClient()) == 0)
			nr++;
	}
	if (nr >= 3)
		return 1;
	return 0;
}

void scriereComenzi(ofstream& file, char nume[], double costTotal)
{
	file << nume << ", " << costTotal;
}

bool verificaSiActualizeaza(ingredient ingr[], int nr_ingrediente, const string& numeProdus,
	const vector<vector<string>>& produseSiIngrediente, char limba[]) {
	vector<string> ingredienteNecesare;
	bool produsGasit = false;

	for (size_t i = 0; i < produseSiIngrediente.size(); i++) {
		if (produseSiIngrediente[i][0] == numeProdus) {
			produsGasit = true;
			for (size_t j = 2; j < produseSiIngrediente[i].size(); j++) {
				ingredienteNecesare.push_back(produseSiIngrediente[i][j]);
			}
			break;
		}
	}

	if (!produsGasit) {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Produsul " << numeProdus << " nu exista in meniul disponibil.\n";
		}
		else
		{
			cout << "The product " << numeProdus << " is not available anymore.\n";
		}
		return false;
	}

	for (size_t i = 0; i < ingredienteNecesare.size(); i++) {
		bool gasit = false;

		for (int j = 0; j < nr_ingrediente; j++) {
			if (ingr[j].getNume() == ingredienteNecesare[i]) {
				if (ingr[j].getCantitate() > 0) {
					gasit = true;
					break;
				}
				else {

					if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
					{
						cout << "NU se poate prepara " << numeProdus << " din cauza lipsei de "
							<< ingredienteNecesare[i] << endl;
					}
					else
					{
						cout << "Cannot prepare " << numeProdus << " due to the lack of "
							<< ingredienteNecesare[i] << endl;
					}
					return false;
				}
			}
		}

		if (!gasit) {
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Ingredientul " << ingredienteNecesare[i] << " nu este disponibil pentru: "
					<< numeProdus << endl;
			}
			else
			{
				cout << "The ingredient " << ingredienteNecesare[i] << " is not available for:  "
					<< numeProdus << endl;
			}

			return false;
		}
	}

	for (size_t i = 0; i < ingredienteNecesare.size(); i++) {
		for (int j = 0; j < nr_ingrediente; j++) {
			if (ingr[j].getNume() == ingredienteNecesare[i]) {
				ingr[j].setCantitate(ingr[j].getCantitate() - 1);
				break;
			}
		}
	}
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Se poate prepara " << numeProdus << endl;
	}
	else
	{
		cout << "It can be prepared " << numeProdus << endl;
	}
	return true;
}

void verificareComenzi(ingredient ingr[], int nr_ingrediente, const char* numeProdus, int& sePoate, const char numeOras[], char limba[]) {
	char denumireFisier[41] = "ingredienteleProduselor";
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream f(denumireFisier);
	sePoate = 1;
	if (!f.is_open()) {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cerr << "Eroare la deschiderea fisierului principal.";
		}
		else
		{
			cerr << "Error opening main file.";
		}
		return;
	}

	vector<vector<string>> produseSiIngrediente;
	char linie[101];

	while (f.getline(linie, 101)) {
		char* p = strtok(linie, ",");
		vector<string> produs;
		int numarIngrediente = 0;

		while (p) {
			if (numarIngrediente != 0) {
				while (*p == ' ') p++;
			}
			produs.push_back(string(p));
			numarIngrediente++;
			p = strtok(NULL, ",");
		}
		produseSiIngrediente.push_back(produs);
	}

	if (!verificaSiActualizeaza(ingr, nr_ingrediente, string(numeProdus), produseSiIngrediente, limba)) {
		sePoate = 0;
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Comanda nu poate fi procesata.\n";
		}
		else
		{
			cout << "The order cannot be processed.\n";
		}

	}
}

void citireIngrediente(ifstream& file, ingredient ingr[], int& nr_ingrediente)
{
	nr_ingrediente = 0;
	char line[101];

	while (file.getline(line, 101)) // Citim fiecare linie
	{
		if (strlen(line) == 0) // Sarim peste liniile goale
			continue;

		char nume[30];
		double cantitate = 0;
		char* p = strtok(line, ",");
		int nr = 0;

		while (p)
		{
			if (nr == 0)
				strcpy(nume, p);
			else if (nr == 1)
				cantitate = strtod(p, NULL);
			nr++;
			p = strtok(NULL, ", ");
		}

		if (nr >= 2) // Asiguram ca avem atat numele, cat si cantitatea
		{
			ingr[nr_ingrediente++].setAll(nume, cantitate);
		}
	}
}
void adaugaEveniment(Evenimente evenimente[], int& nr_evenimente, Produse produse[], int nr_produse, ofstream& file, char limba[])
{
	/*ofstream file("evenimente.csv", ios::app);*/
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Vrei sa ai azi eveniment? (da/nu): ";
	}
	else
	{
		cout << "Do you want to have an event today? (yes/no): ";
	}
	char raspuns[11];
	cin >> raspuns;

	if (strcmp(raspuns, "da") == 0 || strcmp(raspuns, "Da") == 0 || strcmp(raspuns, "yes") == 0 || strcmp(raspuns, "YES") == 0) {
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Ce eveniment vrei sa fie astazi?" << endl;
			cout << "Introdu numele evenimentului: ";
		}
		else
		{
			cout << "What event do you want to be today?" << endl;
			cout << "Enter event name: ";
		}

		char nume_eveniment[50];
		cin.ignore();
		cin.getline(nume_eveniment, 50);
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Ce ai nevoie? Introdu nr de produse si ce produse (ex: 3 produse: Cafea/Coffee, Suc/Juice, Biscuite/Biscuit):" << endl;
		}
		else
		{
			cout << "What do you need? Enter the number of products and which products (ex: 3 produse: Cafea/Coffee, Suc/Juice, BIscuite/Biscuit):" << endl;
		}
		int nrProduse;
		cin >> nrProduse;

		// Calcularea costului total al evenimentului
		double cost_total = 0;
		for (int i = 0; i < nrProduse; i++) {
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Introdu produsul " << i + 1 << ": ";
			}
			else
			{
				cout << "Enter the product" << i + 1 << ": ";
			}
			char produs[51];
			cin >> produs;
			double cost_produs;
			int bucati;
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Cantitatea: ";
			}
			else
			{
				cout << "Quantity: ";
			}

			cin >> bucati;
			bool produs_gasit = false;
			for (int j = 0; j < nr_produse; j++) {
				char* nume = produse[j].getNume();
				if (strcmp(produs, produse[j].getNume()) == 0) {
					cost_total += bucati * produse[j].getPret();
					produs_gasit = true;
					break;
				}
			}
			if (!produs_gasit) {
				cout << "Produsul introdus nu a fost gasit: " << produs << endl;
			}
		}


		evenimente[nr_evenimente].setNume(nume_eveniment);
		evenimente[nr_evenimente].setCost(cost_total);
		nr_evenimente++;

		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Costul total al evenimentului este: " << cost_total << " lei." << endl;
			cout << "Il organizam? (da/nu): ";
			char organizare[5];
			cin >> organizare;

			if (strcmp(organizare, "da") == 0 || strcmp(organizare, "Da") == 0) {
				cout << "Iuhu, sa inceapa petrecerea!" << endl;
				//adaug doar costul(doar atat am nevoie)
				file << cost_total << endl;
			}
			else {
				cout << "Nu am organizat evenimentul astazi." << endl;
				cout << "Vrei sa adaugi alt eveniment? (da/nu): ";
				cin >> raspuns;

				if (strcmp(raspuns, "da") == 0 || strcmp(raspuns, "Da") == 0) {
					adaugaEveniment(evenimente, nr_evenimente, produse, nr_produse, file, limba); // Apeleaza recursiv pentru a adauga alt eveniment
				}
				else {
					cout << "Alta data!" << endl;
				}
			}
		}
		else {
			cout << "The final price is: " << cost_total << " lei." << endl;
			cout << "Do you want to organize it?{yes/no): ";
			char organizare[11];
			cin >> organizare;

			if (strcmp(organizare, "yes") == 0 || strcmp(organizare, "yes") == 0) {
				cout << "Iuhu, let the party begin!" << endl;
				//adaug doar costul(doar atat am nevoie)
				file << cost_total << endl;
			}
			else {
				cout << "I didn't organize the event today." << endl;
				cout << "Do you want to add another event? (yes/no): ";
				cin >> raspuns;

				if (strcmp(raspuns, "yes") == 0 || strcmp(raspuns, "Yes") == 0) {
					adaugaEveniment(evenimente, nr_evenimente, produse, nr_produse, file, limba); // Apeleaza recursiv pentru a adauga alt eveniment
				}
				else {
					cout << "Another time!!" << endl;
				}
			}
		}

	}
}

void raportFinal(ifstream& file1, ifstream& file2, ofstream& file3, Produse produse[], int nr_produse, Angajat* a[], int nr_angajati, Comenzi comenzi[], int nr_comenzi, char limba[])
{
	double venit = 0;
	double profit = 0;

	int i;
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Numar comenzi: " << nr_comenzi << endl;
		for (i = 0; i < nr_comenzi; i++)
		{
			venit = venit + comenzi[i].getCostTotal();
		}
		cout << "Acestea este venitul de la comenzi: " << venit << endl;
		double numar;
		while (file1 >> numar)
		{
			venit = venit + numar;
		}
		cout << "Venitul total este: " << venit << endl;

		cout << "Costurile produselor:" << endl;
		for (i = 0; i < nr_produse; i++)
			cout << produse[i].getNume() << " " << produse[i].getPret() << endl;

		cout << "Acestea sunt numele si salariile angajatilor: " << endl;
		double salarii = 0;
		for (i = 0; i < nr_angajati; i++)
		{
			cout << a[i]->getNume() << " " << a[i]->getSalariu() << endl;
			salarii = salarii + a[i]->getSalariu();
		}
		cout << "Acum voi calcula PROFITUL in felul urmator: " << endl;
		cout << "Venituri(vanzarea pe parcursul zilei + veniturile evenimentelor) - salarii:" << endl;
		cout << venit - salarii;
		//aici scriu un csv daca e bine
		file3 << "Acesta este raportul zilnic:" << endl;
		file3 << "Venit total:" << venit << endl;
		file3 << "Salariile adunate:" << salarii << endl;
		file3 << "Profit:" << venit - salarii << endl;
	}
	else
	{
		cout << "Number of orders: " << nr_comenzi << endl;
		for (i = 0; i < nr_comenzi; i++)
		{
			venit = venit + comenzi[i].getCostTotal();
		}
		cout << "This is the income from the orders: " << venit << endl;
		double numar;
		while (file1 >> numar)
		{
			venit = venit + numar;
		}
		cout << "Total income is: " << venit << endl;

		cout << "Product costs:" << endl;
		for (i = 0; i < nr_produse; i++)
			cout << produse[i].getNume() << " " << produse[i].getPret() << endl;

		cout << "These are the names and salaries of the employees:" << endl;
		double salarii = 0;
		for (i = 0; i < nr_angajati; i++)
		{
			cout << a[i]->getNume() << " " << a[i]->getSalariu() << endl;
			salarii = salarii + a[i]->getSalariu();
		}
		cout << "Now I will calculate the PROFIT as follows:" << endl;
		cout << "Incomes (sales during the day + event revenues) - salaries:" << endl;
		cout << venit - salarii;
		//aici scriu un csv daca e bine
		file3 << "This is the daily report:" << endl;
		file3 << "Total income:" << venit << endl;
		file3 << "Collected salaries:" << salarii << endl;
		file3 << "Profit:" << venit - salarii << endl;
	}

	file1.close();
	file2.close();
	file3.close();
}
