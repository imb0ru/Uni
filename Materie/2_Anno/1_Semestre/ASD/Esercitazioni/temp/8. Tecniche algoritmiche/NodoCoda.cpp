#include <iostream>
#include <cstdlib>
#include "NodoCoda.h"


NodoCoda::NodoCoda(){
   etichetta = 0;
};


NodoCoda::NodoCoda(elemCoda a){
   etichetta = a;
};

NodoCoda::~NodoCoda(){};

elemCoda NodoCoda::getEtichetta(){
   return etichetta;
};

void NodoCoda::setEtichetta(elemCoda a){
   etichetta = a;     
};
