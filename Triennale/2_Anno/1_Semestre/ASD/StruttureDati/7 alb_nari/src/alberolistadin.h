#ifndef _ALBEROLISTADIN_H
#define _ALBEROLISTADIN_H

#include <iostream>
#include "alberoAstratto.h"
#include "nodoAlbero.h"
#include "listaPuntatore.h"
#include "treeException.h"

using namespace std;

template <class T>
class alberoListaDin : public alberoAstratto<T, alberoListaDin<T>> {
public:
    typedef typename alberoAstratto<T, alberoListaDin<T>>::posizione posizione;

    // Costruttore
    alberoListaDin() : radice(nullptr) {}

    // Distruttore
    ~alberoListaDin() override {
        if (radice) {
            cancSottoAlbero(radice);
            delete radice;
        }
    }

    // Restituisci la radice dell'albero
    virtual posizione radiceAlbero() const override;

    // Restituisci il padre di un nodo
    virtual posizione padre(posizione) const override;

    // Restituisci true se il nodo è una foglia
    virtual bool foglia(posizione) const override;

    // Restituisci la posizione del primo figlio del nodo
    virtual posizione primoFiglio(posizione) const override;

    // Restituisci true se il nodo è l'ultimo fratello
    virtual bool ultimoFratello(posizione) const override;

    // Restituisci la posizione del fratello successivo
    virtual posizione succFratello(posizione) const override;

    // Inserisci la radice dell'albero
    void insRadice(const T& elem);

    // Inserisci un nodo come primo figlio del nodo in posizione p
    void insPrimoSottoAlbero(posizione p, const alberoListaDin<T>& sottoAlbero);

    // Inserisci un nodo come ultimo figlio del nodo in posizione p
    void insSottoAlbero(posizione p, const alberoListaDin<T>& sottoAlbero);

    // Cancella il sottoalbero radicato in p
    void cancSottoAlbero(posizione p);

    // Altre funzioni della classe...

private:
    nodoAlbero<T, alberoListaDin<T>>* radice;

    // Funzione ausiliaria per cancellare ricorsivamente il sottoalbero
    void cancSottoAlbero(nodoAlbero<T, alberoListaDin<T>>* p);
};

// Implementazione delle funzioni

template <class T>
typename alberoListaDin<T>::posizione alberoListaDin<T>::radiceAlbero() const {
    return posizione(radice);
}

template <class T>
typename alberoListaDin<T>::posizione alberoListaDin<T>::padre(posizione p) const {
    if (p.radice != nullptr) {
        return posizione(p.radice->getPadre());
    }
    return posizione();
}

template <class T>
bool alberoListaDin<T>::foglia(posizione p) const {
    return p.radice != nullptr && p.radice->getFigli().lunghezza() == 0;
}

template <class T>
typename alberoListaDin<T>::posizione alberoListaDin<T>::primoFiglio(posizione p) const {
    if (p.radice != nullptr && !foglia(p)) {
        return posizione(p.radice->getFigli().primoLista());
    }
    return posizione();
}

template <class T>
bool alberoListaDin<T>::ultimoFratello(posizione p) const {
    if (p.radice != nullptr && p.radice->getPadre() != nullptr) {
        return p.radice == p.radice->getPadre()->getFigli().ultimoLista();
    }
    return true;  // Se non ha padre, allora è l'unico figlio
}

template <class T>
typename alberoListaDin<T>::posizione alberoListaDin<T>::succFratello(posizione p) const {
    if (p.radice != nullptr && p.radice->getPadre() != nullptr) {
        return posizione(p.radice->getPadre()->getFigli().succLista(p.radice->getPosizioneLista()));
    }
    return posizione();
}

template <class T>
void alberoListaDin<T>::insRadice(const T& elem) {
    if (radice == nullptr) {
        radice = new nodoAlbero<T, alberoListaDin<T>>(elem);
    }
}

template <class T>
void alberoListaDin<T>::insPrimoSottoAlbero(posizione p, const alberoListaDin<T>& sottoAlbero) {
    if (p.radice != nullptr) {
        nodoAlbero<T, alberoListaDin<T>>* nuovoNodo = new nodoAlbero<T, alberoListaDin<T>>();
        nuovoNodo->setElemento(sottoAlbero.radice->getElemento());
        nuovoNodo->setPadre(p.radice);
        nuovoNodo->setFigli(sottoAlbero.radice->getFigli());

        p.radice->getFigli().insLista(nuovoNodo, p.radice->getFigli().primoLista());
    }
}

template <class T>
void alberoListaDin<T>::insSottoAlbero(posizione p, const alberoListaDin<T>& sottoAlbero) {
    if (p.radice != nullptr) {
        nodoAlbero<T, alberoListaDin<T>>* nuovoNodo = new nodoAlbero<T, alberoListaDin<T>>();
        nuovoNodo->setElemento(sottoAlbero.radice->getElemento());
        nuovoNodo->setPadre(p.radice);
        nuovoNodo->setFigli(sottoAlbero.radice->getFigli());

        p.radice->getFigli().insLista(nuovoNodo);
    }
}

template <class T>
void alberoListaDin<T>::cancSottoAlbero(posizione p) {
    if (p.radice != nullptr) {
        cancSottoAlbero(p.radice);
        p.radice->getPadre()->getFigli().cancLista(p.radice->getPosizioneLista());
        delete p.radice;
    }
}

template <class T>
void alberoListaDin<T>::cancSottoAlbero(nodoAlbero<T, alberoListaDin<T>>* p) {
    if (p != nullptr) {
        listaPuntatore<alberoListaDin<T>> figli = p->getFigli();
        while (!figli.listaVuota()) {
            cancSottoAlbero(figli.primoLista());
        }
        delete p;
    }
}

// Altre implementazioni delle funzioni della classe...

#endif // _ALBEROLISTADIN_H
