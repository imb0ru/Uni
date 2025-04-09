/*
 ============================================================================
 Name        : MinTraMaxRMatrice.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define R 20
#define C 20
int searchMaxR(int v[][C], int r, int nc);

int main(void) {
	int v[R][C];
	int min=INT_MAX;

	for(int r=0;r<R;r++)
		if(searchMaxR(v,r,C)<min)
			min=searchMaxR(v,r,C);

	return 0;
}

int searchMaxR(int v[][C], int r, int nc){
	static int m=INT_MIN;
	for(int c=0;c<nc;c++) if(m<v[r][c]) m=v[r][c];
	return m;
}
