//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389

/*
Implementare la struttura dati di tipo lista per la rappresentazione di polinomi
di qualunque grado.
In più si chiede di implementare eval(p,x) di valutazione del polinomio p
nel punto x e la somma/differenza di 2 polinomi:

definizione delle funzioni di immissione e stampa della lista implementata
definizione della funzione eval(p,x), che valuti il polinomio p nel punto x
definizione della funzione somma del polinomio p(x)
definizione della funzione differenza del polinomio p(x)

*/

/*
NB:  	la funzione visualizzazione(), esegue una serie di controlli per adeguare
		la stampa alle convenzioni di rappresentazione in uso, in particolare:

      l'omissione del coefficiente 1,
      l'omissione dell'intero termine se il coefficiente è zero,
      l'omissione della x quando l'esponente è 1,
      l'omissione dell'esponente quando vale 1.

      Esempio:
		sia un P un polinomio del tipo  3x^0 - 1x^1 - 0x^2 + 0x^3 + 7.4x^4
      allora la stampa sarà:          3-x + 7.4x^4
*/

#include <iostream.h>
#include <stdlib.h>
#include "classe_lista.h"
#include "def_classe_lista.cpp"
#include "servizio.cpp"




void main()
{
	Lista P1,P2,S,D;
   double x;

	cout<<"\n Costruzione della lista polinomio P1(x): ";
	acquisizione(P1);
	visualizzazione(P1);
	system("PAUSE");

	cout<<"\n Costruzione della lista polinomio P2(x): ";
	acquisizione(P2);
	visualizzazione(P2);
	system("PAUSE");

	cout<<"\n Calcolo del valore assunto dal polinomio P1(x) nel punto x= ";
   cin>>x;
   cout<<"\n P1(x)="<<eval(P1,x)<<"\n\n\n";
	system("PAUSE");

	cout<<"\n Costruzione della lista P1(x)+P2(x): ";
	somma(P1,P2,S);
	visualizzazione(S);
	system("PAUSE");

	cout<<"\n Costruzione della lista P1(x)-P2(x): ";
	differenza(P1,P2,D);
	visualizzazione(D);
	system("PAUSE");
}




