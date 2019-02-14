#include <iostream>
#include <string>
using namespace std;
class Roman{
	public:
		Roman();		// default constructor  rStr = "Blank", iStr = 0;
		Roman(string);	 	// constructs a Roman Numeral  given a String. Calls
  		//convertToInt() to assign the correct numeric value
		Roman(int);		// construcs a Roman numeral given a int. Calls
						//convertToStr to assign the correct numeric value
		void setStr(string);	// Sets the Roman Numeral String
		string getStr();		// Returns the Roman Numeral
		void setInt(int);		// Sets the Roman Numeral Value
		int getInt();		// Returns the Roman Numeral Value
		void displayProp();	// Displays the String and Integer Values of the Roman Numeral
		void convertToInt(string);	// coverts the string to its integer value
		void convertToStr(int);		// converts the integer to its string vlaue
	private:
		string romanStr;
		int romanInt;
};
Roman::Roman() {
	romanStr = "Blank";
	romanInt = 0;
}
//Roman::Roman(string input)
//Roman::Roman(int inNumber) convert the int to int string, then use the length of the string to determine value.
void Roman::setStr(string input) {
	romanStr = input;
}
string Roman::getStr() {
	return romanStr;
}
void Roman::setInt(int numeral) {
    romanInt = numeral;
}
int Roman::getInt() {
    return romanInt;
}
void Roman::displayProp() {
	cout << getStr() << endl << getInt() << endl;
}
void Roman::convertToInt(string inputRoman) {
    inputRoman = getStr();
    int outInt = 0;
    int counter = 0;
    while (counter < inputRoman.length()) {
        if (inputRoman[counter] == 'm') {
            outInt+=1000;
        }
        if (inputRoman[counter] == 'd') {
            outInt+=500;
        }
        if (inputRoman[counter] == 'c') {
            outInt+=100;
        }
        if (inputRoman[counter] == 'l') {
            outInt+=50;
        }
        if (inputRoman[counter] == 'x') {
            outInt+=10;
        }
        if (inputRoman[counter] == 'v') {
            outInt+=5;
        }
        if (inputRoman[counter] == 'i') {
            outInt+=1;
        }
        counter++;
    }
    romanInt = outInt;
}
void Roman::convertToStr(int inInt) {
    int copyInt = getInt();
    string outRoman = "";
    while (copyInt > 0) {
        if (copyInt >= 1000) {
            copyInt-=1000;
            outRoman+="m";
        }
        else if (copyInt >= 500) {
            copyInt-=500;
            outRoman+="d";
        }
        else if (copyInt >= 100) {
            copyInt-=100;
            outRoman+="c";
        }
        else if (copyInt >= 50) {
            copyInt-=50;
            outRoman+="l";
        }
        else if (copyInt >= 10) {
            copyInt-=10;
            outRoman+="x";
        }
        else if (copyInt >= 5) {
            copyInt-=5;
            outRoman+="v";
        }
        else if (copyInt >= 1) {
            copyInt-=1;
            outRoman+="i";
        }
    }
    romanStr = outRoman;
}
int main () {
	Roman Julius;
	string defStr = Julius.getStr();
	int defInt = Julius.getInt();
	int choice = 0;
	while (choice != 4) {
		string inRoman, check1;
		int inInt, check2;
		cout << "[1] INPUT ROMAN  [2] INPUT INTEGER" << endl << "[3] DEFAULTS  [4] EXIT" << endl;
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "input Roman numeral: ";
				cin >> inRoman;
				Julius.setStr(inRoman);
				Julius.convertToInt(Julius.getStr());
				Julius.displayProp();
				break;
			case 2:
				cout << "input integer: ";
				cin >> inInt;
				Julius.setInt(inInt);
				Julius.convertToStr(Julius.getInt());
				Julius.displayProp();
				break;
			case 3:
				cout << "defaults: " << defStr << ", " << defInt << endl;
				cout << "enter Roman numeral: "; //convert to int, then convert back, then check.
				cin >> inRoman;
				Julius.setStr(inRoman);
				Julius.convertToInt(Julius.getStr());
				check2 = Julius.getInt();
				cout << "enter integer: ";
				cin >> inInt;
				Julius.setInt(inInt);
				Julius.convertToStr(Julius.getInt());
				check1 = Julius.getStr();
				if (check1 == inRoman && check2 == inInt) {
                    cout << "you entered correct data." << endl;
				}
				else  {
                    cout << "you entered incorrect data the correct int value is " << check2 << endl;
				}
				break;
			case 4:
				cout << "exiting..." << endl;
				break;
		}
	}
	return 0;
}

