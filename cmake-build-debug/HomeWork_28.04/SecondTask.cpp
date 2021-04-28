//
// Created by WUMBAch on 28.04.2021.
//
#include <iostream>
using namespace std;

int SearchCountOfWays(int lengthOfArray)
{
    if (lengthOfArray < 0)
    {
        return 0;
    }
    if (lengthOfArray == 0)
    {
        return 1;
    }
    int count;
    count = SearchCountOfWays(lengthOfArray - 1);
    count += SearchCountOfWays(lengthOfArray - 2);
    return count;

}

int main(){
    cout << "Enter the length of array: ";
    int lengthOfArray;
    cin >> lengthOfArray;
    cout << "Count of ways from start to end: " << SearchCountOfWays(lengthOfArray - 1);
    return 0;
}
