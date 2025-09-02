struct Matrice{
    int righe;
    int colonne;
    int** valori;
}typedef Matrice;

void scrivere_righe(struct Matrice* mat,int r);
int leggere_righe(struct Matrice* mat);
void scrivere_colonne(struct Matrice* mat,int c);
int leggere_colonne(struct Matrice* mat);
int leggere_valore(struct Matrice* mat,int r, int c);
void scrivere_valore(struct Matrice* mat,int r,int c,int v);
void sommare_due_matrici(Matrice* mat1, Matrice* mat2, Matrice* mats);
void inizializzare_matrice(Matrice* mat);
void scrivere_matrice_su_file_binario(Matrice* mat, char* nome_file);
Matrice leggere_matrice_da_file_binario(char * nome_file);
int trova_min_diff_colonna(struct Matrice *mat);