#include <iostream>
#include <cstdlib>
#include "GrafoMatAdExt.h"

GrafoMatAdExt::GrafoMatAdExt(){
   creaGrafo();
}

GrafoMatAdExt::~GrafoMatAdExt(){}
	
void GrafoMatAdExt::creaGrafo(){
   for (int i = 0; i < MAXNODI; i++){
      nodi[i].label = -1;
      nodi[i].archi = 0;
      nodi[i].esiste = false;
      nodi[i].visitato = false;
      for (int j = 0; j < MAXNODI; j++)
         grafo[i][j] = -1;
   }
}

bool GrafoMatAdExt::grafoVuoto(){
   bool vuoto = true;
   int i = 0;
   while ((i < MAXNODI) && (vuoto)){
      if (nodi[i].esiste == true)
         vuoto = false;
      else
         i++;
   }
   return vuoto; 
}

bool GrafoMatAdExt::esisteNodo(NodoLista i){
   return (nodi[i].esiste == true);
}

bool GrafoMatAdExt::esisteArco(NodoLista i, NodoLista j){
   return (grafo[i][j] > -1);
}

bool GrafoMatAdExt::insNodo(NodoLista i, tipolabel a){
   if (!nodi[i].esiste){
      nodi[i].esiste = true;
      nodi[i].label = a;
      return true;
   } else return false;
}

bool GrafoMatAdExt::insArco(NodoLista i, NodoLista j){
   if (!esisteArco(i,j)){
      grafo[i][j] = grafo[j][i] = 0; //verrà cambiato con scriviArco
      nodi[i].archi++;
      nodi[j].archi++;
      return true;
   } else return false;
}

bool GrafoMatAdExt::cancNodo(NodoLista i){
   if (nodi[i].esiste){
      nodi[i].esiste = false;
      return true;
   } else return false;
}

bool GrafoMatAdExt::cancArco(NodoLista i, NodoLista j){
   if (esisteArco(i, j)){
      grafo[i][j] = grafo[j][i] = -1;
      nodi[i].archi--;
      nodi[j].archi--;
      return true;
   } else return false;
}

bool GrafoMatAdExt::leggiArco(NodoLista i, NodoLista j, tipopeso &w){
	if (esisteArco(i, j)){
		w = grafo[i][j];
		return true;
	} else return false;
}

bool GrafoMatAdExt::scriviArco(NodoLista i, NodoLista j, tipopeso w){
	if (esisteArco(i, j)){
		grafo[i][j] = grafo[j][i] = w;
		return true;
	} else return false;
}

void GrafoMatAdExt::adiacenti(NodoLista i, ListaAdiacenti &l){
   for (int j = 0; j < MAXNODI; j++)
      if (esisteArco(i, j))
         l.insLista(j, l.primoLista());
}

bool GrafoMatAdExt::getVisitato(NodoLista i){
   return nodi[i].visitato;
}

void GrafoMatAdExt::setVisitato(bool b, NodoLista i){
   nodi[i].visitato = b;
}

bool GrafoMatAdExt::getLabel(NodoLista i, tipolabel &k){
   if (nodi[i].esiste){
      k = nodi[i].label;
      return true;
   } else return false;
}

bool GrafoMatAdExt::setLabel(NodoLista i, tipolabel k){
   if (nodi[i].esiste){
      nodi[i].label = k;
      return true;
   } else return false;
}

bool GrafoMatAdExt::getArchi(NodoLista i, int &a){
   if (nodi[i].esiste){
      a = nodi[i].archi;
      return true;
   } else return false;
}

void GrafoMatAdExt::azzeraVisitato(){
   for (int i = 0; i < MAXNODI; i++)
      nodi[i].visitato = false;
}
