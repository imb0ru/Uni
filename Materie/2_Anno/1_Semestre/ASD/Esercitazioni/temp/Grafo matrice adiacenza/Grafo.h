


#ifndef GRAFO_H
#define GRAFO_H

const int MAX=30;

typedef int nodo;
typedef char tipoelem;

class Grafo
{

	tipoelem insieme[MAX];
   bool matrice[MAX][MAX];

   Grafo();
   ~Grafo();

   void creagrafo();

   bool grafovuoto();

   void insnodo(tipoelem);

   void insarco(tipoelem, tipoelem);

   void cancnodo(tipoelem);

   void cancarco(tipoelem, tipoelem);

   bool esistenodo(tipoelem);

   bool esistearco(tipoelem, tipoelem);

   tipoelem legginodo(nodo);

   void scrivinodo(tipoelem, nodo);

   nodo postolibero();

   nodo trovaelem(tipoelem);

   void adiacenti(tipoelem);

};

#endif
