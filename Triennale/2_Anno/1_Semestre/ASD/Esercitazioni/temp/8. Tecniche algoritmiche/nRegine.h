/*
  Nome: nRegine.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Implementazione dell'algoritmo che risolve il problema
               delle n regine in maniera ricorsiva (backtracking) 
*/


#include <iostream>
#define CHESS 20

typedef int scacchiera[CHESS];

bool sottoAttacco(int riga, int colonna, scacchiera c){
   bool attack = false;
   for (int i = 0; (i < colonna && !attack); i++)
      if (riga >= c[i])
         attack = (c[i] == riga) || (riga - c[i] == colonna - i);
      else
         attack = (c[i] == riga) || (c[i] - riga == colonna - i);
   return attack;
}

bool piazzaRegine(int colonna, scacchiera c, int dimen){
   if (colonna < dimen){
      bool piazzata = false;
      int riga = 0;
      while(!piazzata && riga < dimen){
         if (sottoAttacco(riga, colonna, c))
            riga++;
         else{
            c[colonna] = riga;
            piazzata = piazzaRegine(colonna+1, c, dimen);
            if (!piazzata){
               c[colonna] = -1;
               riga++;
            }
         }
      }
      return piazzata;
   } else return true;
}

bool regine(scacchiera c, int dimen){
   return piazzaRegine(0, c, dimen);
}

void stampaRegine(scacchiera c, int dimen){
   for (int row = 0; row < dimen; row++){
      for (int col = 0; col < dimen; col++)
         if (c[col] == row)
            std::cout << "O ";
         else
            std::cout << "# ";
      std::cout << std::endl;
   }
}
      
         
