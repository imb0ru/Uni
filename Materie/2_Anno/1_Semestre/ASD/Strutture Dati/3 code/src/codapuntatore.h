#ifndef CODAPUNTATORE_H_INCLUDED
#define CODAPUNTATORE_H_INCLUDED

#include <iostream>

#include "codaAstratta.h"
#include "nodo.h"
#include "queueException.h"

using namespace std;


// DEFINIZIONE
template <class T>
class codaPuntatore : public codaAstratta<T, nodo<T>*>{
   public:
	typedef typename codaAstratta<T, nodo<T>*>::tipoelem tipoelem;
	typedef typename codaAstratta<T, nodo<T>*>::posizione posizione;
	// costrauttori
	codaPuntatore();
	codaPuntatore(const codaPuntatore<T>&); //costruttore di copia
	~codaPuntatore(); // distruttore
	// operatori
	void creaCoda();
	bool codaVuota() const;
	tipoelem leggiCoda() const;
	void fuoriCoda();
	void inCoda(tipoelem);
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const codaPuntatore<T>& c){
		nodo<T>* temp = new nodo<T> ();
    		temp = c.fondo;
    		while (temp != nullptr){
        		os << "<" << temp->getElemento() << ">" << endl;
        		temp = temp->getPrec();
    		}
		return (os);
	}
   private:
	posizione testa;
	posizione fondo;
};


// IMPLEMENTAZIONE
// costruttori
template <class T>
codaPuntatore<T>::codaPuntatore(){
    this->creaCoda();
}


template <class T>
codaPuntatore<T>::codaPuntatore(const codaPuntatore<T>& c){
    nodo<T>* temp = new nodo<T> ();
    temp = c.testa;
    while (!temp->getSucc() != nullptr){
        this->inCoda(temp->getElemento());
        temp = temp->getSucc();
    }
}


template <class T>
codaPuntatore<T>::~codaPuntatore() {
    while (testa != nullptr) {
        nodo<T>* temp = testa;
        testa = testa->getSucc();
        delete temp;
    }
    fondo = nullptr;  // Imposta anche il fondo a nullptr per garantire la coerenza
}



// operatori
template <class T>
void codaPuntatore<T>::creaCoda(){
    testa = nullptr;
    fondo = nullptr;
    return;
}


template <class T>
bool codaPuntatore<T>::codaVuota() const{
    return (testa == nullptr);
}


template <class T>
typename codaPuntatore<T>::tipoelem codaPuntatore<T>::leggiCoda() const{
    return (fondo->getElemento());
}


template <class T>
void codaPuntatore<T>::fuoriCoda(){
    if (!codaVuota()){
        if (testa == fondo){
            testa = nullptr;
            fondo = nullptr;
        }
        else{
            fondo = fondo->getPrec();
            delete fondo->getSucc();
            fondo->setSucc(nullptr);
        }
    }
    else{
        throw emptyQueueException();
    }
}


template <class T>
void codaPuntatore<T>::inCoda(typename codaPuntatore<T>::tipoelem e){
    nodo<T>* nuovoNodo = new nodo<T> ();
    nuovoNodo->setElemento(e);
    nuovoNodo->setPrec(nullptr);
    if (codaVuota()){
        testa = nuovoNodo;
        fondo = nuovoNodo;
        nuovoNodo->setSucc(nullptr);
    }
    else{
        nuovoNodo->setSucc(testa);
        testa->setPrec(nuovoNodo);
        testa = nuovoNodo;
    }
    return;
}


#endif // CODAPUNTATORE_H_INCLUDED
