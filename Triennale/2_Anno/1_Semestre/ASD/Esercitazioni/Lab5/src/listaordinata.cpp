#include "listaordinata.h"
#include "listapuntatore.h"

template <class T>
listaOrdinata<T>::listaOrdinata(const listaPuntatore<T>& l) {
    this->creaLista();
    typename listaPuntatore<T>::posizione pos = l.primoLista();
    while (!l.fineLista(pos)) {
        this->inserisciOrdinato(l.leggiLista(pos));
        pos = l.succLista(pos);
    }
}


template <class T>
void listaOrdinata<T>::inserisciOrdinato(const T& elemento) {
    typename listaPuntatore<T>::posizione p = this->primoLista();

    while (!this->fineLista(p) && elemento > this->leggiLista(p)) {
        p = this->succLista(p);
    }

    this->insLista(elemento, p);
    this->lunghezza++;
}

template <class T>
void listaOrdinata<T>::rimuoviOrdinato(const T& elemento) {
    typename listaPuntatore<T>::posizione p = this->cercaElemento(elemento);

    if (p != nullptr) {
        this->cancLista(p);
        this->lunghezza--;
    }
}

template <class T>
void listaOrdinata<T>::ordinaLista() {
    if (this->lunghezza > 1) {
        bool scambio = true;
        typename listaPuntatore<T>::posizione fine = this->ultimoLista();

        while (scambio) {
            scambio = false;
            typename listaPuntatore<T>::posizione p = this->primoLista();
            while (this->succLista(p) != fine) {
                typename listaPuntatore<T>::posizione successivo = this->succLista(p);

                if (this->leggiLista(p) > this->leggiLista(successivo)) {
                    // Scambia gli elementi
                    typename listaPuntatore<T>::tipoelem temp = this->leggiLista(p);
                    this->scriviLista(this->leggiLista(successivo), p);
                    this->scriviLista(temp, successivo);
                    scambio = true;
                }

                p = successivo;
            }
            fine = this->precedente(fine);
        }
    }
}


template <class T>
listaOrdinata<T> listaOrdinata<T>::fondaListeOrdinate(const listaOrdinata<T>& l) const {
    listaOrdinata<T> result(*this);  // Copia la lista corrente

    typename listaPuntatore<T>::posizione p1 = result.primoLista();
    typename listaPuntatore<T>::posizione p2 = l.primoLista();

    while (!result.fineLista(p1) && !l.fineLista(p2)) {
        if (result.leggiLista(p1) < l.leggiLista(p2)) {
            p1 = result.succLista(p1);
        } else {
            result.insLista(l.leggiLista(p2), p1);
            p2 = l.succLista(p2);
            p1 = result.succLista(p1);
        }
    }

    // Aggiungi eventuali elementi rimanenti dalla seconda lista
    while (!l.fineLista(p2)) {
        result.insLista(l.leggiLista(p2), p1);
        p2 = l.succLista(p2);
        p1 = result.succLista(p1);
    }

    return result;
}

// Aggiungi altre implementazioni dei metodi se necessario
