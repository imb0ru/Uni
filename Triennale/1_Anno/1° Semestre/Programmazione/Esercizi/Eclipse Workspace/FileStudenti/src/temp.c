/*
 * Realizzare una funzione che legge da file di testo un elenco di studenti, rappresentati da nome,
matricola e voti degli esami.
Dopo la lettura da file si deve calcolare la media dei voti di uno studente cercato per nome o per
matricola.
Il tipo di dato studente deve essere rappresentato come un record con 3 campi:
- Nominativo di tipo stringa
- Matricola di tipo intero
- Voti di tipo vettore di interi di dimensione variabile
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct{
	char * nome;
	int matricola;
	int * voto;
}studente;

studente elenco [MAX];
studente LeggereFile(studente s, FILE * fp);
studente Allocvoto(studente s);
studente AllocNome(studente s);

studente ScrivereNome (studente s, char m[MAX]);
studente ScrivereMatricola (studente s, int m);
studente ScrivereVoto (studente s, int v, int nvoti);
char * LeggereNome (studente s);
int LeggereMatricola(studente s);
int LeggereVoto(studente s, int pos);

int LeggereRighe(FILE * fp);


int main(){
	FILE * fp;
	int linee;
	int i=0;
	fp=fopen("studenti.txt","r");
	if(fp==NULL){
		perror("Errore nell'apertura del file");
		exit(1);
	}
	linee=LeggereRighe(fp);
	while(i<linee){
		elenco[i]=LeggereFile(elenco[i],fp);
		i=i+1;
	}
	fclose(fp);
	return 0;
}
//funzione di accesso per scrivere il nome dello studente nel record
studente ScrivereNome(studente s, char m[MAX]){
	strcpy(s.nome,m);
	return s;
}
//funzione di accesso per scrivere la matricola nel record
studente ScrivereMatricola(studente s, int m){
	s.matricola=m;
	return s;
}
//funzione di accesso per scrivere i voti nel record
studente ScrivereVoto(studente s, int v, int pos){
	s.voto[pos]=v;
	return s;
}
//funzione di lettura del nome di un alunno
char* LeggereNome (studente s){
	return s.nome;
}
//funzione di lettura della matricola di un alunno
int LeggereMatricola(studente s){
	return s.matricola;
}
//funzione di lettura dei voti
int LeggereVoto(studente s, int pos){
	return s.voto[pos];
}

studente AllocNome(studente s){
	s.nome=(char*)malloc(100*sizeof(char));
	return s;
}
studente Allocvoto(studente s){
	s.voto=(int*)malloc(20*sizeof(int));
	return s;
}


studente LeggereFile(studente s, FILE * fp){
	int i=0;
	char c;
	char temp[MAX];
	char temp2[MAX];
	int matricola;

	while((c = fgetc(fp)) !=  ' '){
		temp[i]=c;
		i=i+1;
	}
	temp[i]=' ';
	while((c = fgetc(fp)) != ' '){
		temp[i]=c;
		i=i+1;
	}
	temp[i]='\0';
	s=ScrivereNome(s, temp);
	i=0;
	while((c = fgetc(fp)) != ' '){
		temp2[i]=c;
		i=i+1;
	}
	temp2[i]='\0';
	matricola=atoi(temp2);
	s=ScrivereMatricola(s, matricola);
	i=0;
	int j=0;
	while((c = fgetc(fp)) != '\n' && c!=EOF){
		if(c==' '){
			temp2[i]='\0';
			int voto=atoi(temp2);
			s=ScrivereVoto(s,voto,j);
			j=j+1;
			i=0;
		}else{
		temp2[i]=c;
		i=i+1;
		}
	}
	printf("%s %d", LeggereNome(s), LeggereMatricola(s));
	i=0;
	while(i<j){
		printf(" %d ",LeggereVoto(s,i));
		i=i+1;
	}
	return s;
}

int LeggereRighe(FILE*fp){
	int c;
	int linee=0;
	while((c = fgetc(fp)) != EOF){
		if(c=='\0'||c=='\n')
			linee=linee+1;
	}

	return linee;
}
