//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389



#include <iostream.h>
#include <stdlib.h>
#include "classe_lista.h"

void Lista::crealista()
	{
		primo=NULL;
   }

Lista::pos Lista::primolista()
	{
		return(primo);
   }

Lista::boolean Lista::listavuota()
	{
		return(primo==NULL);
   }

Lista::boolean Lista::finelista(pos p)
	{
		return(p==NULL);
   }

void Lista::inslista(tipoelem e,pos p)
	{
		pos nuovo,pre;
		nuovo=(pos) malloc(sizeof(struct nodo));
		if(nuovo==NULL)
      	{
         	cout<<"Memoria esaurita.\n";
            exit(EXIT_FAILURE);
         }
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
            free(p);
            return;
         }
		pre->succ=p->succ;
		free(p);
   }

Lista::pos Lista::succlista(pos p)
	{
		if(p==NULL)
      	return NULL;
		else
      	return(p->succ);
   }

Lista::pos Lista::predlista(pos p)
	{
		pos p_2=primo;
		if(p==primo)
      	return(NULL);
		else
      	{
        		while (p_2->succ!=p)
         		p_2=p_2->succ;
      		return p_2;
     		}
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

Lista::tipoelem Lista::leggilista(pos p) 
	{
		if(!finelista(p))
			return(p->elem);
		else
			cout<<"Nessun nodo da leggere.";
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
