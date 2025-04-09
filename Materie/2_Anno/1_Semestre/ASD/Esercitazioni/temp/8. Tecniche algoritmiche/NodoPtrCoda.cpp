#include <iostream>
#include <cstdlib>
#include "NodoPtrCoda.h"

NodoPtrCoda::NodoPtrCoda(): NodoCoda(0){
   successivo = 0;
};

NodoPtrCoda::NodoPtrCoda(elemCoda a): NodoCoda(a){
   successivo = NULL;
};

NodoPtrCoda::NodoPtrCoda(elemCoda a, posizioneCoda p): NodoCoda(a){
   successivo = p;
};

NodoPtrCoda::~NodoPtrCoda(){};
   
posizioneCoda NodoPtrCoda::getSuccessivo(){
   return successivo;
};

void NodoPtrCoda::setSuccessivo(posizioneCoda p){
   successivo = p;     
};
