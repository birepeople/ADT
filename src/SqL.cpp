//
// Created by birdpeople on 2020/10/10.
//

#include "../inc/SqL.h"
#include "../inc/def.h"

Status InitList(SqList &L)
{
    L.elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) return false;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return true;
}

Status DeleteList(SqList &L)
{
        free(&L);
        return true;
}

Status ListInsert(SqList &L, int i, ElemType e)//put forward
{
    if(i < 1 ||i > L.length+1)
        return false;
    if(L.length >= L.listsize)
    {
        auto newbase = (ElemType*) realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) return false;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
        return true;
    }
    ElemType *insert_posision = &L.elem[i-1];
    for (ElemType* p = &(L.elem[L.length -1]); p >= insert_posision; --p )
        *(p+1) = *p;
    *insert_posision = e;
    ++ L.length;
    return true;
}

Status ListDelete(SqList &L, ElemType* position)
{
    if( (position - L.elem) > L.length )
        return false;
    for(ElemType* i = position; i< ((L.elem)+L.length) ;i++)
        *i = *(i+1);
    *(L.elem + L.length)=0;
    -- (L.length);
    return true;

}

Status PushBack(SqList &L, ElemType e)
{
    if(L.length < L.listsize)
    {
        L.elem[L.length] = e;
        ++ L.length;
        return false;
    }
    else
    {
         auto newbase = (ElemType*) realloc(L.elem, (L.listsize+LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) return false;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ++ L.length;
    L.elem[L.length] = e;
    return true;

}

void MergeSqList(SqList La, SqList Lb, SqList &Lc)
{
    Lc.elem = (ElemType*) malloc(sizeof (ElemType)*(La.length + Lb.length));
    Lc.listsize = La.length + Lb.length;
    Lc.length = 0;
    if(!Lc.elem) return;

    ElemType* pointer_a;
    ElemType* pointer_b;
    pointer_a = La.elem;
    pointer_b = Lb.elem;

    while((Lc.length < Lc.listsize) && (pointer_a <((La.elem)+La.length)) && (pointer_b < ((Lb.elem)+Lb.length)))
        Lc.elem[Lc.length++] = *(pointer_a) < *(pointer_b)? *(pointer_a++):(*(pointer_a) == *(pointer_b++)? *(pointer_a++):*(pointer_b-1));
    while(pointer_b < (Lb.elem+Lb.length))
        Lc.elem[Lc.length++] = *(pointer_b++);
    while(pointer_a < (La.elem+La.length))
        Lc.elem[Lc.length++] = *(pointer_a++);
}

void UniqueSqList(SqList La, SqList Lb, SqList &Lc)
{
    auto TmpList = (SqList*)malloc(sizeof(SqList));
    MergeSqList(La,Lb,*TmpList);
    int offset_c = 0;
    int offset_t = 0;
    while(offset_t < TmpList->length)
    {
        while( Lc.elem[offset_c] < TmpList->elem[offset_t] && ( offset_c < (Lc.length) )) offset_c ++;
        if (Lc.elem[offset_c] == TmpList->elem[offset_t])
            ListDelete( Lc, (Lc.elem)+ offset_c);
        else
            ++ offset_t;
    }
    delete TmpList;
}
void PrintSqList(SqList L)
{
    if(L.length) {
        for (int i = 0; i < L.length; ++i)
            printf("%d%c", L.elem[i], ",\n"[i == L.length - 1]);
    }
    else
        printf("NULL\n");
}
//SL
/*
int main()
{
    SqList *La = (SqList*)malloc(sizeof (SqList));
    SqList *Lb = (SqList*)malloc(sizeof (SqList));
    SqList *Lc = (SqList*)malloc(sizeof (SqList));
    InitList(*La); InitList(*Lb); InitList(*Lc);

    int La_elem[10] = {2,2,3,5,6,7,8,9,11,11};
    int Lb_elem[10] = {1,2,3,4,7,8,9,10,11,13};
    int Lc_elem[10] = {1,1,2,3,3,12,13,14,15,16};
    for(int i = 0; i<10; ++i)
    {
        PushBack(*La,La_elem[i]);
        PushBack(*Lb,Lb_elem[i]);
        PushBack(*Lc,Lc_elem[i]);
    }
    UniqueSqList(*La,*Lb,*Lc);
    for (int i = 0; i < Lc->length; ++i)
        printf("%d,", Lc-> elem[i]);

    return 0;
}

complexity： O( O(ListDelete)*(Lc.length) + Lb.length + La.length)
*/
