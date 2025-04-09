//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE CODA CON VETTORE .........................
//..............................................................................



#ifndef CODA_H
#define CODA_H
#define TOP 1  //in questa realizzazione il top è un riferimento
					//costante al primo elemento del vettore.
#define N 100	//dimensione del vettore

class Coda
	{
		public:
			typedef bool boolean;
 			typedef int tipoelem;
			typedef int pos;

//Specifica delle interfacce
			void		creacoda();
   		boolean	codavuota();
      	tipoelem	leggicoda();
        	void		fuoricoda();
         void		incoda(tipoelem);

//definizione costruttori e distruttori
			Coda();
			Coda& operator = (Coda &);
			Coda& operator ^ (Coda &);
		  ~Coda();

 		private:
         pos fondo;
 			tipoelem coda[N];
	};

#endif

