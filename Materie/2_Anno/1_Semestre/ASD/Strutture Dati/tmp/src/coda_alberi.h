
/*
 * coda_alberi.h
 *
 *  Created on: 12 gen
 *      Author: michele
 */

#ifndef CODA_ALBERI_H_
#define CODA_ALBERI_H_
#include "coda_alberi_astratta.h"


template<class I>
class coda;

template<class I>
class List_node{
	friend class coda<I>;
public:
	List_node();
	void setValue(I &a);
	I getValue();
	void SetNext(List_node<I> * pos);
	List_node<I>*getNext(List_node<I> * pos);
private:
	I _value;
	List_node<I> * _pNext;
};

template <class I>
List_node<I>::List_node() {
	_value=I(NULL);
	_pNext=nullptr;
}

template <class I>
void List_node<I>::setValue(I &a) {
	_value=a;
}
template <class I>
I List_node<I>::getValue() {
	return _value;
}

template <class I>
void List_node<I>::SetNext(List_node<I> *pos) {
	_pNext=pos;
}
template <class I>
List_node<I> * List_node<I>::getNext(List_node<I> *pos) {
	return pos->_pNext;
}

template <class I>
class coda: public coda_astratta<I,List_node<I>*> {
public:

	coda();
	coda(const coda<I>&c);
	~coda();
	void create();
	void crea_coda();
	bool coda_vuota();
	void incoda(const I &a);
	bool end(List_node<I> * p);
	I leggielem(List_node<I> * p);
	I LeggiCoda() const ;
	I fuoricoda();
	int SommaValori();
	int size();
	List_node<I> * avanticoda(List_node<I> * p);
	List_node<I> * getTesta()const;
private:
	int lenght;
	List_node<I> *Testa;
	List_node<I> *Coda;
};

template <class I>
List_node<I> * coda<I>::avanticoda(List_node<I> * p) {
	return p->_pNext;
}
template <class I>
List_node<I> * coda<I>::getTesta()const {
	return Testa;
}

template<class I>
int coda<I>::size() {
	return lenght;
}
template<class I>
int coda<I>::SommaValori() {
	I elemento;
	int somma=0;
	if(coda_vuota()){
		return 0;
	}else {
		List_node<I> *pos;
		pos=Testa;
		while(pos!=nullptr) {
			elemento=leggielem(pos);
			somma+=elemento->getValore();
			pos=pos->_pNext;
		}
		return somma;
	}
}

template <class I>
I coda<I>::LeggiCoda() const {
	return(Testa->_value);
}

template <class I>
I coda<I>::leggielem(List_node<I> * p) {
	return(p->_value);
}

template <class I>
void coda<I>::create(){
	lenght=0;
	Testa=nullptr;
	Coda=nullptr;
}

template <class I>
void coda<I>::crea_coda() {
	lenght=0;
	Testa=nullptr;
	Coda=nullptr;
}

template<class I>
coda<I>::~coda() {
	delete Testa;
	delete Coda;
}
template<class I>
coda<I>::coda() {
	lenght=0;
	Testa=nullptr;
	Coda=nullptr;
}
template<class I>
coda<I>::coda(const coda<I> &altracoda) {
	Testa=nullptr;
	Coda=nullptr;
	lenght=0;
	List_node<I>* p=altracoda.getTesta();
	while(p!=nullptr) {
		I a=altracoda.LeggiCoda();
		incoda(a);
		p=p->getNext(p);
	}
}

template<class I>
bool coda<I>::end(List_node<I> * p) {
	return(p==Coda->_pNext);
}
template<class I>
bool coda<I>::coda_vuota() {
	if(Testa==nullptr) {
		return true;
	}else {
		return false;
	}
}

template<class I>
I coda<I>::fuoricoda() {
	if(!coda_vuota()) {
		List_node<I>* node=Testa;
		I valore=Testa->_value;
		Testa=Testa->_pNext;
		delete node;
		lenght--;
		if(Testa==nullptr) {
			Coda=nullptr;
		}
		return(valore);
	}else {
		throw std::runtime_error("La coda è vuota");
	}
}

template<class I>
void coda<I>::incoda(const I &a) {
	List_node<I> *nuovonodo= new List_node<I>;
	if(coda_vuota()) {
		Testa=nuovonodo;
		Testa->_value=a;
		Coda=Testa;
	}else {
		nuovonodo->_value=a;
		Coda->_pNext=nuovonodo;
		Coda=nuovonodo;
	}
	lenght++;
}

template< class I, class P >
ostream& operator<<(ostream& os,  coda_astratta<I,P> &l){
	List_node<I> *p;
	p = l.getTesta();
	os << "[";
	while (p!=nullptr){
		os << l.leggicoda(p) << " ";
		p=l.avanticoda(p);
	}
	os << "]" << endl;
	return os;

}


#endif /* CODA_ALBERI_H_ */
