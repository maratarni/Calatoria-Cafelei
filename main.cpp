#include "functionsHelper.h"
using namespace std;
int main()
{

	std::cout << "Limba/Language?(Romana/ Enghish)" << endl;
	char limba[10];
	cin >> limba;
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		cout << "Buna ziua!\n";
	else
		cout << "Hello!" << endl;
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		cout << "In ce oras va aflati?\nIntroduceti un numar de la 1 la 5\n1)Bucuresti\n2)Cluj-Napoca\n3)Timisoara\n4)Iasi\n5)Brasov\n";
	else
		cout << "In which city are you located?\nEnter a number from 1 to 5\n1) Bucharest\n2) Cluj-Napoca\n3) Timisoara\n4) Iasi\n5) Brasov\n";
	int oras;
	cin >> oras;
	cin.get();
	char numeOras[21];
	if (oras == 1)
	{
		strcpy(numeOras, "Bucuresti");
	}
	if (oras == 2)
	{
		strcpy(numeOras, "Cluj-Napoca");
	}
	if (oras == 3)
	{
		strcpy(numeOras, "Timisoara");
	}
	if (oras == 4)
	{
		strcpy(numeOras, "Iasi");
	}
	if (oras == 5)
	{
		strcpy(numeOras, "Brasov");
	}
	numeOras[strlen(numeOras)] = '\0';
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "Sunteti Ospatar, Barista sau Manager?\n";
		cout << "Functie: ";
	}
	else
	{
		cout << "Are you a Waiter, Barista or Manager?\n";
		cout << "Function: ";
	}

	char pozitie[20];
	cin >> pozitie;
	while (1)
	{
		if ((strcmp(pozitie, "Ospatar") == 0 || strcmp(pozitie, "ospatar") == 0 || strcmp(pozitie, "OSPATAR") == 0))
		{
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Regulile sunt simple! " << endl;
				cout << "Ii aduci la cunostiinta meniul: " << endl;
				cout << "Intrebi clientul ce isi doreste, verifici in baza de date daca ai ingredientele pentru a prepara acel produs:" << endl;
				cout << "Daca nu, il intrebi pana gaseste ceva in stoc, daca nu vrea nimic, ii urezi: O zi buna!" << endl;
				cout << "Succes azi!" << endl;
			}
			else
			{
				cout << "The rules are simple!" << endl;
				cout << "You inform the client about the menu:" << endl;
				cout << "Ask the client what they want, check the database if you have the ingredients to prepare the product:" << endl;
				cout << "If not, ask until they find something in stock, if they don’t want anything, you wish them: Have a good day!" << endl;
				cout << "Good luck today!" << endl;
			}
			break;
		}
		else if (strcmp(pozitie, "Barista") == 0 || strcmp(pozitie, "barista") == 0 || strcmp(pozitie, "BARISTA") == 0)
		{
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Regulile sunt simple! " << endl;
				cout << "Poti sterge si adauga produse in sistem!!" << endl;
				cout << "Te rog sa adaugi atat produsele cat si ingredientele cu denumirea in romana/in engleza in aceasta ordine" << endl;
				cout << "RETETELE tu le introduci cand introduci si un produs!" << endl;
				cout << "Prepari cat mai repede toate produsele pe care ti le transmite Ospatarul!" << endl;
				cout << "Succes azi!" << endl;
			}
			else
			{
				cout << "The rules are simple!" << endl;
				cout << "You can delete and add products to the system!!" << endl;
				cout << "Please add both the products and the ingredients with the names in Romanian/English in this order" << endl;
				cout << "You introduce the RECIPES when you add a product!" << endl;
				cout << "You prepare all products the Waiter gives you as quickly as possible!" << endl;
				cout << "Good luck today!" << endl;
			}
			break;
		}
		else if (strcmp(pozitie, "Manager") == 0 || strcmp(pozitie, "manager") == 0)
		{
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Regulile sunt simple! " << endl;
				cout << "POTI ADAUGA, STERGE, AFISA TOTI ANGAJATII" << endl;
				cout << "Evenimentele speciale sunt domeniul tau, poti adauga cate vrei si sa alegi ce produse vinzi la acele evenimente!" << endl;
				cout << "Succes azi!" << endl;
			}
			else
			{
				cout << "The rules are simple!" << endl;
				cout << "YOU CAN ADD, DELETE, DISPLAY ALL EMPLOYEES" << endl;
				cout << "Special events are your domain, you can add as many as you want and choose what products to sell at those events!" << endl;
				cout << "Good luck today!" << endl;
			}
			break;
		}
		else
		{
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Nu exista functia pe care ati introdus-o. Incercati din nou: ";
			}
			else
			{
				cout << "The position you entered does not exist. Try again: ";
			}
			cin >> pozitie;
		}
	}
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "_________________________________" << endl;
		cout << "Ati inteles?" << endl;
		cout << "Daca da, apasa 1 si succes astazi!!" << endl;
		cout << "_________________________________" << endl;
	}
	else
	{
		cout << "_________________________________" << endl;
		cout << "Did you understand?" << endl;
		cout << "If yes, press 1 and good luck today!!" << endl;
		cout << "_________________________________" << endl;
	}
	//aici am adugat un pic ceva cu functiile


	int numar;
	cin >> numar;
	bool ok1 = true;
	while (ok1 == true)
	{
		if (numar == 1)
		{
			system("cls");
			ok1 = false;
		}
		else
		{
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Nu ati introdus o varianta valida!" << endl;
				cout << "Introduceti din nou tasta 1 daca ati inteles: ";
				cin >> numar;
			}
			else
			{
				cout << "You have not entered a valid option!" << endl;
				cout << "Enter key 1 again if you understood: ";
				cin >> numar;
			}

		}
	}

	char denumireFisier[51] = "angajatiSiFunctii";
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream f(denumireFisier);
	//if (f.is_open())
	//{
	//	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	//	{
	//		cout << "Deschidere cu succes al fisierului"<<endl;
	//	}
	//	else
	//	{
	//		cout << "Successful opening of the file!" << endl;
	//	}
	//	
	//}
	//else {
	//	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	//	{
	//		cout << "Nu s-a putut deschide fisierul" << endl;
	//	}
	//	else
	//	{
	//		cout << "The file could not be opened" << endl;
	//	}
	//}
	strcpy(denumireFisier, "ingrediente");
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream g(denumireFisier);
	//verificari care merg
	//if (g.is_open())
	//	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	//	{
	//		cout << "Deschidere cu succes al fisierului" << endl;
	//	}
	//	else
	//	{
	//		cout << "Successful opening of the file!" << endl;
	//	}
	strcpy(denumireFisier, "produseSiPreturi");
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream h(denumireFisier);
	//if (h.is_open())
	//{
	//	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	//	{
	//		cout << "Deschidere cu succes al fisierului" << endl;
	//	}
	//	else
	//	{
	//		cout << "Successful opening of the file!" << endl;
	//	}
	//}

	Angajat* a[50];//vector de obiecte neomogene
	int nr_angajati;
	vectorAngajatiSiFunctii(f, a, nr_angajati);

	int optiune;
	bool running = true;
	while (running == true && (strcmp(pozitie, "Manager") == 0 || strcmp(pozitie, "manager") == 0)) {
		// Meniu interactiv
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "\nAlegere:\n";
			cout << "1. Adauga un angajat\n";
			cout << "2. Sterge un angajat\n";
			cout << "3. Afisare angajati \n";
			cout << "4. Organizeaza eveniment\n";
			cout << "5. Iesire\n";
			cout << "Alege optiunea (1, 2, 3, 4, 5): ";
		}
		else
		{
			cout << "\nChoice:\n";
			cout << "1. Add an employee\n";
			cout << "2. Delete an employee\n";
			cout << "3. Display employees \n";
			cout << "4. Organize event\n";
			cout << "5. Output\n";
			cout << "Choose option (1, 2, 3, 4, 5): ";
		}

		strcpy(denumireFisier, "evenimente");
		strcat(denumireFisier, "_");
		strcat(denumireFisier, numeOras);
		strcat(denumireFisier, ".csv");
		ofstream evenimenteo(denumireFisier, ios::app);
		Produse* ajutorp = new Produse[50];
		int nr_evenimente = 0;
		Evenimente* ajutore = new Evenimente[50];

		cin >> optiune;

		if (optiune == 1) {
			introducereAngajati(a, nr_angajati, limba);  // Adaugare angajat
		}
		else if (optiune == 2) {
			stergereAngajati(a, nr_angajati, limba);  // Stergere angajat
		}
		else if (optiune == 3) {
			afisareAngajati(a, nr_angajati);
		}
		else if (optiune == 4) {
			int nr_produse = 0;
			citireProduse(h, ajutorp, nr_produse);
			adaugaEveniment(ajutore, nr_evenimente, ajutorp, nr_produse, evenimenteo, limba);
		}
		else if (optiune == 5) {
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Iesire din program" << endl;
			}
			else
			{
				cout << "Exit the program" << endl;
			}
			// Aici putem salva modificarile
			strcpy(denumireFisier, "angajatiSiFunctii");
			strcat(denumireFisier, "_");
			strcat(denumireFisier, numeOras);
			strcat(denumireFisier, ".csv");
			scrieAngajatiInFisier(denumireFisier, a, nr_angajati);
			running = false;
		}
		else {
			if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
			{
				cout << "Optiune invalida! Te rog, alege o optiune valida.\n";
			}
			else
			{
				cout << "Invalid option! Please choose a valid option.\n";
			}
			cin >> optiune;
		}
		delete[] ajutore;
		delete[] ajutorp;
	}
	ingredient* ingr = new ingredient[50];
	int nr_ingrediente;
	citireIngrediente(g, ingr, nr_ingrediente);

	Produse* produse = new Produse[50];
	int nr_produse;
	citireProduse(h, produse, nr_produse);

	char produseSiPreturi[41] = "produseSiPreturi";
	char ingredienteleProduselor[41] = "ingredienteleProduselor";
	char ingrediente[41] = "ingrediente";
	strcat(produseSiPreturi, "_");
	strcat(produseSiPreturi, numeOras);
	strcat(ingredienteleProduselor, "_");
	strcat(ingredienteleProduselor, numeOras);
	strcat(ingrediente, "_");
	strcat(ingrediente, numeOras);
	if (strcmp(pozitie, "Barista") == 0 || strcmp(pozitie, "barista") == 0)
	{
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Vreti sa adaugati vreun produs(Da/Nu)?\n";
		}
		else
		{
			cout << "Would you like to add a product (Yes/No)?\n";
		}

		char spune[3] = "";
		cin >> spune;

		if (strcmp(spune, "Da") == 0 || strcmp(spune, "da") == 0 || strcmp(spune, "Da") == 0 || strcmp(spune, "da") == 0)
		{
			while (true)
			{
				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Nume produs: ";
				}
				else
				{
					cout << "Product name: ";
				}

				char produsnou[41] = "";
				cin.ignore();
				cin.getline(produsnou, 41);

				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Pret: ";
				}
				else
				{
					cout << "Price: ";
				}

				double pretnou = 0;
				cin >> pretnou;

				adaugaProdus(produse, nr_produse, produsnou, pretnou, produseSiPreturi, ingredienteleProduselor, ingrediente, limba);
				afisareProduse(produse, nr_produse, limba);

				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Mai doriti sa adaugati un produs? (da/nu): ";
				}
				else
				{
					cout << "Would you like to add another product? (yes/no): ";
				}

				char raspuns[3] = "";
				cin >> raspuns;

				if (strcmp(raspuns, "nu") == 0 || strcmp(raspuns, "Nu") == 0 || strcmp(raspuns, "NU") == 0 ||
					strcmp(raspuns, "no") == 0 || strcmp(raspuns, "No") == 0 || strcmp(raspuns, "NO") == 0)
				{
					break;
				}
			}
		}

		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Vreti sa stergeti vreun produs(Da/Nu)?\n";
		}
		else
		{
			cout << "Would you like to delete a product (Yes/No)?\n";
		}

		char spune1[3] = "";
		cin >> spune1;

		if (strcmp(spune1, "Da") == 0 || strcmp(spune1, "da") == 0 || strcmp(spune1, "Yes") == 0 || strcmp(spune1, "yes") == 0)
		{
			while (true)
			{
				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Nume produs de sters: ";
				}
				else
				{
					cout << "Product name to delete: ";
				}

				char produsvechi[20] = "";
				cin >> produsvechi;

				stergeProdus(produse, nr_produse, produsvechi, produseSiPreturi, ingredienteleProduselor);
				afisareProduse(produse, nr_produse, limba);

				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Mai doriti sa stergeti un produs? (da/nu): ";
				}
				else
				{
					cout << "Would you like to delete another product? (yes/no): ";
				}

				char raspuns[3] = "";
				cin >> raspuns;

				if (strcmp(raspuns, "da") != 0 && strcmp(raspuns, "Da") != 0 && strcmp(raspuns, "DA") != 0 ||
					strcmp(raspuns, "yes") != 0 && strcmp(raspuns, "Yes") != 0 && strcmp(raspuns, "YES") != 0)
				{
					exit(1);
				}
			}
		}
	}

	int ok = 0;
	char nume_comenzi[51][51];
	int nr_comenzi = 0;
	strcpy(denumireFisier, "comenzi");
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream infile(denumireFisier);
	char line[1024];

	//if (!infile.is_open()) {
	//	cerr << "Nu am putut deschide fisierul comenzi.csv\n";
	//	return 1;
	//}

	while (infile.getline(line, sizeof(line)))
	{
		char* nume = strtok(line, ",");
		strcpy(nume_comenzi[nr_comenzi++], nume);
	}
	infile.close();

	ofstream ocomenzi(denumireFisier, ios::app);//sa scriu in el Nume + Cost total 
	if (strcmp(pozitie, "Ospatar") == 0 || strcmp(pozitie, "ospatar") == 0)
	{
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Buna ziua!" << endl;
			cout << "Va rog sa imi spuneti pe ce nume trec comanda:";
		}
		else
		{
			cout << "Good day!" << endl;
			cout << "Please tell me the name for the order:";
		}

		char numeClient[30];
		cin >> numeClient;

		ocomenzi << numeClient << ", ";
		int sePoate;
		double cost_total = 0;

		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Acesta este meniul: " << endl;
		}
		else
		{
			cout << "This is the menu: " << endl;
		}

		afisareProduse(produse, nr_produse, limba);

		while (1)
		{
			char produsClient[50]; // aici imi cere si daca am, pun in produseClient cu nume si cost total
			char produseClient[20][20];

			if (ok == 0)
			{
				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Ce doriti?" << endl;
				}
				else
				{
					cout << "What would you like?" << endl;
				}

				cin >> produsClient;
				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Sa verificam daca se poate prepara!" << endl;
				}
				else
				{
					cout << "Let's check if it can be prepared!" << endl;
				}

				verificareComenzi(ingr, nr_ingrediente, produsClient, sePoate, numeOras, limba);
				if (sePoate == 1)
				{
					ocomenzi << produsClient << ", ";
					cost_total = cost_total + afisarePretProdus(produse, nr_produse, produsClient);
				}
				ok++;
			}
			else
			{
				if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
				{
					cout << "Mai doriti ceva?(da/nu)" << endl;
				}
				else
				{
					cout << "Would you like anything else?{Yes/No)" << endl;
				}

				char dorinta[3] = "";
				cin >> dorinta;
				if (strcmp(dorinta, "da") == 0 || strcmp(dorinta, "Da") == 0 || strcmp(dorinta, "DA") == 0
					|| strcmp(dorinta, "yes") == 0 || strcmp(dorinta, "Yes") == 0 || strcmp(dorinta, "YES") == 0)
				{
					if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
					{
						cout << "Ce doriti?" << endl;
					}
					else
					{
						cout << "What would you like?" << endl;
					}

					cin >> produsClient;
					if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
					{
						cout << "Sa verificam daca se poate prepara!" << endl;
					}
					else
					{
						cout << "Let's check if it can be prepared!" << endl;
					}

					verificareComenzi(ingr, nr_ingrediente, produsClient, sePoate, numeOras, limba);
					if (sePoate == 1)
					{
						ocomenzi << produsClient << ", ";
						cost_total = cost_total + afisarePretProdus(produse, nr_produse, produsClient);
					}
				}
				else
				{
					int nrnume = 0;
					for (int i = 0; i < nr_comenzi; i++)
					{
						if (strcmp(numeClient, nume_comenzi[i]) == 0)
							nrnume++;
					}

					if (nrnume >= 3)
					{
						if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
						{
							cout << "Aceasta este nota de plata: " << endl;
							cout << "Client fidel->reducere 30%" << endl;
							cout << "____________________________________" << endl;
						}
						else
						{
							cout << "This is the bill: " << endl;
							cout << "Loyal customer -> 30% discount" << endl;
							cout << "____________________________________" << endl;
						}
						cost_total = cost_total - (cost_total * 30) / 100;
						cout << cost_total << " lei" << endl;
						cout << "____________________________________" << endl;
						ocomenzi << cost_total << endl;
					}
					else
					{
						if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
						{
							cout << "Aceasta este nota de plata: " << endl;
							cout << "____________________________________" << endl;
						}
						else
						{
							cout << "This is the bill: " << endl;
							cout << "____________________________________" << endl;
						}
						cout << cost_total << " lei" << endl;
						cout << "____________________________________" << endl;
						ocomenzi << cost_total << endl;
					}
					exit(1);
				}
			}
		}
	}
	/*ocomenzi.close();*/
	strcpy(denumireFisier, "evenimente");
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream file1(denumireFisier);
	strcpy(denumireFisier, "comenzi");
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ifstream file2(denumireFisier);
	strcpy(denumireFisier, "raportare");
	strcat(denumireFisier, "_");
	strcat(denumireFisier, numeOras);
	strcat(denumireFisier, ".csv");
	ofstream file3(denumireFisier);
	Comenzi* comenzi = new Comenzi[50];
	//file2.seekg(0, std::ios::beg);
	citireComenzi(file2, comenzi, nr_comenzi);
	if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
	{
		cout << "E gata ziua? Afisam raportul? (da/nu)";
	}
	else
	{
		cout << "Is the day ready? Show the schedule? (yes/no)";
	}
	char raport[11];
	cin >> raport;

	if (strcmp(raport, "da") == 0 || strcmp(raport, "Da") == 0 || strcmp(raport, "DA") == 0
		|| strcmp(raport, "yes") == 0 || strcmp(raport, "Yes") == 0 || strcmp(raport, "YES") == 0)
	{
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "RAPORT ZILNIC" << endl;
		}
		else
		{
			cout << "DAILY REPORT" << endl;
		}

		raportFinal(file1, file2, file3, produse, nr_produse, a, nr_angajati, comenzi, nr_comenzi, limba);
	}
	else
	{
		if (strcmp(limba, "Romana") == 0 || strcmp(limba, "romana") == 0 || strcmp(limba, "ROMANA") == 0)
		{
			cout << "Spor in continuare!" << endl;
		}
		else
		{
			cout << "Good luck with the rest!" << endl;
		}
	}

	delete[] ingr;
	delete[] produse;

	return 0;
}