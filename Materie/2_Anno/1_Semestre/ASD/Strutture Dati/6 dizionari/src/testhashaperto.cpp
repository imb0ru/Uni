#include <iostream>

#include "hashaperto.h"

using namespace std;


int main() {
    hashAperto<int, int> dizionario;

    // Inserimento di elementi
    dizionario.inserisci(1, 10);
    dizionario.inserisci(3, 30);
    dizionario.inserisci(1, 11);
    dizionario.inserisci(2, 20);
    dizionario.inserisci(10, 100);
    dizionario.inserisci(4, 40);

    // Inserimento di altri elementi per testare la resize
    dizionario.inserisci(0, 456);
    dizionario.inserisci(400, 40000);

    // Cancellazione di un elemento
    dizionario.cancella(1);

    // Aggiornamento del valore di un elemento
    dizionario.aggiornaValore(4, 50);

    // Visualizzazione delle chiavi e dei valori
    cout << "Chiavi: " << dizionario.keys() << endl;
    cout << "Valori: " << dizionario.values() << endl;

    // Verifica se una chiave appartiene al dizionario
    int chiaveDaVerificare = 2;
    cout << "Appartiene la chiave " << chiaveDaVerificare << "? " << (dizionario.appartiene(chiaveDaVerificare) ? "Sì" : "No") << endl;

    // Recupero di un elemento
    int chiaveDaRecuperare = 10;
    bucket<int, int>* elementoRecuperato = dizionario.recupera(chiaveDaRecuperare);
    if (elementoRecuperato != nullptr) {
        cout << "Elemento recuperato con chiave " << chiaveDaRecuperare << ": " << *elementoRecuperato << endl;
    } else {
        cout << "Elemento non trovato con chiave " << chiaveDaRecuperare << endl;
    }

    // Verifica se un valore è presente nel dizionario
    int valoreDaVerificare = 456;
    cout << "Il valore " << valoreDaVerificare << " è presente nel dizionario? " << (dizionario.containsValue(valoreDaVerificare) ? "Sì" : "No") << endl;

    // Visualizzazione del dizionario
    cout << "Dizionario:" << endl << dizionario << endl;

    return 0;
}

