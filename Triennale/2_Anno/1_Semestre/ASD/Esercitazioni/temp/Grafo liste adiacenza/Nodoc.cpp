#include "Nodoc.h"

//file nodoc.cpp creato esclusivamente per l'implementazione
//dei cursori

Nodoc::Nodoc(){Nodoc::succ=-1;};
Nodoc::~Nodoc(){};
puntaelem Nodoc::leggivalore(){return valore;};
void Nodoc::scrivivalore(puntaelem x){valore=x;};
int Nodoc::leggisucc(){return succ;};
void Nodoc::scrivisucc(int x){succ=x;};

