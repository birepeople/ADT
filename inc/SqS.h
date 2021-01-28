//
// Created by birdpeople on 2020/10/10.
// Sequence_Stack
//

#ifndef ADT_SQS_H
#define ADT_SQS_H
#include "SqL.h"

typedef struct {
ElemType *base;
ElemType *top;
int stacksize;
}SqStack;

Status InitSqStack(SqStack &S);
Status DeleteSqStack(SqStack &S);
Status ClearSqStack(SqStack &S);
Status IsSqSEmpty(SqStack S);
Status SqSPush(SqStack &S);
Status SqSPop(SqStack &S);
Status SqSTranverse(SqStack S,Status (*visit()));
Status SqSGetTop(SqStack S, ElemType &e);
int SqSLength(SqStack S);

#endif //ADT_SQS_H

