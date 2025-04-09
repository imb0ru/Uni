
//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi


//Esame di Algoritmi e Strutture Dati


//Autore: Nico Spadoni
//matr.428389




//..............................................................................
//.......... REALIZZAZIONE GRAFO ORIENTATO CON MATRICE DI INCIDENZA ............
//................................ (PESATO) ....................................
//..............................................................................




//Implementazione operatori grafo



void Grafo :: creagrafo()
	{
		card_nodi=0;
		card_archi=0;
		for(int i=1; i<=MAX_NODI; i++)	//inizializzazione
			for(int j=1; j<=MAX_ARCHI; j++)
   			incid_mat[i-1][j-1]=NULLO;
	}



bool Grafo :: grafovuoto()
	{
		if(card_nodi==0)
      	return true;
      else
      	return false;
	}



void Grafo :: insnodo(nodo n)
	{
		if(card_nodi==MAX_NODI)
      //se è già stato raggiunto l'card_nodi max della matrice
	     	cout<<"\n Non è più possibile inserire altri nodi!";
		else
         card_nodi++;
	}



void Grafo :: insarco(nodo ni, nodo nj, peso pij)
	{
      card_archi++;
		if (ni>0 && ni<=card_nodi && nj>0 && nj<=card_nodi)
        	{
         	incid_mat[ni-1][card_archi-1]=-pij;
         	incid_mat[nj-1][card_archi-1]=pij;
			}
		else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
	}


void Grafo :: cancnodo(nodo n)
	{
		if (n<=0 || n>card_nodi)
	     	cout<<"\n Il nodo non appartiene al grafo!";
		else
    		{
         	for(int i=n; i<=card_nodi; i++)
	    			for(int j=1; j<=card_archi; j++)
               	{
                     if(i==n && incid_mat[i-1][j-1]!=NULLO)
	                  	for(int k=0;k<=card_nodi;k++)
					         	incid_mat[k-1][j-1]=NULLO;

        					incid_mat[i-1][j-1]=incid_mat[i][j-1];
                  }
            card_nodi--;
         }
	}


void Grafo :: cancarco(nodo ni, nodo nj)
	{
		if (ni>0 && ni<=card_nodi && nj>0 && nj<=card_nodi)
	   	for(int j=1;j<=card_archi;j++)
           	if(incid_mat[ni-1][j-1]<NULLO && incid_mat[nj-1][j-1]>NULLO)
              	{
    					incid_mat[ni-1][j-1]=NULLO;
   					incid_mat[nj-1][j-1]=NULLO;
  					}
		else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
	}


Grafo :: boolean Grafo :: esistenodo(nodo n)
	{
		if (n<=0 || n>card_nodi)
	     	return false;
		else
	     	return true;
	}


Grafo :: boolean Grafo :: esistearco(nodo ni, nodo nj)
	{
		if (ni>0 && ni<=card_nodi && nj>0 && nj<=card_nodi)
	   	{
         	for(int j=1;j<=card_archi;j++)
           		if(incid_mat[ni-1][j-1]<NULLO && incid_mat[nj-1][j-1]>NULLO)
						return true;

			 	return false;
         }
      else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
	}

Lista Grafo :: adiacenti(nodo n)
	{
      Lista A;
      A.crealista();

		if (n<=0 || n>card_nodi)
	     	cout<<"\n Il nodo non appartiene al grafo!";
		else
	   	for(int j=1;j<=card_archi;j++)
           	if(incid_mat[n-1][j-1]<NULLO)
			   	for(int i=1;i<=card_nodi;i++)
		           	if(incid_mat[i-1][j-1]>NULLO)
								A.inslista(A.primolista(),i);
      return A;
	}

Grafo :: peso Grafo :: pesoarco(nodo ni, nodo nj)
	{
		if (ni>0 && ni<=card_nodi && nj>0 && nj<=card_nodi)
         {
	   		for(int j=1;j<=card_archi;j++)
           		if(incid_mat[ni-1][j-1]<NULLO && incid_mat[nj-1][j-1]>NULLO)
						return -incid_mat[ni-1][j-1];

          		return INFINITO;
         }
      else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
   }



Grafo :: Grafo()
	{
		creagrafo();
	}



Grafo :: ~Grafo()
	{}



