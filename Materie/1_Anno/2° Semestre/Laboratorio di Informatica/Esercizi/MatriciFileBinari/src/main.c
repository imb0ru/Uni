#include <matrice.h>
int main(){

    Matrice mat1;
    Matrice mat2;
    Matrice mats;

    inizializzare_matrice(&mat1);
    inizializzare_matrice(&mat2);

    scrivere_matrice_su_file_binario(&mat1, "mat.dat");
    scrivere_matrice_su_file_binario(&mat2, "mat.dat");

    mat1 = leggere_matrice_da_file_binario("mat.dat");
    mat2 = leggere_matrice_da_file_binario("mat.dat");

    sommare_due_matrici(&mat1, &mat2, &mats);

    int min_c = trova_min_diff_colonna_matrice(&mats);

    printf("La colonna risultato e': %d\n",min_c);
}
