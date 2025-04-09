//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

                       

//..............................................................................
//.............. REALIZZAZIONE LISTA SEQUENZIALE CON VETTORE ...................
//..............................................................................



#include <iostream.h>
#include <stdlib.h>
#include "lista.h"

//definizione degli operatori

void Lista::crealista()
//si tratta di inizializzare la variabile lunghezza a zero
//in effetti la lista non si crea dinamicamente ma impegna le
//componenti del vettore già creato in fase di compilazione
	{
   	lunghezza=0;
   }

Lista::boolean Lista::listavuota()
	{
   	return lunghezza==0;
   }

Lista::pos Lista::primolista()
	{
   	return 1;
   }

Lista::pos Lista::ultimolista()
	{
   	return lunghezza-1;
   }

Lista::boolean Lista::finelista(pos p)
 	{
   	return (p==lunghezza+1);
   }

Lista::tipoelem Lista::leggilista(pos p)
//la posizione p nell'array corrisponde all'indice p-1
//(perchè in C++ il range degli indici parte da zero)
//il problema si potrebbe aggirare con un overloading
//dell'operatore di indicizzazione  []
//ad esempio ridefinendolo nella classe in questo modo:
/*
tipoelem Lista :: operator[](int p)
	{
   	return lista[p-1];
   }
*/
	{
		return lista[p-1];
   }

void Lista::scrivilista(pos p,tipoelem a)
	{
   	lista[p-1]=a;
   }

Lista::pos Lista::succlista(pos p)
	{
		if(!finelista(p))
   		return p+1;
      else
      	cout<<"\n Non ci sono altri elementi";
	}

Lista::pos Lista::predlista(pos p)
	{
    if(p!=primolista())
	    return p-1;
    else
    	cout<<"\n Hai raggiunto la testa della lista";
	}

void Lista::inslista(pos p,tipoelem a)
	{
      if(p==N)
      //controllo se l'operazione provoca una violazione di accesso alla memoria
        	cout<<"\n Raggiunto il limite max di elementi della lista.";
      else
   	   //sposto gli elementi p e tutti i successivi per liberare
	      //lo spazio in cui inserire il nuovo elemento
      		{
			   	for(int i=lunghezza;i>=p-1;i--)
     					lista[i]=lista[i-1];

   				lista[p-1]=a; //dopo lo spostamento inserisco l'elemento
   				lunghezza++;  //incremento di conseguenza la variabile lunghezza
  				}
	}

void Lista::canclista(pos p)
	{
		if(!listavuota())
      //controllo se l'operazione è effettivamente eseguita su lista non vuota
        	if((!finelista(p))&&(p<=lunghezza))
   	   //sposto gli elementi p e tutti i successivi per ricompattare
	      //lo spazio non più utilizzato (con il primo spostamento sovrascrivo
         //l'elemento da eliminare)
        		{
           		for(int i=p-1;i<(lunghezza-1);i++)
           			lista[i]=lista[i+1];

               lunghezza--;//decremento di conseguenza la variabile lunghezza
        		}
	}

//implementazione dei costruttori e del distruttore
Lista::Lista()
	{
   	crealista();
   }

Lista::~Lista()
	{}
