#include <iostream>
#include <cstdlib>
#include "NodoInsieme.h"

NodoInsieme::NodoInsieme(){
   etichetta = 0;
}

NodoInsieme::NodoInsieme(tipoelem a){
   etichetta = a;
}

NodoInsieme::~NodoInsieme(){}

tipoelem NodoInsieme::getEtichetta(){
   return etichetta;
}

void NodoInsieme::setEtichetta(tipoelem a){
   etichetta = a;     
}
