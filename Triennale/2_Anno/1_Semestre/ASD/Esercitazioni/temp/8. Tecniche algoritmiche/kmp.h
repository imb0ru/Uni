/*
  Nome: kmp.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Implementazione dell'algoritmo di Knuth-Morris-Pratt
               (string matching - backtracking) 
*/


#include <iostream>
#include <string>

using namespace std;
typedef char pattern[21];
typedef char text[100];
typedef int vettore[20];

void spostamenti(pattern p, vettore s){
   int m = strlen(p);
   s[0] = 0; //spostamento al primo carattere è sempre 0
   int k = 0; //spostamento (cambierà nel ciclo)
   for (int q = 2; q <= m; q++){
      while ((k > 0) && (p[k] != p[q-1]))
         k = s[k-1];
      if (p[k] == p[q-1]) 
         k++;
      s[q-1] = k;
   }
}

int kmp(text t, pattern p){
   vettore s;
   spostamenti(p, s);
   int risposta = -1;
   int q = 0;
   int m = strlen(p);
   int n = strlen(t);
   if (n >= m){
      for (int i = 0; (i < n && q != m); i++){
         while ((q > 0) && (p[q] != t[i]))  //finché non combaciano i caratteri di testo e pattern
            q = s[q-1]; // torna indietro di s[q-1] passi nel pattern
         if (p[q] == t[i])
            q++; // se trova corrispondenza confronta il successivo carattere di testo e pattern
         if (q == m) //se q è l'm-esimo carattere vuol dire ke ha trovato un'occorrenza di p in t
            risposta = i + 1 - m; //indice della prima occorrenza
      }
   }
   return risposta+1; // se non trova occorrenze restituisce 0
}

