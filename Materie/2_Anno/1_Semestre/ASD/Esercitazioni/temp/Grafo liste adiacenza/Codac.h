#ifndef Codac_H
#define Codac_H
#include "Nodoc.h"

const int maxlung=100;

class Codac {
    Nodoc elemento[maxlung];
    int testa, fondo, inizioll; // ll = coda libera

public:
    Codac();
    ~Codac();

    void creacoda();
    void inizializzall();
    bool codavuota();
    puntaelem leggicoda();
    void fuoricoda();
    void incoda(puntaelem);
};

typedef Codac coda;
//typedef Nodoc nodo;

#endif
