
#include <iostream>
#include <vector>


using namespace std;

int BinarySearch(vector<int> arrayNum, int element, int left, int right)
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
    return middle;


}

void MainTaskMethod(vector<int> arrayNum, int element)
{
    int first = BinarySearch(arrayNum, element, 0, arrayNum.size() - 1);
    int leftBorder = first;
    int rightBorder = first;
    while (true)
    {
        if ((arrayNum[leftBorder - 1] != element) || (leftBorder - 1 < 0))
        {
            break;
        }
        leftBorder = BinarySearch(arrayNum, element, 0, leftBorder);

    }
    while (true)
    {
        if (arrayNum[rightBorder + 1] != element)
        {
            break;
        }
        if (rightBorder + 1 == arrayNum.size() - 1)
        {
            rightBorder++;
            break;
        }
        rightBorder = BinarySearch(arrayNum, element, rightBorder, arrayNum.size() - 1);
    }
    cout << "Left border is: " << leftBorder << endl;
    cout << "Right border is: " << rightBorder << endl;
}

int main()

{
    cout << "Enter size of array: ";
    int size;
    cin >> size;
    vector<int> array;
    cout << "Now enter elements of array: ";
    for (int i = 0; i < size; ++i)
    {
        int element;
        cin >> element;
        array.push_back(element);
    }
    cout << "Input element to find: ";
    int element;
    cin >> element;

    MainTaskMethod(array, element);

}