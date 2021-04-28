//
// Created by WUMBAch on 27.04.2021.
//


#include <iostream>
#include <vector>


using namespace std;

int BinarySearch(int *arrayNum, int element, int left, int right)
{
    int middle = left + (right - left) / 2;
    if (element < arrayNum[middle])
    {
        return BinarySearch(arrayNum, element, left, middle);
    }
    if (element > arrayNum[middle])
    {
        return BinarySearch(arrayNum, element, middle, right);
    }
    if (right - left == 1)
    {
        return -1;
    }
    return middle;


}

void MainTaskMethod(int (&matrix)[4][4], int n, int m, int element)
{
    int middle;
    int left = 0;
    int right = n - 1;
    while (true)
    {
        if (element > matrix[middle][m - 1])
        {
            left = middle;
            middle += (right - left) / 2;
        }
        if (element < matrix[middle][m - 1])
        {
            right = middle;
            middle -= (right - left) / 2;
        }
        if (element == matrix[middle][m - 1])
        {
            cout << "Element was found";
            break;
        }
        if (right - left == 1)
            break;
    }
    if ((!BinarySearch(matrix[left], element, 0, m - 1) == -1) || (!BinarySearch(matrix[right   ], element, 0, m - 1) == -1)){
        cout << "Element was found";
    }
}

int main()
{
    int n = 4, m = 4;
    int mat[4][4] = {
            {4, 6, 8, 9},
            {10, 11, 12, 14},
            {25, 28, 31, 42},
            {56, 64, 73, 82},
                        };
    MainTaskMethod(mat, n, m,4);
    return 0;
}
