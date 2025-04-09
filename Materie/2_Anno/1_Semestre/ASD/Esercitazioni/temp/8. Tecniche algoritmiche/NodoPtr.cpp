#include <iostream>
#include <cstdlib>
#include "NodoPtr.h"

NodoPtr::NodoPtr(): Nodo(0){
   successivo = NULL;
};

NodoPtr::NodoPtr(tipoelem a): Nodo(a){
   successivo = NULL;
};

NodoPtr::NodoPtr(tipoelem a, posizione p): Nodo(a){
   successivo = p;
};

NodoPtr::~NodoPtr(){};
   
posizione NodoPtr::getSuccessivo(){
   return successivo;
};

void NodoPtr::setSuccessivo(posizione p){
   successivo = p;     
};
