


#include "Nodog.h"

Nodog::Nodog()
{
	ad=0;
   presente=false;
   visitato=false;
};

Nodog::~Nodog(){};


void Nodog::setLabel(tipoelem x)
{
	label=x;
};

tipoelem Nodog::getLabel()
{
	return label;
};

void Nodog::setPresenteYes()
{
	presente=true;
};

void Nodog::setPresenteNo()
{
   presente=false;
};

bool Nodog::leggiPresente()
{
   return presente;
};

void Nodog::setVisitatoYes()
{
   visitato=true;
};

void Nodog::setVisitatoNo()
{
   visitato=false;
};

bool Nodog::leggiVisitato()
{
   return visitato;
};


