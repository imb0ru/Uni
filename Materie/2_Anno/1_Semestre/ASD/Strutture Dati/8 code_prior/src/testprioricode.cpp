#include <iostream>
#include "prioriCode.h"

int main() {
    prioriCoda<int> codaPriorita;

    // Inserimento di alcuni elementi
    codaPriorita.inserisci(10);
    codaPriorita.inserisci(5);
    codaPriorita.inserisci(15);
    codaPriorita.inserisci(7);
    codaPriorita.inserisci(12);

    std::cout << "Contenuto della coda con priorita: " << std::endl;
    std::cout << codaPriorita;

    // Lettura dell'elemento minimo
    std::cout << "Elemento minimo: " << codaPriorita.min() << std::endl;

    // Cancellazione dell'elemento minimo
    codaPriorita.cancellaMin();

    std::cout << "Contenuto della coda con priorita dopo la cancellazione del minimo: " << std::endl;
    std::cout << codaPriorita;

    return 0;
}
