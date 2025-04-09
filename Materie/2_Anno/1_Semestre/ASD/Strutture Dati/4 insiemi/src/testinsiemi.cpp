#include <iostream>

#include "insieme.h"
#include "eccezioniInsiemi.h"

using namespace std;


int main(){
	insieme<int> insieme1;
	
	insieme1.inserisci(1);
	
	insieme1.inserisci(2);
	
	insieme1.inserisci(4);
	
	try{
		insieme1.inserisci(4);
	}
	catch (const elementoPresente& e) {
		cout << "ELEMENTO GIA' PRESENTE" << endl;
	}
	
	insieme1.cancella(4);
	
	cout << " Il primo insieme e': " << insieme1 << endl;
	
	insieme<int> insieme2;
	
	insieme2.inserisci(4);
	
	insieme2.inserisci(5);
	
	insieme2.inserisci(6);
	
	cout << " Il secondo insieme e': " << insieme2 << endl;
	
	insieme1.unione(insieme2);
	
	cout << " L'unione dei due insiemi e': " << insieme1 << endl;
	
	insieme1.intersezione(insieme2);
	
	cout << " L'instersezione tra l'unione dei due insiemi e': " << insieme1 << endl;
	
	insieme1.differenza(insieme2);
	
	cout << " La differenza tra l'intersezione tra l'unione dei due insiemi e':(dovrebbe essere nulla) " << insieme1 << endl;
	
	return 0;
}
