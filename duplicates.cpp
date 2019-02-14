//JP Villamor 3A Potter April 2018
#include "E:/cppsource/mylib.h"
using namespace std;
int main () {
	string master = "";
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char>Singles;
    vector<char>reporting;
    int Count[26];
	int line = 0;
	string coms[6] = {"RESET abracadabracabob", "REPORT 3", "REPORT 5", "ADD BATH", "DELETE boa", "REPORT 5"};
	while (line < 6) {
	    string command = coms[line];
	    string command1 = command.substr(0, command.find(" "));
	    string command2 = command.erase(0, command.find(" ")+1);
	    if (command1 == "RESET") {
	    	for (int a = 0; a < 26; a++) {
	    		Count[a] = 0;
			}
	        Singles.clear();
	        reporting.clear();
	        for (int b = 0; b < command2.length(); b++) {
	        	char c = command2[b];
	        	master += (char)toupper(c);
			}
	    }
	    else if (command1 == "REPORT") {
	    	int position = atoi(command2.c_str());
	    	for (int i = 0; i < master.length(); i++) {
	    		int L = 0;
	    		while (master[i] != letters[L]) {
	    			L++;
				}
				Count[L]++;
				for (int j = 0; j < 26; j++) {
					if (Count[j] > 0) {
						Singles.push_back(letters[j]);
						//cout << letters[j];
					}
				}
				if (Singles.size() >= position) {
					reporting.push_back(Singles[position-1]);
				}
				Singles.clear();
				//cout << endl;
			}
			for (int k = 0; k < reporting.size(); k++) {
				if (reporting[k] != reporting[k-1]) {
					cout << reporting[k];
				}
			}
			for (int a = 0; a < 26; a++) {
	    		Count[a] = 0;
			}
			reporting.clear();
			cout << endl;
	    }
	    else if (command1 == "ADD") {
            master += command2;
	    }
	    else if (command1 == "DELETE") {
            for (int m = 0; m < command2.length(); m++) {
                for (int n = 0; n < master.length(); n++) {
                    if ((char)toupper(command2[m]) == master[n]) {
                        master[n] = '-';
                    }
                }
            }
	    }
	    line++;
	}
    return 0;
}
