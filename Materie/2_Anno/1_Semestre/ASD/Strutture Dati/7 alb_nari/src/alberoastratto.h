#ifndef _ALBEROASTRATTO_H
#define _ALBEROASTRATTO_H


template<class T, class P>
class alberoAstratto{
   public:
	typedef T tipoelem;
	typedef P posizione;
	virtual void creaAlbero() =0;
	virtual bool alberoVuoto() const =0;
	virtual void insRadice(tipoelem) =0;
	virtual posizione radiceAlbero() =0;
	virtual posizione padre(posizione) const =0;
	virtual bool foglia(posizione) const =0;
	virtual posizione primoFiglio(posizione) const =0;
	virtual bool ultimoFratello(posizione) const =0;
	virtual posizione succFratello(posizione) const =0;
	virtual void cancSottoAlbero(posizione&) =0;
};


#endif // _ALBEROASTRATTO_H 
