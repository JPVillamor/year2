#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
char board[8][8];
string convertHexToBin(char hex)
{
    if(hex=='0')
        return ("0000");

    else if(hex=='1')
        return ("0001");

    else if(hex=='2')
        return ("0010");

    else if(hex=='3')
        return ("0011");

    else if(hex=='4')
        return ("0100");

    else if(hex=='5')
        return ("0101");

    else if(hex=='6')
        return ("0110");

    else if(hex=='7')
        return ("0111");

    else if(hex=='8')
        return ("1000");

    else if(hex=='9')
        return ("1001");

    else if(hex=='A')
        return ("1010");

    else if(hex=='B')
        return ("1011");

    else if(hex=='C')
        return ("1100");

    else if(hex=='D')
        return ("1101");

    else if(hex=='E')
        return ("1110");

    else if(hex=='F')
        return ("1111");
}
string take[6];
void input()
{

    int a=0;
    ifstream myfile ("S://Public/CS/ACSL/acsl3.txt");//("walkin.txt");
    if (myfile.is_open())
    {
        while(myfile.good())
        {
            getline(myfile,take[a++]);
            if(a>5)
                break;
        }
        myfile.close();
    }
    else cout << "Unable to open" << endl;

    cout << take[0] << endl;
    string values=take[0];

    string rows[8];

    for(int i=0; i<8; i++)
    {
        rows[i]=values.substr(0,values.find(' '));
        values.erase(0,values.find(' ')+1);

        //cout << rows[i] << endl;
    }
    string hold;
    string rowsbin[8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<rows[i].size(); j++)
        {
            hold=convertHexToBin(rows[i][j]);
            rowsbin[i]=rowsbin[i]+hold;
        }

        if(rowsbin[i].size()<8)
        {
            rowsbin[i]="0000"+rowsbin[i];
        }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            board[i][j]=rowsbin[i][j];
        }
    }
}

void movement(char currentdirection, int &x, int &y)
{
    if(currentdirection=='L')
    {
        y=y+1;
        if(y==8)
        {
            y=0;
        }
    }
    else if(currentdirection=='R')
    {
        y=y-1;
        if(y==-1)
            y=7;
    }
    else if(currentdirection=='B')
    {
        x=x-1;
        if(x==-1)
            x=7;
    }
    else if(currentdirection=='A')
    {
        x=x+1;
        if(x==8)
            x=0;
    }
}

char checkinbox(char boardcopy[][8], char currentdirection, int x, int y)
{
    if(boardcopy[x][y]=='0')
        return(currentdirection);

    else if(boardcopy[x][y]=='1') //90 deg rotation
    {
        boardcopy[x][y]='2';

        if(currentdirection=='L')
        {
            currentdirection='B';
        }
        else if(currentdirection=='R')
        {
            currentdirection='A';
        }
        else if(currentdirection=='B')
        {
            currentdirection='R';
        }
        else if(currentdirection=='A')
        {
            currentdirection='L';
        }

        return (currentdirection);
    }

    else if(boardcopy[x][y]=='2') // continue the same direction
    {
        boardcopy[x][y]='3';
        return (currentdirection);
    }

    else if(boardcopy[x][y]=='3') // 270 deg turn
    {
        boardcopy[x][y]='4';

        if(currentdirection=='L')
        {
            currentdirection='A';
        }
        else if(currentdirection=='R')
        {
            currentdirection='B';
        }
        else if(currentdirection=='B')
        {
            currentdirection='L';
        }
        else if(currentdirection=='A')
        {
            currentdirection='R';
        }

        return (currentdirection);
    }

    else if(boardcopy[x][y]=='4') //360 deg turn, go backwards
    {
        boardcopy[x][y]='1';

        if(currentdirection=='L')
        {
            currentdirection='R';
        }
        else if(currentdirection=='R')
        {
            currentdirection='L';
        }
        else if(currentdirection=='B')
        {
            currentdirection='A';
        }
        else if(currentdirection=='A')
        {
            currentdirection='B';
        }

        return (currentdirection);
    }
}

int main() {
    input();
    for(int a=1; a<6; a++) {
        char boardcopy[8][8];
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                boardcopy[i][j]=board[i][j];
            }
        }
        int xval=(take[a][0])-'0';
        int yval=(take[a][2])-'0';
        char startdirection=take[a][4];
        int nummoves=(take[a][6])-'0';
        cout << xval << " " << yval << " "<< startdirection << " " << nummoves << endl;
        int newxval=xval-1, newyval=yval-1;
        char currentdirection=startdirection;
        for(int i=0; i<nummoves; i++) {
            currentdirection=checkinbox(boardcopy, currentdirection, newxval, newyval);
            movement(currentdirection, newxval, newyval);
        }
        cout << newxval+1 << " " << newyval+1 << endl;
    }
    return 0;
}
