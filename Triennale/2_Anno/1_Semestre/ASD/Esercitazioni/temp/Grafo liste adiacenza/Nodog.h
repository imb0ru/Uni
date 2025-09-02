


#ifndef NODOG_H
#define NODOG_H
#include "Rifnodoa.h"

typedef char tipoelem;

class Nodog
{

   private:
   tipoelem label;
	bool presente;
   bool visitato;

   public:
   Rifnodoa *ad;
   Nodog();
   ~Nodog();
   void setLabel(tipoelem x);
   tipoelem getLabel();
   void setPresenteYes();
	void setPresenteNo();
   bool leggiPresente();
	void setVisitatoYes();
	void setVisitatoNo();
   bool leggiVisitato();
   };

#endif