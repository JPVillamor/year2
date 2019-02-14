//JOHN PAUL VILLAMOR 3A POTTER
#include "E:/cppsource/myLib.h"
using namespace std;
const int arraysize = 10;
ifstream infile("H:/Desktop/example.txt");
void input (int ary[]) {
    if (!infile.is_open())
        infile.open("H:/Desktop/example.txt");
    int inNum, counter2 = 0;
    while (infile.good()) {
        infile >> inNum;
        ary[counter2] = inNum;
        counter2++;
    }
    infile.close();
}
void setRoman (Roman ary3[], int ary4[]) {
    for (int counter = 0; counter < arraysize; counter++) {
		ary3[counter].setInt(ary4[counter]);
		ary3[counter].convertToStr(ary3[counter].getInt());
	}
}
void output (Roman ary1[]) {
    for (int out = 0; out < arraysize; out++) {
		cout << ary1[out].getStr() << " , " << ary1[out].getInt() << endl;
	}
	cout << "# # # # # # # # # # # # #" << endl;
}
int main() {
    int arrayInt[arraysize], arrayInt1[arraysize];
    input(arrayInt); input(arrayInt1);
	Roman roms[arraysize], roms1[arraysize];
	Isort(arrayInt1, arraysize); setRoman(roms1, arrayInt1);
	setRoman(roms, arrayInt); Bsort(roms, arraysize);
	output(roms); output(roms1);
	return 0;
}
