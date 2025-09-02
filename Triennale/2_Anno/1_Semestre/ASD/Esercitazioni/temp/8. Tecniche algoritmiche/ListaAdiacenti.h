#ifndef LISTAADIACENTI_H
#define LISTAADIACENTI_H

#define NIL -1

typedef struct NodoAdiacenti *posizione;
typedef struct tipo tipoelem;
typedef int Nodo;
typedef int tipoPeso;

struct tipo{
	Nodo nodoCur;
	tipoPeso peso;
};

struct NodoAdiacenti{
	tipoelem etichetta;
	posizione successivo;
};

class ListaAdiacenti{
public:
	ListaAdiacenti();
	~ListaAdiacenti();
	
	void creaLista();
   bool listaVuota();
   posizione primoLista();
   	
   posizione predLista(posizione);
   posizione succLista(posizione);
   bool fineLista(posizione);
   
   void insLista(tipoelem, posizione);
   bool cancLista(posizione);
   bool scriviLista(tipoelem, posizione);
   bool leggiLista(tipoelem &, posizione);
   
	ListaAdiacenti &operator=(ListaAdiacenti &);
   posizione pos(int); // mapping della posizione

private:
   posizione primo;
};

#endif // LISTAADIACENTI_H
