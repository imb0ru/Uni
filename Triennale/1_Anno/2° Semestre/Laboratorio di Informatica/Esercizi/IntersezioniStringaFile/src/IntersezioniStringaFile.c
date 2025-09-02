#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


struct Sequenza{
	char* seq;
	int dim;
	int correct;
};

typedef struct Sequenza sequenza;

char leggereValore(sequenza seq, int pos);
sequenza scrivereValore(sequenza seq, char c, int pos);
int leggereDimensione(sequenza seq);
sequenza scrivereDimensione(sequenza seq, int dim);
int isCorrect(sequenza seq);
sequenza setCorrect(sequenza seq, int flag);
sequenza allocSequenza(sequenza seq);


char leggereValore(sequenza seq, int pos){
	char c = *(seq.seq+pos);
	return c;
}

sequenza scrivereValore(sequenza seq, char c, int pos){
	*(seq.seq+pos)=c;
	return seq;
}

int leggereDimensione(sequenza seq){
	int d = seq.dim;
	return d;
}

sequenza scrivereDimensione(sequenza seq, int dim){
	seq.dim = dim;
	return seq;
}

int isCorrect(sequenza seq){
	return seq.correct;
}

sequenza setCorrect(sequenza seq, int flag){
	seq.correct = flag;
	return seq;
}

sequenza allocSequenza(sequenza seq){
	seq.seq=(char*)malloc(seq.dim*sizeof(char));
	return seq;
}

sequenza cancellaSottosequenze(sequenza seq);
sequenza cancellaSottosequenze(sequenza seq){
	int i,j;
	seq=setCorrect(seq, 1);
	i=0;
	while(i<leggereDimensione(seq)){
		if(leggereValore(seq, i)=='('){
			j=i+1;
			while(j<leggereDimensione(seq) && isCorrect(seq) && leggereValore(seq,j) != ')'){
				if(leggereValore(seq,j) != '('){
					if(j==i+1)seq=scrivereValore(seq, '*', j);
					else {
						int x=j;
						while(x<leggereDimensione(seq)){
							seq=scrivereValore(seq, leggereValore(seq, x+1),x);
							x++;
						}
					}
					seq=scrivereDimensione(seq, leggereDimensione(seq)-1);
					j=j+1;
				}else{
					j=leggereDimensione(seq);
					seq=setCorrect(seq, 0);
				}
			}
			if(isCorrect(seq) && leggereValore(seq,j-1) != ')'){
				seq=setCorrect(seq, 0);
				i=leggereDimensione(seq);
			}else i=j;
		}else i=i+1;
	}
	return seq;
}


int main(void) {
	//freopen("C:\\Users\\marco\\OneDrive\\Desktop\\Cartelle Desktop\\Universita\\Materie\\1° Anno\\2° Semestre\\Laboratorio di Informatica\\Esercizi\\IntersezioniStringaFile\\src\\input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
	//freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

	char string[] = "a, b, (a, c, g), b, e, (p,q ), a, (x, x), f";
	int n=44;
	sequenza s;
	char c;
	//assert(1 == scanf("%d", &n));
	s=scrivereDimensione(s,n);
	s=allocSequenza(s);
	int i=0;
	while(i<n) {
		//assert(1 == scanf("%c", &c));
		c=string[i];
		s=scrivereValore(s, c, i);
		i=i+1;
	}

	i=0;
	while(i<leggereDimensione(s)){
		printf("%c", leggereValore(s, i));
		i=i+1;
	}


	s=cancellaSottosequenze(s);
	if(isCorrect(s)) printf("\nErrore! Vincoli di correttezza della stringa non soddisfatti.\n");
	else{
		printf("\nCancellazione effettuata con successo\n");
		i=0;
		while(i<leggereDimensione(s)){
			printf("%c", leggereValore(s, i));
			i=i+1;
		}
	}

	return 0;
}
