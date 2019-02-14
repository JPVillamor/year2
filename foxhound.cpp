#include<windows.h> //  header file for gotoxy
#include <stdio.h>     //header file for standard input output
#include "H:/myLib.h"
COORD coord={0,0}; // this is global variable. center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y) {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class Piece {
    private:
        int x,y,type,active;
    public:
        Piece() {x=-1;y=-1;type=0;active=1;}
        int getX() {return(x);}
        int getY() {return(y);}
        int getT() {return(type);}
        void set(int x_pos,int y_pos,int t)	{x=x_pos;y=y_pos;type=t;}//sets initial coordinates and animal type
        void set(int x_pos,int y_pos) {x=x_pos;y=y_pos;} //sets new coordinates (FOR WHEN YOU MOVE)
        void display();	//displays how a fox/hound is represented
        void out() {active = 0;}
};
void Piece::display() {
    if (getT() == 0) {
        cout << 'H';
    }
    else {
        cout << 'F';
    }
    cout << active;
}
class Board {
    private:
        Piece list[7];//creates 7 pieces ( default animals)
        int x1, y1, x2, y2;	// x1 y1 where you come from, x2 y2 where you go
        int status, winner;	// status = who’s turn,
        int inRange(int x,int y);// makes sure input is slightly valid
        int pieceAtLoc(int x,int y);// checks to see if there is a piece at the location you are trying //to go to
        int spaceEmpty(int x,int y);// self-explanatory
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
    for (int a = 0; a < 18; a++) {
        for (int b = 0; b < 18; b++) {
            gotoxy(a,b);
            if (a!=17 && b != 17) {
                if ((a==0||a==16)||(b==0||b==16)) {
                        cout << "#";
                }
                else if (a%2==0&&b!=17) {
                    cout << "|";
                }
                else if (b%2==0&&a!=17) {
                    cout << "-";
                }
                else {
                    if (a==b) {
                        cout << "N";
                    }
                }
            }
            else if (a==17&&b%2!=0) {
                    if (b!=17) {
                        cout << b/2+1;
                    }
                }
            else if (b==17&&a%2!=0) {
                if (a!=17) {
                    cout << a/2+1;
                }
            }
        }
    }
}
Board::Board() {
    display();
}
void Board::execute() {
    Board();
}
int main() {
    Board b;
    b.execute();
    return 0;
}
