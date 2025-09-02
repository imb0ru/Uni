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




//Definizione metodi della classe Rect 


#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include "classe_rect.h"

Rect::Rect(double a, double b, double c, double d)
	{
   	xad=a;
      yad=b;

      xbs=c;
      ybs=d;
   }

float Rect::base()
	{
   	return fabs(xad-xbs);
   }

float Rect::altezza()
	{
   	return fabs(yad-ybs);
   }

float Rect::diagonale()
	{
   	return sqrt(pow(base(),2)+pow(altezza(),2));
   }

float Rect::perimetro()
	{
   	return (base()+altezza())*2;
   }

float Rect::area()
	{
   	return base()*altezza();
   }



