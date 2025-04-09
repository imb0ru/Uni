/*
 * coda_alberi.h
 *
 *  Created on: 12 gen
 *      Author: michele
 */

#ifndef N_TREES_ALBERO_PTR_H
#define N_TREES_ALBERO_PTR_H

#include "N_tree_astratto.h"
#include "coda_alberi.h"
#include <stdexcept>
#include <iostream>

template<class T>
class AlberoPtr;

template<class T>
class Nodo {
	friend class AlberoPtr<T>;
private:
	T valore;
	Nodo<T>* padre;
	Nodo<T>* primoFiglio;
	Nodo<T>* fratelloSuccessivo;
public:
	Nodo();
	T getValore();
	void setValore(T val);
	Nodo<T>* getpadre();
	Nodo<T>* getprimofiglio();
	Nodo<T>* getfratellosuccessivo();
};

template<class T>
Nodo<T>::Nodo() {
	valore=T(NULL);
	padre=nullptr;
	primoFiglio=nullptr;
	fratelloSuccessivo=nullptr;
}
template<class T>
Nodo<T>* Nodo<T>::getpadre() {
	return padre;
}
template<class T>
Nodo<T>* Nodo<T>:: getprimofiglio() {
	return primoFiglio;
}
template<class T>
Nodo<T>* Nodo<T>:: getfratellosuccessivo() {
	return fratelloSuccessivo;
}
template<class T>
T Nodo<T>::getValore() {
	return valore;
}
template<class T>
void Nodo<T>::setValore(T val) {
	valore=val;
}
template<class T>
class AlberoPtr : public Albero<T, Nodo<T> *> {
public:
	typedef typename Albero<T, Nodo<T> *>::tipoElem tipoElem;
	typedef typename Albero<T, Nodo<T> *>::nodo nodo;

	AlberoPtr();
	AlberoPtr(const AlberoPtr<T>&);
	~AlberoPtr();

	bool alberoVuoto() const;
	nodo radice() const;
	nodo padre(nodo n) const;
	bool foglia(nodo n) const;
	nodo primoFiglio(nodo n) const;
	bool ultimoFratello(nodo n) const;
	nodo fratelloSuccessivo(nodo n) const;
	void inserisciRadice(tipoElem k);
	void insPrimoFiglio(nodo n, tipoElem k);
	void insFratelloSuccessivo(nodo n, tipoElem k);
	void insPrimoSottoAlbero(nodo n, AlberoPtr<T> &a);
	void insSottoAlbero(nodo n, AlberoPtr<T> &a);
	void cancellaSottoAlbero(nodo n);
	int ottieniNumeroNodi() const { return numeroNodi; }
	int profonditaAlbero();
	int profondita(nodo n);
	void scriviNodo(nodo n, tipoElem k);
	int calcolaresumsottoalbero(nodo n);
	tipoElem leggiNodo(nodo n) const;

	bool operator==(const AlberoPtr<T>&a) const;
	bool operator!=(const AlberoPtr<T>&a) const;
	AlberoPtr<T>& operator=(const AlberoPtr<T>& a);
	void copiaNodo(nodo n, nodo daCopiare);
	void previsita(nodo n);
	void stampaRicorsiva(Nodo<T>*, std::string) const;
	bool confrontaNodi(nodo, nodo) const;
	void stampaSottoAlbero(nodo n) const;
	void modificareEtichetta(nodo n);
	void modificare_albero(nodo n);

	int inner(nodo n, const T parent_value);

private:
	Nodo<T>* root;
	int numeroNodi;


};

template<class T>
int AlberoPtr<T>::inner(nodo n, const T parent_value) {
    int count = 0;
    if (n != nullptr) {
        if (n->padre != nullptr && n->getValore() > parent_value) {
            count++;
        }
        nodo child = n->getprimofiglio();
        while (child != nullptr) {
            count += inner(child, n->getValore());
            child = child->getfratellosuccessivo();
        }
    }
    return count;
}


template<class T>
void AlberoPtr<T>::modificare_albero(nodo n) {
	if(n==nullptr) {
			return ;
		}
		modificareEtichetta(n);
		if(!foglia(n)) {
			nodo nod=primoFiglio(n);
			while(nod!=nullptr) {
				modificareEtichetta(nod);
				nod=fratelloSuccessivo(nod);
			}
			modificareEtichetta(nod);
		}
}
template<class T>
void AlberoPtr<T>::modificareEtichetta(nodo n) {
	int newval=0;
	newval=calcolaresumsottoalbero(primoFiglio(n));
	n->setValore(newval);
}

template<class T>
int AlberoPtr<T>::calcolaresumsottoalbero(nodo n) {
	int sum=0;

	if(n==nullptr) {
		return sum;
	}
	sum+=n->getValore();
	if(!foglia(n)) {
		nodo nod=primoFiglio(n);
		while(nod!=nullptr) {
			sum+=calcolaresumsottoalbero(nod);
			nod=fratelloSuccessivo(nod);
		}
		sum+=calcolaresumsottoalbero(nod);
	}
	return sum;
}
template<class T>
void AlberoPtr<T>::previsita(nodo n) {
	if(n==nullptr) {
		return ;
	}
	cout<<n->getValore()<<" ";
	if(!foglia(n)) {
		nodo nod=primoFiglio(n);
		while(nod!=nullptr) {
			previsita(nod);
			nod=fratelloSuccessivo(nod);
		}
		previsita(nod);
	}
}
template<class T>
AlberoPtr<T>::AlberoPtr() {
	numeroNodi = 0;
	root = nullptr;
}

template<class T>
int AlberoPtr<T>::profonditaAlbero() {
	if (alberoVuoto())
		return 0;
	else {
		return profondita(radice());
	}
}

template <class T>
int AlberoPtr<T>::profondita(nodo n) {
	//se il nodo è foglia ritorno 0
	if (foglia(n)) return 0;
	//se il nodo non è foglia allora richiamo la funzione sui suoi figli e fratelli
	//inizializzo un variabile m=1. Questa indica la profondità attuale
	int m = 1;
	int c;
	nodo k = primoFiglio(n);
	while (!ultimoFratello(k)) {
		//calcolo la profondità di ogni fratello del nodo n.
		// Se questa è maggiare della profondità attuale allora aggiorno la profondità attuale
		c = profondita(k);
		if (c > m) {
			m = c;
		}
		k = fratelloSuccessivo(k);
	}
	c = profondita(k);
	if (c > m) {
		m = c;
	}
	//ritorno la profondità attuale piu 1
	return (m + 1);
}
template<class T>
AlberoPtr<T>::AlberoPtr(const AlberoPtr<T>& a) {
	root = new Nodo<T>;
	numeroNodi = 0;
	scriviNodo(root, a.leggiNodo(a.radice()));
	if (!a.foglia(a.radice())) {
		copiaNodo(root, a.primoFiglio(a.radice()));
	}
	numeroNodi++;
}
template<class T>
void AlberoPtr<T>::copiaNodo(nodo n, nodo daCopiare) {
	if (daCopiare != nullptr) {
		if (daCopiare->fratelloSuccessivo != nullptr) {
			copiaNodo(n, daCopiare->fratelloSuccessivo);
		}
		insPrimoFiglio(n, daCopiare->valore);
		if (daCopiare->primoFiglio != nullptr){
			copiaNodo(n->primoFiglio, daCopiare->primoFiglio);
		}
	}
}

template<class T>
AlberoPtr<T>::~AlberoPtr() {
	if (!alberoVuoto()){
		cancellaSottoAlbero(radice());
	}else {
		delete root;
		root = nullptr;
	}
}

template<class T>
bool AlberoPtr<T>::alberoVuoto() const{
	return (root == nullptr);
}

template<class T>
typename AlberoPtr<T>::nodo AlberoPtr<T>::radice() const{
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else
		return root;
}

template<class T>
typename AlberoPtr<T>::nodo AlberoPtr<T>::padre(nodo n) const{
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == root)
		throw std::runtime_error("Il nodo radice non ha un genitore");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else
		return n->padre;
}

template<class T>
bool AlberoPtr<T>::foglia(nodo n) const{
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else
		return n->primoFiglio == nullptr;
}

template<class T>
typename AlberoPtr<T>::nodo AlberoPtr<T>::primoFiglio(nodo n) const{
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else
		return n->primoFiglio;
}

template<class T>
bool AlberoPtr<T>::ultimoFratello(nodo n) const{
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else return (n->fratelloSuccessivo == nullptr);
}

template<class T>
typename AlberoPtr<T>::nodo AlberoPtr<T>::fratelloSuccessivo(nodo n) const{
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else
		return n->fratelloSuccessivo;
}

template<class T>
void AlberoPtr<T>::inserisciRadice(tipoElem val) {
	if (!alberoVuoto())
		throw std::runtime_error("L'albero ha gia' una radice");
	else {
		root = new Nodo<T>();
		root->valore = val;
		root->fratelloSuccessivo = nullptr;
		root->padre = nullptr;
		root->primoFiglio = nullptr;
		numeroNodi++;
	}
}

template<class T>
void AlberoPtr<T>::insPrimoFiglio(nodo n, tipoElem val) {
	if (alberoVuoto()) {
		throw std::runtime_error("Albero vuoto");
	}else if (n == nullptr){
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	}else {
		nodo nuovoNodo = new Nodo<T>();
		nuovoNodo->fratelloSuccessivo = n->primoFiglio;
		n->primoFiglio = nuovoNodo;
		nuovoNodo->valore = val;
		nuovoNodo->padre = n;
		numeroNodi++;
	}
}

template<class T>
void AlberoPtr<T>::insFratelloSuccessivo(nodo n, tipoElem val) {
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else if (n == root)
		throw std::runtime_error("La ridice non puo' avere fratelli successivi");
	else {
		nodo nuovoNodo = new Nodo<T>();
		nuovoNodo->fratelloSuccessivo = n->fratelloSuccessivo;
		n->fratelloSuccessivo = nuovoNodo;
		nuovoNodo->valore = val;
		nuovoNodo->padre = n->padre;
		numeroNodi++;
	}
}

template<class T>
void AlberoPtr<T>::insPrimoSottoAlbero(nodo n, AlberoPtr<T> &a) {
	if (alberoVuoto() && a.alberoVuoto()) {
		throw std::out_of_range("Uno dei due alberi e' vuoto");
	} else {
		//creo un nuovo nodo e vi copio il contenuto della radice di a
		Nodo<T>* sub = new Nodo<T>();
		scriviNodo(sub,a.leggiNodo(a.radice()));
		//se a non è foglia copio tutto il suo sotto-albero in sub
		if (!a.foglia(a.radice())) copiaNodo(sub,a.primoFiglio(a.radice()));
		//inserisco il nuovo albero come primoFiglio di n
		sub->padre = n;
		sub->fratelloSuccessivo = n->primoFiglio;
		n->primoFiglio = sub;
		numeroNodi += a.numeroNodi;
	}
}

template<class T>
void AlberoPtr<T>:: insSottoAlbero(nodo n, AlberoPtr<T> &a) {
	if (alberoVuoto() && a.alberoVuoto()) {
		throw std::out_of_range("Uno dei due alberi e' vuoto");
	} else if (n == nullptr) {
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	} else {
		//creo un nuovo nodo e vi copio il contenuto della radice di a
		Nodo<T>* sub = new Nodo<T>();
		scriviNodo(sub,a.leggiNodo(a.radice()));
		//se a non è foglia copio tutto il suo sotto-albero in sub
		if (!a.foglia(a.radice())) copiaNodo(sub,a.primoFiglio(a.radice()));
		//inserisco il nuovo albero come primoFiglio di n
		sub->padre = n;
		sub->fratelloSuccessivo = n->primoFiglio;
		n->primoFiglio = sub;
		numeroNodi += a.numeroNodi;
	}
}

template <class T>
void AlberoPtr<T>::cancellaSottoAlbero(nodo n) {
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else {
		while (n->primoFiglio != nullptr) {
			cancellaSottoAlbero(n->primoFiglio);
		}
		if (n != root) {
			if (n->fratelloSuccessivo == nullptr) {
				n->padre->primoFiglio->fratelloSuccessivo = nullptr;
			}
			if (n->padre->primoFiglio == n){
				n->padre->primoFiglio = n -> fratelloSuccessivo;
			}
			delete n;
			numeroNodi--;
		} else {
			root = nullptr;
			numeroNodi = 0;
		}
	}
}

template<class T>
void AlberoPtr<T>::scriviNodo(nodo n, tipoElem val) {
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else
		n->valore = val;
}

template<class T>
typename AlberoPtr<T>::tipoElem AlberoPtr<T>::leggiNodo(nodo n) const {
	if (alberoVuoto())
		throw std::runtime_error("Albero vuoto");
	else if (n == nullptr)
		throw std::runtime_error("Il nodo passato come parametro non esiste");
	else
		return n->valore;
}

template<class T>
bool AlberoPtr<T>::operator==(const AlberoPtr<T> &a) const {
	if (alberoVuoto() && a.alberoVuoto())
		return true;
	else if (alberoVuoto() || a.alberoVuoto())
		return false;
	else {
		return confrontaNodi(radice(),a.radice());
	}
}

template<class T>
bool AlberoPtr<T>::operator!=(const AlberoPtr<T> &a) const {
	return !(*this == a);
}

template<class T>
AlberoPtr<T> &AlberoPtr<T>::operator=(const AlberoPtr<T> &a) {
	if (this != &a) {
		if (!alberoVuoto()) {
			// Cancello l'albero corrente
			cancellaSottoAlbero(radice());
		}
		root = new Nodo<T>;
		numeroNodi = 0;
		scriviNodo(root, a.leggiNodo(a.radice()));
		if (!a.foglia(a.radice()))
			copiaNodo(root, a.primoFiglio(a.radice()));
		numeroNodi++;
	}
	return *this;
}

template<class T>
void AlberoPtr<T>::stampaSottoAlbero(nodo n) const {
	stampaRicorsiva(n, "");
}

template<class T>
void AlberoPtr<T>::stampaRicorsiva(Nodo<T> *nodo, std::string spazio) const {
	if (nodo != nullptr) {
		std::cout << spazio;
		if (nodo->padre == nullptr) {
			// Se il nodo è la radice
			std::cout << "r:";
			spazio += "    ";
		} else {
			// Se il nodo è un figlio
			std::cout << "--> ";
			spazio += "|   ";
		}
		std::cout << "[" << nodo->valore << "]" << std::endl;

		// Stampa tutti i figli del nodo corrente
		Nodo<T>* figlio = nodo->primoFiglio;
		while (figlio != nullptr) {
			stampaRicorsiva(figlio, spazio);
			figlio = figlio->fratelloSuccessivo;
		}
	}
}
template<class T>
bool AlberoPtr<T>::confrontaNodi(nodo n1, nodo n2) const {
	if (n1 == n2) {
		// I due nodi sono gli stessi
		return true;
	}

	// Confronta i valori dei due nodi
	if (leggiNodo(n1) != leggiNodo(n2)) {
		return false;
	}

	// Confronta i sotto-alberi dei due nodi
	nodo figlio1 = primoFiglio(n1);
	nodo figlio2 = primoFiglio(n2);
	while (figlio1 != nullptr && figlio2 != nullptr) {
		if (!confrontaNodi(figlio1, figlio2)) {
			return false;
		}
		figlio1 = fratelloSuccessivo(figlio1);
		figlio2 = fratelloSuccessivo(figlio2);
	}

	// I due nodi hanno lo stesso numero di figli e i figli sono uguali
	return figlio1 == nullptr && figlio2 == nullptr;
}



#endif //N_TREES_ALBERO_PTR_H
