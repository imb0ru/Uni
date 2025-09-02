#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* leggiTestoDaFile(const char* nomeFile);
char* leggiTestoDaFile(const char* nomeFile) {
	FILE* file = fopen(nomeFile, "r");

	if (file == NULL) {
		printf("Impossibile aprire il file %s\n", nomeFile);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	long lunghezzaFile = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* testo = malloc(lunghezzaFile + 1);
	fread(testo, 1, lunghezzaFile, file);
	testo[lunghezzaFile] = '\0';

	fclose(file);

	return testo;
}

void rimuoviAccentati(char* str);
void rimuoviAccentati(char* str) {
	char* accenti = "àèéìòóùÀÈÉÌÒÓÙ";
	char* senza_accenti = "aeeioouAEEIOOU";
	int i=0, j;
	while (i<strlen(str)) {
		j=0;
		while (j<strlen(str)) {
			if (str[i] == accenti[j]) {
				str[i] = senza_accenti[j];
				break;
			}
			j=j+1;
		}
		i=i+1;
	}
}

char * sanitizeTesto(const char* testo, const int lunghezzaTesto);
char * sanitizeTesto(const char* testo, const int lunghezzaTesto){
	char* testoSanitizzato = malloc(lunghezzaTesto + 1);

	int j = 0,i;
	i=0;

	rimuoviAccentati(testoSanitizzato);
	while (i < lunghezzaTesto) {
		if (isalpha(testo[i]))
			testoSanitizzato[j++] = tolower(testo[i]);
		else if(isdigit(testo[i]))
			testoSanitizzato[j++] = testo[i];

		i=i+1;
	}
	testoSanitizzato[j] = '\0';

	return testoSanitizzato;

}

int verificaPalindromo(const char* testo, const int lunghezzaTesto);
int verificaPalindromo(const char* testo, const int lunghezzaTesto) {
	char* testoSanitizzato = malloc(lunghezzaTesto + 1);

	int i;

	testoSanitizzato=sanitizeTesto(testo, lunghezzaTesto);
	int lunghezzatestoSanitizzato = strlen(testoSanitizzato);

	i=0;
	while(i < lunghezzatestoSanitizzato / 2) {
		if (testoSanitizzato[i] != testoSanitizzato[lunghezzatestoSanitizzato - i - 1]) {
			free(testoSanitizzato);
			return 0;
		}
		i=i+1;
	}

	free(testoSanitizzato);
	return 1;
}

int main() {
	char* nomeFile = "input.txt";
	char* testo = leggiTestoDaFile(nomeFile);

	if (testo == NULL) {
		return 1;
	}

	int lunghezzaTesto = strlen(testo);
	int palindromo = verificaPalindromo(testo, lunghezzaTesto);

	if (palindromo) {
		printf("Il testo %s e' palindromo\n", testo);
	} else {
		printf("Il testo %s non e' palindromo\n", testo);
	}

	free(testo);

	return 0;
}
