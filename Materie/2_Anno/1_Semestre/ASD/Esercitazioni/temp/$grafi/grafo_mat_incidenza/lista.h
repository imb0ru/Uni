//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.............. REALIZZAZIONE LISTA SEQUENZIALE CON VETTORE ...................
//..............................................................................



#ifndef LISTA_H
#define LISTA_H
#define N 100		//dimensione del vettore

class Lista
	{
		public:
			typedef bool boolean;
 			typedef int tipoelem;
			typedef int pos;

 			//operatori
 			void 		crealista();
 			boolean 	listavuota();
 			tipoelem leggilista(pos);
 			void 		scrivilista(pos,tipoelem);
 			pos 		primolista();
 			pos 		ultimolista();
 			boolean 	finelista(pos);
 			pos 		succlista(pos);
 			pos 		predlista(pos);
 			void 		inslista(pos,tipoelem);
 			void 		canclista(pos);

   		//costruttori e distruttore
   		Lista();
   	  ~Lista();

 		private:
 			int lunghezza;
 			tipoelem lista[N];
	};

#endif

