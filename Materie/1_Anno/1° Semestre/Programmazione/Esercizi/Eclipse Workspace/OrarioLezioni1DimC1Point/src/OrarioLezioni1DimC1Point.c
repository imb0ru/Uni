/*
 ============================================================================
 Name        : OrarioLezioni1DimC1Point.c
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

//record lezione
typedef struct lezione{
	char * materia; //materia della lezione
	char aula; //aula della lezione
	float oraInizio; //ora di inizio della lezione
	float oraFine; //ora di fine della lezione
}lezione;

lezione b = {"-\0",'-',0,0}; //lezione buco

//intestazione funzioni di accesso alla lezione
char leggereAula(lezione l);
char * leggereMateria(lezione l);
float leggereOraInizio(lezione l);
float leggereOraFine(lezione l);
lezione allocMateria(lezione l);
lezione deallocMateria(lezione l);
lezione scrivereAula(lezione l, char c);
lezione scrivereMateria(lezione l, char * c);
lezione scrivereOraInizio(lezione l, float o);
lezione scrivereOraFine(lezione l, float o);

//record tabellaella
typedef struct Tabella{
	int nRighe; //numero righe totali della tabellaella
	int nColonne; //numero colonne totali della tabellaella
	lezione * lezioni[7]; //array bidimensionale per il nostro orario
}tabella;

//intestazione funzioni di accesso alla tabellaella
int leggereNRighe(tabella t);
int leggereNColonne(tabella t);
lezione leggereLezione(tabella t, int r, int c);

tabella scrivereNRighe(tabella t, int nr);
tabella scrivereNColonne(tabella t, int nc);
tabella scrivereLezione(tabella t, int r, int c, lezione l);
tabella allocTabella(tabella t);

//intestazione funzioni principali
tabella newLezione(tabella t, int r, int c); //crea una nuova lezione e la inserisce nell'orario
tabella newOrario(); //crea un nuovo orario
tabella altOrario(tabella t); // modifica una lezione presente nell'orario
tabella remLezione(tabella t); //sostituisce una lezione specifica nell'orario con un'ora di buco
tabella remOrario(tabella t); //sostituisce ogni lezione nell'orario con un'ora di buco
void stampaOrario(tabella t); //stampa l'orario
void consultaOrario(tabella t); //apre il menu di consultazione dell'orario
void stampaLezione(lezione l); //stampa i dettagli di una lezione
void stampaArrayLezioniConsult12(lezione l[]); //stampa il risultato di due tipi di consultazione
void consultaOrarioPerGiorno(tabella t); //effettua la consultazione per giorno
void consultaOrarioPerOra(tabella t); //effettua la consultazione per ora
void consultaOrarioPerMateria(tabella t); //effettua la consultazione per materia
char verificaBuco(tabella t, int r, int c); //verifica la presenza di un'ora di buco in un determinato giorno e in una determinata fascia oraria
void giorniSettimana(int i); //stampa i giorni della settimana


//funzioni di accesso alla tabellaella
int leggereNRighe(tabella t){
	int r = t.nRighe;
	return r;
}

int leggereNColonne(tabella t){
	int c = t.nColonne;
	return c;
}

lezione leggereLezione(tabella t, int r, int c){
	lezione l = *(t.lezioni[c]+r);
	return l;
}

tabella scrivereNRighe(tabella t, int nr){
	t.nRighe=nr;
	return t;
}

tabella scrivereNColonne(tabella t, int nc){
	t.nColonne=nc;
	return t;
}

tabella allocTabella(tabella t){
	int i=0;
	while(i<leggereNColonne(t)){
		t.lezioni[i]=(lezione *)malloc(leggereNColonne(t)*sizeof(lezione));
		i++;
	}
	return t;
}

tabella scrivereLezione(tabella t, int r, int c, lezione l){
	*(t.lezioni[c]+r)=l;
	return t;
}


//funzioni di accesso alla lezione
char leggereAula(lezione l){
	char a = l.aula;
	return a;
}

char * leggereMateria(lezione l){
	char * c;
	c=(char *)malloc(20*sizeof(char));
	strcpy(c, l.materia);
	return c;
}

float leggereOraInizio(lezione l){
	float o = l.oraInizio;
	return o;
}

float leggereOraFine(lezione l){
	float o = l.oraFine;
	return o;
}

lezione allocMateria(lezione l){
	l.materia=(char*)malloc(20*sizeof(char));
	return l;
}

lezione deallocMateria(lezione l){
	free(l.materia);
	return l;
}

lezione scrivereAula(lezione l, char c){
	l.aula=c;
	return l;
}

lezione scrivereMateria(lezione l, char * c){
	strcpy(l.materia, c);
	return l;
}

lezione scrivereOraInizio(lezione l, float o){
	l.oraInizio=o;
	return l;
}

lezione scrivereOraFine(lezione l, float o){
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
tabella newLezione(tabella t, int r, int c){
	setbuf(stdout,NULL);
	char a, risp;
	char * m;
	m=(char *)malloc(20*sizeof(char));
	char* orari[] = {"8.30","9.20","10.10","11.00","11.50","12.40","13.30","14.20","15.10","16.00","16.50","17.40"};
	printf("Inserisci i dettagli della lezione presente dalle %s alle %s\n", orari[r],orari[r+1]);
	do{
		printf("E' un ora di buco?(s/n)-> ");
		scanf(" %c", &risp);
		risp=tolower(risp);
	}while((risp!='s') && (risp!='n'));
	if(risp=='s'){
		t=scrivereLezione(t,r,c,b);
		printf("Ora di buco inserita con successo!\n");
	}else{
		printf("Inserisci la materia->");
		scanf("%19s", m);
		printf("Inserisci l'iniziale dell'aula->");
		scanf(" %c", &a);
		fflush(stdout);
		lezione l;
		l=allocMateria(l);
		l=scrivereMateria(l,m);
		l=scrivereAula(l,a);
		l=scrivereOraInizio(l,atof(orari[r]));
		l=scrivereOraFine(l,atof(orari[r+1]));
		t=scrivereLezione(t,r,c,l);
	}
	free(m);
	printf("----------------------------------------------------------\n");
	fflush(stdout);
	return t;
}

//funzione per creare un nuovo orario e riempirlo con nuove lezioneioni
tabella newOrario(){
	setbuf(stdout,NULL);
	tabella t;
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
	t=allocTabella(t);
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

tabella altOrario(tabella t){
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

tabella remLezione(tabella t){
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

tabella remOrario(tabella t){
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

void stampaLezione(lezione l){
	setbuf(stdout,NULL);
	printf("Materia: %s, ", leggereMateria(l));
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

void stampaOrario(tabella t){
	setbuf(stdout,NULL);
	int i=0,j;
	while(i<leggereNColonne(t)){
		giorniSettimana(i);
		j=0;
		while(j<leggereNRighe(t)){
			stampaLezione(leggereLezione(t,j,i));
			j++;
		}
		i++;
	}
}

void consultaOrario(tabella t){
	setbuf(stdout,NULL);
	int tc;
	do{
		printf("\nBenvenuto nel menu di consultazione dell'orario, ecco le possibili consultazioni:\n1)Per Giorno\n2)Per Ora\n3)Per Materia\n");
		fflush(stdout);
		printf("Selezioneiona il tipo di consultazione da effettuare->");
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

void stampaArrayLezioniConsult12(lezione l[]){
	setbuf(stdout,NULL);
	int i=0;
	while(strcmp(leggereMateria(l[i]),"1\0")!=0){
		printf("Lezione n°%d: \n",i+1);
		fflush(stdout);
		stampaLezione(l[i]);
		i++;
	}
}


void consultaOrarioPerGiorno(tabella t){
	setbuf(stdout,NULL);
	lezione fine = {"1\0",'1','1','1'};
	lezione l[20];
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

void consultaOrarioPerOra(tabella t){
	setbuf(stdout,NULL);
	lezione fine = {"1\0",'1','1','1'};
	lezione l[20];
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

void consultaOrarioPerMateria(tabella t){
	setbuf(stdout,NULL);
	char * m;
	m=(char *)malloc(20*sizeof(char));
	printf("Inserisci la materia da consultare-> ");
	fflush(stdout);
	scanf("%19s", m);
	tabella tg;
	tg=scrivereNRighe(tg, leggereNRighe(t));
	tg=scrivereNColonne(tg,leggereNColonne(t));
	tg=allocTabella(tg);
	int c=0, r;
	while(c<leggereNColonne(t)){
		r=0;
		while(r<leggereNRighe(t)){
			if(strcmp(m,leggereMateria(leggereLezione(t,r,c)))==0) tg=scrivereLezione(tg,r,c,leggereLezione(t,r,c));
			else tg=scrivereLezione(tg,r,c,b);
			r++;
		}
		c++;
	}
	free(m);
	stampaOrario(tg);
}

char verificaBuco(tabella t, int r, int c){
	if(strcmp(leggereMateria(leggereLezione(t,r,c)),leggereMateria(b))==0) return '1';
	else return '0';
}


int main(){
	setbuf(stdout,NULL);
	tabella t = newOrario();
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

