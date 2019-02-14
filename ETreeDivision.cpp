//JP
#include "F:/cppsource/myLib.h"
using namespace std;
class ENode {
private:
    char data;
    double p;
    ENode *left, *right;
public:
    ENode(char x, int pr, ENode *l, ENode *r) {data = x; p = pr; left = l; right = r;} //constructor
    char getData() {return data;}
    ENode* getLeft() {return (left); }
    ENode* getRight() {return (right); }
    double getP() {return p;}
    void setP(double v) {p = v;}
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
    void Calculate(ENode *thing);
    void menu();
};
void Etree::EInsert(ENode *node1, string exp, int &index) {
    string ops = "+-*/";
    ENode *temp = new ENode (exp[index], 999, NULL, NULL);
    if (ops.find(temp->getData()) == -1) {
        string sub = exp.substr(index, 1);
        temp -> setP(atoi(sub.c_str()));
        cout << "number" << endl;
    }
    else
        cout << "operator" << endl;
    node1 -> setLeft(temp);
    cout << "attach l" << endl;
    if (ops.find(temp->getData()) != -1) {
        index++;
        cout << "move l" << endl;
        EInsert(temp, exp, index);
    }
    index++;
    temp = new ENode (exp[index], 999, NULL, NULL);
    if (ops.find(temp->getData()) == -1) {
        string sub = exp.substr(index, 1);
        temp -> setP(atoi(sub.c_str()));
        cout << "number" << endl;
    }
    else
        cout << "operator" << endl;
    node1 -> setRight(temp);
    cout << "attach r" << endl;
    if (ops.find(temp->getData()) != -1) {
        index++;
        cout << "move r" << endl;
        EInsert(temp, exp, index);
    }
}
void Etree::Calculate(ENode *thing) {
    if (thing->getLeft()->getP() == 999) {
        cout << "move l" << endl;
        Calculate(thing->getLeft());
    }
    if (thing->getRight()->getP() == 999) {
        cout << "move r" << endl;
        Calculate(thing->getRight());
    }
    if (thing->getLeft()->getP() != 999 && thing->getRight()->getP() != 999) {
        cout << "solve" << endl;
        if (thing->getData() == '+') {
            thing->setP(thing->getLeft()->getP() + thing->getRight()->getP());
        }
        else if (thing->getData() == '-') {
            thing->setP(thing->getLeft()->getP() - thing->getRight()->getP());
        }
        else if (thing->getData() == '*') {
            thing->setP(thing->getLeft()->getP() * thing->getRight()->getP());
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
    while (option != 4) {
        cout << "[1] Print" << endl;
        cout << "[2] Input expression" << endl;
        cout << "[3] Calculate" << endl;
        cout << "[4] Exit" << endl;
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
            root = new ENode(x[0], 999, NULL, NULL);
            int i = 1;
            EInsert(root, x, i);
        }
        else if (option == 3) {
            if (root != NULL) {
                Calculate(root);
                cout << root -> getP() << endl;
            }
            else
                cout << "NO LIST" << endl;
        }
    }
}
int main () {
    Etree mytree;
    mytree.menu();
    return 0;
}
