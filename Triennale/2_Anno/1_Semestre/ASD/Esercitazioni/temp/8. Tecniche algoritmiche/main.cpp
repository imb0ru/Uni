#include "kmp.h"
//#include "nRegine.h"
//#include "zainoGreedy.h"
//#include "camminiMinimi.h"
//#include "nmSort.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/* Knuth-Morris-Pratt */
int main(int argc, char *argv[]){
   pattern p;
   text t;
   cout << "Inserisci T: ";
   cin >> t;
   cout << "Inserisci P: ";
   cin >> p;
   int i = kmp(t, p);
   if (i != 0)
      cout << "Pattern trovato a partire dalla posizione " << i << endl;
   else
      cout << "Pattern non trovato" << endl;
   system("PAUSE");
   return 0;
}

/* n regine */
/*int main(int argc, char *argv[]){
   scacchiera c;
   int dimen;
   do{
      cout << "Inserisci dimensione scacchiera: ";
      cin >> dimen;
   } while (!(dimen > 0 && dimen <= CHESS));
   cout << endl;
   if (regine(c, dimen))
      stampaRegine(c, dimen);
   else 
      cout << "Non trovata";
   cout << endl;
   system("PAUSE");
   return 0;
}*/

/* ZainoGreedy */
/*int main(int argc, char *argv[]){
   vettore p, c;
   int n = 0;
   int b;
   char risp = 's';
   do{
      n++;
      cout << "Oggetto " << n << endl;
      cout << "Inserisci profitto: ";
      cin >> p[n-1];
      cout << "Inserisci costo: ";
      cin >> c[n-1];
      do{
         cout << "Altri oggetti? (S/N) ";
         cin >> risp;
      } while (!((risp == 's') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
      cout << endl;
   } while ((n < OBJ && (risp == 's' || risp == 'S')));
   cout << endl << "Inserisci budget: ";
   cin >> b;
   cout << endl;
   knapsack k;
   zainoGreedy(n, p, c, b, k);
   cout << "Saranno inseriti gli oggetti: ";
   for (int i = 0; i < n; i++)
      if (k[i])
         cout << i+1 << " ";
   cout << endl;
   system("PAUSE");
   return 0;
}*/

/* Cammini minimi */
/*int main(int argc, char *argv[]){
   GrafoAdiacenti g;
   distanze d;
   padri p;
   inserisciGrafo(g);
   camminiMinimi(g, 1, d, p);
   stampaCammini(g, 1, d, p);
   system("PAUSE");
   return 0;
}*/


/* Natural merge sort */
/*int main(int argc, char *argv[]){
   ListaPtr l;
   nmSort(l);
   system("PAUSE");
   return 0;
}*/




