/*
  Nome: zainoGreedy.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Implementazione dell'algoritmo che risolve il problema
               dello zaino (approccio greedy) 
*/

#include <iostream>
#define OBJ 10

struct aux{
   int index;
   float p_c;
};

typedef struct aux ausiliario[OBJ];
typedef float vettore[OBJ];
typedef bool knapsack[OBJ]; 

void bubbleSort(ausiliario v, int n){
   int i, j;
   bool flag = true;
   aux temp;
   for(i = 1; (i <= n && flag); i++){
      flag = false;
      for (j=0; j < n-1; j++){
         if (v[j+1].p_c > v[j].p_c){
            temp = v[j];         
            v[j] = v[j+1];
            v[j+1] = temp;
            flag = true; // indica lo swap di 2 elementi
         }
      }
   }
}

void insOggetti(ausiliario v, vettore p, vettore c, int n){
   for (int i = 0; i < n; i++){
      v[i].index = i;
      v[i].p_c = p[i]/c[i];
   }
}

void zainoGreedy(int n, vettore p, vettore c, float b, knapsack &k){
   ausiliario v;
   insOggetti(v, p, c, n);
   bubbleSort(v, n);
   int i;
   for (i = 0; i < n; i++)
      k[i] = false; //inizializza lo zaino
   i = 0;
   while (i < n){
      if (c[v[i].index] <= b){
         k[v[i].index] = true;
         b = b - c[v[i].index];
      }
      i++;
   }
}
