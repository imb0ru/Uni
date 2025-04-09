#ifndef _TREEEXCEPTION_H
#define _TREEEXCEPTION_H


struct treeException { };

struct emptyTreeException : public treeException { };

struct notEmptyTreeException : public treeException { };

struct notChildrenException : public treeException { };  

struct invalidPositionException : public treeException { };


#endif // _TREEEXCEPTION_H
