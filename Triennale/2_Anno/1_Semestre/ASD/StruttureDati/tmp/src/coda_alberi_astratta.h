#ifndef CODA_ASTRATTA_ALBERI_H_
#define CODA_ASTRATTA_ALBERI_H_
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template< class I, class P >
class coda_astratta {
public:
	typedef I value_type;
	typedef P position;
	virtual position getTesta()const =0;
	virtual position avanticoda(position p)=0;
	virtual void crea_coda()=0;
	virtual bool coda_vuota()=0;
	virtual value_type fuoricoda()=0;
	virtual void incoda(const value_type &a)=0;
	virtual value_type LeggiCoda()const =0;
};

#endif /* CODA_ASTRATTA_ALBERI_H_ */
