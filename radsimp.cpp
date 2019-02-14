//Radical Simplifier

#include <iostream>
#include <math.h>

using namespace std;

int main () {
	char sqRoot = 251;
	int test = 18, outRad, inRad;
	if ((int)sqrt(test) != sqrt(test)) {
		int countdown = sqrt(test);
		while (test % (countdown*countdown) != 0 && countdown > 1) {
			countdown--;
		}
		outRad = countdown;
		inRad = test / (countdown*countdown);
		if (outRad != 1) {
			cout << outRad << sqRoot << inRad << endl;
		}
		else {
			cout << sqRoot << inRad << endl;
		}


	}
	else {
		cout << sqRoot << test << " is " << sqrt(test) << endl;
	}
	return 0;
}
