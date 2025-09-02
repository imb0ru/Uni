#include <iostream.h>
//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono


//Implementare la struttura dati che permetta di memorizzare una lista di
//rettangoli del piano cartesiano (RxR)
//(si possono memorizzare le coordinate degli estremi dei rettangoli),
//che permette di:

//Inserire e stampare la lista di rettangoli

//Funzione/metodo inscritto() che dati due rettangoli A e B
//restituisce il valore vero se il rettangolo A è inscritto nel rettangolo B

//Funzione/metodo epurazione() che elimina dalla struttura tutti i rettangoli
//inscritti in altri rettangoli usando la funzione/metodo inscritto

//Funzione/metodo maxarea() che calcoli la massima area
//tra quelle dei rettangoli della lista

//Funzione/metodo nonoverlap()che restituisce la sottolista
//dei rettangoli che non si sovrappongono



//Autore: Nico Spadoni
//matr.428389




//MAIN 


#include <stdlib.h>
#include "classe_lista.h"
#include "classe_rect.h"
#include "def_classe_lista.cpp"
#include "def_classe_rect.cpp"
#include "servizio.cpp"




void main()
{
	Lista R,S;
	cout<<"\n Costruzione della lista di rettangoli: ";
	acquisizione(R);
	visualizzazione(R);
	system("PAUSE");

	cout<<"\n\n La massima area tra tutti i rettangoli della lista e': "
	 	 <<maxarea(R)<<"\n\n\n\n\n\n";
	system("PAUSE");

	cout<<"\n Costruzione sottolista dei rettangoli non sovrapposti: ";
   nonoverlap(S,R);
   visualizzazione(S);
	system("PAUSE");

	cout<<"\n Epurazione della lista dai rettangoli inscritti: ";
	epurazione(R);
	visualizzazione(R);
	system("PAUSE");
}
