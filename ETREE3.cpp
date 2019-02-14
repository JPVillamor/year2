//JP
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
    ENode *root;
public:
    Etree() {root = NULL;}
    void EInsert(ENode *node1, string exp, int &index);
    void Print(ENode *thing);
    void Calculate();
    void menu();
};
void Etree::EInsert(ENode *node1, string exp, int &index) {
    string ops = "+-*/";
    ENode *temp = new ENode (exp[index], 999, NULL, NULL);
    if (ops.find(temp->getData()) == -1) {
        string sub = exp.substr(index, 1);
        temp -> setP(atoi(sub.c_str()));
    }
    if (node1 -> getLeft() == NULL) {
        node1 -> setLeft(temp);
        if (ops.find(temp->getData()) != -1) {
            index++;
            EInsert(temp, exp, index);
        }
    }
    else if (node1 -> getLeft() != NULL && ops.find(node1 -> getLeft() -> getData()) != -1) {
        EInsert(node1->getLeft(), exp, index);
    }
    else if (node1 -> getRight() == NULL) {
        node1 -> setRight(temp);
        if (ops.find(temp->getData()) != -1) {
            index++;
            EInsert(temp, exp, index);
        }
    }
    else if (node1 -> getRight() != NULL && ops.find(node1 -> getRight() -> getData()) != -1) {
        EInsert(node1->getRight(), exp, index);
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
            for (int i = 0; i < x.length();i++) {
                if (i == 0) {
                    root = new ENode(x[i], 999, NULL, NULL);
                }
                else {
                    EInsert(root, x, i);
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
