#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
ifstream myinfile("C:/Users/JP/Desktop/example.txt");
void input (double &Principal1, double &Rate1, int &Comp1) {
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
	Principal1 = info[0];
	Rate1 = info[1];
	Comp1 = (int)info[2];
}
void calc (double principal, double amount, double rate, double goal, int comp) {
    cout.setf(ios::showpoint | ios::fixed);
    int time = 0;
    amount = principal;
    do {
        cout << setprecision(2);
        amount = principal*(pow((1 + (rate/comp)),(comp*time)));
        cout << setw(2) << time << setw(8) << "$" << amount << endl;
        time++;
    }
    while (time < 11 && goal > amount);
    if (goal <= amount) {
        cout << "You\'ll reach your goal within " << time-1 << " year";
        if (time == 2) {
        	cout << "." << endl;
		}
		else {
			cout << "s." << endl;
		}
    }
    else {
        cout << "Goal not reached within 10 years." << endl;
    }
}
int main () {
    double Amount, Principal, Rate, Goal;
    int Comp;
    input(Principal, Rate, Comp);
    while (Goal <= Principal) {
    	cout << "Your goal: ";
    	cin >> Goal;
	}
    Rate /= 100;
    cout << "Year" << setw(12) << "Amount" << endl;
    calc(Principal, Amount, Rate, Goal, Comp);
    return 0;
}
