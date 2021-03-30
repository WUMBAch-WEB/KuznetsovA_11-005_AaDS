//
// Created by WUMBAch on 27.03.2021.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <windows.h>


using namespace std;

struct RangeTree
{

    vector<int> arrayNum;
    vector<int> treeArrayForSum;
    vector<int> treeArrayForMin;
    int size;
    int IterationCountOfBuildMinTree;
    int IterationCountOfBuildSumTree;
    int IterationCountOfSearchingMinInRange;
    int IterationCountOfSearchingSumInRange;
    int IterationCountOfSetAnyElementInMinTree;
    int IterationCountOfSetAnyElementInSumTree;


public: RangeTree(vector<int> arrayNum, vector<int> treeArray)
    {
        this->arrayNum = arrayNum;
        this->treeArrayForMin = treeArray;
        this->treeArrayForSum = treeArray;
        this->size = arrayNum.size();
    }



    vector<int> buildTreeForSearchSum(vector<int> arrayNum)
    {
        IterationCountOfBuildSumTree = 0;
        for (int i = 0; i < size; ++i)
        {
         ++IterationCountOfBuildSumTree;
          treeArrayForSum = setForSearchSum(i, arrayNum[i]);
        }
//        if (tl == tr)
//        {
//            treeArray[v] = arrayNum[tl];
//            return treeArray;
//        }
//        else
//        {
//            int tm = (tl + tr) / 2;
//            buildTreeForSearchSum(v * 2, tl, tm, arrayNum);
//            buildTreeForSearchSum(v * 2 + 1, tm + 1, tr, arrayNum);
//            treeArray[v] = treeArray[v * 2] + treeArray[v * 2 + 1];
//        }
        return treeArrayForSum;

    }

    vector<int> setForSearchSum(int i, int v)
    {
        i += size - 1;
        treeArrayForSum[i] = v;
        IterationCountOfSetAnyElementInSumTree = 0;
        while (i > 0)
        {
            ++IterationCountOfSetAnyElementInSumTree;
            i = (i - 1) / 2;
            treeArrayForSum[i] = treeArrayForSum[2 * i + 1] + treeArrayForSum[2 * i + 2];
        }
        return treeArrayForSum;
    }

    int sum(int l, int r)
    {
        IterationCountOfSearchingSumInRange = 0;
        l += size - 1;
        r += size - 2;
        int result = 0;
        while (r >= l)
        {
            ++IterationCountOfSearchingSumInRange;
            if (l % 2 == 0)
            {
                result += treeArrayForSum[l];
            }
            l /= 2;
            if (r % 2 == 1)
            {
                result += treeArrayForSum[r];
            }
            r = (r / 2) - 1;
        }
        return result;
    }

    vector<int> setForSearchMin(int i, int v)
    {
        IterationCountOfSetAnyElementInMinTree = 0;
        i += size - 1;
        treeArrayForMin[i] = v;
        while (i > 0)
        {
            ++IterationCountOfSetAnyElementInMinTree;
            i = (i - 1) / 2;
            int min = treeArrayForMin[2 * i + 1];
            if (treeArrayForMin[2 * i + 2] < min)
            {
                min = treeArrayForMin[2 * i + 2];
            }
            treeArrayForMin[i] = min;
        }
        return treeArrayForMin;
    }

    vector<int> buildTreeForSearchMin(vector<int> arrayNum)
    {
        IterationCountOfBuildMinTree = 0;
        for (int i = 0; i < size; ++i)
        {
            ++IterationCountOfBuildMinTree;
            treeArrayForMin = setForSearchMin(i, arrayNum[i]);
        }
        return treeArrayForMin;
    }

    int min(int l, int r)
    {
        IterationCountOfSearchingMinInRange = 0;
        l += size - 1;
        r += size - 2;
        int result = 99999;
        while (r >= l)
        {
            if (l % 2 == 0 && treeArrayForMin[l] < result && treeArrayForMin[l] <= treeArrayForMin[r])
            {
                ++IterationCountOfSearchingMinInRange;
                result = treeArrayForMin[l];
            }
            l /= 2;
            if (r % 2 == 1 && treeArrayForMin[r] < result && treeArrayForMin[r] <= treeArrayForMin[l])
            {
                result = treeArrayForMin[r];
            }
            r = (r / 2) - 1;
        }
        return result;
    }

};

vector<int> Reading(vector<int> arrayNumb, int size, string path)
{
    int count = 0;
    string line;
    string text;
    ifstream in(path);

    if (in.is_open())
    {
        while (getline(in, line))
        {
            long int number = stoi(line);
            arrayNumb[count] = number;
            count++;
        }
    }
    in.close();
    return arrayNumb;
}

void printTree(vector<int> treeArray)
{
    int x = 0;
    for (int  i = 0;  i < treeArray.size() ; ++ i)
    {


        cout << treeArray[i] << " ";

        if (i == 0 || i == 2 * x + 2){
            x = i;
            cout << endl << endl;
        }

    }
}

void testAllFunctions(vector<int> arrayNum, vector<int> treeArray, int i)
{
    RangeTree * tree = new RangeTree(arrayNum, treeArray);

    auto start2 = chrono::high_resolution_clock::now();
    vector<int> minTreeArray = tree->buildTreeForSearchMin(arrayNum);
    auto finish2 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration2 = finish2 - start2;

    auto start1 = chrono::high_resolution_clock::now();
    vector<int> sumTreeArray = tree->buildTreeForSearchSum(arrayNum);
    auto finish1 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration1 = finish1 - start1;

    cout << "-----------START----------------" << endl;
    cout << "Test #" << i << endl;
//    cout << "Our start array: " << endl << endl;
//    for (int i = 0; i < arrayNum.size(); ++i) {
//        cout << arrayNum[i] << " ";
//    }
    cout << endl << "Size of start array: " << arrayNum.size() << endl;
    cout << endl << endl << "Let's build range tree for search sum." << endl;
//    cout << "Tree will look like: " << endl << endl;
//    printTree(sumTreeArray);
    cout << endl << "Iteration count: " << tree->IterationCountOfBuildSumTree << endl;
    cout << "Time: " << duration1.count() << endl;
    cout << endl << "Also we can set any element. Let's try." << endl;
    cout << "For example try set element at #5 in start array like 100 (set(5, 100)). ";

    auto start5 = chrono::high_resolution_clock::now();
    sumTreeArray = tree->setForSearchSum(5, 100);
    auto finish5 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration5 = finish5 - start5;

    cout << endl << "Iteration count: " << tree->IterationCountOfSetAnyElementInSumTree << endl;
    cout << "Time: " << duration5.count() << endl << endl;
//    cout << "Then our tree will look like: " << endl << endl;
//    printTree(sumTreeArray);

    auto start3 = chrono::high_resolution_clock::now();
    int sum = tree->sum(0, i - i / 2);
    auto finish3 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration3 = finish3 - start3;

    cout << endl << "For example we can search sum in range(0, i - i / 2). It will: " << sum;
    cout << endl << "Iteration count: " << tree->IterationCountOfSearchingSumInRange;
    cout << endl << "Time: " << duration3.count() << endl;


    cout << endl << "-----------------------------------" << endl;


    cout << endl << endl << "Let's build range tree for search min." << endl;
//    cout << "Tree will look like: " << endl << endl;
//
//    printTree(minTreeArray);

    cout << endl << "Iteration count: " << tree->IterationCountOfBuildMinTree << endl;
    cout << "Time: " << duration2.count() << endl;

    cout << endl << "Also we can set any element. Let's try." << endl;
    cout << "For example try set element at #9 in start array like -5 (set(9, -5)). ";

    auto start6 = chrono::high_resolution_clock::now();
    minTreeArray = tree->setForSearchMin(9, -5);
    auto finish6 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration6 = finish6 - start6;

    cout << endl << "Iteration count: " << tree->IterationCountOfSetAnyElementInMinTree << endl;
    cout << "Time: " << duration6.count() << endl << endl;
//    cout << "Then our tree will look like: " << endl << endl;
//    printTree(minTreeArray);

    auto start4 = chrono::high_resolution_clock::now();
    int min = tree->min(0, i - i / 2);
    auto finish4 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration4 = finish4 - start4;


    cout << endl << "For example we can search min in range(0, i - i / 2). It will: " << min;
    cout << endl << "Iteration count: " << tree->IterationCountOfSearchingMinInRange;
    cout << endl << "Time: " << duration4.count() << endl;

    cout << endl << "----------END----------" << endl;
}






int main()
{

    int const size = 100;

    for (size_t i = 0; i < 51; i++)
    {
        vector<int> arrayNum(size + 250 * i);
        vector<int> treeArray((size + 200 * i) * 4);
        string path = "C:\\Users\\WUMBAch\\CLionProjects\\untitled\\cmake-build-debug\\FirstSemesterWork\\Tests\\" + to_string(i) + ".txt";

        arrayNum = Reading(arrayNum, size, path);

        testAllFunctions(arrayNum, treeArray, i);


    }
    return 0;
}
