#include "lista.h"
#include "grafo.h"
#include "ins.h"
#include "coda.h"

int build_grafo(Grafo &G, int &num_nodi)
//costruisce un grafo da input utente user friendly
	{
      char ripeti='?';
		int conta_archi=0;

      cout<<"\n Definizione dei nodi:";
		cout<<"\n Quanti nodi ha il grafo? ";
      cin>>num_nodi;
      for(int k=1;k<=num_nodi;k++)
     		G.insnodo(k);

      cout<<"\n Definizione degli archi:";

      int i,j,peso;
		while(ripeti!='n')
   	   	{
					cout<<"\n Crea arco dal nodo: ";
               cin>>i;
               cout<<" al nodo: ";
               cin>>j;
               cout<<" dal peso pari a: ";
               cin>>peso;
               G.insarco(i,j,peso);
	  				cout<<"\n\n\n Per terminare la creazione degli archi digita [n]";
  					cout<<"\n Per continuare digita [y]: ";
      			cin>>ripeti;
G.esistearco(i,j);
         	}
      return conta_archi;
 	}

void DFS(Grafo G, Ins &V, Grafo :: nodo i)
//Algoritmo Depth First Search ricorsivo stampa tutti i nodi attraversati
//l'algoritmo ricorsivo usa uno stack implicito per tenere traccia
//della sequenza di nodi visitati.
	{
   	Grafo :: nodo succ;

  		cout<<"["<<i<<"]";
  		V.inserisci(i);

      Lista :: pos p=G.adiacenti(i).primolista();
  		while(!G.adiacenti(i).finelista(p))
      	{
            succ=G.adiacenti(i).leggilista(p);
    			if(G.esistearco(i,succ) && !V.appartiene(succ))
      			{
  						cout<<"->";
            		DFS(G,V,succ);
            	}
         	p=G.adiacenti(i).succlista(p);
         }
	}


void visita_dfs(Grafo G)
//effettua la visita in profondita' stampando la sequenza di
//tutti i nodi percorsi (con l'ausilio di una algoritmo RICORSIVO)
	{
      Grafo :: nodo n;
      Ins Visitati;

      cout<<"\n Inserisci il numero del nodo dal quale vuoi partire: ";
      cin>>n;
      cout<<"\n nodo iniziale ->";
  		DFS(G,Visitati,n);    //Algoritmo Depth First Search
      cout<<"<- ultimo nodo";
	}


void visita_bfs(Grafo G)
//Algoritmo Breadth First Search, effettua la visita in ampiezza
//stampando la sequenza di tutti i nodi percorsi
	{
      Ins V,InQ;
      Coda Q;
      Grafo :: nodo i,succ;

      cout<<"\n Inserisci il numero del nodo dal quale vuoi partire: ";
      cin>>i;
      cout<<"\n nodo iniziale ->";

      Q.incoda(i);
      InQ.inserisci(i);
 		V.inserisci(i);
  		cout<<"["<<i<<"]";

  		while(!Q.codavuota())
      	{
            i=Q.leggicoda();
            Q.fuoricoda();
            InQ.cancella(i);

		      Lista :: pos p=G.adiacenti(i).primolista();
  				while(!G.adiacenti(i).finelista(p))
            	{
            		succ=G.adiacenti(i).leggilista(p);
    					if(G.esistearco(i,succ) && !V.appartiene(succ) && !InQ.appartiene(succ))
      					{
  								cout<<"->["<<succ<<"]";
				      		Q.incoda(succ);
 							   InQ.inserisci(succ);
				        		V.inserisci(succ);
            			}
         			p=G.adiacenti(i).succlista(p);
               }
         }
      cout<<"<- ultimo nodo";
   }


void trova_route(Grafo G, Ins &V, Lista &L, Grafo :: nodo i, Grafo :: nodo j, Grafo :: boolean &flag)
//è una DFS modificata, essa percorre tutti i nodi da quello di partenza
//a quello di arrivo (passati come argomenti), quando raggiunge la destinazione
//termina la visita del grafo e man mano che esce dalle ricorsioni in cascata
//memorizza i nodi che si lascia alle spalle in una lista passata per referenza
//dalla procedura chiamante
	{
   	Grafo :: nodo succ;
      Lista Route;
      Lista :: pos q=L.primolista();

  		V.inserisci(i);

      Lista :: pos p=G.adiacenti(i).primolista();
  		while(!G.adiacenti(i).finelista(p) && !flag)
      	{
           	succ=G.adiacenti(i).leggilista(p);
    			if(G.esistearco(i,succ) && !V.appartiene(succ))
      			{
                  if(succ!=j)
            			trova_route(G,V,L,succ,j,flag);
                  else
							{
                  		flag=true;
						      L.inslista(q,j);
                     }
            	}
	         		p=G.adiacenti(i).succlista(p);
		            if(!flag)
				      	L.canclista(q);
                  else
					      L.inslista(q,i);
         }
	}


peso stampa_route(Grafo G)
//la procedura stampa la lista popolata dalla chiamata della funzione
//trova_route(), inoltre calcola il peso totale degli archi che attraversano
//nell'ordine i nodi della lista
	{
      Grafo :: nodo i,j;
      Grafo :: boolean trovato=false;
      Ins Visitati;
      Lista Route;
      Lista :: pos q, p=q=Route.primolista();
      peso w=0;

      cout<<"\n Inserisci gli estremi del percorso:";
		cout<<"\n Inizia dal nodo: ";
      cin>>i;
      cout<<"\n e termina al nodo: ";
      cin>>j;
      cout<<"\n nodo iniziale ->";
  		trova_route(G,Visitati,Route,i,j,trovato);

      while(!Route.finelista(p))
      	{
      		cout<<"["<<Route.leggilista(p)<<"]";
            q=p;
            p=Route.succlista(p);
            if(!Route.finelista(p))
            	w=w+G.pesoarco(Route.leggilista(q),Route.leggilista(p));
         }
      cout<<"<- ultimo nodo";
      return w;
	}

peso stampa_incid_mat(Grafo G)
//la procedura stampa la matrice di incidenza che rappresenta il grafo in input
	{
      enum{MAX_ARCHI=190,MAX_NODI=20};
      Grafo :: nodo i,j;
		Grafo :: nodo vett_archi[MAX_NODI][MAX_ARCHI]; //matrice di appoggio
      Grafo :: boolean trovato;

      for(i=0;i<MAX_NODI;i++) //inizializzazione matrice di appoggio
      	for(j=0;j<MAX_ARCHI;j++)
        		vett_archi[i][j]=0;

      j=0;
      for(i=0;i<MAX_NODI;i++) //annotazione pesi e archi
      	{
            Lista :: pos p=G.adiacenti(i).primolista();
	      	while(!G.adiacenti(i).finelista(p))
      			{
         			vett_archi[i][j]=-G.pesoarco(i,G.adiacenti(i).leggilista(p));
         			vett_archi[G.adiacenti(i).leggilista(p)][j]=-vett_archi[i][j];
                  p=G.adiacenti(i).succlista(p);
                  j++;
         		}
         }

      int nodi=1,
      	 archi=j;
      for(i=0;i<MAX_NODI;i++) //conteggio nodi
         {
            trovato=false;
      		for(j=0;j<MAX_ARCHI;j++)
         		{
	        			if(vett_archi[i][j]<0)
               		trovato=true;
            	}
            if(trovato)
            	nodi++;
         }

		cout<<"\n\n";
      for(int i=1;i<=nodi;i++) //stampa matrice di incidenza
        	{
         	cout<<"\n    ";
	      	for(int j=0;j<archi;j++)
            	if(vett_archi[i][j]<0)
         			cout<<" "<<vett_archi[i][j];
               else
         			cout<<"  "<<vett_archi[i][j];
         }
	}

void stampa_matrice(Grafo G, int ord)
//stampa la matrice di adiacenza dove l'elemento aij rappresenta
//il peso dell'arco che esce da i e entra in j.
	{
      cout<<"\n\n   ";
   	for(int i=1;i<=ord;i++)
      	{
   			for(int j=1;j<=ord;j++)
    	         if(!G.esistearco(i,j))
     					cout<<"! ";
	            else
     					cout<<G.pesoarco(i,j)<<" ";
            cout<<"\n   ";
         }
   }

void wait(char *msg)
//funzione utility per interrompere l'esecuzione del programma
//attende l'input dell'utente per ripartire
	{
   	char stop='?';

      cout<<msg;
      while(stop!='y' && stop!='Y')
      	cin>>stop;
   }

