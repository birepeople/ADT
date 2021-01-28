//
// Created by birdpeople on 2020/12/3.
//

#include "../inc/def.h"
#include "../inc/heap.h"
#include <cmath>
int findRoot(int i)
{
    if(!i)
        return i;
    i++;
    int d = (int)(log(i)/log(2));
    int base = 1 << (d - 1);
    int offset = (i - (1 << d))/2;
    return base + offset - 1;
}
int findLchild(int i){
    i++;
    int d = (int)(log(i)/log(2));
    int base = 1 << (d + 1);
    int offset = (i - (1 << d))*2;
    return base + offset - 1;
}

int findRchild(int i){
    return findLchild(i)+1;
}

void mswap(int &a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void heap::shiftdown(int pos)//less <: big_root
{
    while(  (findLchild(pos)<this->len && h[pos] < h[findLchild(pos)]) ||
            (findRchild(pos)<this->len && h[pos] < h[findRchild(pos)]) )
    {
        if(findLchild(pos)<this->len && h[pos] < h[findLchild(pos)])
        {
            if(findRchild(pos)<this->len && h[pos] < h[findRchild(pos)] &&  h[findLchild(pos)] < h[findRchild(pos)])
                swap(h[pos],h[findRchild(pos)]),pos = findRchild(pos);
            else
                swap(h[pos],h[findLchild(pos)]),pos = findLchild(pos);
        }
        else
            swap(h[pos],h[findRchild(pos)]),pos = findRchild(pos);
    }
}
void heap::shiftup(int pos)
{
    while(h[findRoot(pos)] < h[pos])
        swap(h[pos],h[findRoot(pos)]), pos = findRoot(pos);
}

void heap::build()
{
    for(int i =((1<<(this->depth-1))-2);i>=0;i--)
        this->shiftdown(i);

}
void heap::printHeap()
{
    cout<<"I am a happy heap:("<<endl;
    for(int i =1;i<=depth;i++)
    {
        for(int j = (1<<(i-1))-1;j<(1<<i)-1;j++){
          if(j<this->len)
            cout<<h[j]<<" ";
        }
        cout<<endl;
    }
    cout<<")"<<endl;
}