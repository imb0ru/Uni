#ifndef _TREEEXCEPTION_H
#define _TREEEXCEPTION_H


struct treeException { };

struct invalidPositionException : public treeException { };

struct notEmptyTreeException : public treeException { }; 

struct invalidDimensionException : public treeException { };


#endif // _TREEEXCEPTION_H
