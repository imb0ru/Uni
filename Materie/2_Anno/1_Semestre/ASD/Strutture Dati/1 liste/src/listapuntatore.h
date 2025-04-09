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
};

// IMPLEMENTAZIONE
// costruttori
template <class T>
listaPuntatore<T>::listaPuntatore (){
	this->creaLista ();
}


template <class T>
listaPuntatore<T>::listaPuntatore (const listaPuntatore<T>& l) {
	this->lista = l.lista;
	this->lunghezza = l.lunghezza;
}


template <class T>
listaPuntatore<T>::~listaPuntatore() {
	nodo<T>* temp = lista->getSucc();
	while (temp != lista) {
		nodo<T>* next = temp->getSucc();
		delete temp;
		temp = next;
	}
	delete lista;
}


// operatori
template <class T>
void listaPuntatore<T>::creaLista () {
	this->lunghezza = 0;
	this->lista = new nodo<T> ();
	this->lista->setSucc(this->lista);
	this->lista->setPrec(this->lista);
}


template <class T>
bool listaPuntatore<T>::listaVuota () const{
	return (lista == primoLista());
}


template <class T>
typename listaPuntatore<T>::tipoelem listaPuntatore<T>::leggiLista (typename listaPuntatore<T>::posizione p) const{
	if (!this->listaVuota()){
		return p->getElemento();
	}
	else{
		throw emptyListException();
	}
}


template <class T>
void listaPuntatore<T>::scriviLista (typename listaPuntatore<T>::tipoelem e, typename listaPuntatore<T>::posizione p){
	if (!this->listaVuota()){
		p->setElemento (e);
	}
	else{
		throw emptyListException();
	}
}


template <class T>
typename listaPuntatore<T>::posizione listaPuntatore<T>::primoLista () const{
	return lista->getSucc();
}


template <class T>
typename listaPuntatore<T>::posizione listaPuntatore<T>::ultimoLista () const{
	return (this->lista->getPrec());
}


template <class T>
bool listaPuntatore<T>::fineLista (typename listaPuntatore<T>::posizione p) const{
	return (p == lista->getPrec());
}


template <class T>
typename listaPuntatore<T>::posizione listaPuntatore<T>::succLista (typename listaPuntatore<T>::posizione p) const{
	return (p->getSucc());
}


template <class T>
typename listaPuntatore<T>::posizione listaPuntatore<T>::predLista (typename listaPuntatore<T>::posizione p) const{
	return (p->getPrec());
}


template <class T>
void listaPuntatore<T>::insLista (typename listaPuntatore<T>::tipoelem e, typename listaPuntatore<T>::posizione p){
	if (this->listaVuota()){
		nodo<T>* nuovoNodo = new nodo<T> (e);
		lista->setSucc(nuovoNodo);
		lista->setPrec(nuovoNodo);
		nuovoNodo->setSucc(lista);
		nuovoNodo->setPrec(lista);
		lunghezza++;
	}
	else{
		nodo<T>* nuovoNodo = new nodo<T> (e);
		if (p == lista){
			nuovoNodo->setSucc(lista->getSucc());
			nuovoNodo->setPrec(lista);
			lista->getSucc()->setPrec(nuovoNodo);
			lista->setSucc(nuovoNodo);
			lunghezza++;
		}
		else{
			nuovoNodo->setPrec(p->getPrec());
			nuovoNodo->setSucc(p);
			p->getPrec()->setSucc(nuovoNodo);
			p->setPrec(nuovoNodo);
			lunghezza++;
		}
	}
}


template <class T>
void listaPuntatore<T>::cancLista (typename listaPuntatore<T>::posizione p){
	if(!this->listaVuota()){
		(this->predLista(p))->setSucc(this->succLista(p));
		(this->succLista(p))->setPrec(this->predLista(p));
		lunghezza --;
		delete p;
		p = nullptr;
	}
	else{
		throw emptyListException();
	}
}


// funzioni di servizio
template <class T>
typename listaPuntatore<T>::posizione listaPuntatore<T>::cercaElemento(typename listaPuntatore<T>::tipoelem e) const{
	nodo<T>* temp = new nodo<T>;
	temp = this->lista->getSucc();
	do{
		if (temp->getElemento() == e)
			return temp;
		temp = temp->getSucc();
	}while (temp != this->lista);
	return nullptr;
}


template <class T>
int listaPuntatore<T>::lunghezzaLista() const{
	return this->lunghezza;
}


// sovraccarico operatori
template <class T>
bool listaPuntatore<T>::operator==(const listaPuntatore<T>& l) const {
	if (this->lunghezza != l.lunghezza) {
		return false;
	}

	nodo<T>* temp1 = l.lista->getSucc();
	nodo<T>* temp2 = this->lista->getSucc();

	while (temp1 != l.lista) {
		if (!(temp1->getElemento() == temp2->getElemento())) {
			return false;
		}

		temp1 = temp1->getSucc();
		temp2 = temp2->getSucc();

		if (temp1 == l.lista && temp2 != this->lista) {
			return false;
		}
	}
	return true;
}

template <class T>
bool listaPuntatore<T>::operator!=(const listaPuntatore<T>& l) const {
    return !(*this == l);
}


template <class T>
bool listaPuntatore<T>::palindroma() const {
    if (this->lunghezza < 2) {
        return true; // Una lista con 0 o 1 elemento è palindroma
    }

    nodo<T>* inizio = this->primoLista();
    nodo<T>* fine = this->ultimoLista();

    while (inizio != fine && inizio->getPrec() != fine) {
        if (inizio->getElemento() != fine->getElemento()) {
            return false;
        }

        inizio = inizio->getSucc();
        fine = fine->getPrec();
    }

    return true;
}

// All'interno della tua classe listaPuntatore
template <class T>
void listaPuntatore<T>::inverti() {
    if (!this->listaVuota() && this->lunghezza > 1) {
        typename listaPuntatore<T>::posizione left = this->primoLista();
        typename listaPuntatore<T>::posizione right = this->ultimoLista();

        while (left != right && right != this->precedente(left)) {
            typename listaPuntatore<T>::tipoelem temp = this->leggiLista(left);
            this->scriviLista(this->leggiLista(right), left);
            this->scriviLista(temp, right);

            left = this->successivo(left);
            right = this->precedente(right);
        }
    }
}


template <class T>
void listaPuntatore<T>::aggiungiInTesta(const tipoelem &valore) {
    this->insLista(valore, this->primoLista());
}

template <class T>
void listaPuntatore<T>::aggiungiInCoda(const tipoelem &valore) {
    this->insLista(valore, this->successivo(this->ultimoLista()));
}

template <class T>
void listaPuntatore<T>::rimuoviTesta() {
    if (!this->listaVuota()) {
        this->cancLista(this->primoLista());
    }
}

template <class T>
void listaPuntatore<T>::rimuoviCoda() {
    if (!this->listaVuota()) {
        this->cancLista(this->precedente(this->ultimoLista()));
    }
}

template <class T>
void listaPuntatore<T>::svuotaLista() {
    while (!this->listaVuota()) {
        this->cancLista(this->primoLista());
    }
}

template <class T>
void listaPuntatore<T>::eliminaDallaLista(const listaPuntatore<T>& listaDaEliminare) {
    posizione p = listaDaEliminare.primoLista();
    while (!listaDaEliminare.fineLista(p)) {
        posizione temp = p;
        p = listaDaEliminare.succLista(p);
        cancLista(cercaElemento(listaDaEliminare.leggiLista(temp)));
    }
}

template <class T>
int listaPuntatore<T>::num_elements(posizione p1, posizione p2) const {
    int count = 0;
    posizione p = p1;
    while (p != p2) {
        count++;
        p = succLista(p);
    }
    return count;
}

template <class T>
void listaPuntatore<T>::exchange(posizione p1, posizione p2) {
    tipoelem temp = leggiLista(p1);
    scriviLista(leggiLista(p2), p1);
    scriviLista(temp, p2);
}


// Metodo per spostare il massimo in ultima posizione e il minimo in prima posizione
template <class T>
void listaPuntatore<T>::move_min_max() {
    if (this->lunghezza < 2) {
        return;  // Niente da fare per liste con 0 o 1 elemento
    }

    posizione minPos = primoLista();
    posizione maxPos = primoLista();
    posizione p = primoLista();

    while (!fineLista(p)) {
        if (leggiLista(p) < leggiLista(minPos)) {
            minPos = p;
        } else if (leggiLista(p) > leggiLista(maxPos)) {
            maxPos = p;
        }
        p = succLista(p);
    }

    // Sposta il massimo in ultima posizione
    exchange(maxPos, precedente(ultimoLista()));

    // Sposta il minimo in prima posizione (tenendo conto dello spostamento del massimo)
    if (maxPos == primoLista()) {
        exchange(minPos, primoLista());
    } else {
        exchange(minPos, succLista(primoLista()));
    }
}


// Metodo per ordinare la lista con l'algoritmo di ordinamento per inserzione
template <class T>
void listaPuntatore<T>::insertionSort() {
    posizione i = succLista(primoLista());

    while (!fineLista(i)) {
        tipoelem temp = leggiLista(i);
        posizione j = i;

        while (j != primoLista() && leggiLista(precedente(j)) > temp) {
            scriviLista(leggiLista(precedente(j)), j);
            j = precedente(j);
        }

        scriviLista(temp, j);
        i = succLista(i);
    }
}




#endif // _LISTAPUNTATORE_H
