#include <iostream>
#include <cstdlib>
#include "InsiemePtrN.h"

using namespace std;

InsiemePtrN::InsiemePtrN(){
   creaInsieme();
};

InsiemePtrN::~InsiemePtrN(){
   posizione q;
   while (insieme != NULL){
      q = insieme;
      insieme = insieme->getSuccessivo();
      delete q;
   }
};
   
void InsiemePtrN::creaInsieme(){
   insieme = NULL;
};

bool InsiemePtrN::insiemeVuoto(){
   return (insieme == NULL);
};

bool InsiemePtrN::appartiene(tipoelem a){
   posizione p = insieme;
   bool flag = false;
   while ((p != NULL) && (!flag)){
      flag = (a == p->getEtichetta());
      p = p->getSuccessivo();
   }
   return flag;
};

bool InsiemePtrN::inserisci(tipoelem a){
   if (!appartiene(a)){
      insieme = new NodoPtrInsieme(a, insieme);
      return true;
   } else return false;
};

bool InsiemePtrN::cancella(tipoelem a){
   if (appartiene(a)){
      posizione p = insieme;
      posizione q = p;
	  	while ((p != NULL) && (p->getEtichetta()!=a)){
       	q = p;       		
       	p = p->getSuccessivo();
      }
      if(p==insieme){
      	if(p->getSuccessivo()==NULL)
      		insieme = NULL;
      	else
      		insieme = p->getSuccessivo();
      } else 
   	  	q->setSuccessivo(p->getSuccessivo());
      delete p;
      return true;
   } else return false;      
};

InsiemePtrN &InsiemePtrN::unione(InsiemePtrN &set){
   InsiemePtrN b;
   b = set;
   InsiemePtrN *c = new InsiemePtrN();
   posizione p = insieme;
   tipoelem a;
   while (p != NULL){
      a = p->getEtichetta();
      if (b.appartiene(a)){
         b.cancella(a);
      }
      c->inserisci(a);
      p = p->getSuccessivo();
   }
   p = b.getInsieme();
   while (p != NULL){
      a = p->getEtichetta();
      c->inserisci(a);
      p = p->getSuccessivo();
   }
   return *c;
};

InsiemePtrN &InsiemePtrN::intersezione(InsiemePtrN &set){
   InsiemePtrN b;
   b = set;
   posizione p = b.getInsieme();
   InsiemePtrN *c = new InsiemePtrN();
   tipoelem a;
   while (p != NULL){
      a = p->getEtichetta();
      if (!appartiene(a))
         b.cancella(a);
      p = p->getSuccessivo();
   }
   p = b.getInsieme();
   while (p != NULL){
      a = p->getEtichetta();
      c->inserisci(a);
      p = p->getSuccessivo();
   }
   return *c;
};

InsiemePtrN &InsiemePtrN::differenza(InsiemePtrN &set){
   InsiemePtrN b;
   b = set;
   InsiemePtrN *c = new InsiemePtrN();
   posizione p = insieme;
   tipoelem a;
   while (p != NULL){
      a = p->getEtichetta();
      if (!b.appartiene(a)){
         c->inserisci(a);
      }
      p = p->getSuccessivo();
   }   
   return *c;
};

InsiemePtrN &InsiemePtrN::operator=(InsiemePtrN &i){
	posizione p;
   while (insieme != NULL){
   	p = insieme;
      insieme = insieme->getSuccessivo();
      delete p;
   }
	p = i.getInsieme();
	while (p!=NULL){
		inserisci(p->getEtichetta());
		p = p->getSuccessivo();
	}
	return *this;
}
 
posizione InsiemePtrN::getInsieme(){
   return insieme;
};
