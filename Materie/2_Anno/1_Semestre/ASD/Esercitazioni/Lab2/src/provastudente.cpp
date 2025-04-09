#include "studente.h"

int main() {
    // Test della classe Studente
    Studente studente1;
    studente1.inserisciStudente(300000, "Mario", "Rossi", 25);
    std::cout << "Studente 1:" << std::endl;
    studente1.stampaStudente();
    
    // Creazione di un array dinamico di Studenti
    const int maxStudenti = 3;
    Studente* corso = new Studente[maxStudenti];
    int numStudentiIscritti = 0;

    // Inserimento di nuovi studenti
    corso[numStudentiIscritti++].inserisciStudente(400000, "Anna", "Bianchi", 22);
    corso[numStudentiIscritti++].inserisciStudente(350000, "Luca", "Verdi", 30);

    // Stampa degli studenti iscritti al corso
    std::cout << "\nStudenti iscritti al corso:" << std::endl;
    for (int i = 0; i < numStudentiIscritti; ++i) {
        corso[i].stampaStudente();
        std::cout << std::endl;
    }

    // Deallocazione della memoria
    delete[] corso;

    return 0;
}
