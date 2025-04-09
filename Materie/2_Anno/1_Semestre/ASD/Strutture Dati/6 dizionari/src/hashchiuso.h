#ifndef _HASHCHIUSO_H
#define _HASHCHIUSO_H

#include <iostream>
#include <string>

#include "dizionari.h"
#include "bucket.h"
#include "hash.h"
#include "dictionaryException.h"

using namespace std;


// DEFINIZIONE
template <class K, class V>
class hashChiuso : public dizionario<K,V>{
public:
	typedef typename dizionario<K,V>::chiave chiave;
	typedef typename dizionario<K,V>::valore valore;
	// costruttori
	hashChiuso();
	hashChiuso(int);
	~hashChiuso();
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
	friend ostream& operator<<(ostream& os, const  hashChiuso<K,V>& d){
		if(!d.dizionarioVuoto()){
			os << "[Dizionario]: ";
			os << d.dimensione;
			os << endl;
			for (int i = 0; i<d.dimensione; i++){
				if ((d.hash[i] == NULL)){
					os << "\t[" << i << "]\t->\tVuoto";
					os << endl;
				}
				else{
					if (d.hash[i]->isEliminato()){
						os << "\t[" << i << "]\t->\tEliminato";
						os << endl;
					}
					else{
						os << "\t[" << i << "]\t->\t" << *(d.hash[i]);
						os << endl;
					}
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
	bucket<K,V>** hash;
	hashClass<K> hashMap;
	int dimensione;
	int lunghezza;
};


// IMPLEMENTAZIONE
// costruttori
template <class K, class V>
hashChiuso<K,V>::hashChiuso(){
	this->dimensione = 100;
	this->creaDizionario();
}


template <class K, class V>
hashChiuso<K,V>::hashChiuso(int dim){
	this->dimensione = dim;
	this->creaDizionario();
}


template <class K, class V>
hashChiuso<K,V>::~hashChiuso(){
	delete [] hash;
}


// metodi
template <class K, class V>
void hashChiuso<K,V>::creaDizionario(){
	this->lunghezza = 0;
	this->hash = new bucket<K,V>* [this->dimensione];
	for (int i=0; i < dimensione; i++)
		this->hash[i] = nullptr;
}


template <class K, class V>
bool hashChiuso<K,V>::dizionarioVuoto() const{
	return (this->lunghezza == 0);
}


template <class K, class V>
bool hashChiuso<K,V>::appartiene (const chiave& c) const{
	return (this->recupera(c) != nullptr);
}


template <class K, class V>
void hashChiuso<K,V>::inserisci (const chiave& c, const valore& v){
	if (this->lunghezza < this->dimensione){
		int pos = this->scan(c);
		if(this->appartiene(c)){
			this->hash[pos]->setValore(v);
			if (this->hash[pos]->isEliminato()){
				this->hash[pos]->setEliminato(false);
				this->lunghezza++;
			}
		}
		else{
			this->hash[pos] = new bucket<K,V>(c, v);
			this->lunghezza++;
		}
	}
	else{
		throw fullDictionaryException();
	}
}


template <class K, class V>
void hashChiuso<K,V>::cancella (const chiave& c){
	if (!this->dizionarioVuoto()){
		if (this->appartiene(c)){
			this->recupera(c)->setEliminato(true);
			this->lunghezza --;
		}
	}
	else{
		throw emptyDictionaryException();
	}
}


template <class K, class V>
bucket<K, V>* hashChiuso<K,V>::recupera (const chiave& c) const{
	int pos = this->scan(c);
	if ((this->hash[pos] == nullptr) || (this->hash[pos]->getChiave() != c))
		return nullptr;
	else
		return this->hash[pos];
}


// funzioni di servizio
template <class K, class V>
void hashChiuso<K,V>::aggiornaValore(const chiave& c, const valore& v){
	if (this->recupera(c) != nullptr){
		this->recupera(c)->setValore(v);
	}
	else{
		throw nonExistentKeyDictionaryException();
	}
}


template <class K, class V>
int hashChiuso<K,V>::scan (const chiave& c) const{
	int i = (int)(this->hashMap(c) % this->dimensione);
	int j = i;
	do{
		if((this->hash[j] != nullptr) && (!this->hash[j]->isEliminato())){
			if(this->hash[j]->getChiave() == c){
				return j;
			}
		}
		if((this->hash[j] != nullptr) && (this->hash[j]->isEliminato())){
			return j;
		}
		if(this->hash[j] == nullptr){
			return j;
		}
		j = (j+1)%(this->dimensione); // scansione lineare
	}while(i != j);
	return j;
}

template <class K, class V>
void hashChiuso<K,V>::resize() {
    int nuovaDimensione = this->dimensione * 2;

    bucket<K, V>** nuovaTabella = new bucket<K, V>*[nuovaDimensione];

    for (int i = 0; i < nuovaDimensione; i++) {
        nuovaTabella[i] = nullptr;
    }

    for (int i = 0; i < this->dimensione; i++) {
        if (this->hash[i] != nullptr && !this->hash[i]->isEliminato()) {
            int nuovaPosizione = scan(this->hash[i]->getChiave(), nuovaDimensione);
            while (nuovaTabella[nuovaPosizione] != nullptr) {
                nuovaPosizione = (nuovaPosizione + 1) % nuovaDimensione;
            }
            nuovaTabella[nuovaPosizione] = this->hash[i];
        }
    }

    delete[] this->hash;

    this->dimensione = nuovaDimensione;

    this->hash = nuovaTabella;
}

template <class K, class V>
bool hashChiuso<K,V>::containsValue(const V& value) const {
    for (int i = 0; i < this->dimensione; i++) {
        if (this->hash[i] != nullptr && !this->hash[i]->isEliminato() && this->hash[i]->getValore() == value) {
            return true;
        }
    }
    return false;
}
#endif
