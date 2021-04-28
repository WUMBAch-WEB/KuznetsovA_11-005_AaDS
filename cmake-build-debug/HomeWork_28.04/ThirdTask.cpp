//
// Created by WUMBAch on 28.04.2021.
//
#include <iostream>
using namespace std;
int count = 0;
void SearchCountOfWays(int N, int M, int null)
{

    if((null == N -1) && (M == 0)){
        count++;
    }
    if ((null + 1 < N)){
        SearchCountOfWays(N, M, null + 1);
    }
    if ((M - 1) >= 0){
        SearchCountOfWays(N, M - 1, null);
    }


}

int main(){
    cout << "Enter N and M: ";
    int N;
    int M;
    cin >> N;
    cin >> M;
    cout << "Count of ways from start to end: ";
    SearchCountOfWays(N, M - 1, 0);
    cout << count;
    return 0;
}
