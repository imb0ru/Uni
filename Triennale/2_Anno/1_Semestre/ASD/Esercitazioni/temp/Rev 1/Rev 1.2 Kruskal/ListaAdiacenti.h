/*
  Nome: ListaAdiacenti.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la lista di adiacenza dei nodi
*/

#ifndef LISTAADIACENTI_H
#define LISTAADIACENTI_H

#define NIL -1

typedef struct NodoAdiacenti *posizionelista;
typedef struct tipo tipolista;
typedef int NodoLista;

struct NodoAdiacenti{
	NodoLista etichetta;
	posizionelista successivo;
};

class ListaAdiacenti{
public:
	ListaAdiacenti();
	~ListaAdiacenti();
	
	void creaLista();
   bool listaVuota();
   posizionelista primoLista();
   	
   posizionelista predLista(posizionelista);
   posizionelista succLista(posizionelista);
   bool fineLista(posizionelista);
   
   void insLista(NodoLista, posizionelista);
   bool cancLista(posizionelista);
   bool scriviLista(NodoLista, posizionelista);
   bool leggiLista(NodoLista &, posizionelista);
   
	ListaAdiacenti &operator=(ListaAdiacenti &);
   posizionelista pos(int); // mapping della posizionelista

private:
   posizionelista primo;
};

#endif // LISTAADIACENTI_H
