#ifndef _INSIEME_H
#define _INSIEME_H

#include <iostream>

#include "eccezioniInsiemi.h"

using namespace std;


// DEFINIZIONE
template <class T>
class insieme{
   public:
	typedef T tipoelem;
	// costruttori
	insieme();
	insieme(const insieme<T>&);
	~insieme(); // distruttore
	// operatori
	void creaInsieme();
	bool insiemeVuoto() const;
	bool appartiene(tipoelem) const;
	void inserisci(tipoelem);
	void cancella(tipoelem);
	void unione(const insieme<T>&);
	void intersezione(const insieme<T>&);
	void differenza(const insieme<T>&);
	// funzioni di servizio
	int ricerca(tipoelem) const;
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const insieme<T>& ins){
		os << "< "; 
		for (int i=0; i < ins.cardinalita_insieme; i++)
			os << ins.vettore[i] << "; " ;
		os << ">" << endl;
		return (os);
	}
   private:
	void cambia_dimensione (T*&, int, int);
	tipoelem* vettore;
	int dimensione_vettore;
	int cardinalita_insieme;
};


// IMPLEMENTAZIONE
// costruttori
template <class T>
insieme<T>::insieme(){
	dimensione_vettore = 5;
	this->creaInsieme();	
}

template <class T>
insieme<T>::insieme(const insieme<T>& ins){
	this->dimensione_vettore = ins.dimensione_vettore;
	this->cardinalita_insieme = ins.cardinalita_insieme;
	this->vettore = new tipoelem[dimensione_vettore];
	for (int i=0; i<cardinalita_insieme; i++){
		this->vettore[i] = ins.vettore[i];
	}
}


template <class T>
insieme<T>::~insieme(){
	delete [] vettore;
}


// operatori
template <class T>
void insieme<T>::creaInsieme(){
	cardinalita_insieme = 0;
	this->vettore = new tipoelem[dimensione_vettore];
}


template <class T>
bool insieme<T>::insiemeVuoto() const{
	return (cardinalita_insieme == 0);
}


template <class T>
bool insieme<T>::appartiene(tipoelem e) const{
	bool ricerca = false;
	if (ricerca(e) != -1){
		ricerca = true;
	}
	return ricerca;
}


template <class T>
void insieme<T>::inserisci(tipoelem e){
	if (ricerca(e) == -1){
		if (cardinalita_insieme == dimensione_vettore){
			cambia_dimensione (vettore, dimensione_vettore, dimensione_vettore*2);
			dimensione_vettore = dimensione_vettore*2;
		}
		vettore[cardinalita_insieme] = e;
		cardinalita_insieme++;
	}
	else{
		throw elementoPresente();
	}
}


template <class T>
void insieme<T>::cancella(tipoelem e){
	int pos = ricerca (e);
	if (pos != -1){
		cardinalita_insieme --;
		for (int i=pos; i < cardinalita_insieme; i++)
			vettore[i] = vettore [i+1];
	}
	else{
		throw elementoPresente();
	}
}


template <class T>
void insieme<T>::unione(const insieme<T>& ins){
	if (!(this->insiemeVuoto())){
		for (int i=0; i < ins.cardinalita_insieme; i++){
			tipoelem e = ins.vettore[i];
			if (this->ricerca(e) == -1)
				this->inserisci(e);
		}
	}
	else{
		for (int i=0; i < ins.cardinalita_insieme; i++){
			this->inserisci(ins.vettore[i]);
		}
	}
}


template <class T>
void insieme<T>::intersezione(const insieme<T>& ins){
	if (!(ins.insiemeVuoto())){
		for (int i=0; i < this->cardinalita_insieme; i++){
			tipoelem e = this->vettore[i];
			if (ins.ricerca(e) == -1){
				this->cancella(e);
				i--;
			}
		}
	}
	else{
		this->cardinalita_insieme = 0;
	}
}


template <class T>
void insieme<T>::differenza(const insieme<T>& ins){
	if (!(this->insiemeVuoto())){
		for (int i=0; i < ins.cardinalita_insieme; i++){
			tipoelem e = ins.vettore[i];
			if (this->ricerca(e) != -1){
				this->cancella(e);
				i--;
			}
		}
	}
}


// funzioni di servizio
template <class T>
int insieme<T>::ricerca(tipoelem e) const{
	int pos = -1;
	for (int i=0; (pos == -1) && (i < cardinalita_insieme); i++){
		if (this->vettore[i] == e)
			pos = i;
	}
	return pos;
}


// funzioni private
template <class T>
void insieme<T>::cambia_dimensione (T*& ins, int vecchia_dim, int nuova_dim){
	T* temp = new T[nuova_dim];
	int n;
	if (vecchia_dim < nuova_dim) 
	     n = vecchia_dim;
	else
     	n = nuova_dim;
	for (int i=0; i<n; i++)
	     temp[i] = ins[i];
	delete [] ins;
	ins = temp;
}


#endif // _INSIEME_H 
