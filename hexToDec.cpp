#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
string input[6];
int main () {
	int line = 0;
    ifstream infile("C:/Users/JP/Desktop/potter.txt");
    if (infile.is_open()) {
        while(infile.good()) {
            getline(infile, input[line++]);
            if(line == 6) {
            	break;
			}
        }
        infile.close();
    }
    string hexstring = input[0];
    cout << input[0] << endl;
    vector<string>singles;
    while (hexstring.length() > 0) {
        int space = hexstring.find(" ");
        string sub1 = hexstring.substr(0, space);
        singles.push_back(sub1);
        if (space != -1) {
            hexstring.erase(0, sub1.length()+1);
        }
        else if (space == -1){
            hexstring.erase(0, sub1.length()+1);
        }
    }
    char binaries[8][8];
    string input, nums = "0123456789", letters = "ABCDEF";
    int row = 0;
    for (int a = 0; a < singles.size(); a++) {
        input = singles[a];
        int total = 0, counter1 = input.length()-1, counter2 = 1, temp = 1, value;
        while (counter1 >= 0) {
            for (int i = 1; i < counter2; i++) {
                temp*=16;
            }
            int value;
            if (nums.find(input[counter1]) != -1) {
                string sub = input.substr(counter1, 1);
                value = atoi(sub.c_str());
            }
            else if (letters.find(input[counter1]) != -1) {
                if (input[counter1] == 'A') {
                    value = 10;
                }
                else if (input[counter1] == 'B') {
                    value = 11;
                }
                else if (input[counter1] == 'C') {
                    value = 12;
                }
                else if (input[counter1] == 'D') {
                    value = 13;
                }
                else if (input[counter1] == 'E') {
                    value = 14;
                }
                else if (input[counter1] == 'F') {
                    value = 15;
                }
            }
            total += temp*value;
            counter1--;
            counter2++;
        }
        vector<int>powersTwo;
        string output = "";
        int input2, temp2 = 1, total2 = 0;
        input2 = total;
        while (temp2 <= input2) {
            powersTwo.push_back(temp2);
            temp2*=2;
        }
        for (int i = powersTwo.size()-1; i >= 0; i--) {
            if (total2+powersTwo[i] <= input2) {
                output+="1";
                total2+=powersTwo[i];
            }
            else {
                output+="0";
            }
        }
        while (output.length()<8) {
            output = output.insert(0, "0");
        }
        for (int x = 0; x < 8; x++) {
            binaries[row][x] = output[x];
        }
        row++;
    }
    int check[8][8];
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            check[x][y] = 0;
        }
    }
    string command = "2 3 L 2";
    string r =  command.substr(0,1);
    command.erase(0,2);
    string c = command.substr(0,1);
    command.erase(0,2);
    char dnow = command[0];
    command.erase(0,2);
    int limit = atoi(command.c_str());
    cout << r << " " << c << " " << dnow << " " << limit << endl;
    int rnow = atoi(r.c_str())-1;
    int cnow = atoi(c.c_str())-1;
    char dnext = 'X';
    for (int moves = 0; moves < limit; moves++) {
        if (binaries[rnow][cnow] == '0') {
            if (dnow == 'L') {
                cnow++;
                if (cnow == 8) {
                    cnow = 0;
                }
            }
            else if (dnow == 'R') {
                cnow--;
                if (cnow == -1) {
                    cnow = 7;
                }
            }
            else if (dnow == 'B') {
                rnow--;
                if (rnow == -1) {
                    rnow = 7;
                }
            }
            else if (dnow == 'A') {
                rnow++;
                if (rnow == 8) {
                    rnow = 0;
                }
            }
        }
        else if (binaries[rnow][cnow] == '1') {
            check[rnow][cnow]++;
            if (check[rnow][cnow] == 5) {
                check[rnow][cnow] = 1;
            }
            if (dnow == 'L') {
            	if (check[rnow][cnow] == 1) {
            		dnext = 'B';
				}
				else if (check[rnow][cnow] == 2) {
            		dnext = dnow;
				}
				else if (check[rnow][cnow] == 3) {
            		dnext = 'A';
				}
				else if (check[rnow][cnow] == 4) {
            		dnext = 'R';
				}
				cnow++;
                if (cnow > 7) {
                    cnow = 0;
                }
            }
            else if (dnow == 'R') {
            	if (check[rnow][cnow] == 1) {
            		dnext = 'A';
				}
				else if (check[rnow][cnow] == 2) {
            		dnext = dnow;
				}
				else if (check[rnow][cnow] == 3) {
            		dnext = 'B';
				}
				else if (check[rnow][cnow] == 4) {
            		dnext = 'L';
				}
                cnow--;
                if (cnow < 0) {
                    cnow = 7;
                }
            }
            else if (dnow == 'B') {
            	if (check[rnow][cnow] == 1) {
            		dnext = 'R';
				}
				else if (check[rnow][cnow] == 2) {
            		dnext = dnow;
				}
				else if (check[rnow][cnow] == 3) {
            		dnext = 'L';
				}
				else if (check[rnow][cnow] == 4) {
            		dnext = 'A';
				}
                rnow--;
                if (rnow < 0) {
                    rnow = 7;
                }
            }
            else if (dnow == 'A') {
            	if (check[rnow][cnow] == 1) {
            		dnext = 'L';
				}
				else if (check[rnow][cnow] == 2) {
            		dnext = dnow;
				}
				else if (check[rnow][cnow] == 3) {
            		dnext = 'R';
				}
				else if (check[rnow][cnow] == 4) {
            		dnext = 'B';
				}
                rnow++;
                if (rnow > 7) {
                    rnow = 0;
                }
            }
            dnow = dnext;
        }
    }
    cout << rnow+1 << " " << cnow+1 << endl;
	return 0;
}
