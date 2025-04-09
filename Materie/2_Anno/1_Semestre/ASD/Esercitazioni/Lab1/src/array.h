
/* Soluzioni con l'uso di vector */

#include <vector>

using namespace std;

template <typename T>
int greaterThan( vector<T> v, T k){
	int c = 0;
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
		if (*it > k)
			c++;
	return c;
}

template <typename T>
bool member( vector<T> v, T e){
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
		if (*it == e)
			return true;
	return false;
}

template <typename T>
struct rT1{
	T value;
	int pos;
};

template <typename T>
rT1<T> largest( vector<T> v){
	rT1<T> max;
	if (!v.empty()){
		max.value = v[0];
		max.pos = 0;
		int currPos = 0;
		for (typename vector<T>::iterator it = v.begin() + 1; it != v.end(); it++, currPos++)
			if (*it > max.value){
				max.value = *it;
				max.pos = currPos;
			}
	} else
		max.pos = -1;

	return max;
}

// 0 - crescente
// 1 - decrescente
// 2 - costante
// -1 - none
template <typename T>
int ordering( vector<T> v){
	typename vector<T>::iterator it;
	for (it = v.begin(); it != (v.end() - 1) && *it > *(it+1); it++);
	if (it == v.end() - 1)
		return 1;
	if (it == v.begin()){
		for (it = v.begin(); it != (v.end() - 1) && *it < *(it+1); it++);
		if (it == v.end() - 1)
			return 0;
	}
	if (it == v.begin()){
		for (it = v.begin(); it != (v.end() - 1) && *it == *(it+1); it++);
		if (it == v.end() - 1)
			return 2;
	}
	return -1;
}


template <typename T>
void reverse( vector<T> &v){
	typename vector<T>::iterator left, right;
	T tmp;
	for (left = v.begin(), right = v.end() - 1; left != right || left > right; left++, right--){
		tmp = *left;
		*left = *right;
		*right = tmp;
	}
}

template <typename T>
void reverse2( vector<T> &v){
	for (int i = 0; i < (int)v.size() - 1; i++){
		v.push_back( *(v.end()-2-i) );
		v.erase( v.end() - 3 - i );
	}
}
