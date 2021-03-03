//
// Created by WUMBAch on 03.03.2021.
//

#include <iostream>
using namespace std;

struct LinkedList
{
    struct Node
    {
        int item;
        Node * next = nullptr;
    };
    Node * pHead = nullptr;
    Node * pTail = nullptr;
    void add(int item)
    {
        Node * node = new Node();
        node->item = item;
        if (pTail == nullptr)
        {
            pHead = node;
            pTail = node;
        } else
        {
            pTail->next = node;
            pTail = node;
        }

    }

    int size()
    {
        Node * node = pHead;
        int size = 0;
        while (node != nullptr)
        {
            ++size;
            node = node->next;
        }
        return size;
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
    int get (int i)
    {
        Node * node = pHead;
        int counter = 0;
        while (counter != i)
        {
            ++counter;
            node = node->next;
        }
        return node->item;
    }


};


int main()
{
    LinkedList * list = new LinkedList;
    list->add(10);
    list->add(20);
    list->add(30);
    list->add(40);
    list->add(50);
    list->add(60);
    cout << list->get(3) << endl;
    cout << list->size() << endl;
    list->printAll();
    delete list;
    return 0;
}


