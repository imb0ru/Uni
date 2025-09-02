/*
  Nome: NodoNPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo dell'albero n-ario con puntatore
*/

#ifndef NODONPTR_H
#define NODONPTR_H
#include "Nodo.h"

class NodoNPtr; //dichiarazione anticipata
typedef NodoNPtr *nodoN;

class NodoNPtr: public Nodo{
public:
	NodoNPtr();
	NodoNPtr(tipoelem);
	NodoNPtr(tipoelem, nodoN, nodoN, nodoN);
	~NodoNPtr();
	
	nodoN getFirstSon();
	nodoN getNextBro();
	nodoN getDaddy();
	void setFirstSon(nodoN);
	void setNextBro(nodoN);
	void setDaddy(nodoN);
	
private:
	nodoN daddy, firstSon, nextBro;
};

#endif 
