/*
 ============================================================================
 Name        : OperazioniElenchi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Elenco{
	int dim; //dimensione dell'array
	int * val; //elenco di valori
};

int leggereDimensione(struct Elenco e);
int leggereValore(struct Elenco e, int pos);
struct Elenco scrivereDimensione(struct Elenco e, int d);
struct Elenco scrivereValore(struct Elenco e, int pos, int n);

int leggereDimensione(struct Elenco e){
	return e.dim;
}

int leggereValore(struct Elenco e, int pos){
	return *(e.val+pos);
}

struct Elenco scrivereDimensione(struct Elenco e, int d){
	e.dim=d;
	return e;
}

struct Elenco scrivereValore(struct Elenco e, int pos, int n){
	*(e.val+pos)=n;
	return e;
}

struct Elenco scrivereElenco(struct Elenco e);
struct Elenco scrivereElenco(struct Elenco e){
	int i=0,n=0;
	while(i<leggereDimensione(e)){
		printf("Inserire un numero-> ");
		scanf("%d", &n);
		e=scrivereValore(e,i,n);
		i++;
	}
	return e;
}

struct Elenco calcolaSommaCorrispondenti(struct Elenco e1, struct Elenco e2, struct Elenco somma);
struct Elenco calcolaSommaCorrispondenti(struct Elenco e1, struct Elenco e2, struct Elenco somma){
	int i=0;
	while(i<leggereDimensione(e1)){
		scrivereValore(somma, i, (leggereValore(e1,i)+leggereValore(e2,i)));
		i++;
	}
	return somma;
}

struct Elenco calcolaDifferenzaCorrispondenti(struct Elenco e1, struct Elenco e2,struct Elenco diff);
struct Elenco calcolaDifferenzaCorrispondenti(struct Elenco e1, struct Elenco e2, struct Elenco diff){
	int i=0;
	while(i<leggereDimensione(e1)){
		scrivereValore(diff, i, (leggereValore(e1,i)-leggereValore(e2,i)));
		i++;
	}
	return diff;
}

int maxElenco(struct Elenco e);
int maxElenco(struct Elenco e){
	int max=INT_MIN;
	int i=0;
	while(i<leggereDimensione(e)){
		if(max<leggereValore(e,i))
			max=leggereValore(e,i);
		i=i+1;
	}
	return max;
}

void stampaElenco(struct Elenco e);
void stampaElenco(struct Elenco e){
	int i=0;
	while(i<leggereDimensione(e)){
		printf("%d ",leggereValore(e,i));
		i++;
	}
}

struct Elenco allocaMemoria(struct Elenco e, int d);
struct Elenco allocaMemoria(struct Elenco e, int d){
	e.val=(int *)malloc(d*sizeof(int));
	return e;
}



int main(void) {
	int t=0;

	struct Elenco e1, e2;
	int max1, max2;

	printf("Quanti elementi vuoi inserire per il primo elenco? ->");
	scanf("%d",&t);
	e1=scrivereDimensione(e1,t);
	e1=allocaMemoria(e1,t);

	printf("Quanti elementi vuoi inserire per il secondo elenco? ->");
	scanf("%d",&t);
	e2=scrivereDimensione(e2,t);
	e2=allocaMemoria(e2,t);

	printf("\nInserisci i valori del primo elenco\n");
	e1=scrivereElenco(e1);
	printf("\nInserisci i valori del secondo elenco\n");
	e2=scrivereElenco(e2);

	if(leggereDimensione(e1)==leggereDimensione(e2)){
		struct Elenco  somma, diff;
		somma=scrivereDimensione(somma,leggereDimensione(e1));
		diff=scrivereDimensione(diff,leggereDimensione(e1));

		somma=allocaMemoria(somma,t);
		diff=allocaMemoria(diff,t);

		somma=calcolaSommaCorrispondenti(e1,e2,somma);
		diff=calcolaDifferenzaCorrispondenti(e1,e2, diff);

		printf("\nSomma degli elementi corrispondenti tra gli elenchi: \n");
		stampaElenco(somma);

		printf("\nDifferenza degli elementi corrispondenti tra gli elenchi: \n");
		stampaElenco(diff);
	}else{
		printf("\nOperazioni somma e differenza non effettuabili, elenchi di dimensione diversa!\n");
	}

	max1=maxElenco(e1);
	max2=maxElenco(e2);

	printf("\n\nElemento massimo del primo elenco: %d\n", max1);
	printf("\nElemento massimo del secondo elenco: %d\n", max2);

	system("pause");
	return 0;
}
