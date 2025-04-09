#ifndef _DICTIONARYEXCEPTION_H
#define _DICTIONARYEXCEPTION_H


struct dictionaryException { };

struct fullDictionaryException : public dictionaryException { };

struct emptyDictionaryException : public dictionaryException { };

struct nonExistentKeyDictionaryException : public dictionaryException { };


#endif // _DICTIONARYEXCEPTION_H
