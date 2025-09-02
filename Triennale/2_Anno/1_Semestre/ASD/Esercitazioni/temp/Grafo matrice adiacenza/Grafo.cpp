



#include <iostream>
#include "Grafo.h"

Grafo::Grafo(){creagrafo();};

Grafo::~Grafo(){};

void Grafo::creagrafo()
{
   int x,y;
   for (x=0;x<MAX;x++)
   {
   	insieme[x]=0;
   };
   for (x=0;x<MAX;x++)
   {
     	for (y=1; y<=MAX;y++)
      {
      	matrice[x][y]=false;
      };
   };
};

bool Grafo::grafovuoto()
{
	int c;
   for (c=0; c<MAX; c++)
   {
   	if (insieme[c]!=0)
      	return false;
      c++;
   }
            return true;};

nodo Grafo::postolibero()
{
	int c;c=0;
   while (insieme[c]!=0)
   {
   	c++;
   };
   return c;
};

nodo Grafo::trovaelem(tipoelem val)
{
	int c;
   c=0;
   while (insieme[c]!=val)
   {
   	c++;
   }
   return c;
};

void Grafo::insnodo(tipoelem val)
{
	insieme[postolibero()]=val;
};

void Grafo::insarco(tipoelem val1, tipoelem val2)
{
	int x,y;
   x=trovaelem(val1);
   y=trovaelem(val2);
   matrice[x][y]=true;
   matrice[y][x]=true;
};

void Grafo::cancnodo(tipoelem val)
{
	insieme[trovaelem(val)]=0;
};

void Grafo::cancarco(tipoelem val1, tipoelem val2)
{
	matrice[trovaelem(val1)][trovaelem(val2)]=false;
   matrice[trovaelem(val2)][trovaelem(val1)]=false;
};

bool Grafo::esistenodo(tipoelem val)
{
	int c;
   for (c=0;c<MAX;c++)
   {
   	if (insieme[c]==val)
      	return true;
      c++;
   };
   return false;
};

bool Grafo::esistearco(tipoelem val1, tipoelem val2)
{
   return (matrice[trovaelem(val1)][trovaelem(val2)]==true);
};


tipoelem Grafo::legginodo(nodo x)
{
	return insieme[x];
};

void Grafo::scrivinodo(tipoelem val ,nodo x)
{
	insieme[x]=val;
};

void Grafo::adiacenti(tipoelem val)
{
	int c;
   for (c=0;c<MAX;c++)
   {
   	if (matrice[trovaelem(val)][c]==true)
        	cout << legginodo(c) << " ";
   }
   cout << endl;
};
