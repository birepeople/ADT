//
// Created by birdpeople on 2020/10/12.
//
#include "../inc/SLLS.h"

Status InitSLLStack(SLLStack &S)
{
    S.base = (SLNode*)malloc(sizeof(SLNode));
    if(!S.base) return false;
    InitSLList(S.base);
   S.top = S.base;
   return true;
}

Status DeleteSLLStack(SLLStack &S)
{
    if(!IsSLLSEmpty(S)){
        SLNode *now = S.top;
        SLNode *next ;
        while(SLNodeNext(next,now))
            {
                free(now);
                now = next;
            }
        free(now);
        free(&S);
        return true;
    }
    else{
        free(S.base);
        free(&S);
        return true;
    }
}

Status ClearSLLStack(SLLStack &S)
{
    if(IsSLLSEmpty(S))
        return false;
    SLNode* next = S.top;
    while(next != S.base)
    {
        next = S.top ->next;
        free(S.top);
        S.top = next;
    }
    return true;
}

Status IsSLLSEmpty(SLLStack S)
{
    return S.top == S.base;
}

Status SLLSPush(SLLStack &S,ElemType e)
{
    SLNode *Top = (SLNode*) malloc(sizeof(SLNode));
    if(!Top) return false;
    Top ->next = S.top;
    S.top = Top;
    S.top ->data = e;
    return true;
}

Status SLLSPop(SLLStack &S,ElemType &e)
{
    if(IsSLLSEmpty(S))
        return false;
    e = S.top->data;
    SLNode *next = S.top->next;
    free(S.top);
    S.top = next;
    return true;
}

Status SLLSGetTop(SLLStack S,ElemType &e)
{
    if(IsSLLSEmpty(S))
        return false;
    e = S.top ->data;
    return true;
}

int SLLSLength(SLLStack S)
{
    if(IsSLLSEmpty(S))
        return 0;
    int ans = 0;
    SLNode *now = S.top;
    while( now != S.base)
    {
        now = now->next;
        ++ans;
    }
    return ans;
}
//SLLS

