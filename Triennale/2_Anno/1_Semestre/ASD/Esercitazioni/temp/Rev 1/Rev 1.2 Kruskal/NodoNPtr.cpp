#include <iostream>
#include <cstdlib>
#include "NodoNPtr.h"

NodoNPtr::NodoNPtr(): Nodo(){
	daddy = firstSon = nextBro = NULL;
}

NodoNPtr::NodoNPtr(tipoelem a): Nodo(a){
	daddy = firstSon = nextBro = NULL;
}

NodoNPtr::NodoNPtr(tipoelem a, nodoN p, nodoN pf, nodoN sf): Nodo(a){
	daddy = p;
	firstSon = pf;
	nextBro = sf;
}

NodoNPtr::~NodoNPtr(){}
	
nodoN NodoNPtr::getFirstSon(){
	return firstSon;
}

nodoN NodoNPtr::getNextBro(){
	return nextBro;
}

nodoN NodoNPtr::getDaddy(){
	return daddy;
}

void NodoNPtr::setFirstSon(nodoN n){
	firstSon = n;
}

void NodoNPtr::setNextBro(nodoN n){
   nextBro = n;
}

void NodoNPtr::setDaddy(nodoN n){
	daddy = n;
}
