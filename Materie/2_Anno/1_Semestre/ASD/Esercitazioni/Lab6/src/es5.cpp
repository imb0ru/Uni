#include <iostream>
#include <stack>
#include <unordered_set>

template <typename T>
class PilaSenzaDuplicati {
private:
    std::stack<T> pila;
    std::unordered_set<T> elementiUnici;

public:
    // Aggiunge un elemento alla pila solo se non è già presente
    void inPila(const T& elemento) {
        if (elementiUnici.find(elemento) == elementiUnici.end()) {
            pila.push(elemento);
            elementiUnici.insert(elemento);
        }
    }

    // Altri metodi della pila, ad esempio pop, top, etc.
    // ...

    // Stampa il contenuto della pila
    void stampaPila() const {
        std::stack<T> pilaTemporanea = pila;
        while (!pilaTemporanea.empty()) {
            std::cout << pilaTemporanea.top() << " ";
            pilaTemporanea.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    PilaSenzaDuplicati<char> miaPila;

    miaPila.inPila('L');
    miaPila.inPila('A');
    miaPila.inPila('A');
    miaPila.inPila('S');
    miaPila.inPila('T');
    miaPila.inPila('I');
    miaPila.inPila('I');
    miaPila.inPila('N');
    miaPila.inPila('S');
    miaPila.inPila('L');
    miaPila.inPila('I');

    miaPila.stampaPila();

    return 0;
}

