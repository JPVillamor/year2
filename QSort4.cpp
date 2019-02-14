#include "F:/cppsource/mylib.h"
//JP Villamor 3A March 2018
#include <iostream>
using namespace std;
//int Qcounter = 0;
const int sz = 7;
int main () {
    int Pivot, End;
    int BigMama[sz] = {2, 2, 2, 1, 2, 2, 2};
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
