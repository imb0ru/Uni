#include <iostream>
#include <cstdlib>
#include "GrafoMatAdExt.h"
#include "MFSet.h"
#include "NAlbero.h"
#define MAXARCHI 100

using namespace std;

struct tipoarco{
	NodoLista indPart, indArr;
	tipolabel part, arr;
	tipopeso weight;
};

typedef tipoarco archi[MAXARCHI];

void insGrafo(GrafoMatAdExt &g){
   char risp = 's';
   int i, j, w;
   tipolabel k;
   cout << endl << "Inserimento nodi:" << endl;
   cout << "-----------------" << endl;
   while ((risp == 's') || (risp =='S')){
      do{
         cout << "Inserisci numero nodo: ";
         cin >> i;
      } while (!((i >= 0) && (i < MAXNODI) && (!g.esisteNodo(i))));
      cout << "Inserisci label per il nodo " << i << ": ";
      cin >> k;
      g.insNodo(i, k);
      do{
         cout << "Altro nodo? (S/N) ";
         cin >> risp;
      } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
   }
   risp = 's';
   cout << endl;
   cout << "Inserimento archi:" << endl;
   cout << "------------------" << endl;
   while ((risp == 's') || (risp =='S')){
      do{
         cout << "Inserisci numero nodo di partenza: ";
         cin >> i;
      } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
      do{
         cout << "Inserisci numero nodo di arrivo: ";
         cin >> j;
      } while (!((j >= 0) && (j < MAXNODI) && (g.esisteNodo(j))));
      if (g.esisteArco(i, j))
         cout << "Arco (" << i << ", " << j << ") esistente" << endl;
      else{
      	do{
      		cout << "Inserisci peso (" << i << ", " << j << "): ";
      		cin >> w;
      	} while (w < 0);
         g.insArco(i, j);
         g.scriviArco(i, j, w);
      }
      do{
         cout << "Altro arco? (S/N) ";
         cin >> risp;
      } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
   }
}

void grafoToInsieme(GrafoMatAdExt &g, InsiemePtrN &i){
	tipolabel l;
	for (int j = 0; j < MAXNODI; j++)
		if (g.esisteNodo(j)){
			g.getLabel(j, l);
			i.inserisci(l);
		}			
}

void creaVettArchi(GrafoMatAdExt &g, archi &edges, int &n){
   int i, j;
   n = 0;
   tipopeso w;
   for (i = 0; i < MAXNODI; i++)
   	for (j = i; j < MAXNODI; j++)
   		if (g.esisteArco(i, j)){
   			edges[n].indPart = i;
   			edges[n].indArr = j;
   			g.getLabel(i, edges[n].part);
   			g.getLabel(j, edges[n].arr);
   			g.leggiArco(i, j, w);
   			edges[n].weight = w;
   			n++;
   		}   
	// Ordinamento del vettore degli archi appena creato
   bool flag = true;
   tipoarco temp;
   for(i = 1; (i <= n && flag); i++){
      flag = false;
      for (j = 0; j < n-1; j++)
         if (edges[j+1].weight < edges[j].weight){
            temp = edges[j];         
            edges[j] = edges[j+1];
            edges[j+1] = temp;
            flag = true; // indica lo swap di 2 elementi
         }
   }
}

void spanningTree(NodoLista u, GrafoMatAdExt &g, nodoN n, NAlbero &t){
   if ((!g.grafoVuoto() && g.esisteNodo(u))){
      NodoLista v;
      tipolabel k;
      g.getLabel(u, k);
      nodoN m = new NodoNPtr(k);
		if (t.nAlberoVuoto())
			t.insRadice(m);
		else if (t.foglia(n))
			t.insPrimoSottoAlbero(n, m);
		else{
			nodoN p = t.primoFiglio(n);
			while (!t.ultimoFratello(p))
				p = t.succFratello(p);
			t.insSottoAlbero(p, m);
		}
      g.setVisitato(true, u);
      ListaAdiacenti l;
      g.adiacenti(u, l);
      posizionelista p = l.primoLista();
      while (!l.fineLista(p)){
         l.leggiLista(v, p);
         if (!g.getVisitato(v))
            spanningTree(v, g, m, t);
         p = l.succLista(p);
      }
   }
}

bool antenatoUltimoFratello(nodoN n, NAlbero &t, int liv){
   nodoN m = t.padre(n);
   for(int j = liv; j > 1; j--){
      m = t.padre(m);
   }
   if(t.ultimoFratello(m))
      return true;
   else
      return false;
}

void stampaNAlbero(nodoN n, NAlbero &t, int liv){
   if (n != NULL){
      while (n != NULL){
      	for (int i = 1; i <= liv; i++)
      		if (i < liv)
      			if(antenatoUltimoFratello(n, t, liv-i))
      				cout << "   ";
      			else
      				cout << "|  ";
      		else cout << "+--";
         cout << t.leggiNodo(n) << endl;
         stampaNAlbero(t.primoFiglio(n), t, liv+1);
         n = t.succFratello(n);
      }
	}
}

void kruskal(GrafoMatAdExt &g, NAlbero &t){
	GrafoMatAdExt h;
	tipolabel l;
	int i, n;
	archi edges;
	InsiemePtrN set;
	MFSet m;
	for (i = 0; i < MAXNODI; i++)
		if (g.esisteNodo(i)){
			g.getLabel(i, l);
			h.insNodo(i, l);
		}
	grafoToInsieme(g, set);
	creaVettArchi(g, edges, n);
	m.creaMFSet(set);
	for (i = 0; i < n; i++)
		if (m.trova(edges[i].part).radice() != m.trova(edges[i].arr).radice()){
			m.fondi(edges[i].part, edges[i].arr);
			h.insArco(edges[i].indPart, edges[i].indArr);
		}
	t.~NAlbero();
	spanningTree(edges[0].indPart, h, t.radice(), t);		
}
