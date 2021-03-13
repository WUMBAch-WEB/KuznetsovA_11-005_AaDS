//
// Created by WUMBAch on 06.03.2021.
//
#include <iostream>
using namespace std;

struct SortedList
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
        Node * tempHead = pHead;
        Node * node = new Node();
        node->item = item;
        if (pTail == nullptr)
        {
            pHead = node;
            pTail = node;
            node->prev = nullptr;
        } else
        {
            if (pHead->next == nullptr && node->item > pHead->item)
            {
                pTail = node;
                pTail->prev = pHead;
                pHead->next = pTail;
            }

            if (node->item < pHead->item && node->item != pHead->item)
            {
                node->next = pHead;
                pHead = node;
            }
            while (tempHead->next != nullptr)
            {
                if (node->item == tempHead->item)
                {
                    break;
                }
                if (node->item < tempHead->item )
                {


                    if (tempHead->prev != nullptr)
                    {
                        tempHead->prev->next = node;
                    }
                    node->prev = tempHead->prev;
                    tempHead->prev = node;
                    node->next = tempHead;
                    break;
                }
                tempHead = tempHead->next;
            }
            if (node->item < pTail->item && tempHead->next == nullptr)
            {
                pTail->prev->next = node;
                node->prev = pTail->prev;
                pTail->prev = node;
                node->next = pTail;
            }
            if (node->item > pTail->item && tempHead->next == nullptr)
            {
                pTail->next = node;
                node->prev = pTail;
                pTail = node;
            }

        }

    }

    void remove(int id) {
        Node *tempHead = pHead;
        int count = 0;
        while (tempHead != nullptr && id != count) {
            count++;
            tempHead = tempHead->next;
        }
        if (id == 0) {
            pHead->next->prev = nullptr;
            pHead = pHead->next;
        } else if (id == size() - 1) {
            pTail->prev->next = nullptr;
            pTail = tempHead->prev;

        } else {
            tempHead->prev->next = tempHead->next;
            tempHead->next->prev = tempHead->prev;
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

    SortedList * Union(SortedList * a, SortedList * b)
    {
        SortedList * list = new SortedList;
        int count = 0;
        Node * tempHead1 = a->pHead;
        Node * tempHead2 = b->pHead;
        while (tempHead1 != nullptr)
        {
            list->add(tempHead1->item);
            tempHead1 = tempHead1->next;
        }
        while (tempHead2 != nullptr)
        {
            int newElement = b->get(count);
            list->add(newElement);
            ++count;
            tempHead2 = tempHead2->next;
        }
        return list;
    }

    SortedList * Intersect (SortedList * a, SortedList * b)
    {
        SortedList * list = new SortedList();
        Node * tempHead1 = a->pHead;
        Node * tempHead2 = b->pHead;
        while (tempHead1 != nullptr && tempHead2 != nullptr)
        {
           if (tempHead1->item == tempHead2->item)
           {
               list->add(tempHead1->item);
               tempHead2 = tempHead2->next;
           }
           else if (tempHead1->item < tempHead2->item)
           {
               tempHead1 = tempHead1->next;
           } else
           {
               tempHead2 = tempHead2->next;
           }
        }
        return list;
    }

    SortedList * Difference(SortedList * a, SortedList * b)
    {
        SortedList * list = new SortedList();
        Node * tempHead1 = a->pHead;
        Node * tempHead2 = b->pHead;
        while (tempHead1 != nullptr && tempHead2 != nullptr)
        {
            if (tempHead1->item == tempHead2->item)
            {
                tempHead1 = tempHead1->next;
            }
            else if (tempHead1->item > tempHead2->item)
            {
                tempHead2 = tempHead2->next;
            } else
            {
                list->add(tempHead1->item);
                tempHead1 = tempHead1->next;
            }
        }
        return list;
    }


};
int main()
{
    cout << "Let's test this piece of code: " << endl;
    SortedList * listA = new SortedList();
    SortedList * listB = new SortedList();
    SortedList * listC = new SortedList();
    SortedList * listD = new SortedList();
    SortedList * listE = new SortedList();
    cout << "Try to add anything in lists..." << endl;
    listA->add(10);
    listA->add(20);
    listA->add(5);
    listA->add(30);
    listA->add(25);
    listA->add(40);
    listB->add(20);
    listB->add(45);
    listB->add(6);
    listB->add(14);
    listB->add(10);
    cout << "Now i can show the lists." << endl;
    cout << "List A: " << endl;
    listA->printAll();
    cout << "List B: " << endl;
    listB->printAll();
    cout << "If you wanna union them, they will look like this:  " << endl;
    listC = listC->Union(listA, listB);
    listC->printAll();
    cout << "If you wanna see their difference, it will look like this:  " << endl;
    listD = listD->Difference(listA, listB);
    listD->printAll();
    cout << "If you wanna see their intersection, it will look like this:  " << endl;
    listE = listE->Intersect(listA,listB);
    listE->printAll();
    cout << "Let's imagine that you wanna remove element #3 from List A. List will look like this: " << endl;
    listA->remove(3);
    listA->printAll();
    cout << "Let's try get element #3 from list B. It will be: " << endl;
    cout << listB->get(3) << endl;
    delete listA;
    delete listB;
    delete listC;
    delete listD;
    delete listE;


    return 0;
}
