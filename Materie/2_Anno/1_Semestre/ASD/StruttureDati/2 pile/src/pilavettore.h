#ifndef _PILAVETTORE_H
#define _PILAVETTORE_H

#include <iostream>

#include "pilaAstratta.h"
#include "stackException.h"

using namespace std;


// DEFINIZIONE
template <class T>
class pilaVettore : public pilaAstratta<T, int> {
public:
	typedef typename pilaAstratta<T, int>::tipoelem tipoelem;
	typedef typename pilaAstratta<T, int>::posizione posizione;
	// costruttori
	pilaVettore();
	pilaVettore(int); // setta una dimensione iniziale specifica per il vettore
	pilaVettore (const pilaVettore<T>&); // costruttore di copia
	~pilaVettore(); // distruttore
	// operatori
	void creaPila();
	bool pilaVuota() const;
	tipoelem leggiPila() const;
	void fuoriPila();
	void inPila(tipoelem);
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const pilaVettore<T>& p){
		if (!p.pilaVuota()){
			int pos = p.testa - 1;
			while (pos >= 0){
				os << p.vettore[pos] << endl;
				pos --;
			}
		}
		else{
			os << "La pila è vuota!" << endl;
		}
		return os;
	};
private:
	void cambia_dimensione (T*&, int, int);   
	tipoelem* vettore;
	posizione testa;
	int dimensione_vettore;
};


// IMPLEMENTAZIONE
// costruttori
template <class T>
pilaVettore<T>::pilaVettore(){
	dimensione_vettore = 5;
	creaPila();
}


template <class T>
pilaVettore<T>::pilaVettore(int dim){
	dimensione_vettore = dim;
	creaPila();
}


template <class T>
pilaVettore<T>::pilaVettore (const pilaVettore<T>& p){
	this->testa = p.testa;
	this->dimensione_vettore = p.dimensione_vettore;
	this->vettore = new T[dimensione_vettore];
	for (int i=0; i<testa; i++)
		this->vettore[i] = p.vettore[i]; 
}


template <class T>
pilaVettore<T>::~pilaVettore(){
	delete[] vettore;
}


// operatori
template <class T>
void pilaVettore<T>::creaPila() {
	this->vettore = new T (dimensione_vettore);
	this->testa = 0;
}


template <class T>
bool pilaVettore<T>::pilaVuota() const {
	return (testa == 0);
}


template <class T>
typename pilaVettore<T>::tipoelem pilaVettore<T>::leggiPila() const{
	if (!pilaVuota())
		return (vettore[testa-1]);
	else
		throw emptyStackException();
}


template <class T>
void pilaVettore<T>::fuoriPila() {
	if (!pilaVuota())
		testa-=1;
	else
		throw emptyStackException();
}


template <class T>
void pilaVettore<T>::inPila (typename pilaVettore<T>::tipoelem e){
	if (testa == dimensione_vettore){
		cambia_dimensione (vettore, dimensione_vettore, dimensione_vettore*2);
		dimensione_vettore = dimensione_vettore*2;
	}
	vettore[testa] = e;
	testa++;
}


// funzioni private
template <class T>
void pilaVettore<T>::cambia_dimensione (T*& p, int vecchia_dim, int nuova_dim){
	T* temp = new T[nuova_dim];
	int n;
	if (vecchia_dim < nuova_dim) 
		n = vecchia_dim;
	else
		n = nuova_dim;
	for (int i=0; i<n; i++)
		temp[i] = p[i];
	delete [] p;
	p = temp;
}


#endif // _PILAVETTORE_H 
