//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

//..............................................................................
//..................... REALIZZAZIONE MFSET CON FORESTA ........................
//..............................................................................

#include <stdlib.h>
#include <iostream.h>
#include "mfset.h"

//definizione degli operatori

void Mfset :: creamfset(insieme A)
   {
      for(int i=0;i<A;i++)
      	{
      		mfset[i].padre=-1;
      		mfset[i].dimensione=1;
         }
   }

Mfset :: componente  Mfset :: trova(tipoelem x)
//con la compressione dei percorsi
   {
      if(mfset[x].padre==-1)
			return x;
      else
      	{
            //ogni nodo incontrato nella risalita (dopo l'ultima ricorsione)
            //diventa figlio della radice della componente interessata
            //in tal modo l'azione di trova() riduce via via i percorsi
            //da effettuare per rintracciare la radice della componente
            mfset[x].padre=trova(mfset[x].padre);
      		return mfset[x].padre;
         }
   }

void Mfset :: fondi(tipoelem x,tipoelem y)
   {
		int 	i=trova(x),
      		j=trova(y);

      if(i!=j)
      	if(mfset[i].dimensione<mfset[j].dimensione)
      		{
      			mfset[i].padre=j;
      			mfset[j].dimensione=mfset[j].dimensione+mfset[i].dimensione;
         	}
      	else
      		{
      			mfset[j].padre=i;
      			mfset[i].dimensione=mfset[i].dimensione+mfset[j].dimensione;
         	}
   }

//costruttori e distruttori

Mfset :: Mfset()
//crea Ins vuota
   {
      creamfset(N);
   }

Mfset :: ~Mfset()
	{}
