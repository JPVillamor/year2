#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;
struct PERSON {
    string name;
    int age;
};
void input (vector<PERSON>&vectname) {
	PERSON temp;
	temp.name = "Jompawl";
	temp.age = 17;
	cout << "Name: ";
	cin.ignore();
    getline(cin, temp.name);
    cout << "Age: ";
    cin >> temp.age;
    vectname.push_back(temp);
}
void sortp (vector<PERSON>&vectname) {
	PERSON temp;
	for (int counter1 = 0; counter1 < vectname.size(); counter1++) {
		for (int counter2 = counter1+1; counter2 < vectname.size(); counter2++) {
			if (vectname[counter1].age > vectname[counter2].age) {
                temp = vectname[counter1];
                vectname[counter1] = vectname[counter2];
                vectname[counter2] = temp;
			}
		}
	}
}
int findLength (vector<PERSON>vectname) {
    int longest = vectname[0].name.length();
    for (int element = 0; element < vectname.size(); element++) {
    	if (vectname[element].name.length() >= longest) {
    		longest = vectname[element].name.length();
		}
	}
    return longest;
}
void output (vector<PERSON>vectname) {
	int counter = 0;
	cout << setw(findLength(vectname)) << "Name" << "   Age" << endl;
	do {
		if (findLength(vectname) > 4) {
			cout << setw(findLength(vectname));
		}
		else {
			cout << setw(4);
		}
		cout << vectname[counter].name << " | "<< vectname[counter].age << endl;
		counter++;
	}
	while (counter < vectname.size());
}
int main () {
    vector<PERSON>People;
    vector<PERSON>Longs;
    int option = 0;
    while (option != 3) {
    	cout << "[1] INPUT PERSON" << "  " << "[2] OUTPUT DATA" << "  " << "[3] EXIT" << endl;
    	cin >> option;
    	if (option == 1) {
    		input(People);
		}
		else if (option == 2) {
            sortp(People);
			output(People);
			cout << endl << "# OF PEOPLE: " << People.size() << endl;
			cout << "LONGEST = " << findLength(People) << endl;
			cout << "Longest Name(s): " << endl;
			for (int elem = 0; elem < People.size(); elem++) {
				if (People[elem].name.length() == findLength(People)) {
					Longs.push_back(People[elem]);
				}
			}
			sortp(Longs);
			output(Longs);
			cout << endl;
			Longs.clear();
		}
	}
    return 0;
}

