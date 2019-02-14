//JP Villamor 3A 16 Jan 2018
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
string input(string Input) {
    string inputCopy;
    cout << "Enter a number: ";
    getline(cin, Input);
    inputCopy = Input;
    return inputCopy;
}
string change(string rawNumber) {
    string changed;
    changed = rawNumber;
    if (rawNumber.length() == 10) {
        changed.insert(0, "(");
        changed.insert(4, ")");
        changed.insert(5, " ");
        changed.insert(9, "-");
    }
    else if (rawNumber.length() == 7) {
        changed.insert(0, "(919)");
        changed.insert(5, " ");
        changed.insert(9, "-");
    }
    else if (rawNumber.length() == 14) {
        changed.insert(0, "(");
        changed.insert(4, ")");
        changed.insert(5, " ");
        changed.insert(9, "-");
        changed.insert(14, " ext");
        changed.insert(18, " ");
    }
    else if (rawNumber.length() == 15 && rawNumber[0] == '1') {
        changed.insert(1, " ");
        changed.insert(2, "(");
        changed.insert(6, ")");
        changed.insert(7, " ");
        changed.insert(11, "-");
        changed.insert(16, " ext");
        changed.insert(20, " ");
    }
    return changed;
}
void output(string outStr) {
    cout << outStr << endl;
}
int main () {
    for (int i = 0; i < 5; i++) {
        string inputNum;
        output((change(input(inputNum))));
    }
    return 0;
}
