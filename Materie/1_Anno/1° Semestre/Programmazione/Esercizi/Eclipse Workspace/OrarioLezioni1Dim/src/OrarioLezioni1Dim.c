/*
 ============================================================================
 Name        : OrarioLezioni1dim.c
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
	struct Lezione lezioni[168]; //array bidimensionale per il nostro orario
};

//intestazione funzioni di accesso alla tabella
int leggereNRighe(struct Tabella t);
int leggereNColonne(struct Tabella t);
struct Lezione leggereLezione(struct Tabella t, int r, int c);

struct Tabella scrivereNRighe(struct Tabella t, int nr);
struct Tabella scrivereNColonne(struct Tabella t, int nc);
struct Tabella scrivereLezione(struct Tabella t, int r, int c, struct Lezione l);

//intestazione funzioni principali
struct Tabella newLezione(struct Tabella t, int r, int c); //crea una nuova lezione e la inserisce nell'orario
struct Tabella newOrario(); //crea un nuovo orario
struct Tabella altOrario(struct Tabella t); // modifica una lezione presente nell'orario
struct Tabella remLezione(struct Tabella t); //sostituisce una lezione specifica nell'orario con un'ora di buco
struct Tabella remOrario(struct Tabella t); //sostituisce ogni lezione nell'orario con un'ora di buco
void stampaOrario(struct Tabella t); //stampa l'orario
void consultaOrario(struct Tabella t); //apre il menu di consultazione dell'orario
void stampaLezione(struct Lezione l); //stampa i dettagli di una lezione
void stampaArrayLezioniConsult12(struct Lezione l[]); //stampa il risultato di due tipi di consultazione
void consultaOrarioPerGiorno(struct Tabella t); //effettua la consultazione per giorno
void consultaOrarioPerOra(struct Tabella t); //effettua la consultazione per ora
void consultaOrarioPerMateria(struct Tabella t); //effettua la consultazione per materia
char verificaBuco(struct Tabella t, int r, int c); //verifica la presenza di un'ora di buco in un determinato giorno e in una determinata fascia oraria
void giorniSettimana(int i); //stampa i giorni della settimana


//funzioni di accesso alla tabella
int leggereNRighe(struct Tabella t){
	return t.nRighe;
}

int leggereNColonne(struct Tabella t){
	return t.nColonne;
}

struct Lezione leggereLezione(struct Tabella t, int r, int c){
	return t.lezioni[(t.nColonne*r)+c];
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
	t.lezioni[(t.nColonne*r)+c]=l;
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


void giorniSettimana(int i){
	if(i==0){
		printf("\nLezioni presenti il Lunedi\n");
		fflush(stdout);
	}else if (i==1){
		printf("\nLezioni presenti il Martedi\n");
		fflush(stdout);
	}else if(i==2){
		printf("\nLezioni presenti il Mercoledi\n");
		fflush(stdout);
	}else if(i==3){
		printf("\nLezioni presenti il Giovedi\n");
		fflush(stdout);
	}else if(i==4){
		printf("\nLezioni presenti il Venerdi\n");
		fflush(stdout);
	}else{
		printf("\nLezioni presenti il Sabato\n");
		fflush(stdout);
	}
}

//funzione per creare una nuova lezione
struct Tabella newLezione(struct Tabella t, int r, int c){
	setbuf(stdout,NULL);
	char a, risp;
	char m;
	float oi,of;
	printf("Inserisci i dettagli della lezione presente nella fascia oraria %d\n", r+1);
	do{
		printf("E' un ora di buco?(s/n)-> ");
		scanf(" %c", &risp);
		risp=tolower(risp);
	}while((risp!='s') && (risp!='n'));
	if(risp=='s'){
		t=scrivereLezione(t,r,c,b);
		printf("Ora di buco inserita con successo!\n");
	}else{
		printf("Inserisci l'iniziale della materia->");
		scanf(" %c", &m);
		printf("Inserisci l'iniziale dell'aula->");
		scanf(" %c", &a);
		fflush(stdout);
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
	printf("----------------------------------------------------------\n");
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
	}while((c<1) && (c>6));
	do{
		printf("Inserisci il numero di fasce orarie del tuo orario scolastico->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	t=scrivereNRighe(t,r);
	t=scrivereNColonne(t,c);
	int i=0,j;
	while(i<leggereNColonne(t)){
		printf("\n");
		giorniSettimana(i);
		j=0;
		while(j<leggereNRighe(t)){
			t=newLezione(t,j,i);
			j++;
		}
		i++;
	}
	printf("----------------------------------------------------------\n");
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
	}while((c<1) && (c>6));;
	c--;
	do{
		printf("Inserisci il numero della fascia oraria della lezione da modificare->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	r--;
	t=newLezione(t,r,c);
	printf("----------------------------------------------------------\n");
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
	}while((c<1) && (c>6));;
	c--;
	do{
		printf("Inserisci il numero della fascia oraria della lezione da cancellare->");
		fflush(stdout);
		scanf("%d",&r);
	}while(r<1);
	r--;
	t=scrivereLezione(t,r,c,b);
	printf("----------------------------------------------------------\n");
	fflush(stdout);
	return t;
}

struct Tabella remOrario(struct Tabella t){
	int i=0,j;
	while(i<leggereNColonne(t)){
		j=0;
		while(j<leggereNRighe(t)){
			t=scrivereLezione(t,j,i,b);
			j++;
		}
		i++;
	}
	return t;
}

void stampaLezione(struct Lezione l){
	setbuf(stdout,NULL);
	printf("Materia: %c, ", leggereMateria(l));
	fflush(stdout);
	printf("Aula: %c, ", leggereAula(l));
	fflush(stdout);
	printf("Ora di Inizio: %2.2f, ", leggereOraInizio(l));
	fflush(stdout);
	printf("Ora di Fine: %2.2f ", leggereOraFine(l));
	fflush(stdout);
	printf("\n----------------------------------------------------------\n\n");
	fflush(stdout);
}

void stampaOrario(struct Tabella t){
	setbuf(stdout,NULL);
	int i=0,j;
	while(i<leggereNColonne(t)){
		giorniSettimana(i);
		j=0;
		while(j<leggereNRighe(t)){
			struct Lezione l = leggereLezione(t,j,i);
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
		printf("\nBenvenuto nel menu di consultazione dell'orario, ecco le possibili consultazioni:\n1)Per Giorno\n2)Per Ora\n3)Per Materia\n");
		fflush(stdout);
		printf("Seleziona il tipo di consultazione da effettuare->");
		scanf("%d", &tc);
		if(tc!=1&&tc!=2&&tc!=3){
			printf("Errore, inserire 1,2 oppure 3!");
			fflush(stdout);
		}
	}while((tc!=1)&&(tc!=2)&&(tc!=3));

	if(tc==1) consultaOrarioPerGiorno(t);
	else if(tc==2)consultaOrarioPerOra(t);
	else consultaOrarioPerMateria(t);

}

void stampaArrayLezioniConsult12(struct Lezione l[]){
	setbuf(stdout,NULL);
	int i=0;
	while(leggereMateria(l[i])!='1'){
		printf("Lezione n°%d: \n",i+1);
		fflush(stdout);
		stampaLezione(l[i]);
		i++;
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
	}while((c<1) && (c>6));
	c--;
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
	r--;
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
	scanf(" %c", &m);
	struct Tabella tg;
	tg=scrivereNRighe(tg, leggereNRighe(t));
	tg=scrivereNColonne(tg,leggereNColonne(t));
	int c=0, r;
	while(c<leggereNColonne(t)){
		r=0;
		while(r<leggereNRighe(t)){
			if(m==leggereMateria(leggereLezione(t,r,c))) tg=scrivereLezione(tg,r,c,leggereLezione(t,r,c));
			else tg=scrivereLezione(tg,r,c,b);
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
	int risp;
	char cont;

	do{
		do{
			printf("\nEcco le possibili operazioni con il tuo orario:\n"
					"1)Modifica una lezione presente nell'orario\n"
					"2)Rimuovi una lezione sostituendola con un'ora di buco\n"
					"3)Rimuovi l'intero orario sostituendo ogni lezione con un'ora di buco\n"
					"4)Visualizza l'orario\n"
					"5)Apri il menu di consultazione dell'orario\n"
					"Inserisci il numero dell'operazione che vuoi effettuare-> ");
			scanf("%d",&risp);
			if((risp<1 || risp>5)) printf("Nessuna operazione presente con questo identificativo, riprova!\n");
		}while((risp<1) && (risp>5));

		if(risp==1) t=altOrario(t);
		else if(risp==2) t=remLezione(t);
		else if(risp==3) t=remOrario(t);
		else if(risp==4) stampaOrario(t);
		else consultaOrario(t);

		do{
			printf("Vuoi continuare ad effettuare operazioni?(s/n)-> ");
			scanf(" %c", &cont);
			cont=tolower(cont);
		}while((cont!='s') && (cont!='n'));
	}while(cont=='s');
	return 0;
}
