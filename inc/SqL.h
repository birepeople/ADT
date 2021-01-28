//
// Created by birdpeople on 2020/10/10.
// Sequence_List
//

#ifndef ADT_SQL_H
#define ADT_SQL_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "def.h"

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

Status InitList(SqList &L);
Status DeleteList(SqList &L);
Status ListInsert(SqList &L, int i, ElemType e);//put forward (just here i !);
Status ListDelete(SqList &L, ElemType* position);
Status PushBack(SqList &L, ElemType e);


void MergeSqList(SqList La, SqList Lb, SqList &Lc);
void UniqueSqList(SqList La, SqList Lb, SqList &Lc);
void PrintSqList(SqList L);


#endif //ADT_SQL_H
//SL.h
