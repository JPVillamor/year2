#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int main () {
    string original;
    string ops = "+-/*^";
    string nums = "1234567890";
    vector<int>terms;
    vector<int>terms2;
    cout << "Enter postfix: ";
    getline(cin, original);
    int counter = 0;
    
    while (counter < original.length()) {
        if (ops.find(original[counter]) != -1) {
        		string sub1 = original.substr(counter-2, 1);
                string sub2 = original.substr(counter-1, 1);
                int a = atoi(sub1.c_str());
                int b = atoi(sub2.c_str());
            if (original[counter] == '/') {
                terms.push_back(a/b);
            }
            else if (original[counter] == '*') {
                terms.push_back(a*b);
			}
			else if (original[counter] == '+') {
				terms.push_back(a+b);
			}
			else if (original[counter] == '-') {
				terms.push_back(a-b);
			}
			else if (original[counter] == '^') {
				int outcome = 1;
				for (int exp = 0; exp < b; exp++) {
					outcome*=a;
				}
				terms.push_back(outcome);
			}
        }
        counter++;
    }
    for (int i = 0; i < terms.size(); i++) {
    	cout << terms[i] << endl;
	}
    return 0;
}
