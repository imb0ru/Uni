#include "listavettore.h";

// costruttori
template <class T>
listaVettore<T>::listaVettore (){
	dimensione_vettore = 5;
	creaLista ();
}


template <class T>
listaVettore<T>::listaVettore (int dim){
	dimensione_vettore = dim;
	creaLista ();
}


template <class T>
listaVettore<T>::listaVettore (const listaVettore<T>& l){
	this->lunghezza = l.lunghezza;
	this->dimensione_vettore = l.dimensione_vettore;
	this->vettore = new T[dimensione_vettore];
	for (int i=0; i<lunghezza; i++)
		this->vettore[i] = l.vettore[i];
}


template <class T>
listaVettore<T>::~listaVettore (){
	delete[] vettore;
}


// operatori
template <class T>
void listaVettore<T>::creaLista (){
	this->vettore = new T[dimensione_vettore];
	this->lunghezza = 0;
}


template <class T>
bool listaVettore<T>::listaVuota () const{
	return (lunghezza == 0);
}


template <class T>
typename listaVettore<T>::tipoelem listaVettore<T>::leggiLista (typename listaVettore<T>::posizione p) const{
	if ((p > 0) && (p < lunghezza+1))
		return (this->vettore[p-1]);
	else
		throw indexOutOfRangeListException();
}


template <class T>
void listaVettore<T>::scriviLista (typename listaVettore<T>::tipoelem e, typename listaVettore<T>::posizione p){
	if ((p > 0) && (p < lunghezza+1))
		this->vettore[p-1] = e;
}


template <class T>
typename listaVettore<T>::posizione listaVettore<T>::primoLista () const{
	return 1;
}


template <class T>
typename listaVettore<T>::posizione listaVettore<T>::ultimoLista () const{
	if (!listaVuota())
		return lunghezza;  // restituisce l'indice dell'ultimo elemento
	else
		throw emptyListException();
}


template <class T>
bool listaVettore<T>::fineLista (typename listaVettore<T>::posizione p) const{
	if ((p > 0) && (p <= lunghezza+1))
		return (p == lunghezza);
	else
		throw indexOutOfRangeListException();
}


template <class T>
typename listaVettore<T>::posizione listaVettore<T>::succLista (typename listaVettore<T>::posizione p) const{
	if ((p > 0) && (p < lunghezza+1))
		return (p+1);
	else
		throw indexOutOfRangeListException();
}


template <class T>
typename listaVettore<T>::posizione listaVettore<T>::predLista (typename listaVettore<T>::posizione p) const {
	if ((p > 1) && (p < lunghezza+1))
		return (p-1);
	else
		throw indexOutOfRangeListException();
}


template <class T>
void listaVettore<T>::insLista (typename listaVettore<T>::tipoelem e, typename listaVettore<T>::posizione p){
	if (lunghezza == dimensione_vettore){
		cambia_dimensione (vettore, dimensione_vettore, dimensione_vettore*2);
		dimensione_vettore = dimensione_vettore*2;
	}
	if ((p > 0) && (p <= lunghezza+1)){
		for (int i=lunghezza; i >= p; i--)
			vettore [i] = vettore [i-1];
		vettore [p-1] = e;
		lunghezza ++;
	}
	else
		throw indexOutOfRangeListException();
}


template <class T>
void listaVettore<T>::cancLista (typename listaVettore<T>::posizione p){
	if ((p > 0) && (p < lunghezza+1)){
		if (!listaVuota()){
			for (int i=p-1; i < lunghezza; i++)
				vettore[i] = vettore [i+1];
			lunghezza --;
		}
	}
	else
		throw indexOutOfRangeListException();
}


// funzioni private
template <class T>
void listaVettore<T>::cambia_dimensione(T*& l, int vecchia_dim, int nuova_dim) {
    T* temp = new T[nuova_dim];
    int n = (vecchia_dim < nuova_dim) ? vecchia_dim : nuova_dim;

    for (int i = 0; i < n; i++)
        temp[i] = l[i];

    delete[] l;  // Deallocazione corretta dell'array vecchio
    l = temp;
}

