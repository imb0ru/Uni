/*
 * mylib.c
 *
 *  Created on: 5 nov 2022
 *      Author: marco
 */
#include <limits.h>

int searchmax(int n, int v[]){
	static int max = INT_MIN;
	static int i;
	for(i=1;i<n;i++){
		if(max<v[i]) max=v[i];
	}
	return max;
}
int searchmin(int n, int v[]){
	static int min = INT_MAX;
	static int i;
	for(i=1;i<n;i++){
		if(min>v[i]) min=v[i];
	}
	return min;
}
int searchimax(int n, int v[]){
	static int max = INT_MIN;
	static int i;
	for(i=1;i<n;i++){
		if(v[max]<v[i]) max=i;
	}
	return max;
}
int searchimin(int n, int v[]){
	static int min = INT_MAX;
	static int i;
	for(i=1;i<n;i++){
		if(v[min]>v[i]) min=i;
	}
	return min;
}

int sumarrayelem(int n, int v[]){
	static int i=0;
	int s=0;
	for(i=0;i<n;i++){
		s=s+v[i];
	}
	return s;
}

int swaparrayelem(int v[], int n, int m){
	static int temp;
	temp=v[n];
	v[n]=v[m];
	v[m]=temp;
	return v;
}

int ascsortarray(int n, int v[]){
	static int i;
	static int j;
	static int min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=0;j<n;j++) if(v[j]<v[min]) min=j;
		v=swaparrayelem(v, i, min);
	}
	return v;
}

int descsortarray(int n, int v[]){
	static int i;
	static int j;
	static int max;
	for(i=0;i<n-1;i++){
		max=i;
		for(j=0;j<n;j++) if(v[j]>v[max]) max=j;
		v=swaparrayelem(v, i, max);
	}
	return v;
}

char searchvalue(int n, int v[], int val){
	static int i=0;
	static char find='0';
	while(i<n && find=='0'){
		if(v[i]==val) find='1';
		i++;
	}
	return find;
}

int searchivalue(int val, int n, int v[]){
	static int i=0;
	static char find='0';
	while(i<n && find=='0'){
		if(v[i]==val) find='1';
		i++;
	}
	if(find=='1') return i-1;
	else return -1;
}



