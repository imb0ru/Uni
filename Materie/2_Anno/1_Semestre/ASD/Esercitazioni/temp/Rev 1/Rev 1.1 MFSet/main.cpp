#include <cstdlib>
#include <iostream>
#include "MFSet.h"

using namespace std;

int main(int argc, char *argv[]){
	char risp = 's';
	int n = 0;
	tipoelem a, b;
	InsiemePtrN i;
	MFSet m;
	while ((risp == 's') || (risp == 'S')){
		n++;
		do{
			cout << "Inserisci elemento " << n << ": ";
			cin >> a;
		} while (i.appartiene(a));
		i.inserisci(a);
		do{
			cout << "Altri elementi? (S/N) ";
			cin >> risp;
		} while (!((risp == 's') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
	}
	cout << "Hai inserito " << n << " elementi" << endl;
	m.creaMFSet(i);
	cout << endl << "Fusione elementi:" << endl;
	risp = 's';
	while ((risp == 's') || (risp == 'S')){
		do{
			cout << "Inserisci elemento 1: ";
			cin >> a;
		} while (!i.appartiene(a));
		do{
			cout << "Inserisci elemento 2: ";
			cin >> b;
		} while (!i.appartiene(b));
		if (m.trova(a).radice() != m.trova(b).radice())
			m.fondi(a, b);
		else
			cout << a << " e " << b << " fanno parte della stessa componente" << endl;
		do{
			cout << "Altre fusioni? (S/N) ";
			cin >> risp;
		} while (!((risp == 's') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
	}
	cout << endl << "Stampa del MF set:" << endl;
	m.stampaMFSet();
	system("PAUSE");
	return 0;
}

