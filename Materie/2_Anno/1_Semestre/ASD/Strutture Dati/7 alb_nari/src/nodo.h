#ifndef _NODO_H
#define _NODO_H


template <class T>
class nodo{
   public:
	typedef T tipoelem;
	// costruttori
	nodo () { };
	nodo (const tipoelem e) { elemento = e; };
	~nodo () { }; // distruttore
	// operatori
	void setElemento (tipoelem e) { elemento = e; };
	tipoelem getElemento () const { return elemento; };
	void setSucc (nodo* c) { successivo = c; };
	nodo* getSucc () const { return successivo; };
	void setPrec (nodo* c) { precedente = c; };
	nodo* getPrec () const { return precedente; };
   private:
	tipoelem elemento;
	nodo* successivo;
	nodo* precedente;
};

#endif // _NODO_H

