
//Definizione funzioni di servizio


#include <stdlib.h>
#include <iostream.h>
#include "classe_lista.h"



void acquisizione(Lista &R)
//crea la lista e la popola da imput utente, acquisendo le coordinate degli
//estremi della diagonale dei rettangoli
	{
		Lista::pos p=R.primolista();

		double a,b,c,d;
      char e='$';

		while(e!='N' && e!='n')
      	{
				cout<<"\n\n Inserire le coordinate del vertice alto a destra";
            cout<<"\n [dopo ogni inserimento premere Invio]\n";

				cout<<"\n   x(ad)= ";
				cin>>a;

				cout<<"   y(ad)= ";
				cin>>b;

				cout<<"\n Inserire le coordinate del vertice basso a sinstra\n";

				cout<<"\n   x(bs)= ";
				cin>>c;

				cout<<"   y(bs)= ";
				cin>>d;

				Lista::tipoelem elem(a,b,c,d);
				R.inslista(elem,p);
            p=R.succlista(p);
            cout<<"\n\n Per inserire nella lista un altro rettangolo"
            	 <<"\n premere [Y], per terminare premere [N]";
            cin>>e;
         }
}




void visualizzazione(Lista &R)
//stampa la lista dei rettangoli
	{
		if (R.listavuota())
      	{
         	cout<<"\n La lista vuota!!!";
            return;
         }

      Lista::pos p=R.primolista();
      int i=0;
		
		cout<<"\n\n Ecco la lista dei rettangoli elaborata: ";
		cout<<"\n ---------------------------------------------";
		
		while(!R.finelista(p))
			{
            i++;
				cout<<"\n "<<i<<"^ Rettangolo: [ ad=("<<
            R.leggilista(p).xad<<","<<R.leggilista(p).yad<<");  bs=("<<
            R.leggilista(p).xbs<<","<<R.leggilista(p).ybs<<") ]";

      		p=R.succlista(p);
   		}
		
		cout<<"\n ---------------------------------------------\n\n\n\n\n\n";
	}




Lista :: boolean inscritto(Lista :: tipoelem a, Lista :: tipoelem b)
//verifica se il primo parametro-rettangolo è inscritto nel secondo
	{
   	if(b.xbs<=a.xbs && b.xad>=a.xad && b.ybs<=a.ybs && b.yad>=a.yad)
      	return true;
      else
      	return false;
   }





void epurazione(Lista &R)
//rimuove i nodi contenenti tutti i rettangoli inscritti
//in altri rettangoli della lista
	{
      Lista::pos 	pivot=R.primolista(),
      				p=pivot;

		while(!R.finelista(pivot))
			{
				while(!R.finelista(p))
					{
                  if(pivot==p)
                  	p=R.succlista(p);

    					if(inscritto(R.leggilista(p),R.leggilista(pivot)))
                  	{
                     	p=R.succlista(p);
                     	R.canclista(R.predlista(p));
                     }
						else
                  	p=R.succlista(p);
					}
            p=R.primolista();
				pivot=R.succlista(pivot);
			}
		return;
   }


double maxarea(Lista &R)
//individua l'area massima tra quelle dei rettangoli nella lista
	{

      Lista::pos 	p=R.primolista();
      double max=R.leggilista(p).area();

      p=R.succlista(p);
      while(!R.finelista(p))
			{
				if(R.leggilista(p).area()>max)
            	max=R.leggilista(p).area();
				p=R.succlista(p);
			}
		return max;
   }


void nonoverlap(Lista &S, Lista &R)
//crea una sottolista in cui inserire solo i rettangoli che non si sovrappogono
	{
      Lista::pos 		pivot=R.primolista(),
      					p=pivot;
      Lista::boolean pOverlap, sentinella, condX, condY;
      float sommaBasi, sommaAltezze;
		while(!R.finelista(pivot))
			{
        		sentinella=false;
				while(!R.finelista(p) && !sentinella)
					{
               	if(pivot==p)
               		p=R.succlista(p);
//condizione per cui il rettangolo in p si sovrappone a quello in pivot è dedotta dal verificarsi di due condizioni:
//condX (prima condizione) che la somma delle basi sia maggiore uguale tanto alla distanza tra i punti xad di p e
//xbs di pivot, quanto tra i punti xad di pivot e xbs di p. Il controllo va effettuato 2 volte perchè non si può 
//sapere a priori le rispettive posizioni dei rettangoli sul piano cartesiano...
//condY (seconda condizione) che la somma delle altezze sia maggiore uguale tanto alla distanza tra i punti 
//yad di p e ybs di pivot, quanto tra i punti yad di pivot e ybs di p. 
//Analogamente il controllo va effettuato 2 volte
				sommaBasi=
					R.leggilista(p).base()+R.leggilista(pivot).base();
                  condX=(sommaBasi>=
                  		 fabs(R.leggilista(p).xbs-R.leggilista(pivot).xad))&&
                         sommaBasi>=
                  		 fabs(R.leggilista(pivot).xbs-R.leggilista(p).xad);
                  sommaAltezze=
                  	R.leggilista(p).altezza()+R.leggilista(pivot).altezza();
                  condY=(sommaAltezze>=
                  		 fabs(R.leggilista(p).ybs-R.leggilista(pivot).yad))&&
                         sommaAltezze>=
                  		 fabs(R.leggilista(pivot).ybs-R.leggilista(p).yad);
                  pOverlap=(condX&&condY);
                //se si verifica una sovrapposizione la sentinella registra l'evento e cambia il suo stato a TRUE
    					if(pOverlap)
							sentinella=true;
						p=R.succlista(p);
					}
            if(!sentinella)
			//se il pivot corrente non risulta sovrapposto ad uno dei p scanditi viene copiato nella sottolista
           		S.inslista(R.leggilista(pivot),S.primolista());
			pivot=R.succlista(pivot);
            p=R.primolista();
			}
		return;
   }