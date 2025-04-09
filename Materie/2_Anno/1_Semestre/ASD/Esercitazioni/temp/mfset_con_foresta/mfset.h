//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//...................... REALIZZAZIONE MFSET CON VETTORE .......................
//..............................................................................



#ifndef MFSET_H
#define MFSET_H
#define N 100



//definizione della classe Mfset

class Mfset
   {
      public:
//definizione dei tipi

            typedef int tipoelem;
            typedef int componente;
            typedef int insieme;

            struct nodo
               {
                  tipoelem padre;
                  int dimensione;
               };

//Specifica delle interfacce
            void     	creamfset(insieme);
            componente  trova(tipoelem);
            void     	fondi(tipoelem,tipoelem);

//costruttori e distruttori
            Mfset();
           ~Mfset();

      private:
            nodo mfset[N];
   };
#endif

