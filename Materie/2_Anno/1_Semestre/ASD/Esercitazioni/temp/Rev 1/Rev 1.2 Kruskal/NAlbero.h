/*
  Nome: NAlbero.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa l'albero n-ario con puntatore
*/

#ifndef NALBERO_H
#define NALBERO_H
#include "NodoNPtr.h"

class NAlbero{
public:
	NAlbero();
	~NAlbero();
	
	void creaNAlbero();
	bool nAlberoVuoto();
	bool insRadice(nodoN);
	nodoN radice();
	nodoN padre(nodoN);
	bool foglia(nodoN);
	nodoN primoFiglio(nodoN);
	bool ultimoFratello(nodoN);
	nodoN succFratello(nodoN);
	bool insPrimoSottoAlbero(nodoN, nodoN);
	bool insSottoAlbero(nodoN, nodoN);
	bool cancSottoAlbero(nodoN);
	
	tipoelem leggiNodo(nodoN);
	bool scriviNodo(nodoN, tipoelem);
	
private:
   nodoN root;
};

#endif // NALBERO_H
