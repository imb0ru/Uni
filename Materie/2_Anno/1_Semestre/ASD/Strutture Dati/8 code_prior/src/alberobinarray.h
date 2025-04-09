#ifndef _ALBEROBINARRAY_H 
#define _ALBEROBINARRAY_H

#include "alberoBinAstratto.h"
#include "treeException.h"

using namespace std;


// DEFINIZIONE
template <class T>
class alberoBinArray : public alberoBinAstratto<T, int>{
   public:
	typedef typename alberoBinAstratto<T, int>::tipoelem tipoelem;
	typedef typename alberoBinAstratto<T, int>::posizione posizione;
	struct cella{
		posizione padre;
		posizione sinistro;
		posizione destro;
		bool vuoto;
		tipoelem valore;
	};
	// costruttori
	alberoBinArray();
	alberoBinArray(int);
	~alberoBinArray(); // distruttore
	// metodi
	void creaBinAlbero();
	bool binAlberoVuoto() const;
	posizione binRadice() const;
	posizione figlioSinistro(posizione) const;
	posizione figlioDestro(posizione) const;
	bool sinistroVuoto(posizione) const;
	bool destroVuoto(posizione) const;
	void costrBinAlbero(alberoBinArray<T>, tipoelem);
	void cancSottoBinAlbero(posizione);
	tipoelem leggiNodo(posizione) const;
	void scriviNodo(posizione, tipoelem);
	void insBinRadice(tipoelem);
	void insFiglioSinistro(posizione, tipoelem);
	void insFiglioDestro(posizione, tipoelem);
	// funzioni di servizio
	tipoelem getValore(posizione) const;
	posizione getPadre(posizione) const;
	posizione getFratello(posizione) const;
	bool valorePresente(tipoelem) const;
	posizione ricercaElemento(tipoelem) const;
	// sovraccarico operatori
	friend ostream& operator<<(ostream& os, const  alberoBinArray<T>& a){
		if (!a.binAlberoVuoto()){
			cout << endl << endl;
			for (int i=0; i<a.dimensioneArray; i++){
				if (a.array[i].vuoto != true){
					os << "NODO IN POSIZIONE " << i << ":" << endl;
					os << "VALORE: " << a.array[i].valore << endl;
					if (a.array[i].padre != NIL)
						os << "Il padre di questo nodo e': " << "nodo in pos [" << a.array[i].padre << "]" << endl;
					else
						os << "Questo nodo è la radice" << endl;
					if (a.array[i].sinistro != NIL)
						os << "Il figlio sinistro di questo nodo e': " << "nodo in pos [" << a.array[i].sinistro << "]" << endl;	
					else 
						os << "Questo nodo non ha figlio sinistro." << endl;
					if (a.array[i].destro != NIL)
						os << "Il figlio destro di questo nodo e': " << "nodo in pos [" << a.array[i].destro << "]" << endl;
					else
						os << "Questo nodo non ha figlio destro." << endl;
					cout << endl << endl;						
				}
			}
			cout << "FINE ALBERO" << endl;  
		}
		else{
			os << "L'albero è vuoto!";
		}
		return (os);
	};
   private:
	posizione trovaValore(posizione, tipoelem) const;
	void aggiornaLibero();
	int ultimaPos();	
	void cambiaDimensioneArray (cella*&, int, int);
	cella* array;
	int dimensioneArray;
	int nElementi;
	posizione radice;
	posizione libero;
	static const int NIL = -1;

};


// IMPLEMENTAZIONE
// costruttori
template <class T>
alberoBinArray<T>::alberoBinArray(){
	this->dimensioneArray = 20;
	this->array = new cella [this->dimensioneArray];
	this->creaBinAlbero();
}


template <class T>
alberoBinArray<T>::alberoBinArray(int dim){
	if (dim > 3){
		this->dimensioneArray = dim;
		this->array = new cella [this->dimensioneArray];
		this->creaBinAlbero();
	}
	else{
		throw invalidDimensionException();
	}
}


template <class T>
alberoBinArray<T>::~alberoBinArray(){
	delete [] array;
}


// metodi
template <class T>
void alberoBinArray<T>::creaBinAlbero(){
	this->radice = NIL;
	this->libero = 0;
	this->nElementi = 0;
	for (int i = 0; i < this->dimensioneArray; i++)
		this->array[i].vuoto = true;
	return;
}


template <class T>
bool alberoBinArray<T>::binAlberoVuoto() const{
	return (this->nElementi == 0);
}


template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::binRadice() const{
	return (this->radice);
};


template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::figlioSinistro(typename alberoBinArray<T>::posizione p) const{
	if (!this->sinistroVuoto(p))
		return (this->array[p].sinistro);
	else
		return NIL;
}


template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::figlioDestro(typename alberoBinArray<T>::posizione p) const{
	if (!this->destroVuoto(p))
		return (this->array[p].destro);
	else
		return NIL;
}


template <class T>
bool alberoBinArray<T>::sinistroVuoto(typename alberoBinArray<T>::posizione p) const{
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false))
		return (this->array[p].sinistro == NIL);
	else
		throw invalidDimensionException();
}


template <class T>
bool alberoBinArray<T>::destroVuoto(typename alberoBinArray<T>::posizione p) const{
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false))
		return (this->array[p].destro == NIL);
	else
		throw invalidDimensionException();
}


template <class T>
void alberoBinArray<T>::costrBinAlbero(alberoBinArray<T> a, typename alberoBinArray<T>::tipoelem valoreRadice){
	this->array[this->libero].valore = valoreRadice; // setta il valore della nuova radice
	this->array[this->libero].padre = NIL; // setta il valore del padre della nuova radice a NIL poichè è una radice
	this->array[this->libero].vuoto = false; // assume che la cella adesso è piena
	if(!this->binAlberoVuoto()){ 
		this->array[this->libero].sinistro = this->radice; // setta il figlio sinistro della nuova radice
		this->array[this->radice].padre = this->libero; // setta il padre della vecchia radice
	}
	else{
		this->array[this->libero].sinistro = NIL;
	}
	this->radice = this->libero; // aggiorna il valore della radice
	this->libero = this->ultimaPos();
	this->nElementi ++;
	if (!a.binAlberoVuoto()){
		int dimThisArray = this->libero; // valore utile per l'aggiornamento dei valori delle nuove celle
		a.array[a.radice].padre = this->radice - dimThisArray; // setta la parentela con la nuova radice (-dimThisArray poichè è un valore che verrà aggiunto nel ciclo)
		for (int i=0; i < a.nElementi; i++){ // copia l'albero a alla fine di this->array
			this->array[this->libero] = a.array[i]; // copia la cella nella prima posizione libera di this->array
			this->array[this->libero].vuoto = false; // assume che la cella adesso è piena
			this->array[this->libero].padre += dimThisArray; // aggiorna i valori della nuova cella
			if (this->array[this->libero].sinistro != NIL)
				this->array[this->libero].sinistro += dimThisArray;
			if (this->array[this->libero].destro != NIL)
				this->array[this->libero].destro += dimThisArray;
			this->libero++;
			if (this->libero == this->dimensioneArray){
				cambiaDimensioneArray (this->array, dimensioneArray, dimensioneArray*2);
				dimensioneArray *= 2;
				this->libero = this->nElementi;
			}
			this->nElementi++;
		}
		this->array[this->radice].destro = a.radice+dimThisArray; // setta il figlio destro della nuova radice
	}
	else{
		this->array[this->radice].destro = NIL;
	}
	return;
}


template <class T>
void alberoBinArray<T>::cancSottoBinAlbero(typename alberoBinArray<T>::posizione p) {
    if ((p >= 0) && (p < dimensioneArray) && (!binAlberoVuoto()) && (!array[p].vuoto)) {
        if (!sinistroVuoto(p)) {
            cancSottoBinAlbero(array[p].sinistro);
        }
        if (!destroVuoto(p)) {
            cancSottoBinAlbero(array[p].destro);
        }
        array[p].vuoto = true;
        if (p != radice) {
            posizione genitore = array[p].padre;
            if (array[genitore].sinistro == p) {
                array[genitore].sinistro = NIL;
            } else {
                array[genitore].destro = NIL;
            }
        } else {
            radice = NIL;
        }
        nElementi--;
        libero = p;
    }
    return;
}


template <class T>
typename alberoBinArray<T>::tipoelem alberoBinArray<T>::leggiNodo(typename alberoBinArray<T>::posizione p) const{
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false))
		return (this->array[p].valore);
	else
		throw invalidPositionException();
}


template <class T>
void alberoBinArray<T>::scriviNodo(typename alberoBinArray<T>::posizione p, typename alberoBinArray<T>::tipoelem e){
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false))
		this->array[p].valore = e;
	else
		throw invalidPositionException();
	return;
}


template <class T>
void alberoBinArray<T>::insBinRadice(typename alberoBinArray<T>::tipoelem e){
	if(this->radice == NIL){
		this->radice = this->libero;
		this->array[this->radice].vuoto = false;
		this->array[this->radice].padre = NIL;
		this->array[this->radice].destro = NIL;
		this->array[this->radice].sinistro = NIL;
		this->array[this->radice].valore = e;
		this->nElementi++;
		this->aggiornaLibero();
	}
	else{
		throw notEmptyTreeException();
	}
	return;
}


template <class T>
void alberoBinArray<T>::insFiglioSinistro(typename alberoBinArray<T>::posizione p, typename alberoBinArray<T>::tipoelem e){
	if (	(p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false) && (this->sinistroVuoto(p))){
		this->array[p].sinistro = this->libero;
		this->array[this->libero].valore = e;
		this->array[this->libero].padre = p;
		this->array[this->libero].destro = NIL;
		this->array[this->libero].sinistro = NIL;
		this->array[this->libero].vuoto = false;
		this->nElementi++;
		this->aggiornaLibero();
	}
	else{
		throw invalidPositionException();
	}
	return;
}


template <class T>
void alberoBinArray<T>::insFiglioDestro(typename alberoBinArray<T>::posizione p, typename alberoBinArray<T>::tipoelem e){
	if (	(p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false) && (this->destroVuoto(p))){
		this->array[p].destro = this->libero;
		this->array[this->libero].valore = e;
		this->array[this->libero].padre = p;
		this->array[this->libero].destro = NIL;
		this->array[this->libero].sinistro = NIL;
		this->array[this->libero].vuoto = false;
		this->nElementi++;
		this->aggiornaLibero();
	}
	else{
		throw invalidPositionException();
	}
	return;
}


// funzioni di servizio
template <class T>
typename alberoBinArray<T>::tipoelem alberoBinArray<T>::getValore(typename alberoBinArray<T>::posizione p) const{
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false))
		return (this->array[p].valore);
	else
	 throw invalidPositionException();
}


template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::getPadre(typename alberoBinArray<T>::posizione p) const{
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false) && (p != this->radice))
		return (this->array[p].padre);
	else
		throw invalidPositionException();
}


template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::getFratello(typename alberoBinArray<T>::posizione p) const{
	if ((p >= 0) && (p < dimensioneArray) && (this->array[p].vuoto == false) && (p != this->radice)){
		if ((!this->sinistroVuoto(this->getPadre(p))) && (!this->destroVuoto(this->getPadre(p)))){
			if (this->figlioSinistro(this->getPadre(p)) == p){
				return (this->figlioDestro(this->getPadre(p)));
			}
			else{
				return (this->figlioSinistro(this->getPadre(p)));
			}
		}
		else{
			return p;
		}
	}
	else{	
		throw invalidPositionException();
	}
}


template <class T>
bool alberoBinArray<T>::valorePresente(typename alberoBinArray<T>::tipoelem e) const{
	if (!binAlberoVuoto()){
		if (trovaValore(binRadice(), e) != NIL)
			return true;
		else
			return false;
	}
	else{
		return false;
	}
}


template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::ricercaElemento(typename alberoBinArray<T>::tipoelem e) const{
	if (!binAlberoVuoto())
		return (trovaValore(binRadice(), e)); 
	else
		return NIL;
}



// funzioni private
template <class T>
typename alberoBinArray<T>::posizione alberoBinArray<T>::trovaValore(typename alberoBinArray<T>::posizione p, typename alberoBinArray<T>::tipoelem e) const{
	if (getValore(p) == e){
		return p;
	}
	else{
		typename alberoBinArray<T>::posizione pos;
		if (!sinistroVuoto(p)){
			pos = trovaValore(figlioSinistro(p), e);
			if(pos != NIL)
				return pos;
		}
		if (!destroVuoto(p)){
			pos = trovaValore(figlioDestro(p), e);
			if (pos != NIL)
				return pos;
		}
	}
	return NIL;
}


template <class T>
void alberoBinArray<T>::aggiornaLibero(){
	bool trovato = false;
	for(int i=0; (i < this->dimensioneArray) && (trovato == false); i++){
		if (this->array[i].vuoto == true){
			this->libero = i;
			trovato = true;
		}
	}
	if (trovato == false){
		cambiaDimensioneArray (this->array, dimensioneArray, dimensioneArray*2);
		dimensioneArray *= 2;
		this->libero = this->nElementi;
	}
	return;
}


template <class T>
int alberoBinArray<T>::ultimaPos(){
	int pos;
	for(int i=0; i<this->dimensioneArray; i++){
		if (this->array[i].vuoto == false)
			pos = i;
	}
	pos++;
	if (pos == this->dimensioneArray){
		cambiaDimensioneArray (this->array, this->dimensioneArray, this->dimensioneArray*2);
		dimensioneArray *= 2;
		this->libero = this->nElementi;
	}
	return pos;
}


template <class T>
void alberoBinArray<T>::cambiaDimensioneArray (cella*& c, int vecchiaDim, int nuovaDim){
	cella* temp = new cella [nuovaDim];
	int n;
	if (vecchiaDim < nuovaDim) 
	     n = vecchiaDim;
	else
     	n = nuovaDim;
	for (int i=0; i<n; i++)
	     temp[i] = c[i];
	delete [] c;
	c = temp;
	return;
}


#endif // _ALBEROBINARRAY_H
