#include <iostream>
#include <queue>

// Funzione per costruire una nuova coda con valori positivi
std::queue<int> codaPositivi(const std::queue<int>& codaOriginale) {
    // Coda per i valori positivi
    std::queue<int> codaPositiva;

    // Copia della coda originale
    std::queue<int> codaCopia = codaOriginale;

    // Scorrimento della coda copia
    while (!codaCopia.empty()) {
        // Estrazione del front della coda
        int valore = codaCopia.front();
        
        // Verifica se il valore è positivo
        if (valore > 0) {
            // Inserimento nella coda dei valori positivi
            codaPositiva.push(valore);
        }

        // Rimozione dell'elemento dalla coda copia
        codaCopia.pop();
    }

    // Restituzione della nuova coda con valori positivi
    return codaPositiva;
}

int main() {
    // Creazione di una coda originale
    std::queue<int> codaOriginale;
    codaOriginale.push(-2);
    codaOriginale.push(5);
    codaOriginale.push(-8);
    codaOriginale.push(10);
    codaOriginale.push(-3);

    // Chiamata alla funzione per ottenere la coda con valori positivi
    std::queue<int> codaPositiva = codaPositivi(codaOriginale);

    // Stampa della coda originale
    std::cout << "Coda originale: ";
    while (!codaOriginale.empty()) {
        std::cout << codaOriginale.front() << " ";
        codaOriginale.pop();
    }
    std::cout << std::endl;

    // Stampa della coda con valori positivi
    std::cout << "Coda con valori positivi: ";
    while (!codaPositiva.empty()) {
        std::cout << codaPositiva.front() << " ";
        codaPositiva.pop();
    }
    std::cout << std::endl;

    return 0;
}
