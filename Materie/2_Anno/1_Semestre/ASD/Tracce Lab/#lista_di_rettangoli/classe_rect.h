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




//Interfaccia della classe Rect


#ifndef CLASSE_RECT_H
#define CLASSE_RECT_H


class Rect {
					public:
						float 	xad,yad,
               				xbs,ybs;

						float base();
                  float altezza();
                  float perimetro();
                  float area();
                  float diagonale();

						Rect(double =0, double =0, double =0, double =0);
                  //inizializzazione necessaria per consentire al compilatore
                  //di accedere al costruttore come default
			   };

#endif
