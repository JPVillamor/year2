//JP Villamor 3A Potter April 2018
#include "D:/cppsource/mylib.h"
using namespace std;
int main () {
	string master = "";
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<string>Singles;
    vector<char>reporting;
    int Count[26];
	int line = 0;
	ifstream myinfile ("D:/potter.txt");
	string temp;
	vector<string>coms;
	if (myinfile.is_open()) {
		while (getline(myinfile, temp)) {
			coms.push_back(temp);
		}
		myinfile.close();
	}
	while (line < coms.size()) {
	    string command = coms[line];
	    string command1 = command.substr(0, command.find(" "));
	    string command2 = command.erase(0, command.find(" ")+1);
	    if (command1 == "RESET") {
	    	for (int a = 0; a < 26; a++) {
	    		Count[a] = 0;
			}
			master = "";
	        Singles.clear();
	        reporting.clear();
	        for (int b = 0; b < command2.length(); b++) {
	        	char c = command2[b];
	        	master += (char)toupper(c);
			}
	    	string single = "";
	    	for (int i = 0; i < master.length(); i++) {
	    		int L = 0;
	    		while (master[i] != letters[L]) {
	    			L++;
				}
				Count[L]++;
				for (int j = 0; j < 26; j++) {
					if (Count[j] > 0) {
						single += letters[j];
						//cout << letters[j];
					}
				}
				//cout << endl;
				Singles.push_back(single);
				single = "";
			}
	    }
	    else if (command1 == "REPORT") {
			int position = atoi(command2.c_str());
			for (int q = 0; q < Singles.size(); q++) {
                if (Singles[q].length() >= position) {
                    reporting.push_back(Singles[q][position-1]);
                }
			}
			for (int k = 0; k < reporting.size(); k++) {
				if (reporting[k] != reporting[k-1]) {
					cout << reporting[k];
				}
			}
			reporting.clear();
			cout << endl;
	    }
	    else if (command1 == "ADD") {
            for (int m = 0; m < command2.length(); m++) {
                command2[m] = (char)toupper(command2[m]);
            }
            string single = "";
            for (int i = 0; i < command2.length(); i++) {
	    		int L = 0;
	    		while (command2[i] != letters[L]) {
	    			L++;
				}
				Count[L]++;
				for (int j = 0; j < 26; j++) {
					if (Count[j] > 0) {
						single += letters[j];
						//cout << letters[j];
					}
				}
				//cout << endl;
				Singles.push_back(single);
				single = "";
			}
	    }
	    else if (command1 == "DELETE") {
	        string single = "";
            for (int m = 0; m < command2.length(); m++) {
                command2[m] = (char)toupper(command2[m]);
                int L = 0;
	    		while (command2[m] != letters[L]) {
	    			L++;
				}
				Count[L]--;
                for (int j = 0; j < 26; j++) {
					if (Count[j] > 0) {
						single += letters[j];
						//cout << letters[j];
					}
				}
				//cout << endl;
				Singles.push_back(single);
				single = "";
            }
	    }
	    line++;
	}
    return 0;
}
