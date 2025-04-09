#ifndef NODOPTR_H
#define NODOPTR_H

#include "NodoCoda.h"

class NodoPtrCoda; // dichiarazione anticipata
typedef NodoPtrCoda *posizioneCoda; //necessita della dichiarazione anticipata

class NodoPtrCoda: public NodoCoda{ // NodoPtrCoda estende Nodo
public:
   NodoPtrCoda(); // costruttore standard
   NodoPtrCoda(elemCoda);  // costruttore che inizializza l'etichetta
   NodoPtrCoda(elemCoda, posizioneCoda); // etichetta + puntatore
   ~NodoPtrCoda(); // distruttore
   
   posizioneCoda getSuccessivo();
   void setSuccessivo(posizioneCoda);
   
private:
   posizioneCoda successivo;
};

#endif
