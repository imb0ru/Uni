#ifndef _NODOALBERO_H
#define _NODOALBERO_H

#include "listaPuntatore.h"


template <class T, class P>
class nodoAlbero{
public:
	typedef T tipoelem;
	nodoAlbero(const tipoelem e) : elemento(e), padre(nullptr) {}
	nodoAlbero() : padre(nullptr) {}

	~nodoAlbero() {
	    if (padre)
	        padre->eliminaNodo(this);
	}

	// operatori
	void setElemento (tipoelem e) { elemento = e; };
	tipoelem getElemento () const { return elemento; };
	void setFigli (listaPuntatore<P> l) { figli = l; };
	listaPuntatore<P> getFigli () const { return figli; };
	void setPadre (P* p) { padre = p; };
	P* getPadre () const { return padre; };
private:
	tipoelem elemento;
	listaPuntatore<P> figli;
	P* padre;
};


#endif // _NODOALBERO_H

