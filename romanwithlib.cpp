//JOHN PAUL VILLAMOR 3A POTTER
#include <iostream>
#include "myLib.h"
using namespace std;
int main() {
	Roman Cornelius;
	int choice = 0;
	while (choice != 4) {
		string inRoman, check1;
		int inInt, check2;
		cout << "[1] INPUT ROMAN  [2] INPUT INTEGER  [3] DEFAULTS  [4] EXIT" << endl << "OPTION: " ;
		cin >> choice;
		if (choice == 1) {
			cout << "INPUT ROMAN NUMERAL: ";
			cin >> inRoman;
			Roman Julius(inRoman);
			Julius.displayProp();
		}
		else if (choice == 2) {
			cout << "INPUT INTEGER: ";
			cin >> inInt;
			Roman Julius(inInt);
			Julius.displayProp();
		}
		else if (choice == 3) {
			cout << "DEFAULTS: " << Cornelius.getStr() << " = " << Cornelius.getInt() << endl;
			cout << "INPUT ROMAN NUMERAL: ";
			cin >> inRoman;
			Roman Julius(inRoman);
			check2 = Julius.getInt();
			cout << "INPUT INTEGER: ";
			cin >> inInt;
			if (check2 == inInt) {
				cout << "YOU ENTERED VALID DATA." << endl;
			}
			else {
				cout << "YOU ENTERED INVALID DATA; THE CORRECT INT VALUE IS " << check2 << endl;
				Julius.displayProp();
			}
		}
		else if (choice == 4) {
            cout << "EXITING..." << endl;
		}
	}
	return 0;
}
