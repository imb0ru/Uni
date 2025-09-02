/*
  Nome: NodoPtrInsieme.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo dell'insieme con
               lista non ordinata
*/

#ifndef NODOPTRINSIEME_H
#define NODOPTRINSIEME_H

#include "NodoInsieme.h"

class NodoPtrInsieme; // dichiarazione anticipata
typedef NodoPtrInsieme *posizione; //necessita della dichiarazione anticipata

class NodoPtrInsieme: public NodoInsieme{ // NodoPtrInsieme estende Nodo
public:
   NodoPtrInsieme(); 
   NodoPtrInsieme(tipoelem);  // costruttore che inizializza l'etichetta
   NodoPtrInsieme(tipoelem, posizione); // etichetta + puntatore
   ~NodoPtrInsieme(); 
   
   posizione getSuccessivo();
   void setSuccessivo(posizione);
   
private:
   posizione successivo;
};

#endif
