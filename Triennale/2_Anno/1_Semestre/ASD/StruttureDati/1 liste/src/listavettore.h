#ifndef _LISTAVETTORE_H
#define _LISTAVETTORE_H

#include <iostream>
#include <cstring>

#include "listaLineare.h"
#include "listException.h"


// DEFINIZIONE
template <class T>
class listaVettore : public listaLineare<T, int>{
public:
	typedef typename listaLineare<T, int>::tipoelem tipoelem;
	typedef typename listaLineare<T, int>::posizione posizione;
	// costruttori
	listaVettore ();
	listaVettore (int); // setta una dimensione specifica dell'array 
	listaVettore (const listaVettore<T>&); // costruttore di copia
	~listaVettore (); // distruttore
	// operatori
	void creaLista ();
	bool listaVuota () const;
	tipoelem leggiLista (posizione) const;
	void scriviLista (tipoelem, posizione); // scrive un elemento nella posizione scelta
	posizione primoLista () const;
	posizione ultimoLista () const;
	bool fineLista (posizione) const;
	posizione succLista (posizione) const;
	posizione predLista (posizione) const;
	void insLista (tipoelem, posizione); // inserisce un elemento nella lista
	void cancLista (posizione);
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const listaVettore<T>& l){
		if (!l.listaVuota()){
			for (int i=0; i < l.lunghezza; i++){
				os << "<" << l.vettore[i] << ">" << endl;
			}
		}
		else{
			os << "La lista è vuota" << endl;
		}
		return (os);
	};
private:
	void cambia_dimensione (T*&, int, int);
	tipoelem* vettore;
	int lunghezza; // lunghezza della lista
	int dimensione_vettore; // dimensione dell'array
};




#endif // _LISTAVETTORE_H
