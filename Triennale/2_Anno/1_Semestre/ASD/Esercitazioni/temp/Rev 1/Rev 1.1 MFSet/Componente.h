/*
  Nome: Componente.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la componente del MF set
*/

#ifndef COMPONENTE_H
#define COMPONENTE_H
#include "NodoNPtr.h"

class Componente{
public:
	Componente();
	~Componente();
	
	void creaComponente();
	bool componenteVuota();
	bool insRadice(nodoN);
	nodoN radice();
	nodoN padre(nodoN);
	bool foglia(nodoN);
	nodoN primoFiglio(nodoN);
	bool ultimoFratello(nodoN);
	nodoN succFratello(nodoN);
	bool insPrimoSottoAlbero(nodoN, nodoN);
	bool insSottoAlbero(nodoN, nodoN);
	void cancSottoAlbero(nodoN);
	
	tipoelem leggiNodo(nodoN);
	bool scriviNodo(nodoN, tipoelem);
	
private:
   nodoN root;
};

#endif
