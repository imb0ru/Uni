#ifndef _LISTALINEARE_H 
#define _LISTALINEARE_H

#include <iostream>

using namespace std;


template <class T, class P>
class listaLineare{
   public:
	typedef T tipoelem;
	typedef P posizione;
	// operatori
	virtual void creaLista () =0;
	virtual bool listaVuota () const=0;
	virtual tipoelem leggiLista (posizione) const=0;
	virtual void scriviLista (tipoelem, posizione)=0; // scrive un elemento nella posizione scelta
	virtual posizione primoLista () const=0;
	virtual bool fineLista (posizione) const=0;
	virtual posizione succLista (posizione) const=0;
	virtual posizione predLista (posizione) const=0;
	virtual void insLista (tipoelem, posizione) =0; // inserisce un elemento nella lista
	virtual void cancLista (posizione)=0;
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, listaLineare<T,P>& l){
		if(!l.listaVuota()){
			posizione p;
			p = l.primoLista();
			os << "Lista: ";
			while(!l.fineLista(p)){
				os << "[" << l.leggiLista(p) << "]";
				p = l.succLista(p);
			}
			os << "[" << l.leggiLista(p) << "]";
			os << endl;
		}
		else{
			os << "ATTENZIONE: la lista e' vuota" << endl;
		}
		return os;
	}
};


#endif // _LISTALINEARE_H
