

#include "../inc/BST.h"
#include <stack>
stack<ElemType> list;
bool visit(int pos,BST* T)
{
   if(pos>=0 && pos<T->getSize())
   {
       list.push(T->getEle(pos));
       return true;
   }
   return false;
}

int main() {
    BST test = BST(10);
    test.insert(10);
    test.insert(9);
    test.insert(100);
    test.insert(1);
    test.insert(5);
    test.insert(6);
    test.insert(1000);
    test.InOrderTranverse(visit,0);
    int k;
    cin >> k;
    for(int i = 0;i<list.size();i++)
    {
        if(list.top()<k)
            break;
        cout<<list.top()<<" ";
        list.pop();
    }
    return 0;

}
