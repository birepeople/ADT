//
// Created by birdpeople on 2020/10/12.
// Single_LinkList_Stack
//

#ifndef ADT_SLLS_H
#define ADT_SLLS_H
#include "SLL.h"

typedef struct SLLStack{
SLNode *base;
SLNode *top;
}SLLStack;

Status InitSLLStack(SLLStack &S);
Status DeleteSLLStack(SLLStack &S);
Status ClearSLLStack(SLLStack &S);
Status IsSLLSEmpty(SLLStack S);
Status SLLSPush(SLLStack &S);
Status SLLSPop(SLLStack &S);
Status SLLSGetTop(SLLStack S,ElemType &e);
int SLLSLength(SLLStack S);

#endif //ADT_SLLS_H
