#include <iostream>
#include <cstdlib>
#include "ListaAdiacenti.h"

using namespace std;

ListaAdiacenti::ListaAdiacenti(){
	creaLista();
}

ListaAdiacenti::~ListaAdiacenti(){
	posizionelista q;
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

posizionelista ListaAdiacenti::primoLista(){
	return primo;
}

posizionelista ListaAdiacenti::predLista(posizionelista p){
	if(p!=primo){
		posizionelista q = primo;
		while ((q->successivo!=p)&&(q!=NULL))
			q = q->successivo;
		return q;
	}else 
		return NULL;
}

posizionelista ListaAdiacenti::succLista(posizionelista p){
	return p->successivo;
}

bool ListaAdiacenti::fineLista(posizionelista p){
	return (p==NULL);
}

void ListaAdiacenti::insLista(NodoLista a, posizionelista p){
	posizionelista q = new NodoAdiacenti;
	q->etichetta = a;
	q->successivo = p; 
	if (p==primo){
		primo = q;
	}else{
		p = predLista(p);
		p->successivo = q;
	}
}

bool ListaAdiacenti::cancLista(posizionelista p){
	if (p!=NULL){
		if(p==primo){
			primo = p->successivo;
		} else {
			posizionelista q;
			q = predLista(p);
			q->successivo = p->successivo;
		}
		delete p;
		return true;
	}else return false; //ERRORE!	
}
bool ListaAdiacenti::scriviLista(NodoLista a, posizionelista p){
	if(p!=NULL){
		p->etichetta = a;
		return true;
	}else return false; //ERRORE!
}

bool ListaAdiacenti::leggiLista(NodoLista &a, posizionelista p){
	if(p!=NULL){
		a = p->etichetta;
		return true;
	}else return false; //ERRORE!
}

ListaAdiacenti &ListaAdiacenti::operator=(ListaAdiacenti &l){
	posizionelista p;
	while(primo!=NULL){
		p = primo->successivo;
		delete primo;
		primo = p;
	}	
	p = l.primoLista();
	NodoLista a;
	while (!l.fineLista(p)){
		l.leggiLista(a,p);
		insLista(a, NULL);
		p = l.succLista(p);
	}
	return *this;
}

posizionelista ListaAdiacenti::pos(int i){ // mapping della posizionelista
	if(i>=1){
		posizionelista p = primo;
		int j;
		for(j = 0; (j<i)&&(p!=NULL); j++){
			p = p->successivo;
		}
		return p;
	}else {
	 	return NULL;
	}
}
