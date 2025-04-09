#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int controllare_validita_carattere(int numero, int base) {
	int esito = 0;

	if(numero >= 0 && numero <= base - 1) esito = 1;

	return esito;
}

int convertire_numero_in_decimale(char *stringa, int base) {
	int lunghezza = strlen(stringa);
	int numero = 0;
	int i = 0;
	while (i < lunghezza){
		if (!controllare_validita_carattere(stringa[i] - '0', base)) {
			numero = -1;
		}else{
			int cifra = stringa[i] - '0';
			numero = numero + cifra * pow(base, lunghezza - i - 1);
		}
		i = i + 1;
	}
	return numero;
}

int main() {
	FILE *fp;
	char *riga = NULL;
	size_t lunghezza = 0;
	ssize_t esito_lettura;
	int base;
	int massimo = 0;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		perror("Errore apertura file");
		exit(EXIT_FAILURE);
	}

	// Leggi la base
	printf("Inserire la base dei valori presenti nel file: ");
	scanf("%d", &base);

	// Leggi la stringa e calcola il massimo
	if ((esito_lettura = getline(&riga, &lunghezza, fp)) != -1) {
		char *token;
		token = strtok(riga, "-");
		while (token != NULL) {
			int num = convertire_numero_in_decimale(token, base);
			if (num == -1) {
				massimo = -1;
				token = NULL;
			}else if (num > massimo) {
				massimo = num;
				token = strtok(NULL, "-");
			}
		}
	}

	fclose(fp);
	if (riga) {
		free(riga);
	}

	printf("Il massimo valore in base 10 nella stringa è %d\n", massimo);
	return 0;
}
