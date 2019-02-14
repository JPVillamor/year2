#include <iostream>
using namespace std;
class BNode {
private:
    string letter;
    BNode *left;
    BNode *right;
public:
    BNode(char d, BNode *l, BNode *r) {letter = d; left = l; right = r;} //constructor
    string getData() {return letter;}
    BNode* getLeft() {return (left); }
    BNode* getRight() {return (right); }
    void setData(string d) {letter = d;}
    void setLeft(BNode *l) {left = l;}
    void setRight(BNode *r) {right = r;}
};
class Btree {
private:
    BNode *root;
public:
    Btree() {root = NULL;}
    void Insert(string word);
    void Print(BNode *thing);
    void menu();
};
void Btree::Insert(string word) {
    root = new BNode(word[0], NULL, NULL);
    for (int i = 1; i < word.length(); i++) {
        BNode *current = root;
        int found = 0;
        BNode *temp = new BNode(word[i], NULL, NULL);
        while (found == 0) {
            if (temp -> getData() <= current -> getData()) {
                if (current -> getLeft() == NULL) {
                    current -> setLeft(temp);
                    found = 1;
                }
                else
                    current = current -> getLeft();
            }
            else {
                if (current -> getRight() == NULL) {
                    current -> setRight(temp);
                    found = 1;
                }
                else
                    current = current -> getRight();
            }
        }
    }
}
void Btree::Print(BNode *thing) {
    if (thing -> getLeft() != NULL) {
        Print(thing -> getLeft());
    }
    cout << thing -> getData();
    if (thing -> getRight() != NULL) {
        Print(thing -> getRight());
    }
}
void Btree::menu() {
    int option = 0;
    while (option != 3) {
        cout << "[1] Print" << endl;
        cout << "[2] Input word" << endl;
        cout << "[3] Exit" << endl;
        cout << " I: ";
        cin >> option;
        if (option == 1) {
            if (root != NULL) {
                Print(root);
            }
            else
                cout << "NO LIST TO PRINT";
            cout << endl;
        }
        else if (option == 2) {
            string x;
            cin.ignore();
            cout << "Word: ";
            getline(cin, x);
            Insert(x);
        }
    }
}
int main () {
    Btree mytree;
    mytree.menu();
    return 0;
}
