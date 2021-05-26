//
// Created by WUMBAch on 17.05.2021.
//

#include <iostream>
using namespace std;

void searchSqrt(int num, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (mid * mid == num)
    {
        cout << mid;
    }
    if ((mid + 1) * (mid + 1) > num && (mid - 1) * (mid - 1) < num)
    {
        if ((mid + 1) * (mid + 1) - num < num - mid * mid)
        {
            cout << "Sqrt: " << mid + 1;
            return;
        }
        if (num - (mid - 1) * (mid - 1) < mid * mid - num)
        {
            cout << "Sqrt: " << mid - 1;
            return;
        }
        cout << "Sqrt: " << mid;
        return;
    }
    if (mid * mid < num)
    {
        searchSqrt(num, mid, end);
    }
    if (mid * mid > num)
    {
        searchSqrt(num, start, mid);
    }
}

int main()
{
    cout << "Enter the number: ";
    int num;
    cin >> num;
    searchSqrt(num, 0, num);
    return 0;
}