// Created by birdpeople on 2020/10/5.
// Let "0" "even number","odd number" be three kinds of Elem,
//   which will be test in function: JudgeElem();
//


#include "../inc/CDLL.h"

CDLinkList InitCDList(CDLinkList &L)
{
    L -> data = 0;
    L -> freq = 0;
    L -> next = L;
    L -> prior = L;
    return L;
}

CDLNode* CDLGetElem( CDLinkList L, int i)

{
    CDLNode * pos = L ;
    int j = 1;
    while(pos && j<i)
    {
        pos = pos -> next; ++j;
    }
    return pos;
}

Status CDListInsert(CDLinkList &L, int i, ElemType e)//i can > AbsLength, whatever
{
    if(!L) return false;
    CDLNode* p = CDLGetElem(L, i);
    CDLNode* InserEele = (CDLinkList) malloc(sizeof(CDLNode));
    if(!InserEele) return false;
    InserEele-> data = e;
    InserEele -> next = p; p -> prior ->next = InserEele;
    InserEele -> prior = p-> prior; p ->prior = InserEele;
    InserEele ->freq = 0;
    return true;

}

Status CDListPushBack(CDLinkList &L, int i, ElemType e)
{
    CDLinkList p = CDLGetElem(L, i);
    CDLNode* InserEle = (CDLinkList) malloc(sizeof(CDLNode));
    if(!InserEle) return false;
    InserEle-> data = e;
    InserEle -> prior = p; p -> next ->prior = InserEle;
    InserEle -> next = p-> next; p ->next = InserEle;
    InserEle ->freq = false;
    return true;

}

Status CDListDelete(CDLinkList &L, int i ,ElemType &e)
{

    CDLinkList p = CDLGetElem(L, i);
    e = p -> data;
    p -> prior -> next = p ->next;
    p -> next -> prior = p ->prior;
    free(p);
   return true;
}

int GetAbsLength(CDLinkList L)
{
    int result = 0;
    CDLNode* pos = L;
    while((pos -> next) != L)
    {
        pos = pos -> next;
        result ++;
    }
    return result + 1;
}

CDLNode* CDLGetTailor(CDLinkList L)
{

    CDLNode* pos = L;
    while((pos -> next) != L)
        pos = pos -> next;
    return pos;

}

Status DeleteCDList(CDLinkList &L)
{
    CDLNode* Prior = CDLGetTailor(L);
    CDLNode* Prior_prior = Prior->prior;
    while( Prior_prior != L)
    {
        Prior_prior = Prior->prior;
        free(Prior);
        Prior = Prior_prior;
    }
    free(L);
    return true;
}

Status SwapCDLNode(CDLNode &La , CDLNode &Lb)
{
    if(&La == &Lb)
        return false;
    if(GetAbsLength(&La)<=2)
        return false;
    else{
        CDLNode* Pr_a; CDLNode* Ne_a;
        CDLNode* Pr_b; CDLNode* Ne_b;
        Pr_a = La.next ; Ne_a = La.prior;
        Pr_b = Lb.next ; Ne_b = Lb.prior;

        Pr_a->prior = &Lb; Ne_a->next = &Lb;
        Pr_b->prior = &La; Ne_b->next = &La;

        CDLNode* Pr; CDLNode* Ne;
        Ne = La.next; La.next = Lb.next; Lb.next = Ne;
        Pr = La.prior; La.prior = Lb.prior; Lb.prior = Pr;
    }
    return true;
}

CDLNode* CDLLocate(CDLinkList &L, ElemType e)
{
    CDLNode* pos = L;
    if (pos->data ==e)
    {
        L->freq++;
        return L;
    }
    while((pos->data != e) && (pos -> next != L))
        pos = pos->next;

    if(pos->data!=e)
        return NULL;

    pos->freq ++;

    CDLNode* upbound_freqNode = L;
    while(upbound_freqNode->freq >= pos->freq && upbound_freqNode ->next != L)
        upbound_freqNode = upbound_freqNode->next;

    while( pos->prior != upbound_freqNode)
        SwapCDLNode(*pos,*pos->prior);

    SwapCDLNode(*pos,*pos->prior);
    if(pos->freq > L->freq)
        L = pos;
    return pos;

}
Status ScanfPushBackCDList(CDLinkList &L,int n)
{
    L = (CDLinkList)malloc(sizeof(CDLNode));
    if(!L)
        return false;
    InitCDList(L);
    cin >> L->data;
    int da = 0;
    for(int i = 1; i < n; i++)
    {
        cin >> da;
        if(!CDListPushBack(L,i,da))
            return false;
    }
return true;
}

Status ScanfFrontCDList(CDLinkList &L,int n)
{
    L = (CDLinkList)malloc(sizeof(CDLNode));
    if(!L)
        return false;
    InitCDList(L);
    cin >> L->data;
    int da = 0;
    for(int i = 1; i < n; i++)
    {
        cin >> da;
        if(!CDListInsert(L,1,da))
            return false;
    }
return true;
}
void PrintCDList(CDLinkList L)
{
    int length = GetAbsLength(L);
    CDLNode* pos = L;
    for(int i = 0;i < length; i++)
    {
        printf("%d%c", pos->data, ",\n"[i == length-1]);
        pos = pos->next;
    }
}

ElemType JudgeElem(CDLNode* La)
{
    if(La -> data==0 )
        return 0;
    if (La -> data % 2 ==0)
        return 2;
    if(La -> data % 2 !=0)
        return 1;

    return 0;
}

Status RemoveMergeCDLNode(CDLNode* &La, CDLinkList &L)
{
    if( La == NULL)
        return false;
    if (L == NULL)
    {
        La ->next ->prior = La ->prior;
        La ->prior -> next = La ->next;
        L = La;
        int freq = L->freq;
        int da = L->data;
        InitCDList(L);
        L ->data = da;
        L ->freq = freq;
        return true;
    }
    else
    {
        CDLNode * Pr;
        CDLNode*  Ne;
        Pr = La ->next; Ne = La ->prior;
        Pr ->prior = Ne;
        Ne ->next = Pr;
        CDLNode* pos = CDLGetTailor(L) ;
        CDLNode* Pr_pos = pos->next;
        Pr_pos ->prior = La ; La ->next = Pr_pos;
        pos->next = La; La ->prior = pos;
        return true;
    }
}

void SeparateCDList(CDLinkList &L, CDLinkList &La, CDLinkList &Lb, CDLinkList &Lc)
{
    La = NULL; Lb = NULL; Lc = NULL;
    CDLNode* pos = L;
    CDLNode* pos_next = NULL ;
    int length = GetAbsLength(L);
    int index = 0;
    while (index++ < length)
    {
        pos_next = pos ->next;

        switch( JudgeElem (pos) ){
            case(0):
                RemoveMergeCDLNode(pos, La);
                break;
            case(1):
                RemoveMergeCDLNode(pos, Lb);
                break;
            case(2):
                RemoveMergeCDLNode(pos, Lc);
                break;
        }

        pos = pos_next;
    }
}
//CDLL.cpp

/*
int main()
{
    CDLinkList Test;
    ScanfFrontCDList(Test,10);
    CDLinkList Test1;
    CDLinkList Test2;
    CDLinkList Test3;
    separateCDList(Test,Test1, Test2,Test3);
    PrintCDList(Test1);
    PrintCDList(Test2);
    PrintCDList(Test3);

}
*/

