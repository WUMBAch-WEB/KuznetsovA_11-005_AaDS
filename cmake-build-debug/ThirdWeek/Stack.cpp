//
// Created by WUMBAch on 03.03.2021.
//

#include <iostream>
using namespace std;

struct Stack
{
    struct Node
    {
        int item;
        Node * next = nullptr;
    };
    Node * pHead = nullptr;

    void Push(int item)
    {
        Node * node = new Node;
        node->item = item;
        node->next = pHead;
        pHead = node;
    }

    int Pop()
    {
        if (!pHead)
            throw 1;

        Node * temp = pHead;
        int x = temp->item;
        pHead = temp->next;
        delete temp;
        return x;
    }
    void printAll()
    {
        Node * temp = pHead;
        while (temp != nullptr)
        {
            cout << temp->item << endl;
            temp = temp->next;
        }
        cout << "End" << endl;
    }

    int Peek()
    {
        if (!pHead)
            throw 1;

        return pHead->item;
    }
};


int main()
{
    Stack * stack = new Stack;

    stack->Push(10);
    stack->Push(20);
    stack->Push(30);
    stack->Push(40);
    stack->Push(50);
    stack->Push(60);
    stack->printAll();


    delete stack;
    return 0;
}


