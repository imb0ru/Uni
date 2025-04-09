#include <iostream>
#include "Codac.h"

Codac::Codac(){Codac::creacoda();};
Codac::~Codac(){};

void Codac::creacoda(){testa=-1; inizializzall();};
void Codac::inizializzall(){
				int c, g;
            inizioll=1;
            for (c=0; c<100;c++){
            		g=c;
                  g++;
                  elemento[c].scrivisucc(g);};};
bool Codac::codavuota()
              {return testa==-1;};
puntaelem Codac::leggicoda(){
                return elemento[testa].leggivalore();};
void Codac::incoda(puntaelem val){
            if (testa==-1)
            {testa=1; fondo=1; inizioll=2;
            elemento[testa].scrivivalore(val);
            elemento[testa].scrivisucc(-1);}
            else
            {int temp;
            temp=elemento[fondo].leggisucc();
            elemento[fondo].scrivisucc(inizioll);
            elemento[inizioll].scrivivalore(val);
            fondo=inizioll;
            inizioll=elemento[inizioll].leggisucc();
            elemento[fondo].scrivisucc(temp);};
            };
void Codac::fuoricoda(){
            int temp;
            temp=testa;
            testa=elemento[testa].leggisucc();
            elemento[temp].scrivisucc(inizioll);
            inizioll=temp;
            };
