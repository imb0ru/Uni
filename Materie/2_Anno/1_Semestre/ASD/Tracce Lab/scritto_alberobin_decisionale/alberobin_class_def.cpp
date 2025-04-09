//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//................ REALIZZAZIONE ALBERO BINARIO CON PUNTATORI ..................
//.................. (orientato alla costruzione top down) .....................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "alberobin_class.h"



//Specifica delle interfacce comuni

void AlberoBin :: creaBinAlbero()
   {
      T=NULL;
   }

AlberoBin :: boolean AlberoBin :: binAlberoVuoto()
   {
      return T==NULL;
   }

AlberoBin :: nodo AlberoBin :: binRadice()
   {
      if(!binAlberoVuoto())
      	return T;
      else
      	cout<<"\n L'albero e' vuoto";
			return NULL;
   }

AlberoBin :: nodo AlberoBin :: binPadre(nodo n)
   {
      if(!binAlberoVuoto()&& n!=binRadice())
      	return n->padre;
   	else
      	return NULL;
   }

AlberoBin :: nodo AlberoBin :: figlioSinistro(nodo n)
   {
      if(!binAlberoVuoto())
      	return n->sinistro;
   	else
      	return NULL;
   }

AlberoBin :: nodo AlberoBin :: figlioDestro(nodo n)
   {
      if(!binAlberoVuoto())
      	return n->destro;
   	else
      	return NULL;
   }




AlberoBin :: boolean AlberoBin :: sinistroVuoto(nodo n)
   {
      if(!binAlberoVuoto())
      	return figlioSinistro(n)==NULL;
   }



AlberoBin :: boolean AlberoBin :: destroVuoto(nodo n)
   {
      if(!binAlberoVuoto())


      	return figlioDestro(n)==NULL;
   }





//Specifica delle interfacce di costruzione e potatura


void AlberoBin :: insBinRadice()
   {
  		nodo newNodo=new nodoBin;
      newNodo->sinistro=NULL;
      newNodo->destro=NULL;
      newNodo->padre=NULL;
      T=newNodo;
      return;
   }



void AlberoBin :: insFiglioSinistro(nodo n)
   {
		if(!binAlberoVuoto() && sinistroVuoto(n))
         {
      		nodo newFiglio=new nodoBin;
      		newFiglio->sinistro=NULL;
      		newFiglio->destro=NULL;
      		newFiglio->padre=n;
            n->sinistro=newFiglio;
         }


      return;
   }



void AlberoBin :: insFiglioDestro(nodo n)
   {
		if(!binAlberoVuoto() && destroVuoto(n))
         {
      		nodo newFiglio=new nodoBin;
      		newFiglio->sinistro=NULL;
      		newFiglio->destro=NULL;
      		newFiglio->padre=n;
		      n->destro=newFiglio;
         }


      return;
   }






void AlberoBin :: cancSottoBinAlbero(nodo n)
{
   if(!binAlberoVuoto())//controlla che l'albero non sia vuoto
	   {
         if(!sinistroVuoto(n))
         //controlla che abbia un figlio sinistro e procede ricorsivamente con la cancellazione più in profondità
         	{
              	if(figlioSinistro(n)->sinistro!=NULL||figlioSinistro(n)->destro!=NULL)
         			cancSottoBinAlbero(figlioSinistro(n));
         	}
        	if(!destroVuoto(n))
         //controllo che abbia un figlio sinistro e procedere ricorsivamente con la cancellazione più in profondità
         	{
              	if(figlioDestro(n)->sinistro!=NULL||figlioDestro(n)->destro!=NULL)
         			cancSottoBinAlbero(figlioDestro(n));
         	}
        	if(n==binRadice())
         //se dopo la cancellazione resta solo la radice cancello anch'essa stabilendo lo stato di albero vuoto
           	{
              	T=NULL;
               delete(n);
            }
        	else
         //altrimenti mi sposto sul padre e, dopo aver verificato se fosse
         //figlio destro o sinistro, cancello opportunamente anche n
          	{
              	nodo temp=binPadre(n);
        	  		if(temp->sinistro==n)
                 	{
                    	temp->sinistro=NULL;
                     delete(n);
                  }
           		else
                 	{
                    	temp->destro=NULL;
                     delete(n);
                  }
           	}
     	}
	return;
}


//Specifica delle interfacce di utilizzo dei dati contenuti
AlberoBin :: tipoelem AlberoBin :: leggiNodo(nodo n)
   {
      if(!binAlberoVuoto())
      	return n->elem;
   }

void AlberoBin :: scriviNodo(tipoelem e,nodo n)
   {
     	n->elem=e;
      return;
   }


//Specifica delle interfacce costrutttore e distruttore
AlberoBin :: AlberoBin()
	{
   	creaBinAlbero();
   }


//definizione del distruttore
AlberoBin :: ~AlberoBin()
	{
//   	if(!binAlberoVuoto())
  //    	cancSottoBinAlbero(binRadice());
   }
