#include <stdlib.h>
#include <iostream.h>
#include "ins.h"
#include "ins.cpp"
#include "coda.h"
#include "coda.cpp"
#include "lista.h"
#include "lista.cpp"
#include "grafo.h"
#include "grafo.cpp"
#include "grafo_servizio_def.cpp"

int main()
	{
		Grafo G;
      char ripeti='?';
      int num_nodi;


      build_grafo(G,num_nodi);
      ripeti='?';

      cout<<"\n\n La matrice di incidenza e' la seguente:";
      stampa_incid_mat(G);

      cout<<"\n\n La matrice di adiacenza e' la seguente:";
		stampa_matrice(G, num_nodi);

      cout<<"\n\n Visita del Grafo in profondita'(DFS)"
      	 <<"\n e stampa del percorso a partire da un nodo scelto";
		visita_dfs(G);

      cout<<"\n\n Visita del Grafo in ampiezza(BFS)"
      	 <<"\n e stampa del percorso a partire da un nodo scelto";
		visita_bfs(G);

      cout<<"\n\n Stampa del percorso tra due nodi scelti";
		peso peso_route=stampa_route(G);
      cout<<"\n tale percorso ha un costo pari a: "<<peso_route;

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
	}
