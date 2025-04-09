#ifndef _BUCKET_H
#define _BUCKET_H

#include <iostream>

using namespace std;


template <class K, class V>
class bucket{
   public:
	typedef K chiave;
	typedef V valore;
	bucket() { this->eliminato = false; } ;
	bucket(chiave c, valore v) : _chiave(c), _valore(v) { this->eliminato = false; };
	~bucket(){ };
	void setChiave(chiave c) { this->_chiave = c; };
	void setValore(valore v) { this->_valore = v; };
	chiave getChiave() const { return this->_chiave; };
	valore getValore() const { return this->_valore; };
	bool isEliminato() const { return this->eliminato; };
	void setEliminato(bool e) {this->eliminato = e;};
	friend ostream& operator<<(ostream& os, const bucket& b){
		return os << "<"<<b._chiave<<">:<"<<b._valore<<">";
	}
	friend ostream& operator<<(ostream& os, const bucket* b){
		return os << "<"<<b->_chiave<<">:<"<<b->_valore<<">";
	}
   private:
	chiave _chiave;
	valore _valore;
	bool eliminato;
};


#endif // _BUCKET_H
