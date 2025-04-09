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
#include "classe_lista.h"

void acquisizione(Lista &P)
	{
		Lista::pos p=P.primolista();

		double a;
      int i,r;

		cout<<"\n\n Inserire il grado del polinomio:\n\n"
      	 <<" Grado = ";
      cin>>r;

		cout<<"\n\n Inserire i coefficienti del polinomio che si vuole\n"
        	 <<" definire a partire dal termine di grado 0.\n ";
		for(i=0;i<=r;i++)
      	{
				cout<<"\n Coefficiente di x^"<<i<<" : ";
				cin>>a;

				Lista::tipoelem elem(a);
				P.inslista(elem,p);
            p=P.succlista(p);
         }
}

void visualizzazione(const Lista &P)
	{
      int esp=0;
      char sign=' ';
		if (P.listavuota())
      	{
         	cout<<"\n La lista vuota!!!";
            return;
         }

      Lista::pos p=P.primolista();
		cout<<"\n\n    Ecco la lista polinomio elaborata: ";
		cout<<"\n --------------------------------------------------------";
		cout<<"\n  P(x)= ";
		while(!P.finelista(p))
			{
				if(P.leggilista(p)>0 && esp!=0)
            	cout<<(sign='+');

        		if(P.leggilista(p)==0){}
	            else
               	{
     						if(P.leggilista(p)==1)
                  		{
                     		if(esp==0)
										cout<<P.leggilista(p);
                     	}
                  	else
                     	if(P.leggilista(p)==-1)
                        	cout<<"-";
								else
									cout<<P.leggilista(p);

     						if(esp==0)
                     	cout<<" ";
								else
              					if(fabs(esp)==1)
										cout<<"x"<<" ";
               				else
										cout<<"x^"<<esp<<" ";
                   }
      		p=P.succlista(p);
            esp++;
   		}
		cout<<"\n --------------------------------------------------------\n\n\n";
}

double eval(const Lista &P, double x)
	{
      Lista::pos p=P.primolista();
      double val;
      int esp=0;
      while(!P.finelista(p))
			{
            if(x==0 && esp==0)
					val=P.leggilista(p);
            else
					val=val+(P.leggilista(p)*pow(x,esp));
  				p=P.succlista(p);
        		esp++;
   		}

   	return val;
   }

void somma(const Lista &P1, const Lista &P2, Lista &Sum)
	{
	   Lista::pos p1=P1.primolista(),
      			  p2=P2.primolista(),
   				  pivot=Sum.primolista();

      while(!P1.finelista(p1))
      	{
	  			Sum.inslista(P1.leggilista(p1),pivot);
            p1=P1.succlista(p1);
         }

      pivot=Sum.primolista();
      
      while(!P2.finelista(p2))
      	{
            if(!Sum.finelista(pivot))
            	{
  						Sum.scrivilista((Sum.leggilista(pivot)+P2.leggilista(p2)),pivot);
	            	pivot=Sum.succlista(pivot);
               }
            else
     				Sum.inslista(P2.leggilista(p2),pivot);
            p2=P2.succlista(p2);
         }
      return;
   }


void differenza(const Lista &P1, const Lista &P2, Lista &Diff)
	{
	   Lista::pos p1=P1.primolista(),
      			  p2=P2.primolista(),
   				  pivot=Diff.primolista();

      while(!P1.finelista(p1))
      	{
	  			Diff.inslista(P1.leggilista(p1),pivot);
            p1=P1.succlista(p1);
         }

      pivot=Diff.primolista();
      
      while(!P2.finelista(p2))
      	{
            if(!Diff.finelista(pivot))
            	{
  						Diff.scrivilista((Diff.leggilista(pivot)-P2.leggilista(p2)),pivot);
	            	pivot=Diff.succlista(pivot);
               }
            else
     				Diff.inslista((-P2.leggilista(p2)),pivot);
            p2=P2.succlista(p2);
         }
      return;
   }






















