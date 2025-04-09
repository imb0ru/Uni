#include <iostream>
#include <cstdlib>
#include "Nodo.h"


Nodo::Nodo(){
   etichetta = 0;
};


Nodo::Nodo(tipoelem a){
   etichetta = a;
};


Nodo::~Nodo(){};


tipoelem Nodo::getEtichetta(){
   return etichetta;
};


void Nodo::setEtichetta(tipoelem a){
   etichetta = a;     
};
