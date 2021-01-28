//
// Created by birdpeople on 2020/10/12.
//

#ifndef ADT_CSQQ_H
#define ADT_CSQQ_H
#include "SqL.h"
#define MAXQUEUESIZE = 100;
typedef struct CQueue{
SqList data;
ElemType* rear;
ElemType* front;
} CQueue;

#endif //ADT_CSQQ_H
