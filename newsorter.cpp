#include <iostream>
using namespace std;
int main () {
	int limit, sum = 0;
	cout << "how many # ";
	cin >> limit; 
	double List[limit];
	for (int num = 0; num < limit; num++) {
		cin >> List[num];
	}
	for (int num = 0; num < limit; num++) {
		for (int num1 = num+1; num1 < limit; num1++) {
			if (List[num] > List[num1]) {
				double temp = List[num];
				List[num] = List[num1];
				List[num1] = temp;	
			}
			
		}
	}
	for (int i = 0; i < limit; i++) {
		sum += List[i];	
		cout << List[i] << " ";
	}
	cout << endl << "Total = " << sum << endl;
	cout << "Avg = " << (double)sum/limit << endl;
	if (limit%2 != 0) {
		cout << "Median = " << List[(int)(limit/2)] << endl;
	}
	else {
		cout << "Median = " << (double)(List[limit/2-1] + List[limit/2])/2 << endl;
	}
	return 0;
}
