#ifndef _LISTAORDINATA_H
#define _LISTAORDINATA_H

#include "listapuntatore.h"

template <class T>
class listaOrdinata : public listaPuntatore<T> {
public:
    listaOrdinata(const listaPuntatore<T>&);
    void inserisciOrdinato(const T&);
    void rimuoviOrdinato(const T&);
    void ordinaLista();
    listaOrdinata<T> fondaListeOrdinate(const listaOrdinata<T>&) const;
};

#endif // _LISTAORDINATA_H
