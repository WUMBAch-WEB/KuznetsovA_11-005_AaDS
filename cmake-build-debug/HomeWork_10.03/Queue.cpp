//
// Created by WUMBAch on 06.03.2021.
//

//
// Created by WUMBAch on 06.03.2021.
//
#include <iostream>
using namespace std;

struct Queue
{
    struct Node
    {
        int item;
        Node * next = nullptr;
        Node * prev = nullptr;
    };
    Node * pHead = nullptr;
    Node * pTail = nullptr;


    void enqueue(int item)
    {
        Node * node = new Node();
        node->item = item;
        if (pTail == nullptr)
        {
            pHead = node;
            pTail = node;
            node->prev = nullptr;
        } else
        {
            node->prev = pTail;
            pTail->next = node;
            pTail = node;
        }

    }
    void dequeue()
    {
        Node * node = pTail;
        if (pHead->next == nullptr){
            pHead = nullptr;
        }
        else
        {
            pHead = pHead->next;
        }
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





};
int main()
{
    Queue * queue = new Queue();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->dequeue();
    queue->printAll();
    return 0;
}
