#ifndef _CODAASTRATTA_H
#define _CODAASTRATTA_H 


template <class T, class P>
class codaAstratta{
   public:
	typedef T tipoelem;
	typedef P posizione;
	virtual void creaCoda() =0;
	virtual bool codaVuota() const =0;
	virtual tipoelem leggiCoda() const =0;
	virtual void fuoriCoda() =0;
	virtual void inCoda(tipoelem) =0;
};


#endif // _CODAASTRATTA_H
