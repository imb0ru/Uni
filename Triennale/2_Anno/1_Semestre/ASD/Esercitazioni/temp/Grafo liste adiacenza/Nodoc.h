#ifndef NODOC_H
#define NODOC_H
#include "Nodop.h"

typedef Nodop *puntaelem;

class Nodoc{
   public:
   puntaelem valore;
   int succ;

   Nodoc();
   ~Nodoc();
   puntaelem leggivalore();
   void scrivivalore(puntaelem);
   int leggisucc();
   void scrivisucc(int);
   };

#endif
