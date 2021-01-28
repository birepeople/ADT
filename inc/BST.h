//
// Created by birdpeople on 2020/12/4.
//

#ifndef ADT_BST_H
#define ADT_BST_H
#include "def.h"
typedef struct BSTNode{
    int data;
    int Rchild,Lchild;
    BSTNode():data(0),Rchild(-1),Lchild(-1){}
    BSTNode(const BSTNode &ele) = default;
}BSTNode,* BSTree;

class BST{
    public:
        BST(){
            container = new BSTNode[10];
            this -> cnt = 0;
            this -> containerSize = 10;
            this -> Root = container;
        };
        BST(int len):cnt(len){
            container = new BSTNode[len];
            this -> cnt = 0;
            this -> containerSize = len;
            this -> Root  = container;
        }
        ~BST() {delete[] container;}
        bool PreOrderTranverse(bool (*visit)(int,BST*),int pos);
        bool PostOrderTranverse(bool (*visit)(int,BST*),int pos);
        bool InOrderTranverse(bool (*visit)(int,BST*),int pos);

        Status insert(int ele);
        Status reserve(int size);
        int erase(int pos);
        int Search(int ele);
        int getEle(int pos){
            return pos < cnt && pos >= 0 ?  container[pos].data : -1;
        }
        int getSize(){return this -> cnt;}
    private:
        int cnt;
        int containerSize;
        BSTree container;
        BSTNode* Root;
        int inside(int ele,int pos);
        int insideSearch(int ele,int pos);
        int getRoot(int ele);
        int insideGetRoot(int pos, int ele);
        void mask(int pos, int mask);
};
#endif //ADT_BST_H
