#include "matrice.h"

int main() {
    matrice A(3, 2), T(2, 3);
    A.rand();
    A.stampa();
    T = A.trasposta();
    T.stampa();

    matrice B(4, 4);
    B.stampa();
    B = T;
    B.stampa();

    matrice C(2, 2);
    C.rand();
    C.stampa();

    matrice D = A.prodottoMatrici(C);
    D.stampa();

    return 0;
}
