/*
 ============================================================================
 Name        : FileCountWords1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * file;

	char c, n;
	int parole, fineparola=1;

	file = fopen("testo.txt", "r");

	if (file == NULL){
		printf("\nImpossibile aprire il file.\n");
		exit(EXIT_FAILURE);
	}

	parole = 0;
	c=fgetc(file);
	while (c != EOF){
		if ((c == ' ' || c == '\n') && fineparola==0)
				parole++;
		else if(c != ' ' && c != '\n')
			fineparola=0;

		n=fgetc(file);

	}

	if (c == EOF)
		parole++;

	printf("Totale parole = %d\n", parole);

	fclose(file);

	return 0;
}


