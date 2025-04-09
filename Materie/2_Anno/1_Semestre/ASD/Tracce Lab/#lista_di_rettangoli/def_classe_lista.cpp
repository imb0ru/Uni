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




//Definizione metodi della classe Lista 


#include <iostream.h>
#include <stdlib.h>
#include "classe_lista.h"


void Lista::crealista()
	{
		primo=NULL;
   }

Lista::boolean Lista::listavuota()
	{
		return primo==NULL;
   }

Lista::pos Lista::primolista()
	{
		return primo;
   }

Lista::boolean Lista::finelista(pos p)
	{
		return p==NULL;
   }

Lista::pos Lista::succlista(pos p)
	{
		if(p==NULL)
      	return NULL;
		else
      	return p->succ;
   }

Lista::pos Lista::predlista(pos p)
	{
		pos p_2=primo;
		if(p==primo)
      	return NULL;
		else
      	{
        		while (p_2->succ!=p)
         		p_2=p_2->succ;
      		return p_2;
     		}
   }

Lista::tipoelem Lista::leggilista(pos p)
	{
		if(!finelista(p))
			return p->elem;
   }

void Lista::scrivilista(tipoelem e,pos p)
	{
		if(finelista(p))
      	{
         	cout<<"Nodo da aggiornare errato."<<endl;
            return;
         }
		p->elem=e;
   }

void Lista::inslista(tipoelem e,pos p)
	{
		pos 	nuovo=new nodo,
      		pre;
		nuovo->elem=e;
		pre=predlista(p);
		if(pre==NULL)
      	{
         	nuovo->succ=primo;
            primo=nuovo;
            return;
         }
		pre->succ=nuovo;
		nuovo->succ=p;
   }

void Lista::canclista(pos p)
	{
		if(finelista(p))
      	{
         	cout<<"Nessun nodo da cancellare.\n";
            return;
         }
		pos pre=predlista(p);
		if(pre==NULL)
      	{
         	primo=primo->succ;
            delete p;
            return;
         }
		pre->succ=p->succ;
		delete p;
   }

Lista::Lista()
	{
		crealista();
   }

Lista::~Lista()
	{
		pos p=primolista();
		while(!finelista(p))
      	{
         	canclista(p);
            p=primolista();
         }
   }

Lista& Lista::operator = (Lista &lista)
	{
		pos p,p_2;
		crealista();
		p=lista.primolista();
		p_2=primolista();
		while (!lista.finelista(p))
      	{
      		tipoelem e=lista.leggilista(p);
      		inslista(e,p_2);
      		p=lista.succlista(p);
         }
		return *this;
   }
