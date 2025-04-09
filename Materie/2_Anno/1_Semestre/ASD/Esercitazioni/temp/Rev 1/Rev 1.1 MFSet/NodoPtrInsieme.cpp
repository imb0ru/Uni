#include <iostream>
#include <cstdlib>
#include "NodoPtrInsieme.h"

NodoPtrInsieme::NodoPtrInsieme(): NodoInsieme(0){
   successivo = NULL;
};

NodoPtrInsieme::NodoPtrInsieme(tipoelem a): NodoInsieme(a){
   successivo = NULL;
};

NodoPtrInsieme::NodoPtrInsieme(tipoelem a, posizione p): NodoInsieme(a){
   successivo = p;
};

NodoPtrInsieme::~NodoPtrInsieme(){};
   
posizione NodoPtrInsieme::getSuccessivo(){
   return successivo;
};

void NodoPtrInsieme::setSuccessivo(posizione p){
   successivo = p;     
};
