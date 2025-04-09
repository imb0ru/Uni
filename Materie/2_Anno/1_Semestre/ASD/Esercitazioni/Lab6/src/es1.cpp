#include <iostream>
#include <queue>

#include <iostream>
#include <vector>

// Definizione della classe Stack
class Stack {
private:
    std::vector<int> elements; // Vettore per memorizzare gli elementi dello stack

public:
    // Funzione per inserire un elemento nello stack
    void push(int value) {
        elements.push_back(value);
    }

    // Funzione per eliminare e restituire l'elemento in cima allo stack
    int pop() {
        if (!elements.empty()) {
            int top = elements.back();
            elements.pop_back();
            return top;
        } else {
            std::cerr << "Lo stack è vuoto." << std::endl;
            return -1; // Valore sentinella per indicare uno stack vuoto
        }
    }

    // Funzione per verificare se lo stack è vuoto
    bool isEmpty() const {
        return elements.empty();
    }
};

// Definizione della classe MultipleStack
class MultipleStack {
private:
    std::vector<Stack> stacks; // Vettore di stack
    unsigned int numStacks;    // Numero totale di stack gestiti

public:
    // Costruttore che inizializza il numero di stack
    MultipleStack(unsigned int numStacks) : numStacks(numStacks) {
        // Creazione di numStacks stack e inserimento nel vettore
        stacks.resize(numStacks);
    }

    // Funzione per inserire un oggetto in uno specifico stack
    void push(int value, unsigned int stackIndex) {
        // Verifica se l'indice dello stack è valido
        if (stackIndex < numStacks) {
            // Inserimento nell'elemento stackIndex dello stack corrispondente
            stacks[stackIndex].push(value);
        } else {
            std::cerr << "Indice dello stack non valido." << std::endl;
        }
    }

    // Funzione per eliminare e restituire l'oggetto da uno specifico stack
    int pop(unsigned int stackIndex) {
        // Verifica se l'indice dello stack è valido
        if (stackIndex < numStacks) {
            // Chiamata alla funzione pop dello stack corrispondente
            return stacks[stackIndex].pop();
        } else {
            std::cerr << "Indice dello stack non valido." << std::endl;
            return -1; // Valore sentinella per indicare uno stack non valido
        }
    }

    // Funzione per verificare se uno specifico stack è vuoto
    bool isStackEmpty(unsigned int stackIndex) const {
        // Verifica se l'indice dello stack è valido
        if (stackIndex < numStacks) {
            // Chiamata alla funzione isEmpty dello stack corrispondente
            return stacks[stackIndex].isEmpty();
        } else {
            std::cerr << "Indice dello stack non valido." << std::endl;
            return true; // Considera uno stack non valido come vuoto
        }
    }
};

int main() {
    // Creazione di una istanza di MultipleStack con 3 stack
    MultipleStack multiStack(3);

    // Inserimento di valori negli stack
    multiStack.push(5, 0);
    multiStack.push(10, 1);
    multiStack.push(15, 2);

    // Pop dagli stack
    std::cout << "Pop dallo stack 0: " << multiStack.pop(0) << std::endl;
    std::cout << "Pop dallo stack 1: " << multiStack.pop(1) << std::endl;
    std::cout << "Pop dallo stack 2: " << multiStack.pop(2) << std::endl;

    // Verifica se gli stack sono vuoti
    std::cout << "Lo stack 0 è vuoto: " << (multiStack.isStackEmpty(0) ? "true" : "false") << std::endl;
    std::cout << "Lo stack 1 è vuoto: " << (multiStack.isStackEmpty(1) ? "true" : "false") << std::endl;
    std::cout << "Lo stack 2 è vuoto: " << (multiStack.isStackEmpty(2) ? "true" : "false") << std::endl;

    return 0;
}
