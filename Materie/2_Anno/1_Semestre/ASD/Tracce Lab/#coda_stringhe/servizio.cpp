//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389



#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#include "classe_coda.h"

void setcoda(Coda &coda)
//popola la coda di un numero dato di elementi
	{
 		Coda :: tipoelem a;
      int num;

      cout<<"\n Con quanti elementi vuoi inizializzare la coda? ";
      cin>>num;
      while(num<=0)
         {
            cout<<"\n Il numero degli elementi deve essere maggiore"
                <<" o uguale a 1.\n Inserire nuovamente il numero: ";
            cin>>num;
         }

      cout<<" \n Inserisci ora il valore che"
          <<" vuoi assegnare a ciascun elemento:\n\n";

      for(int i=1;i<=num;i++)
         {
            cin>>a;
	        	coda.incoda(a);
         }
		return;
  	}

void printcoda(Coda &coda)
//stampa la coda con accorgimenti grafici
	{
		Coda :: tipoelem a;
      Coda coda_appoggio;

		cout<<"\n TOP <-";
		while(!coda.codavuota())
  			{
     			cout<<"["<<coda.leggicoda()<<"]\n       ";
            coda_appoggio.incoda(coda.leggicoda());
     			coda.fuoricoda();
         }
		cout<<" ^  FONDO\n\n";
		while(!coda_appoggio.codavuota())
  			{
            coda.incoda(coda_appoggio.leggicoda());
     			coda_appoggio.fuoricoda();
         }
		return;
 	}
void acquisizione(Coda &coda)
//popola la coda di interi positivi con stop da input negativo
	{
		Coda::tipoelem e;
		cout<<"\n Acquisizione di una coda di interi positivi --" <<endl;
		cout<<" Per terminare l'inserimento digitare un intero negativo" <<endl;
		cout<<" Inserire un intero positivo: ";
		cin>>e;
		while (e>=0)
      	{
         	coda.incoda(e);
            cout<<"Inserire un intero positivo: ";
            cin>>e;
         }
		return;
}

void acquiStringaInt(Coda &coda)
//popola la coda con cifre da una stringa numerica in input
	{
		char* numero;
		cout<<"\n Inserire la stringa che rappresenta il numero da acquisire\n\n n=";
		cin>>numero;
		for(int i=0;i<strlen(numero);i++)
	  		coda.incoda(*(numero+i)-48);
		return;
	}

void visualizzazione(Coda coda)
//visualizza la coda in modo spartano
	{
		Coda coda_2;
		if (coda.codavuota())
      	{
         	cout<<"Coda vuota." <<endl;
         	return;
      	}
		cout<<"-- Nodi della coda: --" <<endl;
		while(!coda.codavuota())
      	{
            cout<<coda.leggicoda()<<endl;
            coda_2.incoda(coda.leggicoda());
            coda.fuoricoda();
         }
		while(!coda_2.codavuota())
      	{
				coda.incoda(coda_2.leggicoda());
            coda_2.fuoricoda();
         }
		return;
}

Coda::boolean is_greater(Coda &coda1, Coda &coda2)
//confronta le due code numeriche e stabilisce se il primo argomento è
//maggiore del secondo.
	{
      Coda 	appoggio,
				add1inv,
      		add2inv;

   	int 	val1=0,
      		val2=0,
				esp=0,
            base=10;

      add1inv^coda1;
     	add2inv^coda2;

      while(!add1inv.codavuota())
      	{
            val1=val1+add1inv.leggicoda()*pow(base,esp);
            appoggio.incoda(add1inv.leggicoda());
            add1inv.fuoricoda();
         	esp++;
         }

      while(!appoggio.codavuota())
      	{
            add1inv.incoda(appoggio.leggicoda());
            appoggio.fuoricoda();
         }

      esp=0;
      while(!add2inv.codavuota())
      	{
            val2=val2+add2inv.leggicoda()*pow(base,esp);
            appoggio.incoda(add2inv.leggicoda());
            add2inv.fuoricoda();
         	esp++;
         }

      while(!appoggio.codavuota())
      	{
            add2inv.incoda(appoggio.leggicoda());
            appoggio.fuoricoda();
         }

      if(val1>=val2)
			return true;
      else
      	return false;
   }
   
   
   


void somma(Coda &add1,Coda &add2,Coda &totale)
//esegue la somma tra due code di stringhe numeriche
	{
		Coda 	add1inv,
      		add2inv,
            appoggio;

   	Coda::tipoelem 	riporto=0,
                        a1, a2, sub;

		add1inv^add1;
      add2inv^add2;

      while(!(add1inv.codavuota()&&add2inv.codavuota()))
      	{
        	if(add1inv.codavuota())
            	a1=0;
            else
              	a1=add1inv.leggicoda();

         	if(add2inv.codavuota())
            	a2=0;
            else
              	a2=add2inv.leggicoda();

            sub=a1+a2+riporto;
            if(sub>=10)
            	{
               	sub=sub-10;
                  riporto=1;
               }
            else
            	riporto=0;

            appoggio.incoda(sub);
           	add1inv.fuoricoda();
            add2inv.fuoricoda();
         }
 
      if(riporto)
	      appoggio.incoda(riporto);

      totale^appoggio;
		return;
   }




void differenza(Coda &add1,Coda &add2,Coda &differenza)
//esegue la differenzaa tra due code di stringhe numeriche
	{
		Coda 	add1inv, add2inv, appoggio;
   	    Coda::tipoelem   base=10, sentinella=0,	riporto=0, a1, a2, sub;

		if(is_greater(add1,add2))
      	{
				add1inv^add1;
      		add2inv^add2;
         }
      else
      	{
				add1inv^add2;
      		add2inv^add1;
            sentinella=1;
         }

      while(!add1inv.codavuota())
      	{
        		a1=add1inv.leggicoda()-riporto;
            if(a1==0)
            	riporto=0;

         	if(add2inv.codavuota())
            	a2=0;
            else
              	a2=add2inv.leggicoda();

				if(a1>=a2)
					if(a1==0)
               	{
               		a1=base*riporto;
                     sub=a1-a2;
                  }
               else
						{
           	      	sub=a1-a2;
		      	      riporto=0;
                  }
            else
            	{
               	a1=a1+base;
                  sub=a1-a2;
                  riporto=1;
               }
            appoggio.incoda(sub);
           	add1inv.fuoricoda();
            add2inv.fuoricoda();
         }
      differenza^appoggio;
      if(sentinella)
      	differenza.incoda(-1);
		return;
   }






