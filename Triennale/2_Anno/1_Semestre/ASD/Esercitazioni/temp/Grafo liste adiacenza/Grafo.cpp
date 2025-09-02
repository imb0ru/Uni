
#include <iostream>
#include "Grafo.h"

	Grafo::Grafo()
	{
		creagrafo();
   };

	Grafo::~Grafo(){};

	void Grafo::creagrafo()
   {
   	for (int i=0; i<MAX-1; i++)
   	listadiacenti[i]=-1;
   };

	bool Grafo::grafovuoto()
   {
   	bool tf;
   	for (int i=0; i<MAX; i++)
      {
      	if (insieme[i].leggiPresente()==true)
         {
         	tf=true;
            i=MAX+1;
         }
      }
      return tf;
   };

   void Grafo::insnodo(nodo x)
   {
   if (x>=MAX)
   	cout<< "numero non valido, nessun inserimento avvenuto";
      else
   	insieme[x].setPresenteYes();
   };

   void Grafo::insarco(nodo x, nodo y)
   {
         Rifnodoa *ptr;
         ptr=insieme[x].ad;
         insieme[x].ad=new Rifnodoa;
         insieme[x].ad->pos=y;
         insieme[x].ad->succ=ptr;

         Rifnodoa *ptr2;
         ptr2=insieme[y].ad;
         insieme[y].ad=new Rifnodoa;
         insieme[y].ad->pos=x;
         insieme[y].ad->succ=ptr2;
   };

   void Grafo::cancnodo(nodo x)
   {
   	insieme[x].setPresenteNo();
      insieme[x].setVisitatoNo();
      insieme[x].ad=0;
   };

   void Grafo::cancarco(nodo x, nodo y)
   {
   	Rifnodoa *ptr;
      Rifnodoa *ptr2;
      if (esistearco(x,y))
      {
	      ptr=insieme[x].ad;
   	   if (ptr->pos==y)
         {
         	insieme[x].ad=ptr->succ;
         }
      	else
      	{
      		while (ptr->succ!=0)
      		{
       			ptr=ptr->succ;
        			if (ptr->pos==y)
               {
               	ptr2=ptr;
                  ptr=insieme[x].ad;
                  while (ptr->succ!=ptr2)
                  {
                  	ptr=ptr->succ;
                  }
                  ptr->succ=ptr2->succ;
               }
    			}
      	}
      }
      else
      {
      	cout << "l'arco che vuoi cancellare e' gia' assente\n";
      }

      if (esistearco(y,x))
      {
      	ptr=insieme[y].ad;
      	if (ptr->pos==x)
         {
         	insieme[y].ad=ptr->succ;
         }
      	else
      	{
      		while (ptr->succ!=0)
      		{
       			ptr=ptr->succ;
        			if (ptr->pos==x)
               {
               	ptr2=ptr;
                  ptr=insieme[y].ad;
                  while (ptr->succ!=ptr2)
                  {
                  	ptr=ptr->succ;
                  }
                  ptr->succ=ptr2->succ;
               }
    			}
      	}
      }
      else
      {
      	cout << "l'arco che vuoi cancellare e' gia' assente\n";
      }
   };

   bool Grafo::esistenodo(nodo x)
   {
   	return insieme[x].leggiPresente()==true;
   };

   bool Grafo::esistearco(nodo x, nodo y)
   {
      bool tf=false;
   	Rifnodoa *ptr;
      ptr=insieme[x].ad;
      if (ptr->pos==y)
      	tf=true;
      else
      {
      	while (ptr->succ!=0)
      	{
       		ptr=ptr->succ;
        		if (ptr->pos==y)
            	tf=true;
    		}
      }
      return tf;
   };

   tipoelem Grafo::legginodo(nodo x)
   {
   	return insieme[x].getLabel();
   };

   void Grafo::scrivinodo(tipoelem val ,nodo x)
   {
   	insieme[x].setLabel(val);
   };

   void Grafo::adiacenti(nodo x)
   {
      for (int i=0; i<MAX-1; i++)
      listadiacenti[i]=-1;
      Rifnodoa *ptr;
      ptr=insieme[x].ad;
      int i=0;
		while (ptr!=0)
      {
      	listadiacenti[i]=ptr->pos;
         i++;
         ptr=ptr->succ;
      }
   };

	void Grafo::marcanodo(nodo x)
   {
   	insieme[x].setVisitatoYes();
   };

   bool Grafo::nodomarcato(nodo x)
   {
   	return (insieme[x].leggiVisitato()==true);
   };



   void Grafo::smarcatuttinodi()
   {
   	for (int i=0; i<MAX; i++)
      	insieme[i].setVisitatoNo();
   };
