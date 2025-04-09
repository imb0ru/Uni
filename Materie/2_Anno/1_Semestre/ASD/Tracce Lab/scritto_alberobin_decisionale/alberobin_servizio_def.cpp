//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi
//Esame di Algoritmi e Strutture Dati
//Autore: Nico Spadoni, matr.428389

/*  - Costruire interattivamente l'albero
    - Visita e stampa dell'albero in preordine
    - Verifica della presenza di un cammino dettato da una stringa in input   */

#include <stdlib.h>
#include <iostream.h>

//definizione delle funzioni di servizio
void	visitaOutput(AlberoBin &, AlberoBin :: nodo, int, int &);
void  costruisci(AlberoBin &, AlberoBin :: nodo, int);
boolean	estPercorsoCompleto(AlberoBin &, AlberoBin :: nodo, char*, int &);
void wait(char *msg);

boolean	estPercorsoCompleto(AlberoBin &T,AlberoBin::nodo r,char*s,int &depth)
	{
    	char corrente;
      nodo v=r;
      boolean interrompi=false;
      int counter=0;

      depth=0;
     	if(*s!=T.leggiNodo(v))
	      interrompi=true;
      else
      	{
            s++;
		      while(*s!='\0' && !interrompi)
      			{
                  if(T.destroVuoto(v)&&T.sinistroVuoto(v))
          		      interrompi=true;
                  else
							{
		         			if(!T.sinistroVuoto(v))
		           		   	if(*s==T.leggiNodo(T.figlioSinistro(v)))
      		           			{
            		  					depth++;
	               		      	v=T.figlioSinistro(v);
		           		      	}
      		            if(!T.destroVuoto(v))
     					        	if(*s==T.leggiNodo(T.figlioDestro(v)))
	         	   		     	{
	               					depth++;
		     		        	      	v=T.figlioDestro(v);
      		           			}
							}
		            s++;
		            counter++;
		         }
			}

      if(interrompi)
      	return false;
      else
         if(counter!=depth)
            {
      	     depth=-depth;
		        return false;
            }
         else
	        	{
	  	   		depth=-depth;
      	  		return true;
           	}
   }





void wait(char *msg)
//funzione utility per interrompere l'esecuzione del programma
//attende l'input dell'utente per ripartire
//richiede una strinda come argomento, essa sarà visualizzata
//come messaggio per l'utente
	{
   	char stop='?';

      cout<<msg;
      while(stop!='y' && stop!='Y')
      	cin>>stop;
		return;
   }





void visitaOutput(AlberoBin &tree, AlberoBin::nodo n, int counter, int &numNodi)
//preordine con conteggio del livello di profondità
//e stampa del contenuto
	{
   	int 	i;
      numNodi++;

      for(i=0;i<counter-1;i++)
			cout<<"    ";
      if(counter>0)
   		cout<<"+---";
      cout<<tree.leggiNodo(n)<<"\n";

   	if (!tree.sinistroVuoto(n))
        	visitaOutput(tree, tree.figlioSinistro(n),counter+1,numNodi);
   	else
      	{
		      for(i=0;i<counter;i++)
					cout<<"    ";

				if(counter==0)
      			cout<<"    ";

		      if(counter>0)
   				cout<<"+---";
     			cout<<"<>\n";
         }

      if (!tree.destroVuoto(n))
     		visitaOutput(tree, tree.figlioDestro(n),counter+1,numNodi);
   	else
      	{
		      for(i=0;i<counter;i++)
					cout<<"    ";

		      if(counter>0)
   				cout<<"+---";
     			cout<<"<>\n";
         }
		return;
   }









void costruisci(AlberoBin &tree, AlberoBin::nodo n, int counter)
//Crea e popola un albero
	{
      char val;
      char side='?';

		if(n==tree.binRadice())
      	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
		      tree.scriviNodo(val,n);
            cout<<"\n nodo Radice etichetta:["<<tree.leggiNodo(n)<<"]";
            counter++;
         }

      cout<<"\n Vuoi aggiungere un figlio?"
  		    <<"\n Digita:\n   's' per il sinistro,\n"
          <<"   'd' per il destro (senza il sinistro)\n"
  		    <<"   'x' per non aggiungere figli: ";
      while(side!='s' && side!='d' && side!='x')
  			cin>>side;

      if(side=='s')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
         	tree.insFiglioSinistro(n);
		      tree.scriviNodo(val,tree.figlioSinistro(n));
            cout<<"\n nodo["<<val<<"] - figlio sinistro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
           	costruisci(tree, tree.figlioSinistro(n), counter+1);
            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio sinistro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
		      cout<<"\n Vuoi aggiungere un fratello a destra?"
              	 <<"\n Digita:\n   'd' in caso affermativo,\n"
            	 <<"   'x' per non aggiungere figli: ";
		      while(side!='d' && side!='x')
      	   	cin>>side;
         }

      if(side=='d')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
         	tree.insFiglioDestro(n);
		      tree.scriviNodo(val,tree.figlioDestro(n));
            cout<<"\n nodo["<<val<<"] - figlio destro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
           	costruisci(tree, tree.figlioDestro(n), counter+1);
            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio destro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
         }
      return;
   }
