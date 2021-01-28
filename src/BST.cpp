//
// Created by birdpeople on 2020/12/12.
//

#include"../inc/BST.h"

bool BST::PreOrderTranverse(bool (*visit)(int,BST*),int pos){
    if(pos == -1)
        return true;
    if(!visit(pos,this)) return false;
    else
    {
        if(PreOrderTranverse(visit,(Root+pos)->Lchild)); else return false;
        if(PreOrderTranverse(visit,(Root+pos)->Rchild)); else return false;
    }
    return true;
}
bool BST::PostOrderTranverse(bool (*visit)(int,BST*),int pos)
{
    if(pos == -1)
        return true;
    if(PostOrderTranverse(visit,(Root+pos)->Lchild)); else return false;
    if(PostOrderTranverse(visit,(Root+pos)->Rchild)); else return false;
    return visit(pos, this);
}
bool BST::InOrderTranverse(bool (*visit)(int,BST*),int pos)
{
    if(pos == -1)
        return true;
    if(InOrderTranverse(visit,(Root+pos)->Lchild)); else return false;
    if(!visit(pos,this)) return false;
    if(InOrderTranverse(visit,(Root+pos)->Rchild)); else return false;

    return true;
}
Status BST::insert(int ele)
{
    if(containerSize == cnt)
    {
        if(this->reserve((this->cnt)<<1)); else return false;
    }
    inside(ele,0);
    return true;
}
int BST::inside(int ele,int pos)
{
    if(pos==-1||cnt==0)
    {
        container[cnt].Rchild = -1;
        container[cnt].Lchild = -1;
        container[cnt].data = ele;
        return cnt++;
    }
    if(ele<container[pos].data)
        container[pos].Lchild = inside(ele,container[pos].Lchild);
    else
        container[pos].Rchild = inside(ele,container[pos].Rchild);
    return pos;
}

int BST::erase(int pos)
{
    if(pos < 0 || pos >= cnt)
        return -1;
    int tmp_ele = (Root + pos) -> data;
    if(container[pos].Rchild == -1 && container[pos].Lchild == -1)
        mask(pos,-1);

    else if(container[pos].Lchild != -1 && container[pos].Rchild ==-1)
        mask(pos,container[pos].Lchild);

    else if(container[pos].Lchild == -1 && container[pos].Rchild != -1)
        mask(pos,container[pos].Rchild);
    else
    {
        /*
         * pos-----
         * ｜      ｜
         * 1---   any
         * ｜  ｜
         * any null(put_any)
         */
        if(container[container[pos].Lchild].Rchild == -1)
            container[container[pos].Lchild].Rchild = container[pos].Rchild,
                    mask(pos,container[pos].Lchild);

            /*(pos)
            * put here---
            * ｜         ｜
            * 1---      any
            * ｜  ｜
            * any 1---
            *     .....
            *     ｜  ｜
            *    any here(null_now)
            */
        else{
            int localmax = container[pos].Lchild;
            while(container[localmax].Rchild != -1)
                localmax = container[localmax].Rchild;
            int rootOfLocalmax = getRoot(localmax);

            container[rootOfLocalmax].Rchild = -1;
            container[localmax].Rchild = container[pos].Rchild,
            container[localmax].Lchild = container[pos].Lchild;
            mask(pos,localmax);
        }
    }
    --cnt;
    return tmp_ele;
}
void BST::mask(int pos, int mask)
{
    int root = getRoot(pos);
    if(container[root].Rchild == pos)
        container[root].Rchild = mask;
    else
        container[root].Lchild = mask;
}

Status BST::reserve(int size) {
    if (this->containerSize >= size)
        return true;
    BSTree tmp = new BSTNode[size+1];
    if(!tmp) return false;
    for (int i = 0; i < cnt; i++)
        *(tmp + i) = container[i];
    delete[] container;
    this->Root = tmp;
    this->container = tmp;
    containerSize = size;
    return true;
}

int BST::Search(int ele)
{
    return insideSearch(ele,0);
}
int BST::insideSearch(int ele,int pos)
{
    if(cnt == 0 || pos == -1)
        return -1;

    if(container[pos].data == ele)
        return pos;
    else{
        if(ele < container[pos].data)
            return insideSearch(ele,container[pos].Lchild);
        else
            return insideSearch(ele,container[pos].Rchild);
    }
}

int BST::getRoot(int ele){
    return insideGetRoot(0,ele);
};
int BST::insideGetRoot(int pos, int ele)
{
    if(!cnt || cnt == 1)
        return cnt ? ((container[0].data == ele) - 1) : -1 ;
    if(container[pos].data < ele )
    {
        return container[container[pos].Lchild].data == ele ?
               pos : insideGetRoot(container[pos].Lchild,ele);
    }
    else
        return container[container[pos].Rchild].data == ele ?
               pos : insideGetRoot(container[pos].Rchild,ele);

}