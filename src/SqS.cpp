//
// Created by birdpeople on 2020/10/10.
//
#include "../inc/SqS.h"

Status InitSqStack(SqStack &S);
Status DeleteSqStack(SqStack &S);
Status ClearSqStack(SqStack &S);
Status IsSqSEmpty(SqStack S);
Status SqSPush(SqStack &S);
Status SqSPop(SqStack &S);
Status SqSTranverse(SqStack S,Status (*visit()));
int SqSLength(SqStack S);

//SQS