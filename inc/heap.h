//
// Created by birdpeople on 2020/12/3.
//
#include"def.h"
#ifndef ADT_HEAP_H
#define ADT_HEAP_H
#define OVERFLOW 110
#endif //ADT_HEAP_H
class heap{
public:
    heap(int size){
        h = new int[size];
        memset(h,0,sizeof(h));
        this -> len = 0;
        this-> allcator_length = size;
        depth = 1;
        this->renewDepth();
    }
    heap() {
        h = new int[10];
        memset(h,0,sizeof(h));
        this->len = 0;
        depth = 1;
        this-> allcator_length = 10;
    }
    ~heap()
    {
        delete[] h;
    }

    int& operator[](int i){
        if(i>this->len)
            exit(OVERFLOW);
        return *(h+i);
    }
    void printHeap();
    Status insert(int ele){
        if(this->len == this->allcator_length)
            this->reserve(len+20);
        if(h)
        {
            *(h+this->len) = ele, this->len ++;
            shiftup(this->len-1);
            this->renewDepth();
            return true;
        }
        return false;
    }
    void pop()
    {
        int tmp = h[0];
        h[0] = h[this->len-1], h[this->len-1] = 0, this->len--;
        this->shiftdown(0);
        this->renewDepth();
    }
    int top(){return h[0];}
    void build();

    Status reserve(int size){
        if(this->len < size)
            h =(int*) realloc(h,size*sizeof(int));
       if(h) {
           this->allcator_length = size;
           return true;
       }
       return false;
    }

    Status resize(int size)
    {
        if(size> this->len)
            h =(int*) realloc(h,size*sizeof(int));
        if(h)
        {
            this -> len = size, this->allcator_length = size;
            this->renewDepth();
            return true;

        }
        return false;
    }
    int size(){return this->len;}
    int length(){return this->len;}

    private:
        int *h;
        int len;
        int depth;
        int allcator_length;
        void shiftdown(int pos);
        void shiftup(int pos);
        void renewDepth()
        {
            if(this->depth-1)
                depth--;
            while((1<<this->depth)<=this->len)
                this->depth++;
        }
};