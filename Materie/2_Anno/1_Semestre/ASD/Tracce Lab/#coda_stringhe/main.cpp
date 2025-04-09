//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389



/*Traccia a:
Fornendo una realizzazione in C++ della struttura dati di coda di caratteri
numerici rappresentanti numeri interi lunghi a piacere,
si implementino le funzioni richieste di seguito:


inserimento nella coda di stringa di caratteri numerici letti da tastiera
creazione della funzione di stampa a video del contenuto della coda
funzione che calcola la coda contenente la somma dei numeri
contenuti nelle due code passate in input
Dimostrare il corretto funzionamento delle funzioni mediante opportuno main.

Traccia b:
Fornendo una realizzazione in C++ della struttura dati di coda
di caratteri numerici rappresentanti numeri interi lunghi a piacere,
si implementino le funzioni richieste di seguito:
inserimento nella coda di stringa di caratteri numerici letti da tastiera
creazione della funzione di stampa a video del contenuto della coda
funzione che calcola la coda contenente la differenza dei numeri
contenuti nelle due code passate in input
Dimostrare il corretto funzionamento delle funzioni mediante opportuno main. */

//NB: la funzione differenza() restituisce anche stringhe che rappresentano
//    numeri negativi (in tal caso è previsto l'accodamento di un elemento
//    aggiuntivo che li caratterizza ossia -1)
//Esempio: se il risultato della differenza è -256, allora sarà restituita
//         una coda del tipo:
/*                              	 top->[ 2]
													[ 5]
                                       [ 6]
                                       [-1]<-fondo                            */


#include <iostream.h>
#include <stdlib.h>
#include "classe_coda.h"
#include "def_classe_coda.cpp"
#include "servizio.cpp"


void main()
{
Coda C1,C2, S, D;

acquiStringaInt(C1);
printcoda(C1);

acquiStringaInt(C2);
printcoda(C2);

cout<<"\n Sto per eseguire la somma tra due code\n\n";
system("PAUSE");
somma(C1, C2, S);
printcoda(S);

cout<<"\n Sto per eseguire la differenza tra due code\n\n";
system("PAUSE");

differenza(C1, C2, D);
printcoda(D);




system("PAUSE");
}
