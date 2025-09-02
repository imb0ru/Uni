//					HEADER
//##################################################### 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COEFF_PONTE  0.06
#define COEFF_LOCANDA 0.21
#define COEFF_POZZO 0.34
#define COEFF_PRIGIONE  0.46
#define COEFF_LABIRINTO 0.57
#define COEFF_SCHELETRO 0.64

#define NORMALE 0
#define OCA 1
#define PONTE 2
#define LOCANDA 3
#define POZZO 4
#define PRIGIONE 5
#define LABIRINTO 6
#define SCHELETRO 7

typedef struct{
	int lunghezza;
	int * mappa;
}Percorso;

int LeggereLunghezza(Percorso p);
Percorso ScrivereLunghezza(Percorso p, int lunghezza);
Percorso ScrivereCasella(Percorso p, int pos, int casella);
int LeggereCasella(Percorso p,int pos);
char * VerbalizzaCasella(Percorso p, int pos);
Percorso ScambiaCasella(Percorso p, int pos);
void StampaPercorso(Percorso p);

Percorso GeneraPercorso(int  lunghezza);
void ImpostaSpeciali(Percorso p);

//################################################


//				SETTERS & GETTERS		
//**********************************************
int LeggereLunghezza(Percorso p)
{
	int temp = p.lunghezza;
	return temp;
}

Percorso ScrivereLunghezza(Percorso p, int lunghezza)
{
	p.lunghezza = lunghezza;
	p.mappa = (int *)malloc(sizeof(int)* lunghezza);
	return p;
}

Percorso ScrivereCasella(Percorso p, int pos, int casella)
{	
	p.mappa[pos]= casella;
	return p;
}

int LeggereCasella(Percorso p,int pos){
	int temp = p.mappa[pos];
	return temp;
}

char * VerbalizzaCasella(Percorso p, int pos)
{
	char str[10];

	if(LeggereCasella(p, pos) == NORMALE)
		strcpy(str , "normale");

	else if(LeggereCasella(p, pos) == OCA)
		strcpy(str , "oca");

	else if(LeggereCasella(p, pos) == PONTE)
		strcpy(str , "ponte");

	else if(LeggereCasella(p, pos) == LOCANDA)
		strcpy(str ,"locanda");

	else if(LeggereCasella(p, pos) == POZZO)
		strcpy(str , "pozzo");

	else if(LeggereCasella(p, pos) == PRIGIONE)
		strcpy(str ,"prigione");

	else if(LeggereCasella(p, pos) == LABIRINTO)
		strcpy(str ,"labirinto");

	else 
		strcpy(str , "scheletro");

	return str;

}

//stampa del percorso con struttura a serpentina
void StampaPercorso(Percorso p) {
	int righe, colonne;
	int dim = LeggereLunghezza(p);

	righe=ceil(sqrt(dim))+1;
	colonne=ceil(dim/righe)+1;

	int i,j,x=0;
	int count=0;

	printf("\nLegenda Caselle:\n"
			"- Casella di tipo (0): Normale\n"
			"- Casella di tipo (1): Oca\n"
			"- Casella di tipo (2): Ponte\n"
			"- Casella di tipo (3): Locanda\n"
			"- Casella di tipo (4): Pozzo\n"
			"- Casella di tipo (5): Prigione\n"
			"- Casella di tipo (6): Labirinto\n"
			"- Casella di tipo (7): Scheletro\n\n");

	printf("%d %d %d\n", dim, righe, colonne);
	for(i=0;i<dim;i++)
		printf("%d ", LeggereCasella(p,x++));
	printf("\n");

	i=0;
	x=0;
	while(i < righe)
	{
		if (i % 2 == 0)
		{
			j=0;
			while (j < colonne && x<dim)
			{
				printf("%d(%d) ", count+1,  LeggereCasella(p,count));
				count=count+1;
				j=j+1;
				x=x+1;
			}
			printf("\n");
		}
		else
		{
			count=count+colonne-1;
			j=colonne-1;
			while(j >= 0 && x<dim)
			{
				printf("%d(%d) ", count+1,  LeggereCasella(p,count));
				count=count-1;
				j=j-1;
				x=x+1;
			}
			printf("\n");
			count=count+colonne+1;
		}
		i=i+1;
	}

}


//scambio con l'immediato successivo non nessito di 3 parametro
Percorso ScambiaCasella(Percorso p, int pos)
{
	int temp;

	temp = LeggereCasella(p, pos);
	p = ScrivereCasella(p, pos, LeggereCasella(p, pos+1));
	p = ScrivereCasella(p, pos+1, temp);

	return p;
}

//*************************************************

Percorso GeneraPercorso(int  lunghezza)
{
	Percorso p;

	p = ScrivereLunghezza(p, lunghezza);

	if(p.mappa != NULL)
	{
		int i;
		i = 0;

		while(i  < lunghezza)
		{
			ScrivereCasella(p, i , 0);
			i=i+1;
		}
		ImpostaSpeciali(p);

	}else 
	{
		printf("Errore allocazione memoria");	
	}

	return p;
}

void ImpostaSpeciali(Percorso p)
{
	int l = LeggereLunghezza(p);

	ScrivereCasella(p, l * COEFF_PONTE, 2);
	ScrivereCasella(p, l * COEFF_LOCANDA, 3);
	ScrivereCasella(p, l * COEFF_POZZO, 4);
	ScrivereCasella(p, l * COEFF_PRIGIONE, 5);
	ScrivereCasella(p, l * COEFF_LABIRINTO, 6);
	ScrivereCasella(p, l * COEFF_SCHELETRO, 7);

	int i = 0;
	while(i < l){
		if(i % 9 == 0)
		{
			if(LeggereCasella(p, i) != 1)
			{
				ScambiaCasella(p, i);	
			}
			ScrivereCasella(p, i, 1);
		}
		i = i + 1;
	}
}

int main(){
	Percorso p;
	int l;
	do{
		printf("Inserisci la lunghezza del percorso: ");
		fflush(stdout);
		scanf("%d", &l);
	}while(l<50 || l>90);
	p = GeneraPercorso(l);
	StampaPercorso(p);

	return 0;
}
