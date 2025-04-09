#include <iostream>
#include <stack>
#include <queue>
#include <cctype>

bool isOperator(char carattere) {
    return carattere == '+' || carattere == '-' || carattere == '*' || carattere == '/';
}

int precedenzaOperatore(char operatore) {
    switch (operatore) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::queue<char> convertiInPostfissa(const std::string& espressioneInfissa) {
    std::queue<char> espressionePostfissa;
    std::stack<char> operatori;

    for (char carattere : espressioneInfissa) {
        if (std::isdigit(carattere)) {
            espressionePostfissa.push(carattere);
        } else if (isOperator(carattere)) {
            while (!operatori.empty() && precedenzaOperatore(operatori.top()) >= precedenzaOperatore(carattere)) {
                espressionePostfissa.push(operatori.top());
                operatori.pop();
            }
            operatori.push(carattere);
        } else if (carattere == '(') {
            operatori.push(carattere);
        } else if (carattere == ')') {
            while (!operatori.empty() && operatori.top() != '(') {
                espressionePostfissa.push(operatori.top());
                operatori.pop();
            }
            operatori.pop();  // Rimuove la parentesi aperta
        }
    }

    // Svuota gli operatori rimanenti dalla pila
    while (!operatori.empty()) {
        espressionePostfissa.push(operatori.top());
        operatori.pop();
    }

    return espressionePostfissa;
}

int main() {
    std::string espressioneInfissa = "35 + 17 * (40 - 9) - 7";
    std::queue<char> espressionePostfissa = convertiInPostfissa(espressioneInfissa);

    // Stampare l'espressione postfissa
    while (!espressionePostfissa.empty()) {
        std::cout << espressionePostfissa.front() << " ";
        espressionePostfissa.pop();
    }

    return 0;
}
