//JP Villamor
//2/8/18
//Enloe HS
//Potter
//Int 5
//Contest #2
#include "E:/cppsource/myLib.h"
using namespace std;
ifstream myinfile ("S://Public/CS/ACSLinput/inttest.txt");
int checkOps (string str) {
    string ops = "+-/*";
    int in = 0;
    for (int op = 0; op < 4; op++) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ops[op]) {
                in = 1;
            }
        }
    }
    if (in == 1)
        return 1;
    else
        return 0;
}
int main () {
    string temporary, ops = "+-/*", nums = "0123456789";
    vector<string>inputs;
    if (myinfile.is_open()) {
		while (getline(myinfile, temporary)) {
			cout << temporary << endl;
			inputs.push_back(temporary);
		}
	}
	cout << endl;
	for (int x = 0; x < inputs.size(); x++) {
        int brackets = 0, parenth = 0, position = 0;
        if (x+1<6)
            cout << x+1 << ".";
        if (inputs[x].find("[") == -1 && inputs[x].find("]") != -1) {
            brackets = 1;
            while (position < inputs[x].length()) {
                string newstr = inputs[x];
                if (!(position < inputs[x].find(")") && position > inputs[x].find("(")) && position < inputs[x].find("]")) {
                    if (ops.find(inputs[x][position-1]) != -1 || ((position == 0) && nums.find(inputs[x][position]) != -1)) {
                        newstr.insert(position, "[");
                        string sub = newstr.substr(position, newstr.find("]")-position);
                        if (checkOps(sub) == 1) {
                            cout << "  " << position+1;
                        }
                    }
                }
                position++;
            }
        }
        if (inputs[x].find("]") == -1 && inputs[x].find("[") != -1) {
            brackets = 2;
            while (position <= inputs[x].length()) {
                string newstr = inputs[x];
                if (!(position < inputs[x].find(")") && position > inputs[x].find("(")) && position > inputs[x].find("[")) {
                    if (ops.find(inputs[x][position]) != -1 || ((position == inputs[x].length()) && nums.find(inputs[x][position-1]) != -1)) {
                        newstr.insert(position, "]");
                        string sub = newstr.substr(newstr.find("["), position-newstr.find("["));
                        if (checkOps(sub) == 1) {
                            cout << "  " << position+1;
                        }
                    }
                }
                position++;
            }
        }
        if (inputs[x].find("(") == -1 && inputs[x].find(")") != -1) {
            parenth = 1;
            while (position < inputs[x].length()) {
                string newstr = inputs[x];
                if (inputs[x].find("[") == -1 && inputs[x].find("]") == -1) {
                    if ((ops.find(inputs[x][position-1]) != -1  || (position == 0)) && position < inputs[x].find(")")) {
                        if ((nums.find(inputs[x][position]) != -1)) {
                            newstr.insert(position, "(");
                            string sub = newstr.substr(position, newstr.find(")")-position);
                            if (checkOps(sub) == 1) {
                                cout << "  " << position+1;
                            }
                        }
                    }
                }
                else if (position > inputs[x].find("[") && position < inputs[x].find(")")) {
                    if (nums.find(inputs[x][position]) != -1) {
                        if (ops.find(inputs[x][position-1]) != -1 || ((inputs[x][position-1] == '[') && nums.find(inputs[x][position]) != -1)) {
                            newstr.insert(position, "(");
                            string sub = newstr.substr(position, newstr.find(")")-position);
                            if (checkOps(sub) == 1) {
                                cout << "  " << position+1;
                            }
                        }
                    }
                }
                position++;
            }
        }
        if (inputs[x].find(")") == -1 && inputs[x].find("(") != -1) {
            parenth = 2;
            while (position < inputs[x].length()) {
                string newstr = inputs[x];
                if (inputs[x].find("[") == -1 && inputs[x].find("]") == -1) {
                    if (position > inputs[x].find("(")) {
                        if ((ops.find(inputs[x][position])) != -1) {
                            if ((nums.find(inputs[x][position-1])) != -1) {
                                    newstr.insert(position, ")");
                                    string sub = newstr.substr(newstr.find("("), position-newstr.find("("));
                                    if (checkOps(sub) == 1) {
                                        cout << "  " << position+1;
                                    }
                                }
                        }
                    }
                }
                else if (position > inputs[x].find("(")) {
                    if ((ops.find(inputs[x][position])) != -1 || inputs[x][position] == ']') {
                        if (nums.find(inputs[x][position-1]) != -1) {
                            newstr.insert(position, ")");
                            string sub = newstr.substr(newstr.find("("), position-newstr.find("("));
                            if (checkOps(sub) == 1) {
                                cout << "  " << position+1;
                            }
                        }
                    }
                }
                position++;
            }
        }
        cout << endl;
	}
    return 0;
}
