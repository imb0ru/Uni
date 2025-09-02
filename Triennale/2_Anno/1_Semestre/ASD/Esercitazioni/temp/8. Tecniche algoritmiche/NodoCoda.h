#ifndef NODOCODA_H
#define NODOCODA_H
#include "GrafoAdiacenti.h"

typedef Nodo elemCoda;

class NodoCoda{
public:
   NodoCoda(); // costruttore standard
   NodoCoda(elemCoda);  // costruttore che inizializza l'etichetta
   ~NodoCoda(); // distruttore
   
   elemCoda getEtichetta();
   void setEtichetta(elemCoda);
   
private:
   elemCoda etichetta;
};

#endif
