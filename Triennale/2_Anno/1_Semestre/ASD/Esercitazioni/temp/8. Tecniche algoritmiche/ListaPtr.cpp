#include <iostream>
#include <cstdlib>
#include "ListaPtr.h"

ListaPtr::ListaPtr(){
   creaLista();
};
 
ListaPtr::~ListaPtr(){
   posizione q;
   while (primo != NULL){
      q = primo;
      primo = primo->getSuccessivo();
      delete q;
   }
};
   
void ListaPtr::creaLista(){
   primo = NULL;
};
   
bool ListaPtr::listaVuota(){
   return (primo == NULL);
};

posizione ListaPtr::primoLista(){
   return primo;
};
   
posizione ListaPtr::predLista(posizione p){
   if (p == primo){
      return NULL;
   } else {
      posizione q = primo;
      while (q->getSuccessivo() != p){
         q = q->getSuccessivo();
      }
      return q;
   }
};

posizione ListaPtr::succLista(posizione p){
   if (p != NULL) return p->getSuccessivo();      
   else return NULL;
};

bool ListaPtr::fineLista(posizione p){
   return (p == NULL);
};
   
void ListaPtr::insLista(tipoelem a, posizione p){
   posizione q = new NodoPtr(a, p);
   if (p == primo)
      primo = q;
   else {
      p = predLista(p);
      p->setSuccessivo(q);
   }
}

bool ListaPtr::cancLista(posizione p){
   if ((primo != NULL) && (p != NULL)){
      posizione q = predLista(p);
      q->setSuccessivo(p->getSuccessivo());
      delete p; 
      return true;
   } else return false;
};

bool ListaPtr::scriviLista(tipoelem a, posizione p){
   if ((primo != NULL) && (p != NULL)){
      p->setEtichetta(a);
      return true;
   } else return false;
}

bool ListaPtr::leggiLista(tipoelem &a, posizione p){
   if ((primo != NULL) && (p != NULL)){
      a = p->getEtichetta();
      return true;
   } else return false;
};
   
posizione ListaPtr::pos(int n){
   posizione p = primo;
   int i = 1;
   while ((p != NULL) && (i < n)){
      p = p->getSuccessivo();
      i++;
   }
   return p;
};
