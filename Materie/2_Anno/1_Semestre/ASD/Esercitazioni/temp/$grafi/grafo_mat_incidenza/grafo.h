//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.......... REALIZZAZIONE GRAFO ORIENTATO CON MATRICE DI INCIDENZA ............
//................................ (PESATO) ....................................
//..............................................................................



#include <iostream.h>
#include <stdlib.h>
#include "lista.h"


#ifndef GRAFO_H
#define GRAFO_H

// Classe Grafo
class Grafo
	{
		public:
			typedef int nodo;
			typedef int peso;
			typedef bool boolean;

  	    	void 		creagrafo();
     	 	bool 		grafovuoto();
     		void 		insnodo(nodo);
        	void 		insarco(nodo,nodo,peso);
  	    	void 		cancnodo(nodo);
     	 	void 		cancarco(nodo,nodo);
         boolean  esistenodo(nodo);
         boolean  esistearco(nodo,nodo);
     		Lista 	adiacenti(nodo);
			peso 		pesoarco(nodo, nodo);

//costruttore e distruttore
       	Grafo();
        ~Grafo();

		private:

      	//MAX_NODI=max numero di nodi;
      	//MAX_ARCHI=max numero di archi (questo valore è legato al primo
         //infatti si può calcolare il massimo numero di connessioni A tra
         //n nodi come A=n(n-1)/2 nel caso di grafi non orientati mentre
         //A=n(n-1) nel caso di grafi orientati - ossia esattamente il doppio);
         //Infine, se l'arco (i,j) non appatiene ad A, allora il peso è infinito
      	enum{MAX_NODI=10,MAX_ARCHI=90,NULLO=0,INFINITO=999999};

       	peso incid_mat[MAX_NODI][MAX_ARCHI]; //matrice di incidenza

         int card_nodi; //per ragioni di efficienza riduco le scansioni ai soli
         				 	//nodi esistenti evitando gli elementi della matrice non
                      	//ancora definiti.

         int card_archi;//per ragioni di efficienza riduco le scansioni ai soli
         				 	//archi esistenti evitando gli elementi della matrice
                      	//non ancora definiti.
	};
#endif
