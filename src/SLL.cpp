//
// Created by birdpeople on 2020/10/11.
//
#include "../inc/SLL.h"

Status SLListInsert(SLinkList &L, int i, ElemType e)//Insert just here ,if insert at pos = 1, then the header change!
{
    if(!L)
        return false;
    int length = SLListGetLength(L);
    if(i > length || i <= 0)
        return false;

    SLNode *SLNodeCreate = (SLNode*)malloc(sizeof(SLNode));
    if(! SLNodeCreate)
        return false;

    if(i > 1)
    {
        SLNode * pos = SLGetElem(L,i-1);
        SLNodeCreate ->next = pos -> next;
        pos -> next = SLNodeCreate;
        pos -> next = SLNodeCreate;
    } else{
        SLNodeCreate ->next = L;
        SLNodeCreate ->data = e;
        L = SLNodeCreate;
    }
    return true;
}

Status SLListDelete(SLinkList &L, int i, ElemType &e)
{
    SLNode *Node = SLGetElem(L,i);
    if(!Node) return false;
    if(i>1)
    {
        SLNode * Node_Prior = SLGetElem(L,i-1);
        Node_Prior ->next = Node ->next;
        e = Node -> data;
        free(Node);
    }
    else{
        L = Node ->next;
        e = Node ->data;
        free(Node);
    }
 return true;
}

Status SLListPushBack(SLinkList &L, ElemType e)
{
    SLNode * SLNodeCreate = (SLNode*) malloc(sizeof(SLNode));
    if(!SLNodeCreate)
        return false;
    SLNodeCreate -> next = NULL;
    SLNodeCreate -> data = e;
    SLGetTailor(L) -> next = SLNodeCreate;
    return true;
}

Status InitSLList(SLinkList &L)
{
    if (!L)
        return false;
    L->data = 0;
    L->next = NULL;
    return true;
}

Status DeleteSLList(SLinkList &L)
{
    if(!L)
        return false;
    SLNode* Next = L;
    while(SLNodeNext(Next,L))
    {
        free(L);
        L = Next;
    }
    free(L);
    return true;
}

Status SLNodeNext(SLNode* &La,SLNode *L)
{
    if(L == NULL || L ->next == NULL)
        return false;
    La = L->next;
    return true;
}//notice! La is a outside pointer!!

SLNode* SLGetElem(SLinkList L, int i)
{
    if(!L)
        return NULL;
    int length = SLListGetLength(L);
    if(i>length)
        return NULL;
    SLNode* pos = L;
    for(int index =1; index <i; ++index )
        SLNodeNext(pos,pos);
    return pos;
}

SLNode* SLGetTailor(SLinkList L)
{
    SLNode* Pos = L;
    if(!L)
        return NULL;
    while(SLNodeNext(Pos,Pos));
    return Pos;
}

int SLListGetLength(SLinkList L)
{
    SLNode* Pos = L;
    int ans = 1;
    if(!L)
        return 0;
    else
        while(SLNodeNext(Pos,Pos))
            ++ans;
    return ans;
}

Status ScanfPushBackSLList(SLinkList &L,int n)
{
    L = (SLinkList) malloc(sizeof(SLNode));
    if(!L)
        return false;
    InitSLList(L);
    cin >> L->data;
    SLNode * now = L;
    for(int i = 1; i<n ;++i)
    {

        SLNode* Pos = (SLNode*) malloc(sizeof(SLNode));
        if(!InitSLList(Pos)) return false;
        cin >> Pos ->data;
        now ->next = Pos;
        now = Pos;
    }
    return true;

}

void PrintSLList(SLinkList L)
{
    if(!L)
    {
        printf("NULL"); return;
    }
    SLNode *Pos = L;
    printf("%d",Pos->data);
    while(SLNodeNext(Pos,Pos))
        printf("%d%c",Pos->data,",\n"[Pos->next==NULL]);
}
//SLL