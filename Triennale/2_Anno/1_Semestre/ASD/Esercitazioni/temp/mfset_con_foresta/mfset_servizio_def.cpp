#include <stdlib.h>
#include <iostream.h>
#define NUM 10


//definizione delle funzioni di servizio

void stampa_mfset(Mfset S)
//funzione che visualizza un mfset
   {
      bool trovato=false;

     	cout<<"\n\n\n La configurazione attuale del Mfset e' la seguente";
     	cout<<"\n\n Mfset={ ";

      for(int i=0;i<NUM;i++)
			{
				if(i%10==0)
            	cout<<"\n         ";
            if(S.trova(i)==i)
					cout<<"{ ";
	      	for(int j=0;j<NUM;j++)
      			{
						if(S.trova(j)==i)
                     {
	     						cout<<j<<" ";
                     	trovato=true;
                     }

                  if(j==NUM && !trovato)
               		cout<<i<<" ";
         		}
            if(S.trova(i)==i)
  					cout<<"}";
			}
		cout<<"\n       }";
   }

void fondi_componenti(Mfset &M)
//funzione che visualizza un mfset
   {
      componente a,b;
      
     	cout<<"\n\n\n Fusione di due mfset:";
     	cout<<"\n Inserire valore della prima componente: ";
      cin>>a;
     	cout<<"\n Inserire valore della seconda componente: ";
      cin>>b;
      M.fondi(a,b);
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