//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.............. REALIZZAZIONE INSIEME COME LISTA NON ORDINATA .................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "ins.h"






//Specifica delle interfacce


void Ins :: creains()
   {
      I=NULL;
		return;
   }



Ins :: boolean Ins :: insvuoto()
   {
      return I==NULL;
   }



Ins :: boolean Ins :: appartiene(tipoelem a)
   {
      pos p=I;
      boolean found=0;

    	while(p!=NULL)
      	{
          	if(a==p->elem)
            	return true;
            else
               p=p->succ;
         }
     	return false;
   }



void Ins :: inserisci(tipoelem a)
   {
		if(appartiene(a))
         cout<<"\nElemento gia' presente\n";
      else
         {
				pos newNodo=new nodo;
   			newNodo->elem=a;
    			newNodo->succ=I;
      		I=newNodo;
         }
		return;
   }



void Ins :: cancella(tipoelem a)
   {
      pos 	p=I;
		if(appartiene(a))
      	{
    			while(p!=NULL)
      			{
               	if(a==p->elem)
            			{
                     	if(p=I)
                        	{
                  				I=I->succ;
				               	delete p;
                              return;
               				}
            				else
            					{
               					pos temp=I;
                              while(temp->succ!=p)
                              	temp->succ=p->succ;
                              delete p;
                              return;
				               }
         				}
                  else
                  	p=p->succ;
   				}
          }
		return;
    }

void Ins :: unione(Ins &A, Ins &B)
   {
      pos p=A.I;
      creains();
      while(p!=NULL)
        	{
           	inserisci(p->elem);
            p=p->succ;
         }

      p=B.I;
      while(p!=NULL)
        	{
           	inserisci(p->elem);
            p=p->succ;
        	}
		return;
   }

void Ins :: intersezione(Ins &A, Ins &B)
   {
	   pos p=A.I;
	   creains();
      while(p!=NULL)
        	{
   	      if(B.appartiene(p->elem))
  					inserisci(p->elem);
            p=p->succ;
         }
		return;
   }

void Ins :: differenza(Ins &A, Ins &B)
   {
      pos p=A.I;
	   creains();
      while(p!=NULL)
        	{
	         if(!B.appartiene(p->elem))
  					inserisci(p->elem);
            p=p->succ;
         }
		return;
   }


//costruttori e distruttori

Ins :: Ins()
//crea ins vuota
   {
      creains();
		return;
   }


Ins :: Ins(Ins &A)
	{
   	pos p=A.I;
		creains();
		while (p!=NULL)
   		{
         	inserisci(p->elem);
        		p=p->succ;
      	}
		return;
	}

Ins & Ins :: operator = (Ins &A)
	{
   	pos p=A.I;
		creains();
		while (p!=NULL)
   		{
         	inserisci(p->elem);
        		p=p->succ;
      	}
		return *this;
   }

Ins :: ~Ins()
	{
   	pos p=I,temp;
		while (p!=NULL)
   		{
         	temp=p->succ;
        		cancella(p->elem);
        		p=temp;
      	}
		return;
	}
