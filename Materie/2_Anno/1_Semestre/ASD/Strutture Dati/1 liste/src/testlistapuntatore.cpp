#include <iostream>

#include "listapuntatore.h"

using namespace  std;


int main(){
	listaPuntatore<int> l;
	listaPuntatore<int> r;
	
	r.insLista(10, r.primoLista());
	r.insLista(11, r.primoLista());
	
	l.insLista(10, l.primoLista());
	l.insLista(12, l.primoLista());

	if (r == l){
		cout << "sono uguali" << endl;
	}
	else{
		cout << "non sono uguali" << endl;
	}

	cout << l << endl;
	
	return 0;
}

