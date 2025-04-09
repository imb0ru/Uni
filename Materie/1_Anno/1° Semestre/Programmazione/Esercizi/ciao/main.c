/*
 ============================================================================
 Name        : OrarioLezioni.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//record Lezione
struct Lezione{
	char materia; //materia della lezione
	char aula; //aula della lezione
	float oraInizio; //ora di inizio della lezione
	float oraFine; //ora di fine della lezione
};

struct Lezione b = {'-','-',0,0}; //lezione buco

//intestazione funzioni di accesso alla lezione
char leggereAula(struct Lezione l);
char leggereMateria(struct Lezione l);
float leggereOraInizio(struct Lezione l);
float leggereOraFine(struct Lezione l);

struct Lezione scrivereAula(struct Lezione l, char c);
struct Lezione scrivereMateria(struct Lezione l, char c);
struct Lezione scrivereOraInizio(struct Lezione l, float o);
struct Lezione scrivereOraFine(struct Lezione l, float o);

//record tabella
struct Tabella{
	int nRighe; //numero righe totali della tabella
	int nColonne; //numero colonne totali della tabella
	struct Lezione lezioni[100][100]; //array bidimensionale per il nostro orario
};

//intestazione funzioni di accesso alla tabella
int leggereNRighe(struct Tabella t);
int leggereNColonne(struct Tabella t);
struct Lezione leggereLezione(struct Tabella t, int r, int c);

struct Tabella scrivereNRighe(struct Tabella t, int nr);
struct Tabella scrivereNColonne(struct Tabella t, int nc);
struct Tabella scrivereLezione(struct Tabella t, int r, int c, struct Lezione l);

//intestazione funzioni principali
struct Tabella newLezione(struct Tabella t, int r, int c);
struct Tabella newOrario();
struct Tabella altOrario(struct Tabella t);
struct Tabella remLezione(struct Tabella t);
struct Tabella remOrario(struct Tabella t);
void stampaOrario(struct Tabella t);
void consultaOrario(struct Tabella t);
void stampaLezione(struct Lezione l);
void stampaArrayLezioniConsult12(struct Lezione l[]);
void consultaOrarioPerGiorno(struct Tabella t);
void consultaOrarioPerOra(struct Tabella t);
void consultaOrarioPerMateria(struct Tabella t);
char verificaBuco(struct Tabella t, int r, int c);


//funzioni di accesso alla tabella
int leggereNRighe(struct Tabella t){
	return t.nRighe;
}

int leggereNColonne(struct Tabella t){
	return t.nColonne;
}

struct Lezione leggereLezione(struct Tabella t, int r, int c){
	return t.lezioni[r][c];
}

struct Tabella scrivereNRighe(struct Tabella t, int nr){
	t.nRighe=nr;
	return t;
}

struct Tabella scrivereNColonne(struct Tabella t, int nc){
	t.nColonne=nc;
	return t;
}

struct Tabella scrivereLezione(struct Tabella t, int r, int c, struct Lezione l){
	t.lezioni[r][c]=l;
	return t;
}


//funzioni di accesso alla lezione
char leggereAula(struct Lezione l){
	return l.aula;
}

char leggereMateria(struct Lezione l){
	return l.materia;
}

float leggereOraInizio(struct Lezione l){
	return l.oraInizio;
}

float leggereOraFine(struct Lezione l){
	return l.oraFine;
}

struct Lezione scrivereAula(struct Lezione l, char c){
	l.aula=c;
	return l;
}

struct Lezione scrivereMateria(struct Lezione l, char c){
	l.materia=c;
	return l;
}

struct Lezione scrivereOraInizio(struct Lezione l, float o){
	l.oraInizio=o;
	return l;
}

struct Lezione scrivereOraFine(struct Lezione l, float o){
	l.oraFine=o;
	return l;
}

//funzione per creare una nuova lezione
struct Tabella newLezione(struct Tabella t, int r, int c){
	setbuf(stdout,NULL);
	char a, risp;
	char m[25];
	float oi,of;
	printf("Inserisci i dettagli della lezione presente nel giorno %d nella fascia oraria %d\n", r+1, c+1);
	do{
		printf("E' un ora di buco?(s/n)-> "); fflush(stdout);
		risp=getchar();
	}while(risp!='s' || risp!='n');
	if(risp=='S'){
		t=scrivereLezione(t,r,c,b);
	}else{
		printf("Inserisci la materia lettera per lettera (0 per terminare)->");
		fflush(stdout);
		int i=0;
		do{
			m[i]=getchar();
			i++;
		}while(m[i-1]!=0);
		printf("Inserisci l'iniziale dell'aula->");
		fflush(stdout);
		a=getchar();
		printf("Inserisci l'orario di inizio lezione (formato hh.mm)->");
		fflush(stdout);
		scanf("%f",&oi);
		printf("Inserisci l'orario di fine lezione (formato hh.mm)->");
		fflush(stdout);
		scanf("%f",&of);
		struct Lezione l;
		l=scrivereMateria(l,m);
		l=scrivereAula(l,a);
		l=scrivereOraInizio(l,oi);
		l=scrivereOraFine(l,of);
		t=scrivereLezione(t,r,c,l);
	}
	printf("----------------------------------------------------------");
	fflush(stdout);
	return t;
}

//funzione per creare un nuovo orario e riempirlo con nuove lezioni
struct Tabella newOrario(){
	setbuf(stdout,NULL);
	struct Tabella t;
	int r,c;
	do{
		printf("Inserisci il numero di giorni della settimana da utilizzare nell'orario->");
		fflush(stdout);
		scanf("%d",&c);
	}while(c<1 || c>6);
	do{
		printf("Inserisci il numero di fasce orarie del tuo orario scolastico->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	t=scrivereNRighe(t,r);
	t=scrivereNColonne(t,c);
	int i=0,j;
	while(i<leggereNColonne(t)){
		j=0;
		while(j<leggereNRighe(t)){
			t=newLezione(t,i,j);
			j++;
		}
		i++;
	}
	printf("----------------------------------------------------------");
	fflush(stdout);
	return t;

}

struct Tabella altOrario(struct Tabella t){
	setbuf(stdout,NULL);
	int c,r;
	do{
		printf("Inserisci il numero del giorno della settimana della lezione da modificare->");
		fflush(stdout);
		scanf("%d",&c);
	}while(c<1 || c>6);;
	c--;
	do{
		printf("Inserisci il numero della fascia oraria della lezione da modificare->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	r--;
	newLezione(t,r,c);
	printf("----------------------------------------------------------");
	fflush(stdout);
	return t;
}

struct Tabella remLezione(struct Tabella t){
	setbuf(stdout,NULL);
	int c,r;
	do{
		printf("Inserisci il numero del giorno della settimana della lezione da cancellare->");
		fflush(stdout);
		scanf("%d",&c);
	}while(c<1 || c>6);;
	c--;
	do{
		printf("Inserisci il numero della fascia oraria della lezione da cancellare->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	r--;
	t=scrivereLezione(t,r,c,b);
	printf("----------------------------------------------------------");
	fflush(stdout);
	return t;
}

struct Tabella remOrario(struct Tabella t){
	int i=0,j;
	while(i<leggereNColonne(t)){
		j=0;
		while(j<leggereNRighe(t)){
			t=scrivereLezione(t,i,j,b);
			j++;
		}
		i++;
	}
	return t;
}

void stampaLezione(struct Lezione l){
	setbuf(stdout,NULL);
	printf("Materia: %c", leggereMateria(l));
	fflush(stdout);
	printf("Aula: %c", leggereAula(l));
	fflush(stdout);
	printf("Ora di Inizio: %f", leggereOraInizio(l));
	fflush(stdout);
	printf("Ora di Fine: %f", leggereOraFine(l));
	fflush(stdout);
	printf("----------------------------------------------------------");
	fflush(stdout);
}

void stampaOrario(struct Tabella t){
	setbuf(stdout,NULL);
	int i=0,j;
	while(i<leggereNColonne(t)){
		switch(i){
		case 0: printf("Lezioni presenti il Lunedi");
		fflush(stdout);
		break;
		case 1: printf("Lezioni presenti il Martedi");
		fflush(stdout);
		break;
		case 2: printf("Lezioni presenti il Mercoledi");
		fflush(stdout);
		break;
		case 3: printf("Lezioni presenti il Giovedi");
		fflush(stdout);
		break;
		case 4: printf("Lezioni presenti il Venerdi");
		fflush(stdout);
		break;
		default: printf("Lezioni presenti il Sabato");
		fflush(stdout);
		break;
		}
		j=0;
		while(j<leggereNRighe(t)){
			struct Lezione l = leggereLezione(t,i,j);
			stampaLezione(l);
			j++;
		}
		i++;
	}
}

void consultaOrario(struct Tabella t){
	setbuf(stdout,NULL);
	int tc;
	do{
		printf("Benvenuto nel menu di consultazione per orario, seleziona il tipo di consultazione da effettuare:\n1)Per Giorno\n2)Per Ora\n3)Per Materia\n");
		fflush(stdout);
		scanf("%d", &tc);
		if(tc!=1&&tc!=2&&tc!=3){
			printf("Errore, inserire 1,2 oppure 3!");
			fflush(stdout);
		}
	}while(tc!=1&&tc!=2&&tc!=3);
	switch(tc){
	case 1: consultaOrarioPerGiorno(t);
	break;
	case 2: consultaOrarioPerOra(t);
	break;
	case 3: consultaOrarioPerMateria(t);
	break;
	}
}

void stampaArrayLezioniConsult12(struct Lezione l[]){
	setbuf(stdout,NULL);
	int i=0;
	while(leggereMateria(l[i])!='1'){
		printf("Lezione n°%d: \n",i+1);
		fflush(stdout);
		stampaLezione(l[i]);
	}
}


void consultaOrarioPerGiorno(struct Tabella t){
	setbuf(stdout,NULL);
	struct Lezione fine = {'1','1','1','1'};
	struct Lezione l[20];
	int c=0;
	do{
		printf("Inserisci il numero del giorno della settimana da consultare->");
		fflush(stdout);
		scanf("%d",&c);
	}while(c<1 || c>6);
	int r=0;
	while(r<leggereNRighe(t)){
		l[r]=leggereLezione(t,r,c);
		r++;
	}
	l[r]=fine;
	stampaArrayLezioniConsult12(l);
}

void consultaOrarioPerOra(struct Tabella t){
	setbuf(stdout,NULL);
	struct Lezione fine = {'1','1','1','1'};
	struct Lezione l[20];
	int r=0;
	do{
		printf("Inserisci il numero della fascia oraria da consultare->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	int c=0;
	while(c<leggereNColonne(t)){
		l[c]=leggereLezione(t,r,c);
		c++;
	}
	l[c]=fine;
	stampaArrayLezioniConsult12(l);
}

void consultaOrarioPerMateria(struct Tabella t){
	setbuf(stdout,NULL);
	char m;
	printf("Inserisci la materia da consultare-> ");
	fflush(stdout);
	m=getchar();
	struct Tabella tg;
	tg=scrivereNRighe(tg, leggereNRighe(t));
	tg=scrivereNColonne(tg,leggereNColonne(t));
	int c=0;
	int lc=0;
	int lr=0;
	while(c<leggereNColonne(t)){
		int r=0;
		while(r<leggereNRighe(t)){
			if(m==leggereMateria(leggereLezione(t,r,c))){
				scrivereLezione(tg,lr,lc,leggereLezione(t,r,c));
				lc++;
				lr++;
			}
			r++;
		}
		c++;
	}
	stampaOrario(tg);
}

char verificaBuco(struct Tabella t, int r, int c){
	if(leggereMateria(leggereLezione(t,r,c))==leggereMateria(b)) return '1';
	else return '0';
}


int main(){
	setbuf(stdout,NULL);
	struct Tabella t = newOrario();
	printf("%c",leggereNRighe(t));
	return 0;
}
