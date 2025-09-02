#ifndef MFSET_H
#define MFSET_H

#include "Componente.h"
#include "InsiemePtrN.h"
#define MAXCOMPONENTI 20

typedef struct datiComp datiComponente;

struct datiComp{
	bool presente;
	int numNodi;
};

class MFSet{
public:
	MFSet();
	MFSet(InsiemePtrN &);
	~MFSet();
	
	void creaMFSet(InsiemePtrN &);
	Componente trova(tipoelem);
	void fondi(tipoelem, tipoelem);
	
	void stampaMFSet();

private:
	bool trovaElem(tipoelem, nodoN, Componente &);
	int trovaComponente(Componente &);
	void freeMemory(nodoN, Componente &);
	bool antenatoUltimoFratello(nodoN, Componente &, int);
	void stampaComponente(nodoN, Componente &, int);
	
	Componente mfset[MAXCOMPONENTI];
	datiComponente dati[MAXCOMPONENTI];
};

#endif
