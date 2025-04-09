#ifndef _CODAVETTORE_H
#define _CODAVETTORE_H

#include <iostream>

#include "codaAstratta.h"
#include "queueException.h"

using namespace std;


// DEFINIZIONE
template <class T>
class codaVettore : public codaAstratta<T, int> {
   public:
	typedef typename codaAstratta<T, int>::tipoelem tipoelem;
	typedef typename codaAstratta<T, int>::posizione posizione;
	// costruttori
	codaVettore(int); // setta una dimensione iniziale specifica per il vettore
	codaVettore (const codaVettore<T>&); // costruttore di copia
	~codaVettore(); // distruttore
	// operatori
	void creaCoda();
	bool codaVuota() const;
	tipoelem leggiCoda() const;
	void fuoriCoda();
	void inCoda(tipoelem);
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const codaVettore<T>& c){
		int pos = c.primo;
		for (int i=0; i < c.ultimo; i++){
			if (pos >= c.dimensione_vettore)
				pos = pos - c.dimensione_vettore;
			os << "<" << c.vettore[pos] << ">" << endl;
			pos ++;	
		}
		return (os); 
	};
   private:
	tipoelem* vettore;
	posizione primo; // punta alla prima posizione della coda
	posizione ultimo; // lunghezza della coda 
	int dimensione_vettore;
};


// IMPLEMENTAZIONE
// costruttori
template <class T>
codaVettore<T>::codaVettore(int dim){
	dimensione_vettore = dim;
	creaCoda();
}


template <class T>
codaVettore<T>::codaVettore (const codaVettore<T>& c){
	this->primo = c.primo;
	this->ultimo = c.ultimo;
	this->dimensione_vettore = c.dimensione_vettore;
	this->vettore = new T [dimensione_vettore];
	int pos = primo;
	for (int i = 0; i < ultimo; i++){
		if (pos >= dimensione_vettore)
			pos = 0;  // Riporta pos a 0 se supera la dimensione del vettore
		this->vettore[i] = c.vettore[pos];
		pos++;  // Incrementa posizione dopo la copia
	} 
}


template <class T>
codaVettore<T>::~codaVettore(){
	delete[] vettore;
}


// operatori
template <class T>
void codaVettore<T>::creaCoda() {
	this->vettore = new T (dimensione_vettore);
	this->primo = 0;
	this->ultimo = 0; 
	return;
}


template <class T>
bool codaVettore<T>::codaVuota() const {
	return (ultimo == 0);
}


template <class T>
typename codaVettore<T>::tipoelem codaVettore<T>::leggiCoda() const{
	if (!codaVuota()){
		return (vettore[primo]);
	}
	 else
	 	throw emptyQueueException();
}


template <class T>
void codaVettore<T>::fuoriCoda() {
	if (!codaVuota()){
		int pos = primo+1;
		if (pos >= dimensione_vettore)
			primo = pos - dimensione_vettore;	
		else
			primo = pos;
		ultimo --;
	}
	else
		throw emptyQueueException();
	return;
}


template <class T>
void codaVettore<T>::inCoda (typename codaVettore<T>::tipoelem e){
	if (ultimo < dimensione_vettore){
		ultimo++;
		int pos = primo+ultimo-1;
		if (pos >= dimensione_vettore)
			pos = pos - dimensione_vettore;	
		vettore[pos] = e;
	}
	else{
		throw fullQueueException();
	}
	return;
}


#endif // _PILAVETTORE_H 
