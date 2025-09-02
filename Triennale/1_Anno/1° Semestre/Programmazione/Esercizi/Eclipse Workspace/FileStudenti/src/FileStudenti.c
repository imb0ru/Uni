///*
// ============================================================================
// Name        : FileStudenti.c
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
// ============================================================================
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX 100
//
//typedef struct{
//	char nome[50];
//	int matricola;
//	int voti[50];
//}studente;
//
//char * leggereNome(studente s);
//char * leggereNome(studente s){
//	char n[50];
//	strcpy(n,s.nome);
//	return n;
//}
//
//int leggereMatricola(studente s);
//int leggereMatricola(studente s){
//	int m;
//	m = s.matricola;
//	return m;
//}
//
//int leggereVoto(studente s, int pos);
//int leggereVoto(studente s, int pos){
//	int v;
//	v = s.voti[pos];
//	return v;
//}
//
//void scrivereNome(studente * s, char * n);
//void scrivereNome(studente * s, char * n){
//	strcpy(s->nome,n);
//}
//
//void scrivereMatricola(studente * s, int m);
//void scrivereMatricola(studente * s, int m){
//	s->matricola=m;
//}
//
//void scrivereVoto(studente * s, int v, int pos);
//void scrivereVoto(studente * s, int v, int pos){
//	s->voti[pos]=v;
//}
//
//
//int countRows(FILE * f);
//int countRows(FILE * f){
//	int linee=1;
//	char c;
//	while((c=fgetc(f))!=EOF)
//        if (c == '\n')
//            linee=linee+1;
//
//	fseek(f,0,SEEK_SET);
//	return linee;
//}
//
//
//void leggereStudenti(FILE * f, studente s[] );
//void leggereStudenti(FILE * f, studente s[] ){
//	char c;
//	char nome[MAX];
//	char cognome[MAX];
//	int i=0, j=0;
//	while((c=fgetc(f))!=EOF && j<countRows(f)){
//		while((c = fgetc(f)) !=  ' '){
//			nome[i]=c;
//			i=i+1;
//		}
//		nome[i]='\0';
//		i=0;
//		while((c = fgetc(f)) != ' '){
//			cognome[i]=c;
//			i=i+1;
//		}
//		cognome[i]='\0';
//		strcat(nome,cognome);
//	    scrivereNome(s[i], nome);
//	    printf(leggereNome(s[i]));
//	}
//	fclose(f);
//
//
//}
//
//
//
//int main(void) {
//	FILE * f;
//	f=fopen("studenti.txt","r");
//
//    if (f == NULL){
//        printf("\nImpossibile aprire il file.\n");
//        exit(EXIT_FAILURE);
//    }
//
//
//    const int n = countRows(f);
//
//    printf("%d", n);
//
//    studente studenti[n];
//
//    leggereStudenti(f,studenti);
//
//	return 0;
//}
