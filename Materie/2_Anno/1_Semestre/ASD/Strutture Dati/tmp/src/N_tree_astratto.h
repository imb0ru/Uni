#ifndef N_TREES_ALBERO_H
#define N_TREES_ALBERO_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T, class N>
class Albero {
public:
	typedef T tipoElem;
	typedef N nodo;

	//virtual void crea()=0; SOSTITUITO DAL COSTRUTTORE
	virtual bool alberoVuoto() const = 0;
	virtual nodo radice() const = 0;
	virtual nodo padre(nodo) const = 0;
	virtual bool foglia(nodo) const = 0;
	virtual nodo primoFiglio(nodo) const = 0;
	virtual bool ultimoFratello(nodo) const = 0;
	virtual nodo fratelloSuccessivo(nodo) const = 0;
	virtual void inserisciRadice(tipoElem) = 0;
	virtual void cancellaSottoAlbero(nodo) = 0;
	virtual int ottieniNumeroNodi() const = 0;
	virtual void scriviNodo(nodo, tipoElem) = 0;
	virtual tipoElem leggiNodo(nodo) const = 0;
	int profonditaAlbero();
	int larghezzaAlbero();

};


template <class I,class N>
int Albero<I, N>::larghezzaAlbero() {
	if (!alberoVuoto()) {
		vector<int> v;
		larghezza(radice(),v,0);
		return *max_element(v.begin(),v.end());
	}
	else return 0;
}


#endif //N_TREES_ALBERO_H
