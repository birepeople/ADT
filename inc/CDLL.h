//
// Created by birdpeople on 2020/10/10.
// Circulated_double_LinkList
//

#ifndef ADT_CDLL_H
#define ADT_CDLL_H

#include "def.h"
typedef struct CDLNode
{
    ElemType data;
    struct CDLNode *next;
    struct CDLNode *prior;
    int freq;
}CDLNode, *CDLinkList;

Status CDListInsert(CDLinkList &L, int i, ElemType e);
Status CDListPushBack(CDLinkList &L, int i, ElemType e);
Status SwapCDLNode(CDLNode &La , CDLNode &Lb);
Status RemoveMergeCDLNode(CDLNode* &La, CDLinkList &L);
Status CDListDelete(CDLinkList &L, int i ,ElemType &e);
Status DeleteCDList(CDLinkList &L);
Status ScanfPushBackCDLink(CDLinkList &L,int n);
Status ScanfFrontCDLink(CDLinkList &L,int n);

CDLinkList InitCDList(CDLinkList &L);
CDLNode* CDLGetElem( CDLinkList L, int i);//i can greater than Abslength
CDLNode* CDLGetTailor(CDLinkList L);
CDLNode* CDLLocate(CDLinkList &L, ElemType e);
void PrintCDList(CDLinkList L);
void SeparateCDList(CDLinkList &L, CDLinkList &La, CDLinkList &Lb, CDLinkList &Lc);

ElemType JudgeElem(CDLNode* La);
int GetAbsLength(CDLinkList L);

#endif //ADT_CDLL_H
//CDL.h