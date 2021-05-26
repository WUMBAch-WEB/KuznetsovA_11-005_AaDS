//
// Created by WUMBAch on 14.05.2021.
//
#include <iostream>
using namespace std;

int money = 0;

int counter(int denomination)
{
    int count = 0;
    while (true)
    {
        if (money - denomination >= 0)
        {
            money -= denomination;
            count++;
        } else break;
    }
    return count;
}

int main()
{
    cout << "Enter sum of money: ";
    cin >> money;
    int countOf10 = counter(10);
    int countOf5 = counter(5);
    int countOf1 = counter(1);
    cout << "Answer: " << endl;
    cout << "Count of 10: " << countOf10 << endl;
    cout << "Count of 5: " << countOf5 << endl;
    cout << "Count of 1: " << countOf1 << endl;
    return 0;
}
