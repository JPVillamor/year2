//John Paul Villamor 3A Potter
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
const int arraysize = 25;
void Isort (int array1name[arraysize]) {
    for (int count1 = 0; count1 < arraysize; count1++) {
        for (int count2 = 0; count2 < arraysize; count2++) {
            if (array1name[count1] < array1name[count2]) {
                int tempint = array1name[count1];
                array1name[count1] = array1name[count2];
                array1name[count2] = tempint;
            }
        }
    }
}
void Dsort (double array2name[arraysize]) {
    for (int count1 = 0; count1 < arraysize; count1++) {
        for (int count2 = 0; count2 < arraysize; count2++) {
            if (array2name[count1] < array2name[count2]) {
                double tempdoub = array2name[count1];
                array2name[count1] = array2name[count2];
                array2name[count2] = tempdoub;
            }
        }
    }
}
void Csort (char array3name[arraysize]) {
    for (int count1 = 0; count1 < arraysize; count1++) {
        for (int count2 = 0; count2 < arraysize; count2++) {
            if (array3name[count1] < array3name[count2]) {
                char tempchar = array3name[count1];
                array3name[count1] = array3name[count2];
                array3name[count2] = tempchar;
            }
        }
    }
}
void output (int arrayname1[arraysize], double arrayname2[arraysize], char arrayname3[arraysize]) {
    ofstream outfile;
    outfile.open("C:/Users/JP/Desktop/potter.txt");
    for (int count1 = 0; count1 < arraysize; count1++) {
            outfile << arrayname1[count1] << " ";
            if ((count1+1)%10 == 0) {
                outfile << endl;
            }
    }
    outfile << endl;
    cout << "Integers in file." << endl;
    outfile.setf(ios::showpoint | ios::fixed);
    for (int count2 = 0; count2 < arraysize; count2++) {
        outfile << setprecision(3) << arrayname2[count2] << " ";
        if ((count2+1)%10 == 0) {
            outfile << endl;
        }
    }
    outfile << endl;
    cout << "Doubles in file." << endl;
    for (int count3 = 0; count3 < arraysize; count3++) {
        outfile << arrayname3[count3] << " ";
        if ((count3+1)%10 == 0) {
            outfile << endl;
        }
    }
    outfile << endl;
    cout << "Chars in file." << endl;
    outfile.close();
}
int main () {
    int intarray[arraysize];
    double doublearray[arraysize];
    char chararray[arraysize];
    srand(time(NULL));
    for (int icreate = 0; icreate < arraysize; icreate++) {
        intarray[icreate] = rand() % 10000;
    }
    for (int dcreate = 0; dcreate < arraysize; dcreate++) {
        doublearray[dcreate] = (rand() % 1001)/1000.0;
    }
    for (int ccreate = 0; ccreate < arraysize; ccreate++) {
        chararray[ccreate] = rand() % 256;
    }
    Isort(intarray);
    Dsort(doublearray);
    Csort(chararray);
    output(intarray, doublearray, chararray);
}

