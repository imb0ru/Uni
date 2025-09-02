//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389



#ifndef CLASSE_CODA_H
#define CLASSE_CODA_H

class Coda
	{
		public:
			typedef bool boolean;
			typedef int tipoelem;

			struct nodo
         	{
            	tipoelem elem;
            	struct nodo* succ;
            };
			typedef struct nodo* pos;


			void creacoda();
			boolean codavuota();
			tipoelem leggicoda();
			void fuoricoda();
			void incoda(tipoelem);

			Coda();
			Coda& operator = (Coda &);
			Coda& operator ^ (Coda &);
			~Coda();

		private:
			pos testa,fondo;

};

#endif
