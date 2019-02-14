//JP Villamor 3A 16 Jan 2018
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main () {
    for (int i = 0; i < 5; i++) {
        string input, output, nums = "0123456789";
        output = "";
        cout << "enter formatted number: ";
        getline(cin, input);
        for (int counter = 0; counter < input.length(); counter++) {
            if (nums.find(input[counter]) != -1) {
                output = output + input[counter];
            }
        }
        cout << output << endl;
    }
    return 0;
}
