
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

const char separatori[]={' ', ',', ';', '.',':', '\n', '\t', '\0'};  // caratteri separatori

int ContareParole(char * s);  // Conta le parole presenti nel file
int ContareLettere(char *s);  // Conta i caratteri presenti nel file
int ContareLinee(char *s);   // Conta le linee presenti nel file
void CalcolareFrequenze(char *s, int *f);  //Calcola le frequenze di ogni lunghezza di parola

void LeggereDaFile(char * s);  //Legge il contenuto del file e lo porta in memoria
int Separatore(char c); //Verifica se il carattere e' un separatore
void TrovareParola(char *s, int i, char *p); //estrae una parola dal vettore
int TrovareFrequenza(int *lparole, int l);  //Trova la frequenza di una lunghezza di parola
// int VerificareLunghezza(int l, int * lparole);
void Azzerare(int*v);  //Azzera il vettore delle lunghezze di parole

int main(void) {
	char testo[DIM];
	int frequenze[DIM];
	int nparole;
	int ncaratteri;
	int nlinee;

	int i;

	printf("I N I Z I O !!\n");
	LeggereDaFile(testo);
	if (testo[0]!='\0')
		{
		nparole=ContareParole(testo);
		printf("\n numero parole = %d", nparole);
		nlinee=ContareLinee(testo);
		printf("\n numero linee = %d", nlinee);
		ncaratteri=ContareLettere(testo);
		printf("\n numero caratteri = %d", ncaratteri);
		CalcolareFrequenze(testo, frequenze);
		i=0;
		while(i<nparole)
			{
			printf("\n frequenza = %d", frequenze[i]);
			i=i+1;
			}
		printf("\n");
		}
	else printf("E R R O R E  F I L E  N O N  T R O V A T O !!!\n");

	system("pause");
	return 0;
}


void LeggereDaFile(char * s)
{
	FILE * filetesto;
	int i;
	char c;

	filetesto=fopen("FileTesto.txt", "r");
	if (filetesto!=NULL)
		{
		i=0;
		while ((c=fgetc(filetesto))!=EOF)
			{
			s[i]=c;
			i=i+1;
			}
		s[i]='\0';
		}
	else s[0]='\0';

	return;
}

int ContareParole(char * s)
{
	int nparole;
	int parolacompletata;
	int i;

	nparole=0;
	parolacompletata=1;
	i=0;
	while (s[i]!='\0')
		{
		if ((Separatore(s[i])==1) && (parolacompletata=1)) nparole=nparole+1;
		else if (Separatore(s[i])==0) parolacompletata=0;
		i=i+1;
		}

	return nparole;
}

int ContareLinee(char *s)
{
	int nlinee;
	int i;

	nlinee=0;
	i=0;
	while (s[i]!='\0')
		{
		if (s[i]=='\n') nlinee=nlinee+1;
		i=i+1;
		}

	return nlinee;
}

int ContareLettere(char *s)
{
	int nlettere;
	int i;

	nlettere=0;
	i=0;
	while (s[i]!='\0')
		{
		if (s[i]!='\n') nlettere=nlettere+1;
		i=i+1;
		}

	return nlettere;
}

void CalcolareFrequenze(char * s, int* f)
{
	int i;
	int j;
	int k;
	char parola[DIM];
	int lparole[DIM];

	Azzerare(lparole);
	i=0;
	j=0;
	while (s[i]!='\0')
		{
		if (Separatore(s[i])==0)
			{
			TrovareParola(s, i, parola);
			lparole[j]=strlen(parola);
			j=j+1;
			i=i+strlen(parola);
			}
		else i=i+1;
		}
	lparole[j]=0;
	i=0;
	k=0;
	while(i<j)
		{
		f[k]=TrovareFrequenza(lparole, lparole[i]);
		k=k+1;
		i=i+1;
		}

	return;
}

int Separatore(char c)
{
	int esito;
	int i;

	esito=0;
	i=0;
	while ((separatori[i]!='\0') && (esito==0))
		{
		if (c==separatori[i]) esito=1;
		i=i+1;
		}

	return esito;
}

void TrovareParola(char *s, int i, char *p)
{
	int j;

	j=0;
	while(Separatore(s[i+j])==0)
		{
		p[j]=s[i+j];
		j=j+1;
		}
	p[j]='\0';

	return;
}

int TrovareFrequenza(int *lparole, int l)
{
	int f;
	int i;

	f=0;
	i=0;
	while (lparole[i]!=0)
		{
		if (l==lparole[i]) f=f+1;
		i=i+1;
		}

	return f;
}

/* int VerificareLunghezza(int l, int * lparole)
{
	int esito;
	int i;

	esito=1;
	i=0;
	while ((lparole[i]!=0) && (esito==1))
	{
		if (l==lparole[i]) esito=0;
		i=i+1;
	}
	return esito;
}
*/
void Azzerare(int * v)
{
	int i;

	i=0;
	while (i<DIM)
		{
		v[i]=0;
		i=i+1;
		}

	return;
}
