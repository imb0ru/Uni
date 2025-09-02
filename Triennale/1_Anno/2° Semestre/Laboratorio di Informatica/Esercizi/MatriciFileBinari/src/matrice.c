#include <matrice.h>
#include <stdlib.h>
#include <time.h>

//funzionr dr accesso
void scrivere_righe( Matrice* mat,int r){
    mat->righe = r;
}

int leggere_righe( Matrice* mat){
    int r;
    r = mat->righe;
    return r;
}

void scrivere_colonne(Matrice* mat,int c){
    mat->colonne = c;
}

int leggere_colonne(Matrice* mat){
    int c;
    c = mat->colonne;
    return c;
}

int leggere_valore(Matrice* mat,int r, int c){
    int v;
    v = mat->valori[r][c];
    return v;
}

void scrivere_valore(Matrice* mat,int r,int c,int v){
    mat->valori[r][c] = v;
}

Matrice leggere_matrice_da_file_binario(char * nome_file){
    Matrice mat;

    FILE *fp;

    fp = fopen("mat.dat","rb");
    if(fp == NULL){
            printf("ERRORE Dr APERTURA FILE\n");
            return;
    }

    fread(&mat, sizeof(Matrice), 1, fp);

    fclose(fp);

    return mat;

}

void scrivere_matrice_su_file_binario(Matrice* mat, char* nome_file){

    FILE *fp;

    fp = fopen("mat.dat","ab");
    if(fp == NULL){
            
            printf("ERRORE Dr APERTURA FILE\n");
            return;
    }

    fwrite(&mat, sizeof(Matrice), 1, fp);

    fclose(fp);


}

void inizializzare_matrice(Matrice* mat){

    int r, c;
    time_t t;

    srand((unsigned) time(&t));

    scrivere_righe(mat, rand() % 11);
    scrivere_colonne(mat, rand() % 11);

    r=0;
    while(r<leggere_righe(mat)){
        c=0;
        while(c<leggere_colonne(mat)){
            scrivere_valore(mat, r, c, rand() % 51);
            c=c+1;
        }
        r=r+1;
    }
}

void sommare_due_matrici(Matrice* mat1, Matrice* mat2, Matrice* mats){
    int r, c;

    if((leggere_righe(mat1) == leggere_righe(mat2)) && (leggere_colonne(mat1) == leggere_colonne(mat2))){
        scrivere_righe(mats, leggere_righe(mat1));
        scrivere_righe(mats, leggere_colonne(mat1));

        r=0;
        while(r<leggere_righe(mats)){
            c=0;
            while(c<leggere_colonne(mats)){
            scrivere_valore(mats, r, c, leggere_valore(mat1,r,c)+leggere_valore(mat2,r,c));
            c=c+1;
            }
            r=r+1;
        }
    }else{
        scrivere_righe(mats, 1);
        scrivere_righe(mats, 1);

        r=0;
        while(r<leggere_righe(mats)){
            c=0;
            while(c<leggere_colonne(mats)){
            scrivere_valore(mats, r, c, -1);
            c=c+1;
            }
            r=r+1;
        }  
    }
}

int trova_min_diff_colonna(struct Matrice *mat) {
    int min_diff_colonna;
    int min_diff;
    int c;
    int r;
    int max_diff;
    int diff;


    min_diff_colonna = 0;
    min_diff = abs(leggere_valore(mat,0,0) - leggere_valore(mat,0,1));

    c = 1;
    while (c < leggere_colonne(mat)){
        max_diff = abs(leggere_valore(mat,0,c) - leggere_valore(mat,0,c-1));
        r = 1;
        while (r < leggere_righe(mat)){
            diff = abs(leggere_valore(mat,r,c) - leggere_valore(mat,r,c-1));
            if (diff > max_diff) {
                max_diff = diff;
            }
            r = r + 1;
        }

        if (max_diff < min_diff) {
            min_diff = max_diff;
            min_diff_colonna = c;
        }

        c = c + 1;

    }

    return min_diff_colonna;
}