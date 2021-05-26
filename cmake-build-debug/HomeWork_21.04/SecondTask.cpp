//
// Created by WUMBAch on 27.04.2021.
//


#include <iostream>


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

void MainTaskMethod(int n, int m, int element)
{
    int middle;
    int left = 0;
    int right = n - 1;
    int matrix[n][m];
    cout << "Now enter elements of matrix: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) cout << matrix[i][j] << "\t";
        cout << endl;

    }
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
    if ((!BinarySearch(matrix[left], element, 0, m - 1) == -1) || (!BinarySearch(matrix[right], element, 0, m - 1) == -1)){
        cout << "Element was found";
    } else cout << "Element don't found";
}

int main()
{
    int n, m;
    cout << "Enter N and M: ";
    cin >> n >> m;
//    cout << "Now enter elements of matrix: " << endl;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            cin >> matrix[i][j];
//        }
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j) cout << matrix[i][j] << "\t";
//        cout << endl;
//
//    }
    MainTaskMethod(n, m, 4);
    return 0;
}
