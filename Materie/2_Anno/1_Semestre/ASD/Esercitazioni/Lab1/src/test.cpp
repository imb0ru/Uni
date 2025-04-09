#include "array.h"
#include <iostream>

using namespace std;

int main(){

	/* inizializzazione con una initializer list solo in C++11
		 compilare con opzione -std=c++11
	 */
	vector<int> A = {1,2,3,4,5,6,7,8,9};
	vector<double> B = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};

	cout << "A = {1,2,3,4,5,6,7,8,9}" << endl;

	cout << "B = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9}" << endl << endl;

	cout << "greaterThan(A, 4): " << greaterThan(A, 4) << endl;
	cout << "greaterThan(B, 0.2): " << greaterThan(B, 0.2) << endl << endl;

	cout << "member(A, 6): " << member(A, 6) << endl  << endl;

	rT1<int> r = largest(A);
	cout << "largest(A): [" << r.value << ", " << r.pos << "]" << endl << endl;


	vector<int> C1 = {1,2,3,4,5};
	vector<int> C2 = {5,4,3,2,1};
	vector<int> C3 = {1,1,1,1,1};
	vector<int> C4 = {1,2,1,2,1};

	cout << "C1 = {1,2,3,4,5}" << endl;
	cout << "C2 = {5,4,3,2,1}" << endl;
	cout << "C3 = {1,1,1,1,1}" << endl;
	cout << "C4 = {1,2,1,2,1}" << endl << endl;

	cout << "ordering(C1): " << ordering(C1) << endl;
	cout << "ordering(C2): " << ordering(C2) << endl;
	cout << "ordering(C3): " << ordering(C3) << endl;
	cout << "ordering(C4): " << ordering(C4) << endl << endl;

	reverse(B);
	cout << "reverse(B): ";
	for (int i = 0; i < (int)B.size(); i++)
		cout << B[i] << " ";
	cout << endl;

	reverse2(B);
	cout << "reverse2(B): ";
	for (int i = 0; i < (int)B.size(); i++)
		cout << B[i] << " ";
	cout << endl << endl;

	return 0;
}
