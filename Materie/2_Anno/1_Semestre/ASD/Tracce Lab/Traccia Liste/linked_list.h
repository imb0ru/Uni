/***************************************************************************
 *   Copyright (C) 2016 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"

//Definisco che la classe è di tipo template
template<class T>
class Linked_list;

/*definizione di un nodo che può accedere a tutte le variabili privatedi Linked List*/
template<class T>
class List_node{
	friend class Linked_list<T>;
	//Linked List può accedere a tutte le private di ListNode
 private:
	T _value;
	List_node<T> * _pPrev; //puntatore dello stesso tipo di oggetto --> T*
	List_node<T> * _pNext;
};

//definizione della classe lista con metodi e proprietà
template< class T >
//I : singoli indicano una ereditarietà tra due classi (Linear e Linked)
class Linked_list : public Linear_list<T, List_node<T>*>{
 public:
        /*con typedef definiamo un nuovo tipo e, con la specifica typename
        andiamo a dire al compilatore che il nome che abbiamo definito, non e'
        un oggetto della classe Linear_List, bensì un tipo.
        Per cui value_type è un tipo di dato dello stesso tipo di Linear_list<T, List_node<T>*>::value_type*/
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_node<T>*>::position position;

	// costruttori
	Linked_list();
	Linked_list(int);
	// costruttore per copia
	Linked_list(const Linked_list<T>& );
	//distruttore
	~Linked_list();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const; //testa
	position last() const; //coda
	bool end(position) const; //is end
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);
	int size() const {
		return _length;
	};

	// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
	bool operator==(const Linked_list<T> &) const; // tests two list for equality

 private:
	List_node<T> * _pHead; //testa della lista - sentinella
	int _length; // the length of the list
};

//costruttore 1 (sentinella)
template< class T >
Linked_list< T >::Linked_list() {
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}

//distruttore
template< class T >
Linked_list< T >::~Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
}

//costruttore di copia
//input: reference da copiare
template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) {
    _length = L.size();
    
    //setta sentinella nuova lista
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

    //inserisce sempre in testa
	if (!L.empty()){
		position p = L.last();
		for (int i=0; i < L._length; i++){
            //inserisce nella posizione che vuoi (begin()) per mantere l'ordine originale
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}

//creazione lista - utilità discutibile
template< class T >
void Linked_list< T >::create(){
	if (empty())
		_length = 0;
}

//verifica se la lista è vuota (se testa = testa - sentinella.next=sentinella)
template< class T >
bool Linked_list< T >::empty() const {
	return(_pHead == _pHead->_pNext);
}
//const --> per non modificare il risultato
//ritorna la testa della coda
template< class T > 
typename Linked_list< T >::position Linked_list< T >::begin() const {
	return (_pHead->_pNext);
}

//ritorna la coda della coda
template< class T >
typename Linked_list< T >::position Linked_list< T >::last() const {
	return (_pHead->_pPrev);
}

//elemento successivo all'attuale
template< class T > typename Linked_list< T >::position
Linked_list< T >::next(position p) const {
	return(p->_pNext);
}

//elemento precedente all'attuale, ma devi vedere se non sei già in testa
//sistemare il ritorno in caso di p==_phead
template< class T > 
typename Linked_list< T >::position 
Linked_list< T >::previous(position p) const {
	if (p != _pHead)
		return(p->_pPrev);
}
/*fine lista --> torna vero se il nodo attuale è uguale alla sentinella 
(gli passo p.next, ovviamente)*/
template< class T > 
bool Linked_list< T >::end(position p) const {
	return(p == _pHead);
}

//se non sono all'ultimo elemento (sentinella) - ritorna il valore dell'elemento attuale
template< class T >
typename Linked_list< T >::value_type
Linked_list< T >::read(position p) const {
	if (!end(p))
		return(p->_value);
}

/*se non sono all'ultimo elemento (sentinella) - assegna all'elemento attuale, il valore a
NON aggiunge un nuovo elemento alla lista*/
template< class T >
void Linked_list< T >::write(const value_type &a, position p) {
	if (!end(p))
        p->_value = a;
}

/*Inserisci un nuovo elemento A nella posizione P*/
template< class T >
void Linked_list< T >::insert(const value_type &a, position p){
	position t = new List_node<T>; //alloca un nuovo nodo
	t->_value = a; //setta il valore
    /*/metto l'elemento nella posizione P, per cui, l'elemento che era nella posizione P
     va nella posizione p+1 e diventa l'elemento t.next*/
	t->_pNext = p; 
	t->_pPrev = p->_pPrev; //sistemo le referenze
	p->_pPrev->_pNext = t;
	p->_pPrev = t;
    //incremento la size
	_length++;
}

//Cancella un nodo e sistema le referenze
//TESTARE LUNGHEZZA
template< class T >
void Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
		_length--;
	}
}

//Overloading dell'operatore =
template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
	if (this != &L){ //se la lista attuale è diversa da quella che gli passo
		//_length = L.size();
        //aggiorno la nuova dimensione e creo una nuova lista che punta alla sentinella
		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;
        //stampa se è vuota e la dimensione
        /*
		cout << L.empty();
        cout << L.size();
		*/
		if (!L.empty()){
            //se L non vuota, copio la lista L nella lista che ho creato, dall'ultimo al primo (vedi costruttore copia)
            position p = L.last(); 
			for (int i=0; i < L.size(); i++){
				//cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this; //ritorna la nuova lista creata
}

//overloading operatore di confronto
template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
    //Se le liste hanno size diverse, allora esci
	if (L.size() != _length)
		return false;
	//teste due liste
	position p, pL;
	p = begin();
	pL = L.begin();
	//fin quando non finisce una lista (p o PL uguale)
	while (!end(p)){
		if (p->_value != pL->_value) //se i valori del nodo attuale sono diversi, RIP
			return false;
		//aggiorna i puntatori dei nodi
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}


#endif // _LINKED_LIST_H
