#include <windows.h> //  header file for gotoxy
#include <stdio.h>     //header file for standard input output
#include "E:/cppsource/myLib.h"
COORD coord = { 0,0 }; // this is global variable. center of axis is set to the top left cornor of the screen
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
};
void Piece::display() {
	gotoxy(getX(), getY());
	if (getT() == 0) {
		cout << 'H';
	}
	else {
		cout << 'F';
	}
}
class Board {
private:
	Piece list[7];//creates 7 pieces ( default animals)
	int x1, y1, x2, y2;	// x1 y1 where you come from, x2 y2 where you go
	int status, winner;	// status = who’s turn,
	int inRange(int x, int y);// makes sure input is slightly valid
	int pieceAtLoc(int x, int y);// checks to see if there is a piece at the location you are trying to go to
	int spaceEmpty(int x, int y);// self-explanatory
	void display();	// displays the board and what is on the board (pieces)
	int validMove();// self-explanatory
	void move(); // encompasses moving a piece
	void turn();// encompasses concept of a turn
	void getCoords();// gets Coordinates
public:
	Board();// Sets up the board
	void execute();	// Runs the entire board
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
}
Board::Board() {
	display();
	//Pieces that are hounds:
	list[0].set(2, 1, 0);
	list[1].set(4, 1, 0);
	list[2].set(6, 1, 0);
	list[3].set(8, 1, 0);
	//Pieces that are foxes:
	list[4].set(1, 8, 1);
	list[5].set(5, 8, 1);
	//That mysterious seventh piece:
	list[6].set(-1, -1, 0);
}
int Board::inRange(int x, int y) {
    int checkOnBoard = 0, checkDistance = 0, checkEmpty = 0;
    if ((x<9) && (x>0) && (y<9) && (y>0)) {
        checkOnBoard = 1;
    }
    if (validMove() == 1) {
        checkDistance = 1;
    }
    if (pieceAtLoc(x2, y2)==0) {
        checkEmpty = 1;
    }
	if (checkOnBoard==1&&checkDistance==1&&checkEmpty==1) {
		return 1;
	}
	else {
        return 0;
	}
}
int Board::pieceAtLoc(int x, int y) {
    int piece = 0, check = 0;
	while (piece<6 && check==0) {
		if (list[piece].getX() == x && list[piece].getY() == y) {
			check = 1;
		}
		piece++;
	}
	return check;
}
int Board::spaceEmpty(int x, int y) {
	if (pieceAtLoc(x, y) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int Board::validMove() {
    if ((x2-x1==1||x2-x1==-1)&&(y2-y1==1||y2-y1==-1)) {
        return 1;
    }
    else {
        return 0;
    }
}
void Board::turn() {
	move();
	status = -status;
	system("cls");
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
        if (pieceAtLoc(x1, y1)==0) {
            gotoxy(15,3);
            cout << "pick non-empty space";
        }
    }
    while (pieceAtLoc(x1, y1)==0);
}
void Board::move() {
	getCoords();
	gotoxy(15, 3);
	for (int select = 0; select < 7; select++) {
		if (list[select].getX() == x1 && list[select].getY() == y1) {
			cout << "You selected ";
			if (list[select].getT() == 0) {
				cout << "Hound";
			}
			else {
				cout << "Fox";
			}
			cout << " at (" << list[select].getX() << "," << list[select].getY() << ").   ";
			do {
                gotoxy(15, 4);
                cout << "Move x:    ";
                gotoxy(23, 4);
                cin >> x2;
                gotoxy(15, 5);
                cout << "Move y:    ";
                gotoxy(23, 5);
                cin >> y2;
                if (inRange(x2, y2) == 0) {
                    gotoxy(15, 6);
                    cout << "invalid move!";
                }
			}
			while (inRange(x2, y2) == 0);
            list[select].set(x2, y2);
		}
	}
}
void Board::execute() {
	status = 1;
	while (!(list[4].getA() == 0 && list[5].getA() == 0)) {
		Board();
		for (int pieces = 0; pieces < 6; pieces++) {
			list[pieces].display();
		}
		gotoxy(0, 0);
		if (status == -1) {
			cout << "Hounds' turn!";
			turn();
		}
		else {
			cout << "Foxes' turn! ";
			turn();
		}
	}
}
int main() {
	Board b;
	b.execute();
	return 0;
}
