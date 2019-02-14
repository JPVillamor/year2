#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
int main () {
	while (1) { 
		vector<int>powersTwo;
		string output = "";
		int input, temp = 1, total = 0;
		cout << "integer: ";
		cin >> input;
		while (temp <= input) {
			powersTwo.push_back(temp);
			cout << temp << endl;
			temp*=2;
		}
		for (int i = powersTwo.size()-1; i >= 0; i--) {
			if (total+powersTwo[i] <= input) {
				output+="1";
				total+=powersTwo[i];
			}
			else {
				output+="0";
			}
		}
		while (output.length()<8) {
			output = output.insert(0, "0");
		}
		cout << output << endl;
	}
	return 0;
}
