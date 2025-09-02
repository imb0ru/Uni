/*
  Nome: Nodo.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo
*/

#ifndef NODOINSIEME_H
#define NODOINSIEME_H

typedef int tipoelem;

class NodoInsieme {
public:
   NodoInsieme(); // costruttore standard
   NodoInsieme(tipoelem);  // costruttore che inizializza l'etichetta
   ~NodoInsieme(); // distruttore
   
   tipoelem getEtichetta();
   void setEtichetta(tipoelem);
   
private:
   tipoelem etichetta;
};

#endif
