#include <iostream>

#include "codaPuntatore.h"

using namespace std;


int main(){
	codaPuntatore<int> c;
	
	c.inCoda(1);
	
	c.inCoda(2);
	
	c.inCoda(3);
	
	c.inCoda(4);
	
	c.inCoda(5);
	
	c.fuoriCoda();

	c.fuoriCoda();
	
	c.fuoriCoda();

	c.inCoda(6);
	
	c.inCoda(7);
		
	cout << c << endl;
	
	return 0;
}

