#include <iostream>
#include "alberobinarray.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void inserisciNodoCasuale(alberoBinArray<int>& albero, typename alberoBinArray<int>::posizione p, int valore) {
	if (albero.sinistroVuoto(p) && albero.destroVuoto(p)) {
		if (rand() % 2 == 0)
			albero.insFiglioSinistro(p, valore);
		else
			albero.insFiglioDestro(p, valore);
	} else
		if (albero.sinistroVuoto(p))
			albero.insFiglioSinistro(p, valore);
		else
			if (albero.destroVuoto(p))
				albero.insFiglioDestro(p, valore);
			else {
				if (rand() % 2 == 0)
					inserisciNodoCasuale(albero, albero.figlioSinistro(p), valore);
				else
					inserisciNodoCasuale(albero, albero.figlioDestro(p), valore);
			}
}

void test(alberoBinArray<int>& albero) {
	if (albero.partial_complete(albero.binRadice())) {
		cout << "L'albero è parzialmente completo." << endl;
	} else {
		cout << "L'albero non è parzialmente completo." << endl;
	}
	cout << endl;
}

int main() {

	cout << endl << endl << "----------------------------------------------------------" << endl << endl;

	srand(time(NULL));

	cout << "TEST ALBERO VUOTO" << endl << endl;

	alberoBinArray<int> albero0;

	cout << "ALBERO:" << endl;
	cout << albero0 << endl << endl;

	test(albero0);

	cout << "FINE TEST ALBERO VUOTO" << endl << endl;

	cout << "----------------------------------------------------------" << endl << endl;

	//----------------------------------------------------------------------------------------------

	cout << "----------------------------------------------------------" << endl << endl;

	cout << "TEST ALBERO CON SOLA RADICE" << endl << endl;

	alberoBinArray<int> albero1;
	albero1.insBinRadice(1);

	cout << "ALBERO:" << endl;
	cout << albero1 << endl << endl;

	test(albero1);

	cout << "FINE TEST ALBERO CON SOLA RADICE" << endl << endl;

	cout << "----------------------------------------------------------" << endl << endl;

	//----------------------------------------------------------------------------------------------

	cout << "----------------------------------------------------------" << endl << endl;

	cout << "TEST ALBERO CON RADICE E FIGLIO SINISTRO" << endl << endl;

	alberoBinArray<int> albero2;
	albero2.insBinRadice(1);
	albero2.insFiglioSinistro(albero2.binRadice(), 2);

	cout << "ALBERO:" << endl;
	cout << albero2 << endl << endl;

	test(albero2);
	
	cout << "FINE TEST ALBERO CON RADICE E FIGLIO SINISTRO" << endl << endl;

	cout << "----------------------------------------------------------" << endl << endl;

	//----------------------------------------------------------------------------------------------

	cout << "----------------------------------------------------------" << endl << endl;

	cout << "TEST ALBERO CON RADICE E FIGLIO DESTRO" << endl << endl;

	alberoBinArray<int> albero3;
	albero3.insBinRadice(1);
	albero3.insFiglioDestro(albero3.binRadice(), 2);

	cout << "ALBERO:" << endl;
	cout << albero3 << endl << endl;

	test(albero3);

	cout << "FINE TEST ALBERO CON RADICE E FIGLIO DESTRO" << endl << endl;

	cout << "----------------------------------------------------------" << endl << endl;

	//----------------------------------------------------------------------------------------------

	cout << "----------------------------------------------------------" << endl << endl;

	cout << "TEST ALBERO CON RADICE E FIGLI SINISTRO E DESTRO" << endl << endl;

	alberoBinArray<int> albero4;
	albero4.insBinRadice(1);
	albero4.insFiglioSinistro(albero4.binRadice(), 2);
	albero4.insFiglioDestro(albero4.binRadice(), 3);

	cout << "ALBERO:" << endl;
	cout << albero4 << endl << endl;

	test(albero4);

	cout << "FINE TEST ALBERO CON RADICE E FIGLI SINISTRO E DESTRO" << endl << endl;

	cout << "----------------------------------------------------------" << endl << endl;
	
	//----------------------------------------------------------------------------------------------

	cout << "----------------------------------------------------------" << endl << endl;

	cout << "TEST ALBERO CON NUMERO DI NODI SCELTO DALL'UTENTE E DISPOSTI CASUALMENTE" << endl << endl;

	alberoBinArray<int> albero5;
	// Chiede il numero di nodi da inserire nell'albero
	int numNodi;
	cout << "Inserisci il numero di nodi da inserire nell'albero: ";
	cin >> numNodi;
    cout << endl;
	// Riempie l'albero con nodi casuali
	for (int i = 0; i < numNodi; ++i) {
		int numero_casuale = rand() % 10;

		if (albero5.binAlberoVuoto())
			albero5.insBinRadice(numero_casuale);
		else
			inserisciNodoCasuale(albero5, albero5.binRadice(), numero_casuale);
	}

	cout << "ALBERO:" << endl;
	cout << albero5 << endl << endl;

	test(albero5);

	cout << "FINE TEST ALBERO CON NUMERO DI NODI SCELTO DALL'UTENTE E DISPOSTI CASUALMENTE" << endl << endl;

	cout << "----------------------------------------------------------" << endl << endl;

	//----------------------------------------------------------------------------------------------

	return 0;
}
