/*
 ============================================================================
 Name        : MaxMinRicorrenzeArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define d 100
int leggiNaturale(int n);
void leggiVettoreInteri(int v[], int n);
int calcolaMenoF(int v[],int n);
int calcolaPiuF(int v[],int n);
int calcolaFrequenza(int v[], int n, int el);
void visualizzaRisultati(int piuf, int menof);
int main(){
	setbuf(stdout,NULL);
	int n=0,v[d],menoF,piuF;

	n=leggiNaturale(n);
	leggiVettoreInteri(v,n);
	menoF = calcolaMenoF(v,n);
	piuF = calcolaPiuF(v,n);

	visualizzaRisultati(piuF,menoF);
	system("pause");

	return 0;
}

int leggiNaturale(int n){
	do{
		printf("Quanti numeri vuoi inserire? ->");
		scanf("%d",&n);
		if(n<=10) printf("Errore! Inserisci un numero >10\n");
	}while(n<=10);
	return n;
}

void leggiVettoreInteri(int v[], int n){
	for(int i=0;i<n;i++){
		printf("Inserisci un numero: ");
		scanf("%d", &v[i]);
	}
	return;
}

int calcolaMenoF(int v[],int n){
	int menoF;
	int fminima=INT_MAX;
	for(int i=0;i<n;i++){
		int frequenza=calcolaFrequenza(v,n,v[i]);
		if(frequenza<fminima){
			fminima=frequenza;
			menoF=v[i];
		}
	}
	return menoF;
}

int calcolaPiuF(int v[],int n){
	int piuF;
	int fmassima=INT_MIN;
	for(int i=0;i<n;i++){
		int frequenza=calcolaFrequenza(v,n,v[i]);
		if(frequenza>fmassima){
			fmassima=frequenza;
			piuF=v[i];
		}
	}
	return piuF;
}

int calcolaFrequenza(int v[], int n, int el){
	int frequenza=0;
	for(int i=0;i<n;i++)
		if(v[i]==el)
			frequenza++;
	return frequenza;
}

void visualizzaRisultati(int piuf, int menof){
	printf("Valore con piu' occorrenze: %d\n", piuf);
	printf("Valore con meno occorrenze: %d\n", menof);
	return;

}

