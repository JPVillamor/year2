//JOHN PAUL VILLAMOR 3A POTTER
#include "E:/C++ Source Code/myLib.h"
using namespace std;
const int arraysize = 10;
int main() {
	srand(time(NULL));
	int intarray[arraysize], a = 1;
	for (int icreate = 0; icreate < arraysize; icreate++) {
		intarray[icreate] = rand() % 5000 + 1;
	}
	Roman roms[arraysize];
	for (int counter = 0; counter < arraysize; counter++) {
		roms[counter].setInt(intarray[counter]);
		roms[counter].convertToStr(roms[counter].getInt());
	}
	for (int a = 0; a < 10; a++)
        cout << intarray[a] << endl;
    cout << endl;
    for (int x = 0; x < 10; x++)
        cout << roms[x].getInt() << ", " << roms[x].getStr() << endl;
	return 0;
}
