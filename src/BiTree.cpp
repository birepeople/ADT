//
// Created by birdpeople on 2020/10/26.
//

#include "../inc/BiTree.h"

/*the node structure is about:
 * typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild, *parent;
}BiTNode, *BiTree;
*/

Status InitBiTree(BiTree &T)
{
    if(!T)
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T)
            return false;
    }
    T ->data = 0;
    T ->parent = nullptr;
    T ->lchild = nullptr;
    T -> rchild = nullptr;
    return true;
}

Status DestroyBiTree(BiTree &T)
{
    if(!T||!BiTreeEmpty(T))
        return false;
    if(T->lchild != nullptr)
        DestroyBiTree(T->lchild);
    if(T->rchild!=nullptr)
        DestroyBiTree(T->rchild);
    free(T);
    T = nullptr;// This is of mush significance.
    return true;
}

Status PreCreateBiTree(BiTree &T)
{
    ElemType tmp;
    cin >> tmp;
    if(tmp == 0)
        T = nullptr;
    else{
        if(! (T = (BiTNode*)malloc(sizeof(BiTNode))))
            return false;
        InitBiTree(T);
        T -> data = tmp;
        cout<<"add!"<<tmp<<endl;
        PreCreateBiTree(T->lchild);
        if(T->lchild) T->lchild -> parent = T;
        PreCreateBiTree(T->rchild);
        if(T->rchild) T->rchild -> parent = T;
    }
    return true;
}
void Create(BiTNode* &T)
{
    ElemType e;
    cin >> e;
    if(!e)
        return;
    Create(T->lchild);
    Create(T->lchild);
}

Status CopyBiTreeNode(BiTNode* T,BiTNode *&New){
    if(!T)
    {
        New = nullptr;
        return true;
    }
    if(!InitBiTree(New)) return false;
    New ->data = T ->data;
    if(!CopyBiTreeNode(T->lchild,New->lchild)) return false;
    if(!CopyBiTreeNode(T->rchild,New->rchild)) return false;
    if(New->rchild) New->lchild->parent = New;
    if(New->lchild) New->rchild->parent = New;

    return true;

}
Status CopyBiTree(BiTree T, BiTree & New)
{
    if(BiTreeEmpty(T))
    {
        New = nullptr;
        return false;
    }
    return CopyBiTreeNode(T,New);
}

Status InPostCreateBiTree(BiTree &T)
{

}

Status PreInCreateBiTree(BiTree &T)
{

}

bool BiTreeEmpty(BiTree T)
{
    if(!T)
        return true;
    if(T -> data != 0)
        return false;
    return T->rchild == nullptr && T->lchild == nullptr;
}

bool IsInBiTree(BiTree T, BiTNode *e)
{
    if(!T || !e)
        return false;
    stack<BiTNode*> RecursiveStack;
    RecursiveStack.push(T);
    while(!RecursiveStack.empty())
    {
        BiTNode* ActiveNode = RecursiveStack.top();RecursiveStack.pop();
        if(e == ActiveNode) return true;
        if(ActiveNode->rchild) RecursiveStack.push(ActiveNode->rchild);
        if(ActiveNode->lchild) RecursiveStack.push(ActiveNode->lchild);
    }
    return false;
}

int NodeDepth(BiTNode* T)
{
    if(!T)
        return 0;
    int ans = 0;
    ans = max(NodeDepth(T->lchild),NodeDepth(T->rchild)) + 1;
    return ans;
}
int BiTreeDepth(BiTree T)
{
    if(!T)
        return 0;
    return NodeDepth(T);
}

int NodeWidth(BiTNode* T)
{
    if(!T)
        return 0;
    int ans = 0;
    ans = max(NodeWidth(T->lchild),1) + NodeWidth(T->rchild);
    return ans;
}
int BiTreeWidth(BiTree T)
{
    if(!T)
        return 0;
    return NodeWidth(T);
}
int NodeLeaf(BiTNode* T)
{
    if(!T)
        return 0;
    if(!T->rchild && !T->lchild)
        return 1;
    else return NodeLeaf(T->rchild)+NodeLeaf(T->lchild);
}
int BiTreeLeaf(BiTree T)
{
    if(!T)
        return 0;
    return NodeLeaf(T);
}

int NodeLeaf_ChildSlibling(BiTNode* T){
    if(!T)
        return 0;
    if(!T->rchild && !T->lchild)
        return 1;
    return  NodeLeaf_ChildSlibling(T->lchild)+
            NodeLeaf_ChildSlibling(T->rchild)+
            (int)(T->lchild==nullptr);
}

int BiTreeLeaf_ChildSlibling(BiTree T){
    if(!T)
        return 0;
    return NodeLeaf_ChildSlibling(T);
}

int NodeNum(BiTNode* T)
{
    if(!T)
        return 0;
    int ans = 0;
    ans = NodeNum(T->lchild) + NodeNum(T->rchild) + 1;
    return ans;
}
int BiTreeNodeNum(BiTree T)
{
    if(!T)
        return 0;
    return NodeNum(T);
}

BiTNode* BiTreeRoot(BiTNode *e)
{
    if(!e)
        return nullptr;
    while(e ->parent != nullptr)
        e = e -> parent;
    return e;
}
int BiTNodeLevel(BiTNode *e)
{
    if(!e)
        return 0;
    int ans = 0;
    BiTNode* thisNode = e;
    while(thisNode != nullptr)
        ++ans, thisNode = thisNode -> parent;
    return ans;
}

int BiTreeNodeWPL(BiTNode* T)
{
    if(!T)
        return 0;
    return  BiTreeNodeWPL(T->lchild)
            + BiTreeNodeWPL(T->rchild)
            + (T->data) * BiTNodeLevel(T);
}
int BiTreeWPL(BiTree T)
{
    if(!T)
        return 0;
    return BiTreeNodeWPL(T);
}

ElemType BiTreeNodeValue(BiTree T, BiTNode* e)
{
    if(IsInBiTree(T,e))
        return e->data;
    return 0;
}

Status Assign(BiTree T, BiTNode *&e, ElemType assign_data)
{
    if(!T)
        return false;
    if(!IsInBiTree(T,e))
        return false;
    e->data = assign_data;
    return true;
}

BiTNode* Parent(BiTree T, BiTNode* e)
{
    if(!T)
        return nullptr;
    if(!IsInBiTree(T,e))
        return nullptr;
    return e -> parent;
}

BiTNode* LeftChild(BiTree T, BiTNode* e)
{
    if(!T || !IsInBiTree(T,e) || !e)
        exit(ILLEGAL_INPUT);
    return e -> lchild;
}

BiTNode* RightChild(BiTree T, BiTNode* e)
{
    if(!T || !IsInBiTree(T,e) || !e)
        exit(ILLEGAL_INPUT);
    return e -> rchild;
}

BiTNode* LeftSibling(BiTree T, BiTNode* e)
{
    if(!T || !IsInBiTree(T,e) || !e)
        exit(ILLEGAL_INPUT);
    if(! e-> parent)
        return nullptr;
    return e -> parent -> lchild;

}

BiTNode* RightSibling(BiTree T, BiTNode* e)
{
    if(!T || !IsInBiTree(T,e) || !e)
        exit(ILLEGAL_INPUT);
    if(! e-> parent)
        return nullptr;
    return e -> parent -> rchild;
}

Status InsertChild(BiTree T, BiTree C, BiTNode *e, char control[])
{
    if(BiTreeEmpty(T) || BiTreeEmpty(C) || !e)
        return false;
    if(control[0] == 'L' || control[0] == 'l')
    {
        if(e -> lchild && e -> rchild)
            return false;
        if(!e -> lchild)
            e -> lchild = C, C -> parent = e;
        else
            e -> rchild = e-> lchild, e -> lchild = C, C -> parent = e;

        return true;
    }
    else{
        if(e -> lchild && e -> rchild)
            return false;
        if(!e -> rchild)
            e -> rchild = C, C -> parent = e;
        else
            e -> lchild = e-> rchild, e -> rchild = C, C -> parent = e;

        return true;
    }
}

Status DeleteChild(BiTree T, BiTNode *e, char control[])
{
    if(BiTreeEmpty(T) || !IsInBiTree(T,e) || !e)
        return false;
    BiTNode* DeletingNode = (control[0] == 'L' || control[0] == 'l') ? e -> lchild : e -> rchild;
    if(!DeletingNode)
        return false;
    return DestroyBiTree(DeletingNode);

}

BiTree SeparateBiTree(BiTree T, BiTNode *newBiTree)
{
    if(!T)
        return nullptr;
    if(!IsInBiTree(T,newBiTree))
        return nullptr;
    BiTNode* OneChild = newBiTree -> parent -> lchild == newBiTree? newBiTree : newBiTree -> parent -> rchild;
    OneChild = nullptr;
    newBiTree -> parent = nullptr;
    return newBiTree;
}

Status PreOrderTraverse(BiTree T, Status (*visit)(ElemType e))
{
    if(!T)
        return true;
    if(!visit(T->data))
        return false;
    if(PreOrderTraverse(T->lchild,visit)) ;else return false;
    if(PreOrderTraverse(T->rchild,visit)) ;else return false;
    return true;
}

Status InOrderTraverse(BiTree T, Status (*visit)(ElemType e))
{
    if(!T)
        return true;
    if(InOrderTraverse(T->lchild,visit));else return false;
    if(!visit(T->data))
            return false;
    if(InOrderTraverse(T->rchild,visit));else return false;
   return true;
}
Status PostOrderTraverse(BiTree T, Status (*visit)(ElemType e))
{
    if(!T)
        return true;
    if(PostOrderTraverse(T->lchild,visit));else return false;
    if(PostOrderTraverse(T->rchild,visit));else return false;
    if(!visit(T->data))
        return false;
    return true;
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(ElemType e))
{
    queue<BiTNode*> Node;
    Node.push(T);
    while(!Node.empty())
    {
        BiTNode * ActiveNode = Node.front(); Node.pop();
        if(!visit(ActiveNode->data)) return false;
        else
        {
            if(ActiveNode->lchild) Node.push(ActiveNode->lchild);
            if(ActiveNode->rchild) Node.push(ActiveNode->rchild);
        }
    }
    return true;
}

Status print(ElemType e)
{
    cout<<e<<" ";
    return true;
}

Status PrintfElem(BiTNode *e)
{
    if(!e)
        return false;
    printf("%d\n",e->data);
    return true;
}

void PrintBuffer(vector<vector<char>>buffer, int s_TimeDelay)
{
   // system("clear");  //when you want && in unix || linux
    cout<<endl;
    for(int i =0;i<buffer.size();i++) {
        for (int j = 0; j < buffer[i].size(); ++j)
            cout << buffer[i][j];
        cout<<endl;
    }
    sleep(s_TimeDelay);
}

void addChar(ElemType e,pair<int,int> pos, vector<vector<char>>&target)
{
   int y = pos.first;
   int x = pos.second;
    if(e<10)
   {
       target[y*2][x*5] = e + 48;
       return;
   }
   target[y*2][x*5] = (int)e/10 + 48;
   target[y*2][x*5+1] = e % 10 + 48;
}

void addHorizontalLine(pair<int,int> start_pos, pair<int,int> end_pos, vector<vector<char>>&target)
{
    int start_x = start_pos.second-1; int end_x = end_pos.second;
    int y = start_pos.first -1 ;
    for(int i = start_x*5+2 ; i< end_x*5 ;++i)
        target[y*2][i] = '_';
}

void addUpPlumbLine(pair<int,int> pos, vector<vector<char>>&target)
{
    int y = pos.first; int x = pos.second;
    target[y*2-1][x*5] = '|';

}
int PrintfBiTree(BiTree T)
{
    if(!T)
        return 0;

    int Width = BiTreeWidth(T);
    int Depth = BiTreeDepth(T);
    vector<vector<char>> buffer;
    buffer.resize(Depth * 2);
    for(int i =0;i< buffer.size();++i) {
        buffer[i].resize(Width * 5);
        for (int j = 0; j < Width * 5; ++j)
            buffer[i][j] = ' ';
    }
    stack<BiTNode*> RecursiveStack;
    stack<bool> IsRootMarker;
    stack<pair<int,int>> rootPos;
    IsRootMarker.push(true);
    RecursiveStack.push(T);
    rootPos.push(make_pair(0,0));

    int widthIndex = 0; int nodes = 1;
    while(!RecursiveStack.empty())
    {
        BiTNode* ActiveNode = RecursiveStack.top(); RecursiveStack.pop();
        bool ActiveNodeIsRoot = IsRootMarker.top();IsRootMarker.pop();
        pair<int,int> ActivePos = rootPos.top(); rootPos.pop();
        if(ActiveNodeIsRoot)
        {
            addChar(ActiveNode->data, ActivePos,buffer);
            if(nodes>1)
                addUpPlumbLine(ActivePos, buffer);
        }else{
            pair<int,int> HistoryPos = ActivePos;
            ActivePos.second = ++ widthIndex;
            addChar(ActiveNode->data,ActivePos,buffer);
            addHorizontalLine(HistoryPos,ActivePos,buffer);
            addUpPlumbLine(ActivePos,buffer);
        }
        if(ActiveNode -> rchild)
            RecursiveStack.push(ActiveNode->rchild)
                    ,IsRootMarker.push(false)
                    ,rootPos.push(make_pair(ActivePos.first + 1, widthIndex + 1))
                    , ++nodes;

        if(ActiveNode -> lchild)
            RecursiveStack.push(ActiveNode -> lchild)
            ,IsRootMarker.push(true)
            ,rootPos.push(make_pair(ActivePos.first + 1, widthIndex)),
            ++ nodes;


        //PrintBuffer(buffer,1); //with system("clear");
    }
   PrintBuffer(buffer,1);
    return nodes;

}
