#include <iostream>

#include "pilaPuntatore.h"

using namespace std;


int main (){
	pilaPuntatore<int> p;
	
	p.inPila(1);
	p.inPila(2);
	p.inPila(3);
	p.inPila(3);
	
	p.fuoriPila();
	
	p.inPila(4);
	p.inPila(5);
	
	cout << p << endl;

	p.fuoriPila();

	cout << p << endl;
	return 0;
}

