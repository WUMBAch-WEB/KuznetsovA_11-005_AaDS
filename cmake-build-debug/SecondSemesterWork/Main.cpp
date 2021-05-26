//
// Created by WUMBAch on 15.05.2021.
//
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void Merge(int *array, int first, int last)
{
    int mid, start, final, j;
    int *arr = new int[last+1];
    mid = (first + last) / 2;
    start = first;
    final = mid + 1;
    for (int i = first; i <= last ; ++i)
    {
        if ((start <= mid) && ((final > last) || (array[start] < array[final])))
        {
            arr[i] = array[start];
            start++;
        }
        else
        {
            arr[i] = array[final];
            final++;
        }

    }

    for (int i = first; i <= last ; ++i)
    {
     array[i] = arr[i];
    }
    delete[]arr;
}

void MergeSort(int *array, int first, int last)
{
    if (first < last)
    {
        MergeSort(array, first, (first+last) / 2);
        MergeSort(array, (first+last) / 2 + 1, last);
        Merge(array, first, last);
    }
}

void SelectionSort(int *array,int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}


int* Reading(int *array, int size, string path)
{
    int count = 0;
    string line;
    string text;
    ifstream in(path);

    if (in.is_open())
    {
        while (getline(in, line) && count < size)
        {
            int number = stoi(line);
            array[count] = number;
            count++;
        }
    }
    in.close();
    return array;
}


int main()
{
//    int *array = new int[5];
//    array[0] = 5;
//    array[1] = 2;
//    array[3] = 8;
//    array[2] =  1;
//    array[4] = 6;
//    SelectionSort(array, 5);
//    for (int i = 0; i < 5; ++i) {
//        cout << array[i];
//
//    }

    int const size = 2000;

    for (size_t i = 0; i < 51; i++)
    {
        int sizeOfArray = size + 2000 * i;
//        int *array = new int[sizeOfArray];
        int *array2 = new int[sizeOfArray];
        string path = "C:\\Users\\sascu\\CLionProjects\\KuznetsovA_11-005_AaDS\\cmake-build-debug\\SecondSemesterWork\\Tests" + to_string(i) + ".txt";
//        array = Reading(array, size, path);
        array2 = Reading(array2, size, path);

//        cout << "------ TEST #" << i << " ------" << endl;
//        cout << "Count of elements: " << sizeOfArray << endl;

//        auto start1 = chrono::high_resolution_clock::now();
//        MergeSort(array, 0, sizeOfArray-1);
//        auto finish1 = chrono::high_resolution_clock::now();
//        chrono::duration<float> duration1 = finish1 - start1;
//        cout <<  duration1.count() << endl;

        auto start2 = chrono::high_resolution_clock::now();
        SelectionSort(array2, sizeOfArray);
        auto finish2 = chrono::high_resolution_clock::now();
        chrono::duration<float> duration2 = finish2 - start2;
        cout << "Time of SelectionSort: " << duration2.count() << endl;

//        delete[] array;
        delete[]array2;



    }
    return 0;
}
