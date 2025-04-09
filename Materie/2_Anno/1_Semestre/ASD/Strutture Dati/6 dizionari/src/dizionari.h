#ifndef _DIZIONARI_H
#define _DIZIONARI_H

#include "bucket.h"


// CLASSE ASTRATTA DIZIONARIO
template <class K, class V>
class dizionario{
   public:  
	typedef K chiave;
	typedef V valore;
	// metodi
	virtual void creaDizionario() = 0;		
	virtual bool dizionarioVuoto() const = 0;
	virtual bool appartiene(const chiave&) const = 0;
	virtual void inserisci(const chiave&, const valore&) = 0;	
	virtual void cancella(const chiave&) = 0;	
	virtual bucket<K, V>* recupera(const chiave&) const = 0;	
	// funzioni di servizio		
	virtual void aggiornaValore(const chiave&, const valore&) = 0;
	//virtual int dimensioneDizionario() const = 0;	
};


#endif // _DIZIONARI_H 
