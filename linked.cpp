#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node *next;
public:
    Node(int d, Node *n) {data = d; next = n;} //constructor
    int getData() {return data;}
    Node* getNext() {return (next); }
    void setData(int n) {data = n;}
    void setNext(Node *x) {next = x;}
};
class List {
private:
    Node *first;
public:
    List() {first = NULL;}
    void Add(int num);
    //void Remove();
    void Print();
    void trial();
    void menu();
};
void List::Add(int num) {
    //adding to beginning:
//    Node *newN = new Node(num, NULL);
//    newN -> setNext(first);
//    first = newN;
    //adding to the end:
//    Node *current = first;
//    Node *newN = new Node(num, NULL);
//    do {
//        //most important line of code in linked lists
//        current = current -> getNext(); //"The Slider"
//        if (current -> getNext() == NULL) {
//            current -> setNext(newN);
//            newN -> setNext(NULL);
//        }
//    }
//    while (current -> getNext() != NULL);
    //adding to the middle:
//    Node *current = first;
//    Node *newN = new Node(num, NULL);
//    do {
//        //most important line of code in linked lists
//        current = current -> getNext(); //"The Slider"
//        if (newN -> getData() > current -> getData() && newN -> getData() < current -> getNext() -> getData()) {
//            newN -> setNext(current -> getNext());
//            current -> setNext(newN);
//        }
//    }
//    while (current -> getNext() != NULL);
    //adding the first time:
    Node *newN = new Node(num, NULL);
    if (first == NULL) {
        first = new Node(num, NULL);
        first -> setNext(NULL);
    }
    //size 1
    else if (first -> getNext() == NULL){
        if (newN -> getData() > first -> getData()) {
            first -> setNext(newN);
            newN -> setNext(NULL);
        }
        else if (newN -> getData() <= first -> getData()) {
            newN -> setNext(first);
            first = newN;
        }
    }
    //size 2
    else {
        Node *current = first;
        do {
            if (newN -> getData() > current -> getData() && newN -> getData() < current -> getNext() -> getData()) {
                newN -> setNext(current -> getNext());
                current -> setNext(newN);
            }
            //most important line of code in linked lists
            current = current -> getNext(); //"The Slider"
        }
        while (current -> getNext() != NULL);
    }
}
void List::Print() {
    if (first != 0) {
        cout << "Whole List: " << endl;
        Node *current = first;
        do {
            cout << current -> getData() << endl;
            //most important line of code in linked lists
            current = current -> getNext(); //"The Slider"
            if (current -> getNext() == NULL) {
                cout << current -> getData() << endl;
            }
        }
        while (current -> getNext() != NULL);
    }
    else {
        cout << "NO LIST TO PRINT" << endl;
    }
}
void List::trial() {
    cout << "Hello" << endl;
    cout << first << endl; //spits out 0 not NULL
    //not created any nodes yet; linked list initialized to NULL in default instructor
//    first = new Node(5, NULL);//new is a command that creates a new OBJECT; does not need star
//    cout << first << endl;
//    cout << first -> getData() << endl;
//    cout << first -> getNext() << endl;
//    Node *temp = new Node(12, NULL); //needs star
//    cout << temp-> getData() << endl;
//    first -> setNext(temp);
//    cout << temp << endl;
//    cout << first -> getNext() << endl;
//    cout << first -> getNext() -> getData() << endl;
//    Node *potter = new Node(666, NULL);
//    temp -> setNext(potter);
//    cout << first -> getNext() -> getNext() -> getData() << endl;
    //cout << current -> getData() << endl;
    //Add(17);
    Add(17);
    Add(7);
    Add(17);
    Print();
    Add(10);
    Print();
}
void List::menu() {
    int option = 0;
    while (option != 4) {
        cout << "[1] Print" << endl;
        cout << "[2] Add" << endl;
        cout << "[3] Remove" << endl;
        cout << "[4] Exit" << endl;
        cout << " I: ";
        cin >> option;
        if (option == 1) {
            Print();
        }
        else if (option == 2) {
            int x;
            cout << "Add ";
            cin >> x;
            Add(x);
        }
    }
}
int main () {
    List mylist;
    mylist.trial();
    //mylist.menu();
    return 0;
}
