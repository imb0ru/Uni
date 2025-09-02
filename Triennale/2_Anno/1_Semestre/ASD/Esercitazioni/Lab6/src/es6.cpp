#include <iostream>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <vector>

// Definizione di un token
struct Token {
    enum class Tipo { Assegnamento, Operatore, Variabile, Numero, ParentesiApre, ParentesiChiude, FineProgramma };

    Tipo tipo;
    std::string valore;

    Token(Tipo tipo, const std::string& valore) : tipo(tipo), valore(valore) {}
};

// Funzione per suddividere l'input in token
std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    std::istringstream stream(input);
    char carattere;

    while (stream >> carattere) {
        switch (carattere) {
            case '(':
                tokens.emplace_back(Token::Tipo::ParentesiApre, "(");
                break;
            case ')':
                tokens.emplace_back(Token::Tipo::ParentesiChiude, ")");
                break;
            case '=':
                tokens.emplace_back(Token::Tipo::Assegnamento, "=");
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                tokens.emplace_back(Token::Tipo::Operatore, std::string(1, carattere));
                break;
            default:
                if (isalpha(carattere)) {
                    tokens.emplace_back(Token::Tipo::Variabile, std::string(1, carattere));
                } else if (isdigit(carattere)) {
                    std::string numero(1, carattere);
                    while (stream >> carattere && isdigit(carattere)) {
                        numero += carattere;
                    }
                    stream.putback(carattere);
                    tokens.emplace_back(Token::Tipo::Numero, numero);
                }
        }
    }

    tokens.emplace_back(Token::Tipo::FineProgramma, "");
    return tokens;
}

// Definizione di un interprete
class Interprete {
private:
    std::unordered_map<char, int> variabili;

    int valutaEspressione(const std::vector<Token>& espressione) {
        std::stack<int> valori;
        std::stack<char> operatori;

        for (const auto& token : espressione) {
            if (token.tipo == Token::Tipo::Numero) {
                valori.push(std::stoi(token.valore));
            } else if (token.tipo == Token::Tipo::Variabile) {
                valori.push(variabili[token.valore[0]]);
            } else if (token.tipo == Token::Tipo::Operatore) {
                while (!operatori.empty() && precedenzaOperatore(operatori.top()) >= precedenzaOperatore(token.valore[0])) {
                    eseguiOperazione(valori, operatori);
                }
                operatori.push(token.valore[0]);
            } else if (token.tipo == Token::Tipo::ParentesiApre) {
                operatori.push('(');
            } else if (token.tipo == Token::Tipo::ParentesiChiude) {
                while (operatori.top() != '(') {
                    eseguiOperazione(valori, operatori);
                }
                operatori.pop();  // Rimuove la parentesi aperta
            }
        }

        while (!operatori.empty()) {
            eseguiOperazione(valori, operatori);
        }

        return valori.top();
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

    void eseguiOperazione(std::stack<int>& valori, std::stack<char>& operatori) {
        char operatore = operatori.top();
        operatori.pop();

        int secondoOperando = valori.top();
        valori.pop();

        int primoOperando = valori.top();
        valori.pop();

        switch (operatore) {
            case '+':
                valori.push(primoOperando + secondoOperando);
                break;
            case '-':
                valori.push(primoOperando - secondoOperando);
                break;
            case '*':
                valori.push(primoOperando * secondoOperando);
                break;
            case '/':
                valori.push(primoOperando / secondoOperando);
                break;
        }
    }

public:
    int interpreta(const std::string& programma) {
        std::vector<Token> tokens = tokenize(programma);

        // Analizza le istruzioni di assegnamento
        size_t indice = 0;
        while (tokens[indice].tipo == Token::Tipo::ParentesiApre) {
            char variabile = tokens[indice + 1].valore[0];
            indice += 3;  // Salta "(x = "
            std::vector<Token> espressione;

            while (tokens[indice].tipo != Token::Tipo::ParentesiChiude) {
                espressione.push_back(tokens[indice]);
                indice++;
            }

            variabili[variabile] = valutaEspressione(espressione);
            indice += 2;  // Salta ") "
        }

        // Valuta l'espressione principale
        std::vector<Token> espressionePrincipale;
        while (tokens[indice].tipo != Token::Tipo::FineProgramma) {
            espressionePrincipale.push_back(tokens[indice]);
            indice++;
        }

        return valutaEspressione(espressionePrincipale);
    }
};

int main() {
    Interprete interprete;
    std::string programma = " (x = 1) (y = (x + 1)) (((x + y) * 3) + (4 * x))";

    int risultato = interprete.interpreta(programma);
    std::cout << "Il risultato è: " << risultato << std::endl;

    return 0;
}
