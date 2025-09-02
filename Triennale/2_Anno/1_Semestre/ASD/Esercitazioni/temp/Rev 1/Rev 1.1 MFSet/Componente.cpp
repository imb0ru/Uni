#include <iostream>
#include <cstdlib>
#include "Componente.h"

Componente::Componente(){
   creaComponente();
}

Componente::~Componente(){
   cancSottoAlbero(root);
}

void Componente::creaComponente(){
   root = NULL;
}

bool Componente::componenteVuota(){
   return (root == NULL);
}

bool Componente::insRadice(nodoN n){
   if (root == NULL){
      root = n;
      return true;
   } else return false;
}

nodoN Componente::radice(){
   return root; //se l'albero è vuoto, ritorna NULL
}

nodoN Componente::padre(nodoN n){
   return n->getDaddy(); //se n è la radice, ritorna NULL
}

bool Componente::foglia(nodoN n){
   return (n->getFirstSon() == NULL);
}

nodoN Componente::primoFiglio(nodoN n){
   return n->getFirstSon(); //se n non ha figli, ritorna NULL
}

bool Componente::ultimoFratello(nodoN n){
   return (n->getNextBro() == NULL);
}

nodoN Componente::succFratello(nodoN n){
   return n->getNextBro(); //se n è ultimo fratello, ritorna NULL
}

bool Componente::insPrimoSottoAlbero(nodoN n, nodoN r){
	if ((root != NULL) && (r != NULL) && (n != NULL)){  		
  		r->setNextBro(n->getFirstSon());
  		r->setDaddy(n);
   	n->setFirstSon(r);
   	return true;
	} else return false;
}

bool Componente::insSottoAlbero(nodoN n, nodoN r){
	if ((root!=NULL) && (r!=NULL) && (n!=NULL) && (n!=root)){
		r->setDaddy(n->getDaddy());
		r->setNextBro(n->getNextBro());
		n->setNextBro(r);
		return true;
	}else return false;
}

void Componente::cancSottoAlbero(nodoN n){
	root = NULL;
}

tipoelem Componente::leggiNodo(nodoN n){
	return n->getEtichetta();	
}

bool Componente::scriviNodo(nodoN n, tipoelem a){
	if(n!=NULL){
		n->setEtichetta(a);	
		return true;
	}else return false;
}
