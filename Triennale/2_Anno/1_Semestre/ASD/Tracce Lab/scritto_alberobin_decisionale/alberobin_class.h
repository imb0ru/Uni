//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//................ REALIZZAZIONE ALBERO BINARIO CON PUNTATORI ..................
//.................. (orientato alla costruzione top down) .....................
//..............................................................................



#ifndef ALBEROBIN_CLASS_H
#define ALBEROBIN_CLASS_H


class AlberoBin
	{
		public:
//definizione dei tipi
      	typedef char tipoelem;
			typedef bool boolean;

			struct nodoBin
         	{
					struct nodoBin *sinistro;
               struct nodoBin *padre;
               struct nodoBin *destro;
               tipoelem elem;
          	};
			typedef struct nodoBin *nodo;

//Specifica delle interfacce

//operatori di costruzione top-down
			void 		creaBinAlbero();
			boolean 	binAlberoVuoto();
			nodo 		binRadice();
			nodo 		binPadre(nodo);
			nodo 		figlioSinistro(nodo);
			nodo 		figlioDestro(nodo);
			boolean 	sinistroVuoto(nodo);
			boolean	destroVuoto(nodo);
			void 		cancSottoBinAlbero(nodo);

//operatori di accesso al contenuto dei nodi
			tipoelem leggiNodo(nodo);
			void 		scriviNodo(tipoelem,nodo);

//operatori di costruzione top-down
			void 		insBinRadice();
			void 		insFiglioSinistro(nodo);
			void 		insFiglioDestro(nodo);

//costruttori e distruttori
		   AlberoBin();
		  ~AlberoBin();


		private:
			nodo T;
	};
#endif
