#ifndef CODAPTR_H
#define CODAPTR_H

#include "NodoPtrCoda.h"

class CodaPtr {
public:
   CodaPtr();
   ~CodaPtr();
   
   void creaCoda();
   bool codaVuota();
   
   bool leggiCoda(elemCoda &);
   
   void inCoda(elemCoda);
   bool fuoriCoda();

private:
   posizioneCoda testa, fondo;   
};


#endif
