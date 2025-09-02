#ifndef _HASHAPERTO_H
#define _HASHAPERTO_H

#include <iostream>
#include <string>

#include "dizionari.h"
#include "bucket.h"
#include "hash.h"
#include "dictionaryException.h"
#include "listapuntatore.h"

using namespace std;


// DEFINIZIONE
template <class K, class V>
class hashAperto : public dizionario<K,V>{
   public:
	typedef typename dizionario<K,V>::chiave chiave;
	typedef typename dizionario<K,V>::valore valore;
	// costruttori
	hashAperto();
	hashAperto(int);
	~hashAperto();
	// metodi
	void creaDizionario();
	bool dizionarioVuoto() const;
	bool appartiene(const chiave&) const;
	void inserisci(const chiave&, const valore&);
	void cancella(const chiave&);
	bucket<K, V>* recupera(const chiave&) const;
	bool containsValue(const V& value) const;
	listaPuntatore<V> values() const;
	listaPuntatore<K> keys() const;
    void resize();
	// funzioni di servizio
	void aggiornaValore(const chiave&, const valore&);
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const  hashAperto<K,V>& d){
		if(!d.dizionarioVuoto()){
			os << "[Dizionario]: ";
			os << d.dimensione;
			os << endl;
			for (int i = 0; i<d.dimensione; i++){
				if ((d.hash[i].leggiLista(d.hash[i].primoLista())) == (nullptr)){
					os << "\t[" << i << "]\t->\tVuoto";
					os << endl;
				}
				else{
					typename listaPuntatore<bucket<K,V>* >::posizione pos_lista;					
					pos_lista = d.hash[i].primoLista();
					os << "\t[" << i << "]\t->\t";
					while (!d.hash[i].fineLista(pos_lista)){
						os << (d.hash[i].leggiLista(pos_lista)) << "   ->   ";
						pos_lista = d.hash[i].succLista(pos_lista); 
					}
					os << endl;
				}
			}
		}
		else{
			os << "ATTENZIONE: Il Dizionario e' vuoto!" << endl;
		}
		return os ;
	}
   private:
   	int scan(const chiave&) const;
	listaPuntatore<bucket<K,V>*>* hash;
	hashClass<K> hashMap;
	int dimensione;
	int lunghezza;
};


// IMPLEMENTAZIONE
// costruttori
template <class K, class V>
hashAperto<K,V>::hashAperto(){
	this->dimensione = 100;
	this->creaDizionario();
}


template <class K, class V>
hashAperto<K,V>::hashAperto(int dim){
	this->dimensione = dim;
	this->creaDizionario();
}


template <class K, class V>
hashAperto<K,V>::~hashAperto(){
	delete [] hash;
}


// metodi
template <class K, class V>
void hashAperto<K,V>::creaDizionario(){
	this->lunghezza = 0;
	this->hash = new listaPuntatore<bucket<K,V>*> [this->dimensione];
	for (int i=0; i < dimensione; i++) 
		this->hash[i].insLista(nullptr, this->hash[i].primoLista());
}


template <class K, class V>
bool hashAperto<K,V>::dizionarioVuoto() const{
	return (this->lunghezza == 0);
}


template <class K, class V>
bool hashAperto<K,V>::appartiene (const chiave& c) const{
	return (this->recupera(c) != nullptr);
}


template <class K, class V>
void hashAperto<K,V>::inserisci (const chiave& c, const valore& v){
	if(!this->appartiene(c)){
		int pos = this->scan(c);
		bucket<K,V>* b = new bucket<K,V>(c, v);
		this->hash[pos].insLista(b, this->hash[pos].primoLista());
		this->lunghezza++;
	}
	else{
		this->recupera(c)->setValore(v);
	}
}


template <class K, class V>
void hashAperto<K,V>::cancella (const chiave& c){
	if(this->appartiene(c)){
		int pos = this->scan(c);
		bool trovato = false;
		typename listaPuntatore<bucket<K,V>* >::posizione pos_lista;
		pos_lista = this->hash[pos].primoLista();
		while(!this->hash[pos].fineLista(pos_lista) && !trovato){  // vedere se considera anche l'ultimo elemento della lista in hash[pos]
			if(this->hash[pos].leggiLista(pos_lista)->getChiave() != c){
				pos_lista = this->hash[pos].succLista(pos_lista);
			}
			else{
				trovato = true;
			}
		}
		this->hash[pos].cancLista(pos_lista);
		this->lunghezza--;
	}
	else{
		throw nonExistentKeyDictionaryException();
	}
}


template <class K, class V>
bucket<K, V>* hashAperto<K,V>::recupera (const chiave& c) const{
	int pos = this->scan(c);
	bool trovato = false;
	typename listaPuntatore<bucket<K,V>* >::posizione pos_lista;
	if(!this->hash[pos].listaVuota()){
		pos_lista = this->hash[pos].primoLista();
		while(!this->hash[pos].fineLista(pos_lista) && !trovato){
			if(this->hash[pos].leggiLista(pos_lista)->getChiave() == c){
				trovato = true;
			}
			else{
				pos_lista = this->hash[pos].succLista(pos_lista);
			}
		}
		if(trovato == true){
			return this->hash[pos].leggiLista(pos_lista);
		}
		else{
			return nullptr;
		}
	}
	else{
		return nullptr;
	}
}


// funzioni di servizio
template <class K, class V>
void hashAperto<K,V>::aggiornaValore(const chiave& c, const valore& v){
	if(this->recupera(c) != nullptr){
		this->recupera(c)->setValore(v);
	}
	else{
		throw nonExistentKeyDictionaryException();
	}
}


template <class K, class V>
int hashAperto<K,V>::scan(const chiave& c) const {
    size_t hashValue = this->hashMap(c);
    int pos = static_cast<int>(hashValue % static_cast<size_t>(this->dimensione));
    return pos;
}

template <class K, class V>
bool hashAperto<K,V>::containsValue(const V& value) const {
    for (int i = 0; i < dimensione; ++i) {
        typename listaPuntatore<bucket<K, V>*>::posizione pos_lista;
        pos_lista = hash[i].primoLista();

        while (!hash[i].fineLista(pos_lista)) {
            if (hash[i].leggiLista(pos_lista)->getValore() == value) {
                return true;
            }
            pos_lista = hash[i].succLista(pos_lista);
        }
    }
    return false;
}

template <class K, class V>
listaPuntatore<V> hashAperto<K,V>::values() const {
    listaPuntatore<V> result;
    for (int i = 0; i < dimensione; ++i) {
        typename listaPuntatore<bucket<K, V>*>::posizione pos_lista;
        pos_lista = hash[i].primoLista();

        while (!hash[i].fineLista(pos_lista)) {
            result.insLista(hash[i].leggiLista(pos_lista)->getValore(), result.primoLista());
            pos_lista = hash[i].succLista(pos_lista);
        }
    }
    return result;
}

template <class K, class V>
listaPuntatore<K> hashAperto<K,V>::keys() const {
    listaPuntatore<K> result;
    for (int i = 0; i < dimensione; ++i) {
        typename listaPuntatore<bucket<K, V>*>::posizione pos_lista;
        pos_lista = hash[i].primoLista();

        while (!hash[i].fineLista(pos_lista)) {
            result.insLista(hash[i].leggiLista(pos_lista)->getChiave(), result.primoLista());
            pos_lista = hash[i].succLista(pos_lista);
        }
    }
    return result;
}

template <class K, class V>
void hashAperto<K,V>::resize() {
    int nuovaDimensione = dimensione * 2;
    listaPuntatore<bucket<K, V>*>* nuovaHash = new listaPuntatore<bucket<K, V>*>[nuovaDimensione];

    for (int i = 0; i < dimensione; ++i) {
        typename listaPuntatore<bucket<K, V>*>::posizione pos_lista;
        pos_lista = hash[i].primoLista();

        while (!hash[i].fineLista(pos_lista)) {
            bucket<K, V>* elemento = hash[i].leggiLista(pos_lista);
            int nuovaPos = scan(elemento->getChiave(), nuovaDimensione);
            nuovaHash[nuovaPos].insLista(elemento, nuovaHash[nuovaPos].primoLista());
            pos_lista = hash[i].succLista(pos_lista);
        }
    }

    delete[] hash;
    hash = nuovaHash;
    dimensione = nuovaDimensione;
}

#endif
