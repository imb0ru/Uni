//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.............. REALIZZAZIONE INSIEME COME LISTA NON ORDINATA .................
//..............................................................................



#ifndef INS_H
#define INS_H



//definizione della classe Ins

class Ins
   {
      public:
//definizione dei tipi
            typedef bool boolean;
            typedef int tipoelem;
            struct nodo
               {
                  tipoelem elem;
                  struct nodo* succ;
               };
            typedef struct nodo* pos;

//costruttori e distruttori
            Ins();
				Ins(Ins &A);
				Ins& operator = (Ins &);
           ~Ins();

//Specifica delle interfacce
            void     creains();
            boolean  insvuoto();
            boolean  appartiene(tipoelem);
            void     inserisci(tipoelem);
            void     cancella(tipoelem);
            void     unione(Ins &, Ins &);
            void     intersezione(Ins &, Ins &);
            void     differenza(Ins &, Ins &);

      private:
            pos I; //riferimento iniziale
   };
#endif

