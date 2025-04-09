#ifndef _LISTAPUNTATORE_H
#define _LISTAPUNTATORE_H

#include <iostream>

#include "listaLineare.h"
#include "nodo.h"
#include "listException.h"

template <class T>
class listaPuntatore : public listaLineare<T, nodo<T>*> {
public:
    typedef typename listaLineare<T, nodo<T>*>::tipoelem tipoelem;
    typedef typename listaLineare<T, nodo<T>*>::posizione posizione;

    listaPuntatore();
    listaPuntatore(const listaPuntatore<T>&);
    ~listaPuntatore();

    void creaLista();
    bool listaVuota() const;
    tipoelem leggiLista(posizione) const;
    void scriviLista(tipoelem, posizione);
    posizione primoLista() const;
    posizione ultimoLista() const;
    bool fineLista(posizione) const;
    posizione succLista(posizione) const;
    posizione predLista(posizione) const;
    void insLista(tipoelem, posizione);
    void cancLista(posizione);

    posizione cercaElemento(tipoelem) const;
    int lunghezzaLista() const;
    void inverti();
    bool palindroma() const;
    void aggiungiInTesta(const tipoelem&);
    void aggiungiInCoda(const tipoelem&);
    void rimuoviTesta();
    void rimuoviCoda();
    void svuotaLista();

    bool operator==(const listaPuntatore<T>&) const;
    bool operator!=(const listaPuntatore<T>&) const;

    void clear();
    int num_elements(posizione, posizione) const;
    void exchange(posizione, posizione);
    void move_min_max();
    void insertionSort();
    void eliminaDallaLista(const listaPuntatore<T>& listaDaEliminare);

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
    int dimensione; // Nuova dimensione del vettore
    nodo<T>** vettore; // Nuovo vettore dinamico di nodi
};

#endif // _LISTAPUNTATORE_H
