//
// Created by birdpeople on 2020/10/26.
//Binary_Tree(Trident_Linked_List)
//

#ifndef ADT_BITREE_H
#define ADT_BITREE_H

#define ILLEGAL_INPUT 110
#define EMPTY_TREE 100
#include "def.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <unistd.h>
using namespace std;

typedef struct BiTNode{
ElemType data;
BiTNode *lchild, *rchild, *parent;
}BiTNode, *BiTree;

Status InitBiTree(BiTree &T);
Status DestroyBiTree(BiTree &T);
Status print(ElemType e);
Status PreCreateBiTree(BiTree &T);
Status InPostCreateBiTree(BiTree &T);
Status PreinCreateBiTree(BiTree &T);
Status CopyBiTree(BiTree T, BiTree & New);
Status PreOrderTraverse(BiTree T, Status (*visit)(ElemType e));
Status InOrderTraverse(BiTree T, Status (*visit)(ElemType e));
Status PostOrderTraverse(BiTree T, Status (*visit)(ElemType e));
Status LevelOrderTraverse(BiTree T, Status (*visit)(ElemType e));
Status Assign(BiTree T, BiTNode *&e, ElemType data);
Status InsertChild(BiTree T, BiTree C, BiTNode *e, char control[]);
Status DeleteChild(BiTree T, BiTNode *e, char control[]);
Status PrintfElem(BiTNode *e);

bool BiTreeEmpty(BiTree T);
bool IsInBiTree(BiTree T, BiTNode *e);
int BiTNodeLevel(BiTNode *e);
int BiTreeDepth(BiTree T);
int BiTreeWidth(BiTree T);
int BiTreeLeaf(BiTree T);
int BiTreeLeaf_ChildSlibling(BiTree T);
int BiTreeWPL(BiTree T);
BiTNode* BiTreeRoot(BiTNode *e);
ElemType BiTreeNodeValue(BiTree T, BiTNode* e);
BiTNode* Parent(BiTree T, BiTNode* e);
BiTNode* LeftChild(BiTree T, BiTNode* e);
BiTNode* RightChild(BiTree T, BiTNode* e);
BiTNode* LeftSibling(BiTree T, BiTNode* e);
BiTNode* RightSibling(BiTree T, BiTNode* e);
int PrintfBiTree(BiTree T);
BiTree SeparateBiTree(BiTree T, BiTNode *newBiTree);



#endif //ADT_BITREE_H
