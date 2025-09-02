//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE CODA CON VETTORE .........................
//..............................................................................



#include <iostream.h>
#include <stdlib.h>
#include "coda.h"

//definizione degli operatori

void Coda::creacoda()
//si tratta di settare il top a zero
	{
      fondo=0;
   }

Coda::boolean Coda::codavuota()
	{
   	return fondo==0;
   }

Coda::tipoelem Coda::leggicoda()
	{
		return coda[TOP-1];
   }

void Coda::incoda(tipoelem a)
//
	{
      if(fondo==N)
      //controllo se l'operazione provoca una violazione di accesso alla memoria
        	cout<<"\n Raggiunto il limite max di elementi della coda.";
      else
			{
            fondo++;       //incremento il fondo (la coda si allunga)
				coda[fondo-1]=a; //inserisco l'elemento
         }
	}

void Coda::fuoricoda()
	{
		if(!codavuota())
      //controllo se l'operazione è effettivamente eseguita su coda non vuota
      	{
				for(int i=0;i<fondo;i++)
         		coda[i]=coda[i+1];
         	fondo--;
         }
      else
        	cout<<"\n La coda e' vuota.";
	}

//implementazione dei costruttori e del distruttore
Coda::Coda()
	{
   	creacoda();
   }

Coda& Coda::operator=(Coda &coda)
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

Coda::~Coda()
	{}


