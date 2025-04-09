/*
 ============================================================================
 Name        : FileCountparole2.c
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

    char c;
    int caratteri, parole, linee;

	file = fopen("testo.txt", "r");

    if (file == NULL){
        printf("\nImpossibile aprire il file.\n");
        exit(EXIT_FAILURE);
    }

    caratteri = parole = linee = 0;
    while ((c = fgetc(file)) != EOF){
        if (c != ' ' && c != '\t' && c != '\n' && c != '\0' && c!=EOF)
        	caratteri++;

        if (c == '\n' || c == '\0')
            linee++;

        if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
            parole++;
    }
    if (c == EOF){
        parole++;
        linee++;
    }

    if(caratteri==0)
    	parole=0;

    printf("Totale caratteri = %d\n", caratteri);
    printf("Totale parole      = %d\n", parole);
    printf("Totale linee      = %d\n", linee);


    fclose(file);

    return 0;
}


