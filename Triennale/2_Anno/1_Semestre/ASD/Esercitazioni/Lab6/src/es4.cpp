#include <iostream>
#include <deque>

int main() {
    // Creazione di una deque
    std::deque<int> miaDeque;

    // Inserimento in testa
    miaDeque.push_front(1);
    miaDeque.push_front(2);

    // Inserimento in fondo
    miaDeque.push_back(3);
    miaDeque.push_back(4);

    // Stampa della deque
    std::cout << "Contenuto della deque: ";
    for (const auto& elemento : miaDeque) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;

    // Cancellazione dalla testa
    miaDeque.pop_front();

    // Cancellazione dal fondo
    miaDeque.pop_back();

    // Stampa della deque dopo le cancellazioni
    std::cout << "Contenuto della deque dopo cancellazioni: ";
    for (const auto& elemento : miaDeque) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;

    return 0;
}
