#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void input (string &inputstring) {
    cout << "String: ";
    getline(cin, inputstring);
}
void output () {
    string str1;
    input(str1);
    string str2 = str1;
    int Bork = 0;
    int period = str1.find('.');
    int counter;
    for (int test = 0; test < 17; test++) {
        counter = 0;
        while (counter < str2.length()) {        	
            if (test == 0) {
                if (counter == period) {
                    Bork = 1;
                }
            }
            else if (test == 1) {
                if (str2[counter] == 't' && str2[counter+1] == 'h' && str2[counter+2] == 'e') {
                    str2[counter] = 'Z';
                    str2[counter+1] = str2[counter+2] = 'E';
                }
            }
            else if (test == 2) {
                if (str2[counter] == 'a' && str2[counter+1] == 'n') {
                    str2[counter] = 'U';
                    str2[counter+1] = 'N';
                }
            }
            else if (test == 3) {
                if (str2[counter] == 'a' && str2[counter+1] == 'u') {
                    str2[counter] = str2[counter+1] = 'O';                    
                }
            }
            else if (test == 4) {
                if (str2[counter] == 'a' && str2[counter+1] != ' ') {
                    str2[counter] = 'E';                    
            	}
            }
            else if (test == 5) {
            	if (str2[counter] == 'o') {
	                if (str2[counter+1] == 'w') {
	                    str2[counter] = str2[counter+1] = 'O';	                    
	                }
            	}
			}
			else if (test == 6) {
				if (str2[counter] == 'e') {
					if (str2[counter-1] == ' ' || counter == 0) {
						str2[counter] = 'I';
					}
				}
			}
            else if (test == 7) {
            	if (str2[counter] == 't' && str2[counter+1] == 'i' && str2[counter+2] == 'o' && str2[counter+3] == 'n') {
	                str2[counter] = 'S';
	                str2[counter+1] = 'H';
	                str2[counter+2] = 'U';
	                str2[counter+3] = 'N';	                
            	}
            }
			else if (test == 8) {
				if (str2[counter] == 'o') {
	                str2[counter] = 'U';	                
            	}
			}
            else if (test == 9) {
            	if (str2[counter] == 'i' && str2[counter+1] == 'r') {
	                str2[counter] = 'U';
	                str2[counter+1] = 'R';	                
            	}
			}
            else if (test == 10) {
            	if (str2[counter] == 'i' && counter != 0) {
            		if (str2[counter-1] != ' ') {
            			str2[counter] = 'E';
            			str2.insert(counter, "E");
            			for (int counter1 = counter; counter1 < str2.length() && str2[counter1] != ' '; counter1++) {
							counter = counter1;
						}
					}
				}
			}
            else if (test == 11) {
            	if (str2[counter] == 'e' && str2[counter+1] == 'n') {
	                if (str1[counter+2] == ' ' || counter+2 == period || counter+2 == str1.length()) {
	                    str2[counter] = str2[counter+1] = 'E';
	                }
            	}
			}
            else if (test == 12) {
            	if (str2[counter] == 'f') {
	                str2[counter] = 'F';
	                str2.insert(counter+1, "F");	                
            	}
			}
            else if (test == 13) {
            	if (str2[counter+1] == ' ' || str2[counter+1] == '.') {
            		if (str2[counter] == 'e') {
            			str2.insert(counter+1, "-A");
					}
				}
				else if (counter+1 == str2.length()) {
					if (str2[counter] == 'e') {
						str2 = str2 + "-A";
					}
				}
			}
            else if (test == 14) {
                if (str2[counter] == 'u') {
                    if (counter != 0 && str2[counter-1] != ' ') {
                        str2[counter] = 'O';
                        str2.insert(counter, "O");
                    }
                }
            }
            else if (test == 15) {
                if (str2[counter] == 'v') {
                    str2[counter] = 'F';                    
                }
            }
            else if (test == 16) {
                if (str2[counter] == 'w') {
                    str2[counter] = 'V';
                }
            }
            counter++;
        }
    }
    for (int letter = 0; letter < str2.length(); letter++) {
    	str2[letter] = tolower(str2[letter]);
	}
    cout << str2;
	if (Bork == 1) {
		cout << " Bork Bork Bork!"; 
	}
	cout << endl;
}
int main () {
    for (int grading = 0; grading < 12; grading++) {
        output();
    }
    return 0;
}

