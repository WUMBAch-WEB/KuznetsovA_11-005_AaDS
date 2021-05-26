//
// Created by WUMBAch on 14.05.2021.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter count of days, when programmer working: ";
    int days;
    cin >> days;
    int array[days];
    int tasks[days*3+1];
    int count = 1;
    for (int i = 0; i < days; ++i)
    {
        array[i] = 0;
    }
    for (int i = 1; i < days*3+1 ; ++i)
    {
        if (1 == i % 3)
        {
            cout << "Enter task # " << count << endl;
            count++;
        }
        cin >> tasks[i];
    }
    int max = 0;
    int maxI = 0;
    count = 0;
    while (true)
    {
        for (int i = 1; i < days*3+1; ++i)
        {
            if (i % 3 == 2 && tasks[i] > max)
            {
                max = tasks[i];
                maxI = i;
            }
        }
        tasks[maxI] = 0;
        max = 0;
        int lastNull = -1;
        for (int i = 0; i < tasks[maxI + 1]; ++i)
        {
            if (array[i] == 0)
            {
                lastNull = i;
            }
        }
        array[lastNull] = tasks[maxI - 1];
        count++;
        if (count == days)
        {
            break;
        }
    }
    cout << "Answer: " << endl;
    for (int i = 0; i < days; ++i)
    {
        cout << array[i];
    }
}