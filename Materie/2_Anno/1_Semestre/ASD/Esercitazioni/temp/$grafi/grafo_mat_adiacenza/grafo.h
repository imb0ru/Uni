//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.......... REALIZZAZIONE GRAFO ORIENTATO CON MATRICE DI ADIACENZA ............
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

      	//MAX_ORD=max dim della matrice;
         //se l'arco (i,j) non appatiene ad A allora il peso è infinito
      	enum{MAX_ORD=30,INFINITO=999999};

       	peso adi_mat[MAX_ORD][MAX_ORD];

         int ordine;  //per ragioni di efficienza riduco le scansioni ai soli
         				 //nodi esistenti evitando gli elementi della matrice non
                      //ancora definiti.
	};
#endif
