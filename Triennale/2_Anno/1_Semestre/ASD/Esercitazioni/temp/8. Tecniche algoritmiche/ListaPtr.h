#ifndef LISTAPTR_H
#define LISTAPTR_H

#include "NodoPtr.h"

class ListaPtr{
public:
   ListaPtr(); // costruttore
   ~ListaPtr(); // distruttore
   
   void creaLista();
   bool listaVuota();
   posizione primoLista();
   
   posizione predLista(posizione);
   posizione succLista(posizione);
   bool fineLista(posizione);
   
   void insLista(tipoelem, posizione);
   bool cancLista(posizione);
   bool scriviLista(tipoelem, posizione);
   bool leggiLista(tipoelem &, posizione);
   
   posizione pos(int); // mapping della posizione

private:
   posizione primo;
};

#endif
