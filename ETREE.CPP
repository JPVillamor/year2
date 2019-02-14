#include "F:/cppsource/myLib.h"
using namespace std;
class ENode {
private:
    char data;
    int p;
    ENode *left, *right;
public:
    ENode(char x, int pr, ENode *l, ENode *r) {data = x; p = pr; left = l; right = r;} //constructor
    char getData() {return data;}
    ENode* getLeft() {return (left); }
    ENode* getRight() {return (right); }
    int getP() {return p;}
    void setP(int v) {p = v;}
    void setValue(char x) {data = x;}
    void setLeft(ENode *l) {left = l;}
    void setRight(ENode *r) {right = r;}
};
class Etree {
private:
    ENode *root, *current;
public:
    Etree() {root = NULL;}
    void EInsert(ENode *node1, ENode *node2, ENode *current);
    void Print(ENode *thing);
    void Calculate();
    void menu();
};
void Etree::EInsert(ENode *node1, ENode *node2, ENode *current) {
    int found = 0;
    string ops = "+-*/";
    if (current -> getLeft() != NULL && ops.find(current -> getLeft() -> getData()) != -1) {
        cout << "move left" << endl;
        EInsert(node1, node2, current->getLeft());
    }
    cout << "attach left" << endl;
    cout << "attach right" << endl;
    if (current -> getRight() != NULL && ops.find(current -> getRight() -> getData()) != -1) {
        cout << "move right" << endl;
        EInsert(node1, node2, current->getRight());
    }
}
void Etree::Print(ENode *thing) {
    if (thing -> getLeft() != NULL) {
        Print(thing -> getLeft());
    }
    cout << thing -> getData();
    if (thing -> getRight() != NULL) {
        Print(thing -> getRight());
    }
}
void Etree::menu() {
    int option = 0;
    string ops = "+-*/";
    while (option != 3) {
        cout << "[1] Print" << endl;
        cout << "[2] Input expression" << endl;
        cout << "[3] Exit" << endl;
        cout << " I: ";
        cin >> option;
        if (option == 1) {
            if (root != NULL) {
                Print(root);
                cout << endl;
            }
            else
                cout << "NO LIST TO PRINT" << endl;
        }
        else if (option == 2) {
            string x;
            cout << "Exp: ";
            cin.ignore();
            getline(cin, x);
            for (int i = 0; i < x.length(); i++) {
                if (i == 0) {
                    root = new ENode (x[i], 999, NULL, NULL);
                }
                else {
                    current = root;
                    ENode *temp1 = new ENode (x[i], 999, NULL, NULL);
                    if (ops.find(x[i]) == -1) {
                        string sub = x.substr(i, 1);
                        temp1 -> setP(atoi(sub.c_str()));
                    }
                    ENode *temp2 = new ENode (x[i+1], 999, NULL, NULL);
                    if (ops.find(x[i+1]) == -1) {
                        string sub = x.substr(i+1, 1);
                        temp1 -> setP(atoi(sub.c_str()));
                    }
                    EInsert(temp1, temp2, root);
                    i++;
                }
            }
        }
    }
}
int main () {
    Etree mytree;
    mytree.menu();
    return 0;
}
