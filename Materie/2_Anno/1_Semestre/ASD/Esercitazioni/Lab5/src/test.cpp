#include <iostream>
#include "listapuntatore.cpp"
#include "listaordinata.cpp"

int main() {
    // Creazione di una listaPuntatore
    listaPuntatore<int> listaP;
    listaP.insLista(3, listaP.primoLista());
    listaP.insLista(1, listaP.primoLista());
    listaP.insLista(4, listaP.primoLista());
    listaP.insLista(2, listaP.primoLista());

    std::cout << "Lista non ordinata:" << std::endl;
    std::cout << listaP;

    // Creazione di una listaOrdinata a partire dalla listaPuntatore
    listaOrdinata<int> listaO(listaP);

    std::cout << "\nLista ordinata:" << std::endl;
    std::cout << listaO;

    // Test del metodo di inserimento ordinato
    listaO.inserisciOrdinato(5);
    std::cout << "\nDopo inserimento di 5:" << std::endl;
    std::cout << listaO;

    // Test del metodo di rimozione ordinato
    listaO.rimuoviOrdinato(2);
    std::cout << "\nDopo rimozione di 2:" << std::endl;
    std::cout << listaO;

    // Test del metodo di ricerca ottimale
    int elementoDaCercare = 4;
    listaPuntatore<int>::posizione posizioneCercata = listaO.cercaElemento(elementoDaCercare);
    if (posizioneCercata != nullptr) {
        std::cout << "\nElemento " << elementoDaCercare << " trovato in posizione " << posizioneCercata << std::endl;
    } else {
        std::cout << "\nElemento " << elementoDaCercare << " non trovato nella lista ordinata." << std::endl;
    }

    // Test del metodo di fusione di due liste ordinate
    listaPuntatore<int> listaP2;
    listaP2.insLista(6, listaP2.primoLista());
    listaP2.insLista(7, listaP2.primoLista());
    listaP2.insLista(8, listaP2.primoLista());

    listaOrdinata<int> listaO2(listaP2);
    std::cout << "\nSeconda lista ordinata:" << std::endl;
    std::cout << listaO2;

    listaOrdinata<int> listaFusa = listaO.fondaListeOrdinate(listaO2);
    std::cout << "\nLista ordinata fusa:" << std::endl;
    std::cout << listaFusa;

    return 0;
}
