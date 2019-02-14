#include "E:/cppsource/mylib.h"
//JP Villamor 3A March 2018
#include <iostream>
using namespace std;
//int Qcounter = 0;
const int sz = 20;
int main () {
    int Pivot, End;
    int BigMama[sz] = {1, 2, 3, 4, 10, 9, 8, 7, 6, 5, 20, 19, 18, 17, 16, 15, 13, 11, 12, 14};
    //int BigMama[sz] = {1,1,1,1,1,0,1};
    cout << "size = " << sz << endl;
    Pivot = 0, End = sz-1;
    QSort(BigMama, Pivot, End, sz);
    //cout << "times Q called: " << Qcounter << endl;
    for (int x = 0; x < sz; x++) {
        cout << BigMama[x] << " ";
    }
    return 0;
}
