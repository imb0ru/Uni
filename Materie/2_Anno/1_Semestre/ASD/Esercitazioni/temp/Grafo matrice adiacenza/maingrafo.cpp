


// PROGRAMMA PER LA VERIFICA DEL FUNZIONAMENTO DEL GRAFO
// CON MATRICE DI ADIACENZA

#include <iostream>
#include <stdlib.h>
#include "Grafo.h"

int main(){
	int r;
   tipoelem zzz, www;
   Grafo rete;
   r=1;

   while (r<8)
   {
  		cout << "1)inserisci nodo 2)inserisci arco 3)elimina nodo 4)elimina arco\n";
   	cout << "5)mostra adiacenti 6)esiste nodo? 7)esiste arco? 8)esci\n";
   	cin >> r;
   	switch (r)
      {
   		case 1:
         	cout << "che nodo?\n"; cin >> zzz; cout << endl;
         	rete.insnodo(zzz);
         	break;
	   	case 2:
         	cout << "da che nodo?\n"; cin >> zzz; cout << endl;
         	cout << "a che nodo?\n"; cin >> www; cout << endl;
         	rete.insarco(zzz, www);
         	break;
      	case 3:
         	cout << "che nodo?\n"; cin >> zzz; cout << endl;
         	rete.cancnodo(zzz);
         	break;
      	case 4:
      		cout << "da che nodo?\n"; cin >> zzz; cout << endl;
         	cout << "a che nodo?\n"; cin >> www; cout << endl;
         	rete.cancarco(zzz, www);
         	break;
      	case 5:
         	cout << "che nodo?\n"; cin >> zzz; cout << endl;
         	rete.adiacenti(zzz);
         	break;
      	case 6:
      		cout << "che nodo?\n"; cin >> zzz; cout << endl;
         	if (rete.esistenodo(zzz))
            {
         		cout << "SI\n";
            }
            else
            {
            	cout << "NO!\n";
            };
         	break;
      	case 7:
         	cout << "da che nodo?\n";
            cin >> zzz; cout << endl;
         	cout << "a che nodo?\n";
            cin >> www; cout << endl;
         	if (rete.esistearco(zzz, www))
         		cout << "SI\n";
            else
            	cout << "NO!\n";
         	break;
      };
   };
	system ("pause");
	return 0;
}


