//
// Created by WUMBAch on 25.02.2021.
//
#include <iostream>
using namespace std;
int sum(int *pointer, int size)
{
    int sum = 0;
    for (int *p = pointer; p < pointer + size; ++p)
    {
        sum += *p;
    }
    return sum;
}
void fillArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
}
int main()
{
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int array[size];
    fillArray(array, size);
    int *pointer = &array[0];
    cout << sum(pointer, size);
    return 0;
}
