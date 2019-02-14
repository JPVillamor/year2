//John Paul Villamor 3A 9/1/17
#include <iostream>
#include <math.h>
using namespace std;
void input (int &inputA, int &inputB, int &inputC) {
	cout << "Enter integer for a: ";
	cin >> inputA;
	cout << "Enter integer for b: ";
	cin >> inputB;
	cout << "Enter integer for c: ";
	cin >> inputC;
}
int calculate (int a1, int b1, int c1) {
    int Discriminant = (b1*b1 - (4*a1*c1));
    return Discriminant;
}
void output (int a2, int b2, int c2) {
    char sqRoot = 251, plusMinus = 241;
    int disc = calculate(a2, b2, c2);
    int pdisc = disc;
    int outRad, negB = -b2, inRad = 0; //later a conditional if inRad > 0
    int bottom = 2*a2;
    int posB = negB;
    if (negB < 0) { //we need a positive b later...
        posB = -negB;
    }
    if (disc < 0) {
        pdisc = -disc; //we need a positive discriminant later...
    }
    if ((int)(sqrt(pdisc)) != sqrt(pdisc)) { //Square root IS NOT nice:
        int cdown = pdisc;
        while (pdisc % (cdown*cdown) != 0 && cdown > 1) {
            cdown--;
        }
        outRad = cdown;
        inRad = pdisc / (cdown*cdown);
    }
    else { //Square root IS nice:
        outRad = sqrt(pdisc);
        inRad = 0;
    }
    if (b2 != 0) {
	    if (disc == 0) {
	    	while ((negB%posB != 0 || bottom%posB != 0) && posB > 1) {
	    		posB--;
			}
			negB /= posB;
			bottom /= posB;
			if (negB%bottom != 0) {
				cout << negB << "/" << bottom << " dr" << endl;
			}
			else {
				cout << negB / bottom << " dr" << endl;
			}
		}
		else {
			while ((negB%posB != 0 || bottom%posB != 0 || outRad%posB != 0) && posB > 1) {
	    			posB--;
				}
			negB /= posB;
			outRad /= posB;
			bottom /= posB;
			if (disc < 0) {
				if (bottom != 1 || bottom != -1) {
					cout << "(";
				}
				else {
					negB /= bottom;
					outRad /= bottom;
				}
				cout << negB << plusMinus;
				if (outRad > 1 && inRad > 0) {
					cout << outRad << "i" << sqRoot << inRad;
				}
				else if (outRad == 1 && inRad > 0){
					cout << "i" << sqRoot << inRad;
				}
				else if (outRad > 1 && inRad == 0) {
					cout << outRad << "i";
				}
				else {
					cout << "i";
				}
				if (bottom != 1 || bottom != -1) {
					cout << ")/" << bottom << endl;
				}
			}
			else {
				if (inRad > 0) {
					if (bottom != 1 || bottom != -1) {
					cout << "(";
					}
					else {
					negB /= bottom;
					outRad /= bottom;
					}
					cout << negB << plusMinus;
					if (outRad > 1) {
						cout << outRad;
					}
					cout << sqRoot << inRad;
					if (bottom != 1 || bottom != -1) {
					cout << ")/" << bottom << endl;
					}
				}
				else {
					int ans1 = negB + outRad;
					int ans2 = negB - outRad;
					int gcf = bottom;
					int bottom1 = bottom;
					if (bottom < 0) {
						gcf *= -1;
					}
					if (ans1%bottom != 0) {
						while ((ans1%gcf != 0 || bottom%gcf != 0) && gcf > 1) {
	    					gcf--;
						}
						ans1 /= gcf;
						bottom /= gcf;
						if (ans1 < 0 && bottom < 0) {
							cout << -ans1 << "/" << -bottom;
						}
						else {
							cout << ans1 << "/" << bottom;	
						}
					}
					else {
						cout << ans1/bottom;
					}
					cout << " , ";
					gcf = bottom1;
					if (bottom1 < 0) {
						gcf *= -1;
					}
					if (ans2%bottom1 != 0) {
						while ((ans2%gcf != 0 || bottom1%gcf != 0) && gcf > 1) {
	    					gcf--;
						}
						ans2 /= gcf;
						bottom1 /= gcf;
						if (ans2 < 0 && bottom1 < 0) {
							cout << -ans2 << "/" << -bottom1;
						}
						else {
							cout << ans2 << "/" << bottom1;	
						}
					}
					else {
						cout << ans2/bottom1;
					}
				}
			}
		}
	}
	else {
		if (disc == 0) {
			cout << "0 dr" << endl; 
		}
		else {
			int cdown2 = outRad;
			cout << plusMinus;
			while ((bottom%cdown2 != 0 || outRad%cdown2 != 0) && cdown2 > 1) {
			cdown2--;
			}
			bottom /= cdown2;
			outRad /= cdown2;
			if (outRad%bottom == 0) {
				cout << outRad/bottom;
				if (disc < 0) {
					cout << "i";
				}
				if (inRad > 0) {
					cout << sqRoot << inRad << endl;
				}
			}
			else {
				cout << "(" << outRad;
				if (disc < 0) {
					cout << "i";
				}
				if (inRad > 0) {
					cout << sqRoot << inRad;
				}
				cout << ")/" << bottom << endl;
			}	
		}
	}
}
int main () {
	int a, b, c;
	input(a, b, c);
	output(a, b, c);
	return 0;
}
