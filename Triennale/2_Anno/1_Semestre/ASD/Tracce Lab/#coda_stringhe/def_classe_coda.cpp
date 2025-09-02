//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389



#include <stdlib.h>
#include <iostream.h>
#include "classe_coda.h"


//specifica delle interfacce

void Coda :: creacoda()
	{
 		testa=NULL;
 	}

 	
Coda :: boolean	Coda :: codavuota()
	{
		return testa==NULL;
 	}


Coda :: tipoelem Coda :: leggicoda()
	{
		if(testa==NULL)
			return NULL;
		else
  			return testa->elem;
 	}


void Coda :: fuoricoda()
	{
		Coda :: pos recycle=testa;
		if(testa!=NULL)
  			{
				testa=testa->succ;
				delete(recycle);
			}
		else
			cout<<"\nLa Coda e' vuota";
 	}
 	

void Coda :: incoda(tipoelem a)
	{
		pos newNodo=new nodo;
		newNodo->elem=a;
		newNodo->succ=NULL;
		if(testa==NULL)
    			testa=fondo=newNodo;
		else
			{
         	fondo->succ=newNodo;
				newNodo->succ=NULL;
            fondo=newNodo;
			}
 	}

//costruttori e distruttori

Coda :: Coda()
//crea coda vuota
	{
		creacoda();
	}

Coda& Coda::operator = (Coda &coda)
//crea una coda copia come overloading dell'assegnamento
	{
		Coda coda_appoggio;
   	tipoelem a;
   	while(!coda.codavuota())
   		{
      		a=coda.leggicoda();
      		coda_appoggio.incoda(a);
      		coda.fuoricoda();
      	}
   	creacoda();
   	while(!coda_appoggio.codavuota())
   		{
      		a=coda_appoggio.leggicoda();
      		coda.incoda(a);
	      	incoda(a);
   	   	coda_appoggio.fuoricoda();
      	}
		return *this;
	}

Coda& Coda::operator ^ (Coda &coda)
	{
		Coda coda_appo1,coda_appo2;
		tipoelem a;
      int 	num_elem=0,
      		sentinella,
            i,j;

		creacoda();

      while (!coda.codavuota())
		//popola la coda di appoggio e copia gli elementi in una nuova coda
      	{
      		a=coda.leggicoda();
      		coda_appo1.incoda(a);
            incoda(a);
      		coda.fuoricoda();
            num_elem++;
         }

      while (!codavuota())
		//ripristina la coda originaria e svuota la nuova coda
      	{
      		a=leggicoda();
      		coda.incoda(a);
      		fuoricoda();
         }

      sentinella=num_elem;

      for(i=0;i<num_elem;i++)
		//scandisce ripetutamente la prima coda di appoggio ed
      //copia sempre l'ultimo dei non estratti per inserirlo
      //nella coda appena creata (cioè l'inversa)
      	{
            sentinella--;
         	for(j=0;j<sentinella;j++)
            //trasferisce dalla prima coda appoggio alla seconda
            //gli elementi che precedono quello cercato
            	{
      				a=coda_appo1.leggicoda();
      				coda_appo2.incoda(a);
      				coda_appo1.fuoricoda();
               }
            //copia l'elemento cercato nell'inversa e poi lo trasferisce
            //nella seconda coda appoggio
  				a=coda_appo1.leggicoda();
            coda_appo2.incoda(a);
            incoda(a);
            coda_appo1.fuoricoda();

				while(!coda_appo1.codavuota())
            //trasferisce dalla prima coda appoggio alla seconda
            //gli elementi che seguono quello cercato
      			{
     					a=coda_appo1.leggicoda();
		     			coda_appo2.incoda(a);
     					coda_appo1.fuoricoda();
		         }

				while(!coda_appo2.codavuota())
            //ripristina la prima coda appoggio per il prossimo ciclo
      			{
     					a=coda_appo2.leggicoda();
		     			coda_appo1.incoda(a);
     					coda_appo2.fuoricoda();
		         }
         }
		return *this;
    }


Coda :: ~Coda()
//rilascia la memoria impegnata di una coda
	{
		while(testa!=NULL)
			fuoricoda();
	}
