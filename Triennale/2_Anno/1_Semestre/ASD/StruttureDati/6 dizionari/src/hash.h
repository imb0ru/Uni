#ifndef _HASH_H
#define _HASH_H

#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;


// FUNZIONI DI HASH

template <class T>
class hashClass{
   public:
	size_t operator() (const T chiave) const;
};


// specializzazione con il tipo float
template<>
class hashClass<float>{
	public:
		size_t operator()(const float chiave) const{
			return (chiave);
		}
};


// specializzazione con il tipo int
template<>
class hashClass<int>{
	public:
		size_t operator()(const int chiave) const{
			return (chiave);
		}
};


// specializzazione con il tipo char
template<>
class hashClass<char>{
	public:
		size_t operator()(const char chiave) const{
			unsigned long valore_hash = 1;
			valore_hash = 31 * valore_hash + chiave;
			return size_t(valore_hash);
		}
};


// specializzazione con il tipo string
template <>
class hashClass<string>{
   public:
	size_t operator()(const string chiave) const {
		unsigned long valore_hash = 0;
		int lunghezza = (int) chiave.length();
		for (int i=0; i<lunghezza; i++)
			valore_hash = 31 * valore_hash + chiave.at(i);
		return size_t(valore_hash);
	}
};


#endif // _HASH_H
