#include "alberoListaDin.h"
#include <iostream>

int main() {
    alberoListaDin<int> albero;

    // Inserimento della radice
    albero.insRadice(1);

    // Inserimento di nodi e sottoalberi
    alberoListaDin<int> sottoAlbero1, sottoAlbero2, sottoAlbero3;
    sottoAlbero1.insRadice(2);
    sottoAlbero2.insRadice(3);
    sottoAlbero3.insRadice(4);

    albero.insPrimoSottoAlbero(albero.radiceAlbero(), sottoAlbero1);
    albero.insSottoAlbero(albero.radiceAlbero(), sottoAlbero2);
    albero.insSottoAlbero(albero.primoFiglio(albero.radiceAlbero()), sottoAlbero3);

    // Stampa dell'albero
    std::cout << "Albero:" << std::endl;
    std::cout << "Radice: " << albero.radiceAlbero().radice->getElemento() << std::endl;

    auto pos = albero.primoFiglio(albero.radiceAlbero());
    while (pos.radice != nullptr) {
        std::cout << "Figlio di " << albero.padre(pos).radice->getElemento() << ": " << pos.radice->getElemento() << std::endl;
        pos = albero.succFratello(pos);
    }

    return 0;
}
