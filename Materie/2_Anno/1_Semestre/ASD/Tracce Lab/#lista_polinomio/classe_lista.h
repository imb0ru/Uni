//Università degli Studi di Bari
//facoltà di Informatica

//sede distaccata di Brindisi
//Laboratorio di Algoritmi e Strutture Dati 2002/2003
//docente dr. P.Buono

//Autore: Nico Spadoni
//matr.428389



#ifndef CLASSE_LISTA_H
#define CLASSE_LISTA_H


class Lista
	{
		public:

			typedef bool boolean;
			typedef double tipoelem;

			struct nodo
         	{
					tipoelem elem;
					struct nodo* succ;
            };
			typedef struct nodo* pos;


			void crealista();
         pos primolista();
			boolean listavuota();
			boolean finelista(pos);
			void inslista(tipoelem,pos);
			void canclista(pos);
			pos succlista(pos);
			pos predlista(pos);
			void scrivilista(tipoelem,pos);
			tipoelem leggilista(pos);

			Lista();
			Lista& operator = (Lista &);
		  ~Lista();

		private:
			pos primo;
   };

#endif
