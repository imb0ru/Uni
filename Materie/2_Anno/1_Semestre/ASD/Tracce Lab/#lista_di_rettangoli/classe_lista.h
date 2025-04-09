//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono


//Implementare la struttura dati che permetta di memorizzare una lista di
//rettangoli del piano cartesiano (RxR)
//(si possono memorizzare le coordinate degli estremi dei rettangoli),
//che permette di:

//Inserire e stampare la lista di rettangoli

//Funzione/metodo inscritto() che dati due rettangoli A e B
//restituisce il valore vero se il rettangolo A è inscritto nel rettangolo B

//Funzione/metodo epurazione() che elimina dalla struttura tutti i rettangoli
//inscritti in altri rettangoli usando la funzione/metodo inscritto

//Funzione/metodo maxarea() che calcoli la massima area
//tra quelle dei rettangoli della lista

//Funzione/metodo nonoverlap()che restituisce la sottolista
//dei rettangoli che non si sovrappongono



//Autore: Nico Spadoni
//matr.428389




//Interfaccia della classe Lista 


#ifndef CLASSE_LISTA_H
#define CLASSE_LISTA_H

#include "classe_rect.h"


class Lista
	{
		public:

			typedef bool boolean;
			typedef Rect tipoelem;

			struct nodo
         	{
					tipoelem elem;
					struct nodo* succ;
            };

         typedef nodo* pos;

			Lista();
			Lista& operator = (Lista &);
		  ~Lista();

			void crealista();
			boolean listavuota();
         pos primolista();
			boolean finelista(pos);
			pos succlista(pos);
			pos predlista(pos);
			tipoelem leggilista(pos);
			void scrivilista(tipoelem,pos);
			void inslista(tipoelem,pos);
			void canclista(pos);


		private:
			pos primo;
   };

#endif
