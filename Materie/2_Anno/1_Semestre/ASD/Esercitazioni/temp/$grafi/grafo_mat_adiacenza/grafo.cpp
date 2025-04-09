//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.......... REALIZZAZIONE GRAFO ORIENTATO CON MATRICE DI ADIACENZA ............
//................................ (PESATO) ....................................
//..............................................................................



//Implementazione operatori grafo


void Grafo :: creagrafo()
	{
		ordine=0; //la matrice di ordine zero è una matrice vuota
		for(int i=1; i<=MAX_ORD; i++)	//inizializzazione
			for(int j=1; j<=MAX_ORD; j++)
  	   		adi_mat[i-1][j-1]=INFINITO;
	}




bool Grafo :: grafovuoto()
	{
		if(ordine==0)
      	return true;
      else
      	return false;
	}



void Grafo :: insnodo(nodo n)
	{
		if(ordine==MAX_ORD) //se è già stato raggiunto l'ordine max della matrice
	     	cout<<"\n Non è più possibile inserire altri nodi!";
		else
	      ordine++;
	}

void Grafo :: insarco(nodo ni, nodo nj, peso pij)
	{
		if (ni>0 && ni<=ordine && nj>0 && nj<=ordine)
        	adi_mat[ni-1][nj-1]=pij;
		else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
	}

void Grafo :: cancnodo(nodo n)
	{
		if (n<=0 || n>ordine)
	     	cout<<"\n Il nodo non appartiene al grafo!";
		else
    		{
         	for(int i=n; i<=ordine; i++)
	    			for(int j=1; j<=ordine; j++)
        				adi_mat[i-1][j-1]=adi_mat[i][j-1];
            ordine--;
         }
	}


void Grafo :: cancarco(nodo ni, nodo nj)
	{
		if (ni>0 && ni<=ordine && nj>0 && nj<=ordine)
   		adi_mat[ni-1][nj-1]=INFINITO;
		else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
	}


Grafo :: boolean Grafo :: esistenodo(nodo n)
	{
		if (n<=0 || n>ordine)
	     	return false;
		else
	     	return true;
	}


Grafo :: boolean Grafo :: esistearco(nodo ni, nodo nj)
	{
		if (ni>0 && ni<=ordine && nj>0 && nj<=ordine)
	   	if(adi_mat[ni-1][nj-1]==INFINITO)
   	   	return false;
			else
	     		return true;
      else
	     	cout<<"\n Uno o entrambi i nodi non appartengono al grafo!";
	}

Lista Grafo :: adiacenti(nodo n)
	{
      Lista A;
      A.crealista();

		if (n<=0 || n>ordine)
	     	cout<<"\n Il nodo non appartiene al grafo!";
		else
    		{
    			for(int j=1; j<=ordine; j++)
     				if(adi_mat[n-1][j-1]!=INFINITO)
						A.inslista(A.primolista(),j);
         }
      return A;
	}

Grafo :: peso Grafo :: pesoarco(nodo ni, nodo nj)
	{
   	return adi_mat[ni-1][nj-1];
   }

Grafo :: Grafo()
	{
		creagrafo();
	}

Grafo :: ~Grafo()
	{}
