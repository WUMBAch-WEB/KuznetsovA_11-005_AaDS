//
// Created by WUMBAch on 06.03.2021.
//
#include <iostream>
using namespace std;

struct DoubleLinkedList
{
    struct Node
    {
        int item;
        Node * next = nullptr;
        Node * prev = nullptr;
    };
    Node * pHead = nullptr;
    Node * pTail = nullptr;

    bool isEmpty()
    {
        return pHead == nullptr;
    }

    void add(int item)
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

    void removeAt(int index)
    {
        Node * cur = pHead;
        int c = 0;

        while (cur != nullptr && c != index)
        {
            ++c;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            cout << "Incorrect index! Can't remove." << endl;
            return;
        }
        if (index == 0)
        {
            pHead = pHead->next;
        }
        if (index == size() - 1)
        {
            pTail->prev->next = nullptr;
            pTail = pTail->prev;

        }
        else
        {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }
    }

    void insertAt(int item, int index)
    {
        Node * cur = pHead;
        Node * temp = new Node();
        temp->item = item;
        int c = 0;

        while (cur != nullptr && c != index)
        {
            ++c;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            cout << "Incorrect index! Can't insert." << endl;
            return;
        }
        if (index == 0)
        {
            temp->next = pHead;
            pHead = temp;
        }
        if (index == size())
        {
            pTail->next = temp;
            temp->prev = pTail;
            pTail = temp;
        }
        else
        {
            cur->prev->next = temp;
            temp->prev = cur->prev;
            cur->prev = temp;
            temp->next = cur;
        }


    }


};
int main()
{
    DoubleLinkedList * list = new DoubleLinkedList();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->insertAt(5, 100);
    list->removeAt(40);
    list->printAll();
    return 0;
}
