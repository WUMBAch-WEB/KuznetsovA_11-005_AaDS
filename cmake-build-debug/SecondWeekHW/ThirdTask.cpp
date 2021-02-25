//
// Created by WUMBAch on 25.02.2021.
//
#include <iostream>
using namespace std;

void fillArray(int *array, int size)
{
    for (int *p = array; p < array + size; ++p)
    {
        cin >> *p;
    }
}
void sort(int *array, int size)
{
    for (int i = 1; i < size ; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (array[j] > array[j + 1])
            {
                int t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = t;
            }

        }

    }
}
int main()
{
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int *array = new int[size];
    fillArray(array, size);
    sort( array, size);
    for (int i = 0; i < size ; ++i) {
        cout << array[i];
    }
    return 0;
}
