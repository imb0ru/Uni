#ifndef _QUEUEEXCEPTION_H
#define _QUEUEEXCEPTION_H


struct queueException{};

struct emptyQueueException : public queueException {};

struct fullQueueException : public queueException {};


#endif // _QUEUEEXCEPTION_H
