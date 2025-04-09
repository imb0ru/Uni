/*
  Nome: camminiMinimi.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Implementazione dell'algoritmo per la ricerca dei cammini
               minimi in un grafo orientato ed etichettato sugli archi
               con pesi non negativi (approccio greedy) 
*/


#include <iostream>
#include "GrafoAdiacenti.h"
#include "CodaPtr.h"
#define MAXINT 32767

using namespace std;
typedef int distanze[MAXNODI];
typedef Nodo padri[MAXNODI];

bool copiaCoda(CodaPtr &q, CodaPtr &r){
   if (!q.codaVuota()){
      CodaPtr s;
      elemCoda a;
      while (!q.codaVuota()){
         q.leggiCoda(a);
         r.inCoda(a);
         s.inCoda(a);
         q.fuoriCoda();
      }
      while (!s.codaVuota()){
         s.leggiCoda(a);
         q.inCoda(a);
         s.fuoriCoda();
      }
      return true;
   } else return false;
}

bool ricercaCoda(elemCoda a, CodaPtr &q){
   bool trovato = false;
   if (!q.codaVuota()){
      CodaPtr r; //appoggio per q
      copiaCoda(q, r);
      elemCoda b;
      while (!(r.codaVuota() || trovato)){
         r.leggiCoda(b);
         if (b == a){
            trovato = true;
         }
         else
            r.fuoriCoda();
      }
   }
   return trovato;
}

void inserisciGrafo(GrafoAdiacenti &g){
   int i = 0;
   int index, part, arr, w;
   label a;
   char risp = 's';
   while ((i < MAXNODI) && ((risp == 's') || (risp == 'S'))){
      i++;
      do{
         cout << "Inserisci indice del " << i << "^ nodo: ";
         cin >> index;
      } while ((index < 0) || (index >= MAXNODI) || (g.esisteNodo(index)));
      cout << "Inserisci etichetta: ";
      cin >> a;
      g.insNodo(index);
      g.scriviNodo(index, a);
      do{
         cout << "Altri nodi? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   risp = 's';
   while ((risp == 's') || (risp == 'S')){
      cout << "Inserisci arco:" << endl;
      do{
         cout << "Nodo partenza: ";
         cin >> part;
      } while ((part >= 0) && (part < MAXNODI) && !(g.esisteNodo(part)));
      do{
         cout << "Nodo arrivo: ";
         cin >> arr;
      } while ((arr >= 0) && (arr < MAXNODI) && !(g.esisteNodo(arr)));
      do{
         cout << "Inserisci peso non negativo (" << part << ", " << arr << "): ";
         cin >> w;
      } while (w < 0);
      if (!g.insArco(part, arr))
         cout << "Arco esistente" << endl;
      else
         g.scriviArco(part, arr, w);
      do{
         cout << "Altri archi? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
}

void camminiMinimi(GrafoAdiacenti &g, Nodo start, distanze d, padri p){
   if (g.esisteNodo(start)){
      Nodo i;
      for (i = 0; i < MAXNODI; i++){
         p[i] = i;
         (i == start? d[i] = 0: d[i] = MAXINT);
      }    
      CodaPtr q;
      label a;
      tipoelem temp;
      Nodo u = start;
      Nodo v;
      q.inCoda(u);
      while (!q.codaVuota()){
         q.leggiCoda(u);
         q.fuoriCoda();
	      ListaAdiacenti l;
         g.adiacenti(u, l);
         posizione pl = l.primoLista();
         while (!l.fineLista(pl)){
            l.leggiLista(temp, pl);
            v = temp.nodoCur;
            tipoPeso w;
            g.leggiArco(u, v, w);
            //relax
            if (d[u] + w < d[v]){
               d[v] = d[u] + w;
               p[v] = u;
               if (!ricercaCoda(v, q))
                  q.inCoda(v);
            }
            pl = l.succLista(pl);
         }
      }  
   } 
}

void stampaCammini(GrafoAdiacenti &g, Nodo start, distanze d, padri p){
   int path[MAXNODI];
   for(int i = 0; i < MAXNODI; i++){ //cicla su p
      if (g.esisteNodo(i)){
         int j;
         path[0] = i;
         int tot = 0;
         for(j = 1; ((j < MAXNODI) && (path[j-1] != start)); j++){ //creazione del path
            path[j] = p[path[j-1]];
            tot++;
         }
         tipoPeso w;
         for(j = tot; j >0; j--){ //creazione del path
            g.leggiArco(path[j], path[j-1], w);
            cout << path[j] << " (" << w << ") -> ";
         }
         cout << path[j] << " (distanza totale: " << d[i] << ")" << endl;
      }
   }
}
