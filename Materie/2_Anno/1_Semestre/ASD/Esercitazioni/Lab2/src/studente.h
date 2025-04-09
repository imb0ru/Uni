#ifndef STUDENTE_H
#define STUDENTE_H

#include <iostream>
#include <string>

class Studente {
public:
    // Costruttore
    Studente();

    // Funzioni di inserimento e stampa
    void inserisciStudente(int matricola, const std::string& nome, const std::string& cognome, int eta);
    void stampaStudente() const;

private:
    int matricola;
    std::string nome;
    std::string cognome;
    int eta;

    // Funzioni di validazione
    bool validaMatricola(int matricola) const;
    bool validaNomeCognome(const std::string& nome) const;
    bool validaEta(int eta) const;
};

#endif // STUDENTE_H
