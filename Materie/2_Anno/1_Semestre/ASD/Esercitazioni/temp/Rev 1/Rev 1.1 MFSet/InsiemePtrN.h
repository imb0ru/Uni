/*
  Nome: InsiemePtrN.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa l'insieme con lista non ordinata
*/

#ifndef INSIEMEPTRN_H
#define INSIEMEPTRN_H

#include "NodoPtrInsieme.h"

class InsiemePtrN{
public:
   InsiemePtrN();
	~InsiemePtrN();
		
	void creaInsieme();
   bool insiemeVuoto();
   bool appartiene(tipoelem);
   bool inserisci(tipoelem);
   bool cancella(tipoelem);
   InsiemePtrN &unione(InsiemePtrN &);
   InsiemePtrN &intersezione(InsiemePtrN &);
   InsiemePtrN &differenza(InsiemePtrN &);
   
   posizione getInsieme();
	InsiemePtrN &operator=(InsiemePtrN &);
	   
private:
   posizione insieme;
};

#endif
