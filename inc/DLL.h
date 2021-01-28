//
// Created by birdpeople on 2020/10/13.
// Double_LinkList
//

#ifndef ADT_DLL_H
#define ADT_DLL_H
#include "def.h"
typedef struct DLNode
{
    ElemType data;
    struct DLNode *next;
    struct DLNode *prior;
}DLNode, *DLinkList;

Status DListInsert(DLinkList &L, int i, ElemType e);//Insert just here ,if insert at pos = 1, then the header change!
Status DListDelete(DLinkList &L, int i, ElemType &e);
Status DListPushBack(DLinkList &L, ElemType e);
Status InitDList(DLinkList &L);
Status DeleteDList(DLinkList &L);
Status DLNodeNext(DLNode* &La,DLNode *L);//notice! La is a outside pointer!!
//this method possess auto-overflow-protection, so one can traverse it by SLNodeNext(pos,pos) as pos = header
Status ScanfPushBackDList(DLinkList &L,int n);

DLNode* DLGetElem(DLinkList L, int i);
DLNode* DLGetTailor(DLinkList L);

int DListGetLength(DLinkList L);
void PrintDList(DLinkList L);

#endif //ADT_DLL_H
