// NODO.H

#ifndef _NODO_H
#define _NODO_H

template <class T>
class nodo {
public:
    typedef T tipoelem;
    // costruttori
    nodo() : successivo(nullptr) { };
    nodo(const tipoelem& e) : elemento(e), successivo(nullptr) { };
    nodo(const nodo<T>& other) : elemento(other.elemento), successivo(nullptr) { };
    ~nodo() { }; // distruttore
    // operatori
    void setElemento(const tipoelem& e) { elemento = e; };
    tipoelem getElemento() const { return elemento; };
    void setSucc(nodo* c) { successivo = c; };
    nodo* getSucc() const { return successivo; };
private:
    tipoelem elemento;
    nodo* successivo;
};

#endif // _NODO_H
