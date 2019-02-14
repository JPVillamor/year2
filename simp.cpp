#include <iostream>
using namespace std;
int main () {
	int a = 81, b = 9;
	int d = b;
	while ((a%d != 0 || b%d != 0) && d > 1) {
		d--;
	}
	a = a/d;
	b = b/d;
	cout << "a" << " = " << a << endl;
	cout << "b" << " = " << b << endl;
	return 0;
}
