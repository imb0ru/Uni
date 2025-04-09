#include <iostream>
#include <cstdlib>
#include "NAlbero.h"

NAlbero::NAlbero(){
   creaNAlbero();
}

NAlbero::~NAlbero(){
   cancSottoAlbero(root);
}

void NAlbero::creaNAlbero(){
   root = NULL;
}

bool NAlbero::nAlberoVuoto(){
   return (root == NULL);
}

bool NAlbero::insRadice(nodoN n){
   if (root == NULL){
      root = n;
      return true;
   } else return false;
}

nodoN NAlbero::radice(){
   return root; //se l'albero è vuoto, ritorna NULL
}

nodoN NAlbero::padre(nodoN n){
   return n->getDaddy(); //se n è la radice, ritorna NULL
}

bool NAlbero::foglia(nodoN n){
   return (n->getFirstSon() == NULL);
}

nodoN NAlbero::primoFiglio(nodoN n){
   return n->getFirstSon(); //se n non ha figli, ritorna NULL
}

bool NAlbero::ultimoFratello(nodoN n){
   return (n->getNextBro() == NULL);
}

nodoN NAlbero::succFratello(nodoN n){
   return n->getNextBro(); //se n è ultimo fratello, ritorna NULL
}

bool NAlbero::insPrimoSottoAlbero(nodoN n, nodoN r){
	if ((root != NULL) && (r != NULL) && (n != NULL)){  		
  		r->setNextBro(n->getFirstSon());
  		r->setDaddy(n);
   	n->setFirstSon(r);
   	return true;
	} else return false;
}

bool NAlbero::insSottoAlbero(nodoN n, nodoN r){
	if ((root!=NULL) && (r!=NULL) && (n!=NULL) && (n!=root)){
		r->setDaddy(n->getDaddy());
		r->setNextBro(n->getNextBro());
		n->setNextBro(r);
		return true;
	}else return false;
}

bool NAlbero::cancSottoAlbero(nodoN n){
   if ((n!=NULL) && (root!=NULL)){
      while (n->getFirstSon()!=NULL)
         cancSottoAlbero(n->getFirstSon());
      if (n->getDaddy()!=NULL)
         if (n->getDaddy()->getFirstSon() == n)
            n->getDaddy()->setFirstSon(n->getNextBro());
         else{
            nodoN m = n->getDaddy()->getFirstSon();
            while (m->getNextBro() != n)
               m = m->getNextBro();
            m->setNextBro(n->getNextBro());
         }
		else root = NULL;
      delete n;
		return true;
	} else return false;
}

tipoelem NAlbero::leggiNodo(nodoN n){
	return n->getEtichetta();	
}

bool NAlbero::scriviNodo(nodoN n, tipoelem a){
	if(n!=NULL){
		n->setEtichetta(a);	
		return true;
	}else return false;
}

