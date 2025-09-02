#include "matrice.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>  // Per includere la libreria che contiene la funzione random
#include <ctime>
// costruttore
matrice::matrice(int r, int c){
	colonne = c;
	righe = r;

	int i,j;

	elementi = new tipoelem* [righe];
	for (i=0; i < righe; i++)
		elementi[i] = new tipoelem[colonne];

	for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=0;
}

// costruttore di copia
matrice::matrice(const matrice &m){
	righe = m.righe;
	colonne = m.colonne;
	int i,j;
	elementi = new tipoelem* [righe];
	for (i=0; i < righe; i++)
		elementi[i] = new tipoelem[colonne];
	for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=m.elementi[i][j];

}

matrice::~matrice(){
	for (int j=0; j<colonne; j++)
		delete[] elementi[j];
	delete [] elementi;
}

matrice &matrice::operator=(const matrice &m){
	// evita gli auto assegnamenti
	if (this == &m) return *this;
	else {
		int i,j;
		if (colonne != m.colonne || righe != m.righe){
			this->~matrice();
			colonne = m.colonne;
			righe = m.righe;
			elementi = new tipoelem* [righe];
			for (i=0; i < righe; i++)
				elementi[i] = new tipoelem[colonne];
		}
		for (i=0;i<righe;i++)
			for (j=0;j<colonne;j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return *this;
}

tipoelem matrice::leggimatrice(int r, int c) const {
	return elementi[r][c];
}

void matrice::scrivimatrice(int r, int c, tipoelem e){
	elementi[r][c] = e;
}

void matrice::prodottoScalare(double c){
	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = c * elementi[i][j];
}

matrice matrice::trasposta(){
	matrice T(colonne,righe);

	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			T.scrivimatrice(j,i, elementi[i][j]);
	return T;
}

void matrice::stampa(){
	std::cout << std::endl;
	for (int i=0; i<righe; i++){
		std::cout << std::endl;
		for (int j=0; j<colonne; j++)
			std::cout << elementi[i][j] << " ";
	}
	std::cout << std::endl;
}

void matrice::rand(){
    std::srand(std::time(0));

	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = std::rand() % 100;
}

matrice matrice::prodottoMatrici(const matrice &m) const {
    if (colonne != m.righe) {
        std::cerr << "Errore: Le dimensioni delle matrici non sono compatibili per il prodotto." << std::endl;
        return matrice(0, 0); // Restituisce una matrice vuota
    }

    matrice risultato(righe, m.colonne);
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < m.colonne; ++j) {
            risultato.scrivimatrice(i, j, 0.0);  // Inizializza con zero
            for (int k = 0; k < colonne; ++k) {
                risultato.scrivimatrice(i, j, risultato.leggimatrice(i, j) + elementi[i][k] * m.leggimatrice(k, j));
            }
        }
    }

    return risultato;
}
