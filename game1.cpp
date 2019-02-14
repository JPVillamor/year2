#include <windows.h> //  header file for gotoxy
#include <stdio.h>     //header file for standard input output
#include "E:/cppsource/myLib.h"
using namespace std;
COORD coord = { 0,0 }; // this is global variable. center of axis is set to the top left corner of the screen
void gotoxy(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Piece {
private:
	int x, y, type, active;
public:
	Piece() { x = -1;y = -1;type = 0;active = 1; }
	int getX() { return(x); }
	int getY() { return(y); }
	int getT() { return(type); }
	int getA() { return(active); }
	void set(int x_pos, int y_pos, int t) { x = x_pos;y = y_pos;type = t; }//sets initial coordinates and animal type
	void set(int x_pos, int y_pos) { x = x_pos;y = y_pos; } //sets new coordinates (FOR WHEN YOU MOVE)
	void display();	//displays how a fox/hound is represented
	void out() { active = 0; }
	int operator<(Piece);
};
void Piece::display() {
	gotoxy(getX(), getY());
	if (getT() == 2) {
		cout << 'H';
	}
	else {
		cout << 'F';
	}
}
int Piece::operator<(Piece stuff2) {
	if (getY() <= stuff2.getY()) {
		return 1;
	}
	else {
		return 0;
	}
}
class Board {
private:
	Piece list[7];//creates 7 pieces ( default animals)
	int x1, y1, x2, y2;	// x1 y1 where you come from, x2 y2 where you go
	int status, winner;	// status = whose turn,````````````
	int inRange(int x, int y);// makes sure input is slightly valid
	int pieceAtLoc(int x, int y);// checks to see if there is a piece at the location you are trying to go to
	int spaceEmpty(int x, int y);// self-explanatory
	void display();	// displays the board and what is on the board (pieces)
	int validMove();// self-explanatory
	void move(); // encompasses moving a piece
	void turn();// encompasses concept of a turn
	void getCoords();// gets Coordinates
	int isTrapped(int x, int y);
	void checkFoxes();
public:
	Board();// Sets up the board
	void execute();	// Runs the entire board
	void BasicsTest();
};
void Board::display() {
	for (int width = 0; width < 11; width++) {
		int count = 0;
		for (int height = 1; height < 10; height++) {
			count++;
			gotoxy(width, height);
			if ((width == 0 || width == 9) && height < 9) {
				cout << '|';
			}
			else if (width < 10 && height > 0 && height < 9) {
				if (width % 2 == 0) {
					if (count % 2 != 0) {
						cout << " ";
					}
					else {
						cout << (char)254;
					}
				}
				else {
					if (count % 2 == 0) {
						cout << " ";
					}
					else {
						cout << (char)254;
					}
				}
			}
			else {
				if (height == 9 && width > 0 && width < 9) {
					cout << width;
				}
				if (width == 10 && height < 9) {
					cout << height;
				}
			}
		}
	}
	for (int pieces = 0; pieces < 6; pieces++) {
		list[pieces].display();
	}
}
Board::Board() {
	//Pieces that are hounds:



    list[0].set(2, 3, 2);
	list[1].set(2, 5, 2);
	list[2].set(6, 3, 2);
	list[3].set(7, 6, 2);

	//Pieces that are foxes:


	list[4].set(1, 4, 1);
	list[5].set(7, 4, 1);

	//That mysterious seventh piece:
	list[6].set(-1, -1, 0);
	//	list[6].set(-1, -1, 0);
}
int Board::inRange(int x, int y) {
	int checkOnBoard = 0, checkDistance = 0, checkEmpty = 0;
	if ((x<9) && (x>0) && (y<9) && (y>0)) {
		checkOnBoard = 1;
	}
	if (validMove() == 1) {
		checkDistance = 1;
	}
	if (spaceEmpty(x, y) == 1) {
		checkEmpty = 1;
	}
	if (checkOnBoard == 1 && checkDistance == 1 && checkEmpty == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int Board::pieceAtLoc(int x, int y) {
	int piece = 0, check = 0;
	while (piece<6 && check == 0) {
		if (list[piece].getX() == x && list[piece].getY() == y) {
			if ((status == -1 && list[piece].getT() == 2) || (status == 1 && list[piece].getT() == 1)) {
				if (list[piece].getA() == 1) {
					check = 1;
				}
			}
		}
		piece++;
	}
	return check;
}
int Board::spaceEmpty(int x, int y) {
	int piece = 0;
	while (piece < 6) {
		if (list[piece].getX() == x && list[piece].getY() == y) {
			return 0;
		}
		piece++;
	}
	if (piece == 6) {
		return 1;
	}
}
int Board::validMove() {
	for (int piece = 0; piece < 6; piece++) {
		if (list[piece].getX() == x1 && list[piece].getY() == y1) {
			if (x2 - x1 == 1 || x2 - x1 == -1) {
				if (list[piece].getT() == 1) {
					if ((y2 - y1 == -1 || y2 - y1 == 1)) {
						return 1;
					}
					else {
						return 0;
					}
				}
				else if (list[piece].getT() == 2) {
					if (y2 - y1 == 1) {
						return 1;
					}
					else {
						return 0;
					}
				}
			}
			else {
				return 0;
			}
		}
	}
}
int Board::isTrapped(int x, int y) {
	int strikes = 0;
	if (spaceEmpty(x-1, y-1) == 0) {
		strikes++;
	}
	if (spaceEmpty(x-1, y+1) == 0) {
		strikes++;
	}
	if (spaceEmpty(x+1, y-1) == 0) {
		strikes++;
	}
	if (spaceEmpty(x+1, y+1) == 0) {
		strikes++;
	}
	if (x == 1 && y != 8) {
		strikes+=2;
	}
	if (x == 1 && y == 8) {
		strikes+=3;
	}
	if (x == 8) {
		strikes+=2;
	}
	if (x != 1 && y == 8) {
		strikes+=2;
	}
	if (strikes == 4) {
        return 1;
    }
    else {
    	return 0;
	}
}
void Board::turn() {
	move();
	status = -status;
	//system("cls");
}
void Board::getCoords() {
	do {
		gotoxy(15, 1);
		cout << "Select x:    ";
		gotoxy(25, 1);
		cin >> x1;
		gotoxy(15, 2);
		cout << "Select y:    ";
		gotoxy(25, 2);
		cin >> y1;
		if (pieceAtLoc(x1, y1) == 0) {
			gotoxy(15, 3);
			cout << "pick valid piece            ";
		}
	} while (pieceAtLoc(x1, y1) == 0);
}
void Board::move() {
	getCoords();
	gotoxy(15, 3);
	for (int select = 0; select < 7; select++) {
		if (list[select].getX() == x1 && list[select].getY() == y1) {
			cout << "You selected ";
			if (list[select].getT() == 2) {
				cout << "Hound";
			}
			else {
				cout << "Fox";
			}
			cout << " at (" << list[select].getX() << "," << list[select].getY() << ").   ";
			do {
				gotoxy(15, 4);
				cout << "Move to x:    ";
				gotoxy(26, 4);
				cin >> x2;
				gotoxy(15, 5);
				cout << "Move to y:    ";
				gotoxy(26, 5);
				cin >> y2;
				if (inRange(x2, y2) == 0) {
					gotoxy(15, 6);
					cout << "invalid move!";
				}
			} while (inRange(x2, y2) == 0);
			list[select].set(x2, y2);
		}
	}
}
void Board::checkFoxes() {
	if (list[4].getA() == 1) {
	    if ((isTrapped(list[4].getX(), list[4].getY()) == 1) || ((list[4] < list[0]) && (list[4] < list[1]) && (list[4] < list[2]) && (list[4] < list[3]))) {
    	    list[4].out();
    	    if (isTrapped(list[4].getX(), list[4].getY()) == 1) {
    	    	gotoxy(0, 20); cout << "list[4] is trapped.";
			}
			else {
				gotoxy(0, 20); cout << "list[4] has won.";
			}
    	}
    }
    if (list[5].getA() == 1) {
	    if ((isTrapped(list[5].getX(), list[5].getY()) == 1) || ((list[5] < list[0]) && (list[5] < list[1]) && (list[5] < list[2]) && (list[5] < list[3]))) {
	        list[5].out();
	    	if (isTrapped(list[5].getX(), list[5].getY()) == 1) {
    	    	gotoxy(0, 21); cout << "list[5] is trapped.";
			}
			else {
				gotoxy(0, 21); cout << "list[5] has won.";
			}
	    }
	}
}
void Board::execute() {
	status = 1;
	Board();
	while (list[4].getA() == 1 || list[5].getA() == 1) {
		display();
		checkFoxes();
		gotoxy(0, 0);
		if (status == -1) {
			cout << "Hounds' turn!";
		}
		else {
			cout << "Foxes' turn! ";
		}
		turn();
		checkFoxes();
		gotoxy(15, 6); cout << "             ";
	}
	display();
	if ((list[4] < list[0] && list[4] < list[1] && list[4] < list[2] && list[4] < list[3]) && (list[5] < list[0] && list[5] < list[1] && list[5] < list[2] && list[5] < list[3])) {
		winner = 1;
	}
	else if ((list[4] < list[0] && list[4] < list[1] && list[4] < list[2] && list[4] < list[3]) || (list[5] < list[0] && list[5] < list[1] && list[5] < list[2] && list[5] < list[3])) {
		winner = 0;
	}
	else {
		winner = 2;
	}
	gotoxy(0,0);
	if (winner == 0) {
		cout << "IT'S A TIE!!!";
	}
	else if (winner == 1) {
		cout << "FOXES WIN!!! ";
	}
	else if (winner == 2) {
		cout << "HOUNDS WIN!!!";
	}
	gotoxy(0,16);
}
void Board::BasicsTest() {
	Piece p[7];
	cout << "  Test 1 - Piece Constructor (" << p[1].getX() << ", " << p[1].getY() << ")" << endl;
	p[1].set(5, 2);
	cout << "  Test 2 - Piece Set (" << p[1].getX() << ", " << p[1].getY() << ")" << endl;
	p[1].display();
	gotoxy(10, 1);
	int checkX, checkY;
	checkX = 5;
	checkY = 12;
	p[2].set(checkX, checkY);
	cout << " Piece 2 = (" << p[2].getX() << ", " << p[2].getY() << ")" << endl;
	if (inRange(p[2].getX(), p[2].getY()) == 1)	// may change to True
		cout << "Test 3 in Range WORKS!" << endl;		//if using Boolean
	else
		cout << "Test 3 in Range FAILS!" << endl;
	p[2].set(5, 2);
	cout << " Piece 2 = (" << p[2].getX() << ", " << p[2].getY() << ")" << endl;
	if (spaceEmpty(5, 2) == 1)	// may change to True if using Boolean
		cout << "Test 4 space Empty WORKS!" << endl;
	else
		cout << "Test 4 in space Empty FAILS!" << endl;
	if (pieceAtLoc(5, 2) == 1)	// may change to True if using Boolean
		cout << "Test 5 Piece at location WORKS!" << endl;
	else
		cout << "Test 5 Piece at location  FAILS!" << endl;

	p[0].set(1, 1, 1);		//if you did the game with horizonal
	p[1].set(2, 2, 1);		//movement, then switch the X and Y
	p[2].set(5, 1, 1);		//coordinates
	p[3].set(7, 1, 1);
	p[4].set(2, 6, 2);
	p[5].set(4, 8, 2);
	for (int i = 0;i<7;i++) {
		cout << " point " << i << "is -->" << p[i].getX() << " , " << p[i].getY() << ")  ";
		if ((p[i].getT() == 1) || (p[i].getT() == 2)) {
			p[i].display(); cout << endl;
		}
		else
			cout << "mystery???" << endl;
	}
	//	display();
	//
	//	move();		//Test 6 tests valid fox forward movement	2,6 -> 3,7
	//	display();
	//
	//	move();	 	//Test 7 tests invalid dog movement		1,1 -> 2,2
	//			//Test 8 tests invalid dog movement		2,2 -> 3,1
	//			//Test 9 tests valid dog movement		2,2 -> 3,3
	//	display();
	//
	//	move();		//Test 10 tests valid fox backward movement	3,7 -> 2,6
	//	display();

}
int main() {
	Board b;
	b.execute();
	//b.BasicsTest();
	return 0;
}
