#include "treePt.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void inserisciNodoCasuale(treePt<int>& albero, typename treePt<int>::Node p, int valore) {
    if (albero.isLeaf(p)) {
        albero.insertFirstChild(p, valore);
    } else {
        int rand_child_index = rand() % (albero.numberOfNodes() - 1);
        typename treePt<int>::Node current_child = albero.firstChild(p);

        for (int i = 0; i < rand_child_index; ++i) {
            current_child = albero.nextSibling(current_child);
        }
        albero.insert(current_child, valore);
    }
}

void test(treePt<int>& albero) {
    typename treePt<int>::Node root = albero.readRoot();
    int count_inner_nodes = albero.inner(root);
    cout << "Numero di nodi interni con valore maggiore del padre: " << count_inner_nodes << endl;
}

int main() {
    cout << "----------------------------------------------------------" << endl << endl;

    srand(time(NULL));

    cout << "TEST ALBERO CON NUMERO DI NODI SCELTO DALL'UTENTE E DISPOSTI CASUALMENTE" << endl << endl;

    treePt<int> albero;
    // Chiede il numero di nodi da inserire nell'albero
    int numNodi;
    cout << "Inserisci il numero di nodi da inserire nell'albero: ";
    cin >> numNodi;
    cout << endl;
    // Riempie l'albero con nodi casuali
    for (int i = 0; i < numNodi; ++i) {
        int numero_casuale = rand() % 10;

        if (albero.isEmpty())
            albero.insertRoot(numero_casuale);
        else
            inserisciNodoCasuale(albero, albero.readRoot(), numero_casuale);
    }

    cout << "ALBERO:" << endl;
    albero.printTree();
    cout << endl << endl;

    test(albero);

    cout << "----------------------------------------------------------" << endl << endl;

    return 0;
}
