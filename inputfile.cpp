#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream myinfile("C:/Users/JP/Desktop/example.txt");
int main () {
	vector<double>info;
	double hold;
	if (myinfile.is_open()) {
		int counter = 0;
		while (myinfile.good()) {
			myinfile >> hold;
			info.push_back(hold);
			counter++;
		}
	}
	else {
		cout << "unable to open" << endl;
	}
	double Principal = info[0], Rate = info[1];
	int Comp = (int)info[2];
	cout << Principal << endl << Rate << endl << Comp << endl;
	return 0;
}
