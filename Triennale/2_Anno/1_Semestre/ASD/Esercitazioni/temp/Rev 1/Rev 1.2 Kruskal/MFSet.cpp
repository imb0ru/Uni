#include <iostream> 
#include <cstdlib>
#include "MFSet.h"

using namespace std;

MFSet::MFSet(){}

MFSet::MFSet(InsiemePtrN &i){
	creaMFSet(i);
}

MFSet::~MFSet(){
	for(int i = 0; i < MAXCOMPONENTI; i++)
		if(dati[i].presente)
			freeMemory(mfset[i].radice(), mfset[i]);
}

void MFSet::creaMFSet(InsiemePtrN &set){
	posizione p = set.getInsieme();
	int i = 0;
	nodoN n;
	while((p != NULL) && (i < MAXCOMPONENTI)){
		n = new NodoNPtr(p->getEtichetta());
		mfset[i].insRadice(n);
		dati[i].presente = true;
		dati[i].numNodi = 1; // ogni Componente ha un elemento dell'insieme
		p = p->getSuccessivo();
		i++;
	}
	// inizializza a falso tutte le componenti non necessarie
	for(;i < MAXCOMPONENTI; i++){
		dati[i].presente = false;
		dati[i].numNodi = 0;
	}
}

Componente MFSet::trova(tipoelem a){
	int i = -1;
	bool trovata = false;
	while((i < MAXCOMPONENTI) && (!trovata)){
		i++;
		if (dati[i].presente)
			trovata = trovaElem(a,mfset[i].radice(),mfset[i]);
	}
	return mfset[i];
}

void MFSet::fondi(tipoelem a, tipoelem b){
	Componente t, v;
	int dimT, dimV, indT, indV;
	t = trova(a);
	dimT = dati[trovaComponente(t)].numNodi;
	indT = trovaComponente(t);
	v = trova(b);
	dimV = dati[trovaComponente(v)].numNodi;
	indV = trovaComponente(v);
	if(dimT >= dimV){
		nodoN temp = t.primoFiglio(t.radice());
		if (temp != NULL){
			while (!t.ultimoFratello(temp))
				temp = t.succFratello(temp);
			t.insSottoAlbero(temp, v.radice());
		} else
			t.insPrimoSottoAlbero(t.radice(), v.radice());
		v.cancSottoAlbero(v.radice());
		dati[indT].numNodi = dimT + dimV;
		dati[indV].numNodi = 0;
		dati[indV].presente = false;
	} else {
		nodoN temp = v.primoFiglio(v.radice());
		if (temp != NULL){
			while (!v.ultimoFratello(temp))
				temp = v.succFratello(temp);
			v.insSottoAlbero(temp, t.radice());
		} else
			v.insPrimoSottoAlbero(v.radice(), t.radice());
		t.cancSottoAlbero(t.radice());
		dati[indV].numNodi = dimT + dimV;
		dati[indT].numNodi = 0;
		dati[indT].presente = false;
	}	
}

void MFSet::stampaMFSet(){
	int j = 0;
	for (int i = 0; i < MAXCOMPONENTI; i++)
		if (dati[i].presente){
			cout << "Componente " << ++j << ":" << endl;
			stampaComponente(mfset[i].radice(), mfset[i]);
			cout << endl;
		}
	cout << endl;
}	

bool MFSet::trovaElem(tipoelem a, nodoN n, Componente &t){
   if (n != NULL){
   	bool trovato = false;
//   	if (t.leggiNodo(n) != a){
//   		trovato = false;
	   	while (!((n == NULL) || trovato)){
	         if (t.leggiNodo(n) != a){
	         	trovato = trovaElem(a, t.primoFiglio(n), t);
  		         n = t.succFratello(n);
	         } else
	         	trovato = true;
	      }	
//   	} else trovato = true;
      return trovato;
   } else return false;
}

int MFSet::trovaComponente(Componente &t){
	int i = 0;
	while((i < MAXCOMPONENTI)&&(t.radice() != mfset[i].radice()))
		i++;
	if(i < MAXCOMPONENTI)
		return i;
	else
		return -1; // t non corrisponde a nessuna componente esistente
}

void MFSet::freeMemory(nodoN n, Componente &t){
	if ((n != NULL) && (t.radice() != NULL)){
      while (t.primoFiglio(n) != NULL)
         freeMemory(t.primoFiglio(n), t);
      if (t.padre(n) != NULL)
         if (t.primoFiglio(t.padre(n)) == n)
            t.padre(n)->setFirstSon(t.succFratello(n));
         else{
            nodoN m = t.primoFiglio(t.padre(n));
            while (t.succFratello(m) != n)
               m = t.succFratello(m);
            m->setNextBro(t.succFratello(n));
         }
		else t.cancSottoAlbero(t.radice());
      delete n;
	}
}

void MFSet::stampaComponente(nodoN n, Componente &t){
   if (n != NULL){
      while (n != NULL){
         cout << "(" << t.leggiNodo(n);
         stampaComponente(t.primoFiglio(n), t);
         cout << ")";
         n = t.succFratello(n);
      }
	} else cout << "()";
}
