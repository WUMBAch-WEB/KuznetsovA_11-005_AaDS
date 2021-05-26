//
// Created by WUMBAch on 28.04.2021.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ParseToInt(vector<string>& arrayNum)
{
    vector<int> resultArray;
    for (int i = 0; i < arrayNum.size(); ++i) {
        resultArray.push_back(stoi(arrayNum[i]));
    }
    return resultArray;
}

void TaskMethod(string element, string str, string newNum, vector<string>& arrayNum)
{
    if (newNum.length() == element.length())
    {
        arrayNum.push_back(newNum);

    }
    for (int i = 0; i < element.length(); ++i)
    {
        if (str.find(to_string(i)) == string::npos)
        {
            TaskMethod(element, str + to_string(i), newNum + element[i], arrayNum);
        }
    }
}

int main()
{
    string A;
    string B;
    int C;
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter B: ";
    cin >> B;
    cout << "Enter C: ";
    cin >> C;

    vector<string> arrayNumForA;
    TaskMethod(A,"","", arrayNumForA);
    vector<int> resultArrayForA = ParseToInt(arrayNumForA);
    vector<string> arrayNumForB;
    TaskMethod(B,"","", arrayNumForB);
    vector<int> resultArrayForB = ParseToInt(arrayNumForB);
    bool flag = false;
    for (int i : resultArrayForA)
    {
        for (int j : resultArrayForB)
        {
            if ( i + j == C)
            {
                cout << "If A imagine like " << i << ", and B like " << j << ", then their sum will be C, namely: " << C << endl;
                flag = true;
            }
        }
    }
    if (flag == false)
    {
        cout << "Task is impossible";
    }
    return 0;
}
