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

void sumArrays(int size1, int *p1, int *p2, int *p3, int size2)
{
    for (int i = 0; i < size1; ++i)
    {
        *(p3 + i)  = *(p1 + i);
    }
    for (int i = 0; i < size2 ; ++i) {
        *(p3 + i + size1) = *(p2 + i);
    }
}

int main()
{
    int size1;
    int size2;
    cout << "Enter size of array1 and array2: " << endl;
    cin >> size1 >> size2;
    int *array1 = new int[size1];
    int *array2 = new int[size2];
    int *array3 = new int[size1 + size2];
    fillArray(array1, size1);
    fillArray(array2, size2);
    sumArrays(size1, array1, array2, array3, size2);
    cout << "Result: " << endl;
    for (int i = 0; i < size1 + size2; ++i)
    {
        cout << array3[i];
    }
    delete[]array1;
    delete[]array2;
    return 0;
}
