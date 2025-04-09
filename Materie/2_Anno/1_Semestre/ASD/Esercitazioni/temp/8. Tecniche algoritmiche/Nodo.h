#ifndef NODO_H
#define NODO_H

typedef int tipoelem;

class Nodo {
public:
   Nodo();
   Nodo(tipoelem);
   ~Nodo();
   
   tipoelem getEtichetta();
   void setEtichetta(tipoelem);
   
private:
   tipoelem etichetta;
};

#endif
