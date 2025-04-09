#include <iostream>
#include <cstdlib>

#include "CodaPtr.h"

CodaPtr::CodaPtr(){
   creaCoda();
};

CodaPtr::~CodaPtr(){
   posizioneCoda q;
   while (testa != NULL){
      q = testa;
      testa = testa->getSuccessivo();
      delete q;
   }
};
   
void CodaPtr::creaCoda(){
   testa = fondo = NULL;
};

bool CodaPtr::codaVuota(){
   return testa == NULL;
};
   
bool CodaPtr::leggiCoda(elemCoda &a){
   if (testa != NULL){
      a = testa->getEtichetta();
      return true;
   } else return false;
};
   
void CodaPtr::inCoda(elemCoda a){
   posizioneCoda q = new NodoPtrCoda(a);
   if (testa != NULL){
      fondo->setSuccessivo(q);
      fondo = q;
   }
   else
      testa = fondo = q;   
};

bool CodaPtr::fuoriCoda(){
   if (testa != NULL){
      posizioneCoda q = testa;
      testa = testa->getSuccessivo();
      delete q;
      return true;
   } else return false;
};

