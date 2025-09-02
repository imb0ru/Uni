#include "studente.h"

Studente::Studente() : matricola(0), nome(""), cognome(""), eta(0) {}

void Studente::inserisciStudente(int matricola, const std::string& nome, const std::string& cognome, int eta) {
    if (validaMatricola(matricola) && validaNomeCognome(nome) && validaNomeCognome(cognome) && validaEta(eta)) {
        this->matricola = matricola;
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    } else {
        std::cerr << "Dati non validi. Inserimento studente fallito." << std::endl;
    }
}

void Studente::stampaStudente() const {
    std::cout << "Matricola: " << matricola << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Cognome: " << cognome << std::endl;
    std::cout << "Eta: " << eta << std::endl;
}

bool Studente::validaMatricola(int matricola) const {
    return (matricola >= 255312 && matricola <= 499999);
}

bool Studente::validaNomeCognome(const std::string& nome) const {
    return (nome.length() <= 30);
}

bool Studente::validaEta(int eta) const {
    return (eta >= 12 && eta <= 105);
}
