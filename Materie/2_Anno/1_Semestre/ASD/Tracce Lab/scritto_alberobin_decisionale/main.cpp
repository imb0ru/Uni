//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

/*
          REALIZZAZIONE DELLA TRACCIA DI APPELLO DEL 16/02/04
===========================================================================
Si dispone di un albero binario con nodi etichettati con valori di verità
(vero falso), si vuole controllare che esista nell'albero un corrispondente
cammino a partire dalla radice.
Se si raggiunge una foglia senza aver esaurito la sequenza data, si vuole
conoscere la profondità a cui si è arrivati.
*/

#include <stdlib.h>
#include <iostream.h>
#include "alberobin_class.h"
#include "alberobin_class_def.cpp"
#include "alberobin_servizio_def.cpp"

int main()
   {
      AlberoBin Tree;
      char repeat='s';
      char path[20];
      int liv=0, numNodi=0, depth=0;

     	Tree.insBinRadice();
   	costruisci(Tree,Tree.binRadice(),liv);
      cout<<"\n\n Schema di rappresentazione dell'albero\n\n";
      visitaOutput(Tree, Tree.binRadice(), liv,numNodi);

      while(repeat=='s')
      	{
		  		cout<<"\n Inserisci la sequenza di simboli da sottoporre: "
            		"\n (Sono ammessi solo simboli 1 e 0)\n\n > ";
  				cin>>path;

		  		if(estPercorsoCompleto(Tree,Tree.binRadice(),path,depth))
  					cout<<"\n OK: esiste un percorso corrispondente"
               		"\n alla sequenza in input!";
		  		else
            	{
  						cout<<"\n Attenzione: non esiste un percorso corrispondente"
               			"\n alla sequenza in input!";

            		if(depth>0)
  							cout<<"\n La scansione della stringa non e' stata"
                     		" completata\n perche' e' stata raggiunta una foglia"
                           " anzitempo!"
                     		"\n La profondita' della foglia e' pari a: "<<depth;
           	 		else
            			if(depth==0)
  								cout<<"\n La scansione della stringa non e' stata"
                        		" completata\n perche' non risulta corrispondenza"
                              " sul primo simbolo: ";
               }
		      cout<<"\n\n Se vuoi riprovare con un'altra sequenza"
      		 	 <<"\n digita 's'"
          		 <<"\n altrimenti digita 'n': ";

      		cin>>repeat;
         }
      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
   }
