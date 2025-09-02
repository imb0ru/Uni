#ifndef _ALBEROBINASTRATTO_H
#define _ALBEROBINASTRATTO_H


template <class T, class P>
class alberoBinAstratto{
   public:
	typedef T tipoelem;
	typedef P posizione;
	// metodi
	virtual void creaBinAlbero() = 0;
	virtual bool binAlberoVuoto() const = 0;
	virtual posizione binRadice() const = 0;
	virtual posizione figlioSinistro(posizione) const = 0;
	virtual posizione figlioDestro(posizione) const = 0;
	virtual bool sinistroVuoto(posizione) const = 0;
	virtual bool destroVuoto(posizione) const = 0;
	virtual void cancSottoBinAlbero(posizione) = 0;
	virtual tipoelem leggiNodo(posizione) const = 0;
	virtual void scriviNodo(posizione, tipoelem) = 0;
	virtual void insBinRadice(tipoelem) = 0;
	virtual void insFiglioSinistro(posizione, tipoelem) = 0;
	virtual void insFiglioDestro(posizione, tipoelem) = 0;
};


#endif // _ALBEROBINASTRATTO_H 
