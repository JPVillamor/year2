//JP Villamor 3A Potter April 2018
#include "E:/cppsource/mylib.h"
using namespace std;
ifstream myinfile ("S://Public/CS/check/int.txt");
//ifstream myinfile ("D:/potter.txt");
int main () {
	string command;
	string command1;
    string command2;
	string master = "", letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", single = "";
    vector<string>Singles;
    vector<char>reporting;
    int Count[26];
	string temp;
	vector<string>coms;
	if (myinfile.is_open()) {
		while (myinfile.good()) {
			getline(myinfile, temp);
			coms.push_back(temp);
		}
		myinfile.close();
	}
	for (int line = 0; line < coms.size(); line++) {
	    command = coms[line];
	    command1 = command.substr(0, command.find(" "));
	    command2 = command.erase(0, command.find(" ")+1);
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
                if (Singles[q].length() >= position)
                    reporting.push_back(Singles[q][position-1]);
			}
			for (int k = 0; k < reporting.size(); k++) {
				if (reporting[k] != reporting[k-1])
					cout << reporting[k];
			}
			reporting.clear();
			cout << endl;
		}
	    else if (command1 == "ADD" || command1 == "DELETE") {
            for (int m = 0; m < command2.length(); m++) {
                command2[m] = (char)toupper(command2[m]);
                int L = 0;
	    		while (command2[m] != letters[L]) {
	    			L++;
				}
				if (command1 == "ADD")
					Count[L]++;
				else
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
	}
    return 0;
}
