



#ifndef GRAFO_H
#define GRAFO_H
#include "Nodog.h"
const int MAX=30;

typedef int nodo;

class Grafo
{
	private:
  	Nodog insieme[MAX];
   public:
   int listadiacenti[MAX-1];

   Grafo();
   ~Grafo();

   void creagrafo();

   bool grafovuoto();

   void insnodo(nodo);

   void insarco(nodo, nodo);

   void cancnodo(nodo);

   void cancarco(nodo, nodo);

   bool esistenodo(nodo);

   bool esistearco(nodo, nodo);

   tipoelem legginodo(nodo);

   void scrivinodo(tipoelem, nodo);

   void adiacenti(nodo);

   void marcanodo(nodo);

   bool nodomarcato(nodo);

	void smarcatuttinodi();
};

#endif
