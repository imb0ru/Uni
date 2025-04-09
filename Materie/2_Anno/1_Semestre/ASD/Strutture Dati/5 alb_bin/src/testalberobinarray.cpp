#include <iostream>
#include <ctime>

#include "alberoBinArray.h"

using namespace std;


int main(){

	int a;

	srand((unsigned) time(NULL));
	
	alberoBinArray<int> a1;
	
	alberoBinArray<int> a2;
	
	a1.insBinRadice(1);
	
	a1.insFiglioSinistro(0, 2);
	
	a1.insFiglioDestro(0, 2);	

	a1.insFiglioSinistro(1, 3);
	a1.insFiglioDestro(2, 3);
	
	a1.scriviNodo(3, 4);
	a1.scriviNodo(4, 4);
	
	a1.cancSottoBinAlbero(2);
	
	a2.insBinRadice(40);
	
	for (int i=0; i<2; i++){
		a = rand()%10;
		a2.insFiglioDestro(i, a);
		a2.insFiglioSinistro(i, a);
	}
	
	cout << "ALBERO a2:" << endl << a2 << endl;
	
	cout << "ALBERO a1:" << endl << a1 << endl;
	
	a1.costrBinAlbero(a2, 0);
	
	cout << "LA FUSIONE E': " << endl << a1 << endl;


	alberoBinArray<int> cico;
	
	cico.insBinRadice(1);
	
	cico.insFiglioSinistro(0, 2);
	cico.insFiglioDestro(0, 3);
	cico.insFiglioSinistro(1, 4);
	cico.insFiglioDestro(1, 5);
	cico.insFiglioSinistro(2, 6);
	
	cout << cico << endl;
	
	cout << "Il fratello di 2 e' " << cico.getValore(cico.getFratello(1)) << endl;
	
	if (cico.valorePresente(5))
		cout << "Il 5 è presente!" << endl;
	else
		cout << "Il 5 non è presente"  << endl;
	
	cout << "Il 5 si trova in posizione " << cico.ricercaElemento(5) << endl;
	
	return (0);
}
