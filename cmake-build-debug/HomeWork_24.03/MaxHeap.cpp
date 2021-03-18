//
// Created by WUMBAch on 18.03.2021.
//
#include <iostream>
using namespace std;

struct MaxHeap
{
    int * array = 0;
    int size = 0;
    int maxSize = 0;

    int Parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return  2 * i + 2; }

    void makeArrayForHeap(int size)
    {
        int *arr = new int[size];
        if (size > 1)
        {
            for (int i = 0; i < this->size; ++i)
            {
                int x = array[i];
                arr[i] = array[i];
            }
        }

        delete[] array;
        array = arr;
    }

    void SiftUp(int i)
    {
        while (i > 1 && array[i] > array[Parent(i)])
        {
            int  t = array[i];
            array[i] = array[Parent(i)];
            array[Parent(i)] = t;
            i = Parent(i);
        }
    }

    void SiftDown(int i)
    {
        int maxIndex = i;
        if (array[LeftChild(i)] > array[i] &&  LeftChild(i) < size)
        {
            maxIndex = LeftChild(i);
        }
        if (array[RightChild(i)] > array[i] && RightChild(i) < size)
        {
            maxIndex = RightChild(i);
        }
        if (maxIndex != i)
        {
            int t = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = t;
            SiftDown(maxIndex);
        }
    }

    void Insert(int p)
    {
        if (size < maxSize)
        {
            ++size;
        }
        else
        {
            maxSize = maxSize * 2 + 1;
            makeArrayForHeap(maxSize);
            ++size;
        }
        array[size - 1] = p;
        SiftUp(size - 1);

    }

    int ExtractMax()
    {
        int result = array[0];
        int t = array[size - 1];
//        array[size - 1] = array[0];
        array[0] = t;
        --size;
        SiftDown(0);
        return result;
    }

    int GetMax()
    {
        return array[0];
    }

    static int *sort(int *array, int size)
    {
        MaxHeap heap;
        for (int i = 0; i < size ; ++i)
        {
            heap.Insert(array[i]);
        }
        int *arr = new int[size];
        for (int i = size - 1; i > - 1 ; --i)
        {
            arr[i] = heap.ExtractMax();
        }
        delete [] array;
        return arr;
    }

};

int main()
{
    MaxHeap heap;
    int size = 4;
    int * array = new int[size];
    for (int i = 0; i < size; ++i)
    {
        int t;
        cin >> t;
        array[i] = t;
    }

    array = heap.sort(array, size);

    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << ' ';
    }


    return 0;
}
