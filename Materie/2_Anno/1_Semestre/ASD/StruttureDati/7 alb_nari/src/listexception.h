#ifndef _LISTEXCEPTION
#define _LISTEXCEPTION

#include <iostream>


class listException{
   public:
	listException () : message("List Exception") {};
	listException (string customMessage) { message = customMessage; };
	void printMessage () { std::cout << message << std::endl; }; 
   private:
	string message;
};


class emptyListException : public listException{
	public:
		emptyListException() : listException("Empty List Exception") {};
};


class fullListException : public listException{
	public:
		fullListException() : listException("Full List Exception") {};
};


class indexOutOfRangeListException : public listException{
	public:
		indexOutOfRangeListException() : listException("Index Out Of Range List Exception") {};
};


#endif // _LISTEXCEPTION
