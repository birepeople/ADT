//
// Created by birdpeople on 2020/10/11.
// Single_LinkList
//

#ifndef ADT_SLL_H
#define ADT_SLL_H
#include "def.h"

typedef struct SLNode
{
    ElemType data;
    struct SLNode *next;
}SLNode, *SLinkList;

Status SLListInsert(SLinkList &L, int i, ElemType e);//Insert just here ,if insert at pos = 1, then the header change!
Status SLListDelete(SLinkList &L, int i, ElemType &e);
Status SLListPushBack(SLinkList &L, ElemType e);
Status InitSLList(SLinkList &L);
Status DeleteSLList(SLinkList &L);
Status SLNodeNext(SLNode* &La,SLNode *L);//notice! La is a outside pointer!!
//this method possess auto-overflow-protection, so one can traverse it by SLNodeNext(pos,pos) as pos = header
Status ScanfPushBackSLList(SLinkList &L,int n);

SLNode* SLGetElem(SLinkList L, int i);
SLNode* SLGetTailor(SLinkList L);

int SLListGetLength(SLinkList L);
void PrintSLList(SLinkList L);


#endif //ADT_SLL_H
