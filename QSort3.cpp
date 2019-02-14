//JP Villamor 3A March 2018
#include <iostream>
using namespace std;
int Qcounter = 0;
const int sz = 20;
int single = 0;
int two = 0;
int onlyL = 0;
int onlyR = 0;
int split = 0;
void QSort(int ary[], int P, int E) {
    Qcounter++;
    if (P < E) {
        if (E == P+1) {
            two++;
            if (ary[E] < ary[P]) {
                int schwap = ary[E];
                ary[E] = ary[P];
                ary[P] = schwap;
            }
        }
        else {
            int i = P+1, S = P+1, j = E, done = 0;
            while (done != 1) {
                while (ary[i] <= ary[P] && i < E) {
                    i++;
                }
                while (ary[j] > ary[P] && j > P) {
                    j--;
                }
                if (i < j) {
                    int schwap = ary[i];
                    ary[i] = ary[j];
                    ary[j] = schwap;
                }
                else {
                    int schwap = ary[j];
                    ary[j] = ary[P];
                    ary[P] = schwap;
                    if (i == E) {
                        onlyL++;
                        QSort(ary, P, j-1);
                    }
                    else if (j == P) {
                        onlyR++;
                        QSort(ary, j+1, E);
                    }
                    else {
                        split++;
                        QSort(ary, P, j-1);
                        QSort(ary, j+1, E);
                    }
                    done = 1;
                }
			}
        }
    }
    else
        single++;
}
int main () {
    cout << "TEST RESULTS CHECK" << endl;
    cout << single << endl;
    cout << two << endl;
    cout << onlyL << endl;
    cout << onlyR << endl;
    cout << split << endl;
    int Pivot, End;
    //int BigMama[sz] = {2, 2, 2, 1, 2, 2, 2};
    int BigMama[sz] = {1, 2, 3, 4, 10, 9, 8, 7, 6, 5, 20, 19, 18, 17, 16, 15, 13, 11, 12, 14};

    //int BigMama[sz] = {5, 14, -3, 0, 22, 8, 1, 4, -14, 11};
    //int BigMama[sz] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 14};
    //int BigMama[sz] = {1, 2, 1, -2, 3, 4, -3, -4, 5, 3};
    cout << "size = " << sz << endl;
    Pivot = 0, End = sz-1;
    QSort(BigMama, Pivot, End);
    for (int x = 0; x < sz; x++) {
        cout << BigMama[x] << " ";
    }
    cout << endl;
    cout << "FINAL RESULTS CHECK" << endl;
    cout << single << endl;
    cout << two << endl;
    cout << onlyL << endl;
    cout << onlyR << endl;
    cout << split << endl;
    cout << "times Q called: " << Qcounter << endl;
    return 0;
}
