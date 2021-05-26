//
// Created by WUMBAch on 17.05.2021.
//
#include <iostream>
using namespace std;

int n, m;

void binarySearchMedian(int **matrix)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) cout << matrix[i][j] << "\t";
        cout << endl;

    }

}

int main()
{
    cout << "Enter N and M: ";
    cin >> n >> m;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
    }
    cout << "Now enter elements of matrix: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    binarySearchMedian(matrix);
    return 0;
}
