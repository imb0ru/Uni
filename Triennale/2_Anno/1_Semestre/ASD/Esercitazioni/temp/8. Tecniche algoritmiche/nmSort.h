/*
  Nome: nmSort.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Implementazione del natural merge sort su lista 
               con puntatore (divide et impera) 
*/


#include <iostream>
#include "ListaPtr.h"

void copia(posizione &pa, ListaPtr &a, posizione &pl, ListaPtr &l, bool &fineCatena){
   tipoelem temp;
   a.leggiLista(temp, pa);
   l.insLista(temp, pl);
   pa = a.succLista(pa);
   pl = l.succLista(pl);
   if (a.fineLista(pa))
      fineCatena = true;
   else{
      tipoelem temp2;
      a.leggiLista(temp2, pa);
      fineCatena = (temp > temp2);
   }
}

void copiaCatena(posizione &pa, ListaPtr &a, posizione &pb, ListaPtr &b){
   bool fineCatena;
   do{
      copia(pa, a, pb, b, fineCatena);
   } while (!fineCatena);
}

void fondiCatena(posizione &pa, ListaPtr &a, posizione &pb, ListaPtr &b, posizione &pl, ListaPtr &l){
   bool fineCatena;
   do{
      tipoelem x, y;
      a.leggiLista(x, pa);
      b.leggiLista(y, pb);
      if (x < y){
         copia(pa, a, pl, l, fineCatena);
         if (fineCatena)
            copiaCatena(pb, b, pl, l);
      } else{
         copia(pb, b, pl, l, fineCatena);
         if (fineCatena)
            copiaCatena(pa, a, pl, l);
      }
   } while (!fineCatena);
}

void merge(ListaPtr &a, ListaPtr &b, ListaPtr &l, int &catene){
   posizione pl = l.primoLista();
   posizione pa = a.primoLista();
   posizione pb = b.primoLista();
   while (!(a.fineLista(pa) || b.fineLista(pb))){
      fondiCatena(pa, a, pb, b, pl, l);
      catene++;
   }
   while (!a.fineLista(pa)){
      copiaCatena(pa, a, pl, l);
      catene++;
   }
   while (!b.fineLista(pb)){
      copiaCatena(pb, b, pl, l);
      catene++;
   }
}

void distribuisci(ListaPtr &l, ListaPtr &a, ListaPtr &b){
   posizione pl = l.primoLista();
   posizione pa = a.primoLista();
   posizione pb = b.primoLista();
   do{
      copiaCatena(pl, l, pa, a);
      if (!l.fineLista(pl))
         copiaCatena(pl, l, pb, b);
   } while (!l.fineLista(pl));
}

void inserisciLista(ListaPtr &l){
   int i = 0;
   char risp = 's';
   tipoelem a;
   int p;
   while ((risp == 's') || (risp == 's')){
      i++;
      std::cout << "Inserisci elemento " << i << ": ";
      std::cin >> a;
      l.insLista(a, NULL);
      do{
         std::cout << "Altri elementi? (S/N) ";
         std::cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   std::cout << "Hai inserito " << i << " elementi" << std::endl;
}        

void stampaLista(ListaPtr &l){
   posizione p = l.primoLista();
   tipoelem a;
   while (!l.fineLista(p)){
      l.leggiLista(a, p);
      std::cout << a << " ";
      p = l.succLista(p);
   }
   std::cout << std::endl;
}

void nMergeSort(ListaPtr &l){
   int catene;
   ListaPtr a, b;
   do{
      a.creaLista();
      b.creaLista();
      distribuisci(l, a, b);
      catene = 0;
      l.creaLista();
      merge(a, b, l, catene);
   } while (catene != 1);
}

void nmSort(ListaPtr &l){
   inserisciLista(l);
   std::cout << std::endl;
   stampaLista(l);
   nMergeSort(l);
   std::cout << std::endl;
   stampaLista(l);
   std::cout << std::endl;
}
