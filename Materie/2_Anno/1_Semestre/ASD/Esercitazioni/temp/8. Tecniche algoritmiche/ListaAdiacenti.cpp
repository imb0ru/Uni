#include <iostream>
#include <cstdlib>
#include "ListaAdiacenti.h"

using namespace std;

ListaAdiacenti::ListaAdiacenti(){
	creaLista();
}

ListaAdiacenti::~ListaAdiacenti(){
	posizione q;
	while(primo!=NULL){
		q = primo->successivo;
		delete primo;
		primo = q;
	}
}

void ListaAdiacenti::creaLista(){
	primo = NULL;
}

bool ListaAdiacenti::listaVuota(){
	return (primo == NULL);
}

posizione ListaAdiacenti::primoLista(){
	return primo;
}

posizione ListaAdiacenti::predLista(posizione p){
	if(p!=primo){
		posizione q = primo;
		while ((q->successivo!=p)&&(q!=NULL))
			q = q->successivo;
		return q;
	}else 
		return NULL;
}

posizione ListaAdiacenti::succLista(posizione p){
	return p->successivo;
}

bool ListaAdiacenti::fineLista(posizione p){
	return (p==NULL);
}

void ListaAdiacenti::insLista(tipoelem a, posizione p){
	posizione q = new NodoAdiacenti;
	q->etichetta = a;
	q->successivo = p; 
	if (p==primo){
		primo = q;
	}else{
		p = predLista(p);
		p->successivo = q;
	}
}

bool ListaAdiacenti::cancLista(posizione p){
	if (p!=NULL){
		if(p==primo){
			primo = p->successivo;
		} else {
			posizione q;
			q = predLista(p);
			q->successivo = p->successivo;
		}
		delete p;
		return true;
	}else return false; //ERRORE!	
}
bool ListaAdiacenti::scriviLista(tipoelem a, posizione p){
	if(p!=NULL){
		p->etichetta = a;
		return true;
	}else return false; //ERRORE!
}

bool ListaAdiacenti::leggiLista(tipoelem &a, posizione p){
	if(p!=NULL){
		a = p->etichetta;
		return true;
	}else return false; //ERRORE!
}

ListaAdiacenti &ListaAdiacenti::operator=(ListaAdiacenti &l){
	posizione p;
	while(primo!=NULL){
		p = primo->successivo;
		delete primo;
		primo = p;
	}	
	p = l.primoLista();
	tipoelem a;
	while (!l.fineLista(p)){
		l.leggiLista(a,p);
		insLista(a, NULL);
		p = l.succLista(p);
	}
	return *this;
}

posizione ListaAdiacenti::pos(int i){ // mapping della posizione
	if(i>=1){
		posizione p = primo;
		int j;
		for(j = 0; (j<i)&&(p!=NULL); j++){
			p = p->successivo;
		}
		return p;
	}else {
	 	return NULL;
	}
}
