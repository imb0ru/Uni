#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LunghezzaSequenza();
int LunghezzaSequenza(){
	int c=0;
	char l;
	FILE *fp = fopen("/input.txt","r");
	while((l=fgetc(fp))!='\n' && l!=EOF)
		c=c+1;

	fclose(fp);
	return c;
}

int checkSequenza(char* sequenza, int c);
int checkSequenza(char* sequenza, int c){
	int esito=1;
	int pos=0;
	int posmax=c-1;
	while(pos<c/2 && esito){
		if(sequenza[pos]==sequenza[posmax]){
			pos=pos+1;
			posmax=posmax-1;
		}else esito=0;
	}
	return esito;
}

int main(void) {
	int c,i,p=0;
	c=LunghezzaSequenza()-1;
	FILE *fp = fopen("/input.txt","r");
	char *sequenza=calloc(c+1,sizeof(char));
	char b;

	while(b!='\n' && b!=EOF){
		b=fgetc(fp);
		sequenza[p]=b;
		p=p+1;
	}
	while(i<=c){
		printf("%c",sequenza[i]);
		i=i+1;
	}
	if (c==0){
		printf("il file e' vuoto\n");
		system ("pause");
	}else{
		if (checkSequenza(sequenza,c)==1) printf("palindroma \n");
		else printf ("non palindroma \n");
		system("pause");
		return EXIT_SUCCESS;
	}
}
