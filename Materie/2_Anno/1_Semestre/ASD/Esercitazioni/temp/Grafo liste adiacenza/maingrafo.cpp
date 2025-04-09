



// PROGRAMMA DI GESTIONE DI UN GRAFO CON LISTE DI ADIACENZA + VISITA DFS

#include <iostream>
#include <stdlib.h>
#include "Grafo.h"
#include "Listad.h"


int r,i;
nodo zzz, www;
tipoelem eti;
Grafo rete;


void DFS(nodo u)
{
	nodo v;
   cout << u << endl;
   rete.marcanodo(u);
   rete.adiacenti(u); //compila la lista degli adiacenti
   int c=0;
   Listad l;
   for (int ic=0;ic<MAX-1;ic++)
   {
      l.listadiacenti[ic]=rete.listadiacenti[ic];

   };
	cout << endl;
   while (l.listadiacenti[c]!=-1)
   {
     v=l.listadiacenti[c];
     if (rete.nodomarcato(v)==false)
     DFS(v);
     c++;
   };
};



int main(){
   r=1;
	while (r<99)
   {
  		cout << "1)inserisci nodo 2)inserisci arco 3)elimina nodo 4)elimina arco\n";
   	cout << "5)mostra adiacenti 6)esiste nodo? 7)esiste arco? 10)lista adia\n";
   	cout << "8)inserisci label 9) DFS\n";
   	cin >> r;
   	switch (r){
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
         	for (i=0; i<8; i++)
         	{
         		cout << rete.listadiacenti[i] << endl;
         	}
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
         	cout << "da che nodo?\n"; cin >> zzz; cout << endl;
         	cout << "a che nodo?\n"; cin >> www; cout << endl;
         	if (rete.esistearco(zzz, www))
         		cout << "SI\n";
            else
            	cout << "NO!\n";
         	break;
      	case 8:
      		cout << "a che nodo?"; cin >> zzz; cout << endl;
         	cout << "che etichetta?"; cin >> eti; cout <<endl;
         	rete.scrivinodo(eti, zzz);
         	break;
      	case 9:
      		cout <<"da che nodo vuoi iniziare?"; cin >> zzz; cout << endl;
         	DFS(zzz);
         	rete.smarcatuttinodi();
         	break;
      	case 10:
      		cout << "di che nodo?"; cin >> zzz; cout << endl;
      		rete.adiacenti(zzz);
         	int tro=0;
         	while (rete.listadiacenti[tro]!=-1)
         	{
            	cout << rete.listadiacenti[tro] << endl;
               tro++;
            }
         	break;
      	};
    };
	system ("pause");
	return 0;
}



