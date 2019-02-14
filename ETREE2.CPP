#include "E:/cppsource/myLib.h"
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
    void EInsert(ENode *node1, string exp, int index);
    void Print(ENode *thing);
    void Calculate();
    void menu();
};
void Etree::EInsert(ENode *node1, string exp, int index) {
    string ops = "+-*/";
    if (index == 0) {
        root = new ENode (exp[0], 999, NULL, NULL);
        current = root;
        index++;
        EInsert(current, exp, index);
    }
    else {
        while (index < exp.length()) {
            ENode *temp = new ENode (exp[index], 999, NULL, NULL);
            if (ops.find(temp->getData()) == -1) {
                string sub = exp.substr(index, 1);
                temp -> setP(atoi(sub.c_str()));
            }
            if (ops.find(current->getData()) != -1) {
                if (current -> getLeft() == NULL) {
                    current -> setLeft(temp);
                    index++;
                    if (ops.find(temp->getData()) != -1) {
                        EInsert(current->getLeft(), exp, index);
                    }
                }
                else if (current -> getRight() == NULL) {
                    current -> setRight(temp);
                    index++;
                    if (ops.find(temp->getData()) != -1) {
                        EInsert(current->getRight(), exp, index);
                    }
                }
            }
        }
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
            EInsert(current, x, 0);
//            for (int i = 0; i < x.length();i++) {
//                EInsert(current, x, i);
//            }
        }
    }
}
int main () {
    Etree mytree;
    mytree.menu();
    return 0;
}
