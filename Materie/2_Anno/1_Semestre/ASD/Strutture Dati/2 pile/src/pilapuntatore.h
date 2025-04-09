// PILAPUNTATORE.H

#ifndef _PILAPUNTATORE_H
#define _PILAPUNTATORE_H

#include <iostream>

#include "pilaAstratta.h"
#include "nodo.h"
#include "stackException.h"

using namespace std;

template <class T>
class pilaPuntatore : public pilaAstratta<T, nodo<T>*> {
public:
    typedef typename pilaAstratta<T, nodo<T>*>::tipoelem tipoelem;
    typedef typename pilaAstratta<T, nodo<T>*>::posizione posizione;

    // costruttori
    pilaPuntatore();
    pilaPuntatore(const pilaPuntatore<T>&); // costruttore di copia
    ~pilaPuntatore(); // distruttore

    // operatori
    void creaPila();
    bool pilaVuota() const;
    tipoelem leggiPila() const;
    void fuoriPila();
    void inPila(tipoelem);

    // sovraccarico operatori
    friend ostream& operator<<(ostream& os, const pilaPuntatore<T>& p) {
        if (!p.pilaVuota()) {
            nodo<T>* temp = p.pila;
            while (temp != nullptr) {
                os << "<" << temp->getElemento() << ">" << endl;
                temp = temp->getSucc();
            }
        } else {
            os << "La pila è vuota!" << endl;
        }
        return os;
    };

private:
    posizione pila;
    int lunghezza;
};

// IMPLEMENTAZIONE

// costruttori
template <class T>
pilaPuntatore<T>::pilaPuntatore() {
    creaPila();
}

template <class T>
pilaPuntatore<T>::pilaPuntatore(const pilaPuntatore<T>& p) {
    creaPila();
    nodo<T>* temp = p.pila;
    while (temp != nullptr) {
        inPila(temp->getElemento());
        temp = temp->getSucc();
    }
    lunghezza = p.lunghezza;
}

template <class T>
pilaPuntatore<T>::~pilaPuntatore() {
    while (!pilaVuota()) {
        fuoriPila();
    }
}

// operatori
template <class T>
void pilaPuntatore<T>::creaPila() {
    lunghezza = 0;
    pila = nullptr;
}

template <class T>
bool pilaPuntatore<T>::pilaVuota() const {
    return (lunghezza == 0);
}

template <class T>
typename pilaPuntatore<T>::tipoelem pilaPuntatore<T>::leggiPila() const {
    if (!pilaVuota()) {
        return (pila->getElemento());
    } else {
        throw emptyStackException();
    }
}

template <class T>
void pilaPuntatore<T>::fuoriPila() {
    if (!pilaVuota()) {
        nodo<T>* temp = pila;
        pila = pila->getSucc();
        delete temp;
        lunghezza--;
    } else {
        throw emptyStackException();
    }
}

template <class T>
void pilaPuntatore<T>::inPila(tipoelem e) {
    nodo<T>* n = new nodo<T>(e);
    if (!pilaVuota()) {
        n->setSucc(pila);
        pila = n;
    } else {
        n->setSucc(nullptr);
        pila = n;
    }
    lunghezza++;
}

#endif // _PILAPUNTATORE_H
