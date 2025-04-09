#ifndef _LISTAPUNTATORE_H 
#define _LISTAPUNTATORE_H

#include <iostream>

#include "listaLineare.h"
#include "nodo.h"
#include "listException.h"


// DEFINIZIONE
template <class T>
class listaPuntatore : public listaLineare<T, nodo<T>*>{
public:
	typedef typename listaLineare<T, nodo<T>*>::tipoelem tipoelem;
	typedef typename listaLineare<T, nodo<T>*>::posizione posizione;
	// costruttori
	listaPuntatore ();
	listaPuntatore (const listaPuntatore<T>&); // costruttore di copia
	~listaPuntatore (); // distruttore
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
	// funzioni di servizio 
	posizione cercaElemento(tipoelem) const;
	int lunghezzaLista() const;
	void inverti();
	bool palindroma() const;
    void aggiungiInTesta(const tipoelem &);
    void aggiungiInCoda(const tipoelem &);
    void rimuoviTesta();
    void rimuoviCoda();
    void svuotaLista();
	// sovraccarico operatori
	bool operator==(const listaPuntatore<T>&) const;
	friend ostream& operator<<(ostream& os, const listaPuntatore<T>& l){
		if (!l.listaVuota()){
			nodo<T>* temp = new nodo<T>;
			temp = l.lista->getSucc();
			do{
				os << "<" << temp->getElemento() << ">" << endl;
				temp = temp->getSucc();
			}while (temp != l.lista);
		}
		else{
			os << "<___>" << endl;
		}
		return os;
	};
private:
	posizione lista;
	int lunghezza;
};

#endif // _LISTAPUNTATORE_H

