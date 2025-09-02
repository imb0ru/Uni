#ifndef _PRIORICODE_H
#define _PRIORICODE_H

#include "alberoBinArray.h"
#include "priorityQueueException.h"


// DEFINIZIONE
template <class T>
class prioriCoda{
   public:
	typedef T tipoelem;
	// costruttori
	prioriCoda();
	~prioriCoda();
	// metodi
	void creaPrioriCoda();
	void inserisci(tipoelem);
	tipoelem min() const;
	void cancellaMin();
	friend ostream& operator<<(ostream& os, const prioriCoda<T>& c){
		os << c.albero << endl;
		return (os);
	}
   private:
	void salitaElemento(typename alberoBinArray<T>::posizione);
	void discesaElemento();
	void aggiornaUltimaPos();
	typename alberoBinArray<T>::posizione ultimaFoglia();
	alberoBinArray<T> albero;
	typename alberoBinArray<T>::posizione ultimaPos; // ultima posizione che non ha entrambi i figli
	tipoelem valoreMassimo; // valore senza senso in un albero vuoto
};


// IMPLEMENTAZIONE
template <class T>
prioriCoda<T>::prioriCoda(){
	this->creaPrioriCoda();
}


template <class T>
prioriCoda<T>::~prioriCoda() { };


template <class T>
void prioriCoda<T>::creaPrioriCoda(){	
	return;
}


template <class T>
void prioriCoda<T>::inserisci(typename prioriCoda<T>::tipoelem e){
	if (albero.binAlberoVuoto()){
		albero.insBinRadice(e);
		ultimaPos = albero.binRadice();
		valoreMassimo = e;
	}
	else{
		if (!albero.valorePresente(e)){
			if (albero.sinistroVuoto(ultimaPos)){
				albero.insFiglioSinistro(ultimaPos, e);
				this->salitaElemento(albero.figlioSinistro(ultimaPos));
			}
			else{
				albero.insFiglioDestro(ultimaPos, e);
				this->salitaElemento(albero.figlioDestro(ultimaPos));
				this->aggiornaUltimaPos();
			}
		}
		if (e > valoreMassimo){
			valoreMassimo = e;
		}
	}
}


template <class T>
typename prioriCoda<T>::tipoelem prioriCoda<T>::min() const {
    if (!albero.binAlberoVuoto()) {
        return albero.leggiNodo(albero.binRadice());
    } else {
        throw emptyPriorityQueueException();
    }
}


template <class T>
void prioriCoda<T>::cancellaMin() {
    if (!albero.binAlberoVuoto()) {
        tipoelem minimo = min();  // Ottieni l'elemento minimo
        typename alberoBinArray<T>::posizione posizioneMinimo = albero.ricercaElemento(minimo);

        if (albero.sinistroVuoto(ultimaPos)) {
            tipoelem valoreUltimaPos = albero.getValore(ultimaPos);
            if (valoreUltimaPos == minimo) {
                albero.cancSottoBinAlbero(ultimaPos);
            } else {
                albero.scriviNodo(posizioneMinimo, valoreUltimaPos);
                albero.cancSottoBinAlbero(ultimaPos);
                salitaElemento(posizioneMinimo);
            }
        } else {
            tipoelem valoreSinistro = albero.getValore(albero.figlioSinistro(ultimaPos));
            albero.scriviNodo(posizioneMinimo, valoreSinistro);
            albero.cancSottoBinAlbero(albero.figlioSinistro(ultimaPos));
            salitaElemento(posizioneMinimo);
            aggiornaUltimaPos();
        }
        return;
    } else {
        throw emptyPriorityQueueException();
    }
}



// funzioni private
template <class T>
void prioriCoda<T>::salitaElemento(typename alberoBinArray<T>::posizione p){
	typename prioriCoda<T>::tipoelem temp = albero.getValore(p);
	while ((p != albero.binRadice()) && (temp < albero.getValore(albero.getPadre(p)))){
		albero.scriviNodo(p, albero.getValore(albero.getPadre(p)));
		albero.scriviNodo(albero.getPadre(p), temp);
		p = albero.getPadre(p);
	}
	return;
}


template <class T>
void prioriCoda<T>::discesaElemento(){
	typename alberoBinArray<T>::posizione p = albero.binRadice();
	typename prioriCoda<T>::tipoelem e = albero.getValore(albero.binRadice());
	while ((!albero.sinistroVuoto(p)) && (e > albero.getValore(albero.figlioSinistro(p)))){
		albero.scriviNodo(p, albero.getValore(albero.figlioSinistro(p)));
		albero.scriviNodo(albero.figlioSinistro(p), e);
		p = albero.figlioSinistro(p);
	}
	return;
}


template <class T>
void prioriCoda<T>::aggiornaUltimaPos(){
	if ((!albero.sinistroVuoto(ultimaPos)) && (!albero.destroVuoto(ultimaPos))){
		if ((ultimaPos != albero.binRadice()) && (albero.destroVuoto(albero.getPadre(ultimaPos)))){
			ultimaPos = albero.getFratello(ultimaPos);
		}
		else {
			while ((ultimaPos != albero.binRadice()) && (ultimaPos == albero.figlioDestro(albero.getPadre(ultimaPos)))){
				ultimaPos = albero.getPadre(ultimaPos);
			}
			if (ultimaPos != albero.binRadice()){
				ultimaPos = albero.getFratello(ultimaPos);
			}
			while (!albero.sinistroVuoto(ultimaPos)){
				ultimaPos = albero.figlioSinistro(ultimaPos);
			}
		}
	}
	return;
}


#endif // _PRIORICODE_H 
