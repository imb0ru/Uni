#include <iostream>
using namespace std;
#include "N_tree.h"

AlberoPtr<int> riemp_albero(AlberoPtr<int> &albero, int numero_nodi, int numero_livelli) {

	if (albero.alberoVuoto()) {
		albero.inserisciRadice(2);
		albero.insPrimoFiglio(albero.radice(),3);
		albero.insFratelloSuccessivo(albero.primoFiglio(albero.radice()),5);
		albero.insFratelloSuccessivo(albero.fratelloSuccessivo(albero.primoFiglio(albero.radice())),8);
		albero.insPrimoFiglio(albero.primoFiglio(albero.radice()),18);
		albero.insFratelloSuccessivo(albero.primoFiglio(albero.radice()),89);

	}
	return albero;
}


int main() {
	AlberoPtr<int> albero;
	albero=riemp_albero(albero,2,2);
	albero.stampaSottoAlbero(albero.radice());
    int count = albero.inner(albero.radice(), 0);
	std::cout << "Number of internal nodes with value greater than their parent: " << count << std::endl;
	return 0;
}