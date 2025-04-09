/*
  Nome: GrafoMatAdExt.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il grafo con matrice di adiacenza estesa
*/

#ifndef GRAFOMATADEXT_H
#define GRAFOMATADEXT_H
#define MAXNODI 20
#include <iostream>
#include "ListaAdiacenti.h"

typedef int tipolabel;
typedef int tipopeso;
struct tipoNodi{
   tipolabel label;
   int archi;
   bool esiste, visitato;
};

class GrafoMatAdExt{
public:
	GrafoMatAdExt();
	~GrafoMatAdExt();
	
	void creaGrafo();
	bool grafoVuoto();
	bool esisteNodo(NodoLista);
	bool esisteArco(NodoLista, NodoLista);
	bool insNodo(NodoLista, tipolabel);
	bool insArco(NodoLista, NodoLista);
	bool cancNodo(NodoLista);
	bool cancArco(NodoLista, NodoLista);
	bool leggiArco(NodoLista, NodoLista, tipopeso &);
	bool scriviArco(NodoLista, NodoLista, tipopeso);
	void adiacenti(NodoLista, ListaAdiacenti &);
	
	bool getVisitato(NodoLista);
	void setVisitato(bool, NodoLista);
	bool getLabel(NodoLista, tipolabel &);
	bool setLabel(NodoLista, tipolabel);
	bool getArchi(NodoLista, int &);
	
	void azzeraVisitato();

private:
   tipoNodi nodi[MAXNODI];
   tipopeso grafo[MAXNODI][MAXNODI];
};

#endif

