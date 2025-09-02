#include <iostream>
#include <cstdlib>
#include "GrafoAdiacenti.h"

using namespace std;

GrafoAdiacenti::GrafoAdiacenti(){
	creaGrafo();
}

GrafoAdiacenti::~GrafoAdiacenti(){
	for(int i = 0; i<MAXNODI; i++){
		if (grafo[i].presente){
			grafo[i].neighbours.~ListaAdiacenti();
			grafo[i].presente = false;
		}
	}
}

void GrafoAdiacenti::creaGrafo(){
	for(int i = 0; i<MAXNODI; i++){
		grafo[i].presente = false;
		grafo[i].visitato = false;
		grafo[i].etichetta = "";
		grafo[i].neighbours.creaLista();
	}
}

bool GrafoAdiacenti::grafoVuoto(){
	bool vuoto = true;
	for(int i = 0; (i<MAXNODI && vuoto); i++){
		vuoto = (vuoto && (!grafo[i].presente));
	}
	return vuoto;
}

bool GrafoAdiacenti::esisteNodo(Nodo n){
	return grafo[n].presente;
}

bool GrafoAdiacenti::esisteArco(Nodo n, Nodo m){
	if(grafo[n].presente && grafo[m].presente){
		posizione p = grafo[n].neighbours.primoLista();
		bool trovato = false;
		while (!(grafo[n].neighbours.fineLista(p) || trovato)){
			if (p->etichetta.nodoCur == m)
				trovato = true;
			else
				p = grafo[n].neighbours.succLista(p);
		}
		return trovato;
	} else return false;
}

bool GrafoAdiacenti::insNodo(Nodo n){
	if(!grafo[n].presente){
		grafo[n].presente = true;
		return true;
	}else return false;
}

bool GrafoAdiacenti::insArco(Nodo n, Nodo m){
	if ( esisteNodo(n) && esisteNodo(m) && (!esisteArco(n,m))){
		tipoelem a;
		a.nodoCur = m;
		a.peso = NIL;
		grafo[n].neighbours.insLista(a,grafo[n].neighbours.primoLista());
		return true;
	} else return false;			
}

bool GrafoAdiacenti::cancNodo(Nodo n){
   if (grafo[n].presente){
      if (grafo[n].neighbours.listaVuota()){ // vuol dire che n non ha archi uscenti
		 bool trovato = false;        
         for (int i = 0; ((i < MAXNODI) && (!trovato)); i++)
            if (esisteArco(i, n))
               trovato = true;
         if (!trovato)
            grafo[n].presente = false;
         return !trovato;
      } else return false;
   } else return false;
}

bool GrafoAdiacenti::cancArco(Nodo n , Nodo m){
   	if (esisteArco(n, m)){
    	posizione p = grafo[n].neighbours.primoLista();
  		tipoelem a;
   		grafo[n].neighbours.leggiLista(a,p);
   		while (a.nodoCur != m){
   			p = grafo[n].neighbours.succLista(p);
   			grafo[n].neighbours.leggiLista(a,p);
   		}
      	grafo[n].neighbours.cancLista(p);
      	return true;
   	} else
   	  	return false;
}

void GrafoAdiacenti::adiacenti(Nodo n, ListaAdiacenti &l){
	l = grafo[n].neighbours;
}

bool GrafoAdiacenti::scriviNodo(Nodo n, label l){
	if(grafo[n].presente){
       grafo[n].etichetta = l;
      return true;
   } else return false;
}

bool GrafoAdiacenti::leggiNodo(Nodo n, label &l){
   if (grafo[n].presente){
      l = grafo[n].etichetta;
      return true;
   } else return false;
}

bool GrafoAdiacenti::scriviArco(Nodo n, Nodo m, tipoPeso w){
   if (esisteArco(n, m)){
      posizione p = grafo[n].neighbours.primoLista();
      while (p->etichetta.nodoCur != m)
         p = grafo[n].neighbours.succLista(p);
      p->etichetta.peso = w;
      return true;
   } else return false;
}

bool GrafoAdiacenti::leggiArco(Nodo n, Nodo m, tipoPeso &w){
   if (esisteArco(n, m)){
      posizione p = grafo[n].neighbours.primoLista();
      while (p->etichetta.nodoCur != m)
         p = grafo[n].neighbours.succLista(p);
      w = p->etichetta.peso;
      return true;
   } else return false;
}

bool GrafoAdiacenti::getVisitato(Nodo n){
   return grafo[n].visitato;
}

void GrafoAdiacenti::setVisitato(bool b, Nodo n){
   grafo[n].visitato = b;
}

GrafoAdiacenti &GrafoAdiacenti::operator=(GrafoAdiacenti &g){
	for(int i = 0; i<MAXNODI; i++){
		if (grafo[i].presente){
			grafo[i].neighbours.~ListaAdiacenti();
			grafo[i].presente = false;
			grafo[i].visitato = false;
		}
	}
	for(int i = 0; i<MAXNODI; i++){
      if (g.esisteNodo(i)){
         grafo[i].presente = true;
         g.leggiNodo(i, grafo[i].etichetta);
         g.adiacenti(i, grafo[i].neighbours);
      }
   }
	return *this;
}
