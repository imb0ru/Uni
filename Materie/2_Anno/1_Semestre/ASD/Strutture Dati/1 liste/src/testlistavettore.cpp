/*#include <iostream>
#include "listavettore.h"

using namespace std;

int main() {
    try {
        listaVettore<int> l;

        int a = 2;
        l.insLista(a, l.primoLista());
        int b = 4;
        l.insLista(b, l.succLista(l.primoLista()));
        int c = 7;
        l.insLista(c, l.primoLista());
        int d = 17;
        l.insLista(d, l.succLista(l.primoLista()));
        int e = 1;
        l.insLista(e, l.primoLista());
        int f = 80;
        l.insLista(f, l.primoLista());
        int g = 2;
        l.insLista(g, l.primoLista());

        cout << "Lista dopo l'inserimento:" << endl;
        cout << l << endl;

        cout << "Ultimo elemento in lista: " << l.leggiLista(l.ultimoLista()) << endl;

        cout << "Rimozione dell'ultimo elemento:" << endl;
        l.cancLista(l.ultimoLista());

        cout << "Lista dopo la rimozione:" << endl;
        cout << l << endl;
    } catch (const exception& e) {
        cerr << "Eccezione: " << e.what() << endl;
    }

    return 0;
}
*/
