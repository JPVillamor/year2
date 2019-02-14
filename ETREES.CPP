//maulik
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class Enode
{
private:
    char data;
    int p;
    Enode *left, *right;

public:
    Enode(char x, int pr, Enode *l, Enode *r)
    {
        data=x;
        p=pr;
        left=l;
        right=r;
    }
    char getData()
    {
        return(data);
    }
    Enode* getLeft()
    {
        return(left);
    }
    Enode* getRight()
    {
        return(right);
    }
    int getP()
    {
        return(p);
    }
    void setValue(char x)
    {
        data=x;
    }
    void setLeft(Enode *t)
    {
        left=t;
    }
    void setRight(Enode *t)
    {
        right=t;
    }
    void setP(int x)
    {
        p=x;
    }
};

class Etree
{
private:
    Enode *root;
public:
    Etree()
    {
        root=NULL;
    }

    void menu();
    void Einsert(Enode *,string,int);
    //void removefromBtree(int);
    void print(Enode*);
    void calculate(Enode*);
};

void Etree::menu()
{
    int take=0;
    string expression;
    string temp;
    do
    {
        cout << endl << endl;
        cout << "(1) Print" << endl;
        cout << "(2) Input" << endl;
        cout << "(3) Calculate" << endl;
        cout << "(4) END" << endl;
        cin >> take;
        cout << endl;

        if(take==1)
        {
            if(root==NULL)
            {
                cout << "TREE IS EMPTY" << endl;
            }
            else
                print(root);
        }

        else if(take==2)
        {
            root=NULL;
            cout << "Input Expression: " << endl;
            cin >> expression;
            //for(int i=0; i<expression.size(); i++)
            {
                temp=expression;
                //cout << temp << endl;
                Einsert(root,temp,0);
            }
            //potter entered
            //cout<<root->getRight()->getLeft()->getRight()->getData();
        }

        else if(take==3)
        {
            calculate(root);
        }

    }
    while(take!=4);
}

void Etree::print(Enode* current)
{
    if(current->getLeft()!=NULL)
    {
        print(current->getLeft());
    }

    cout << current->getData();

    if(current->getRight()!=NULL)
    {
        print(current->getRight());
    }
}

void Etree::Einsert(Enode *current, string expression, int location)
{
    if(root==NULL)
    {
        char c=expression[location];
        Enode *temp=new Enode(c, 999, NULL, NULL);
        root=temp;

        //cout << root->getData() << root->getP() << endl;

        Einsert(root,expression,location+1);
    }
    else
    {
        if((expression[location]=='+') || (expression[location]=='-') || (expression[location]=='*') || (expression[location]=='/'))
        {
            char c=expression[location];
            Enode *temp=new Enode (c, 999, NULL, NULL);
            current->setRight(temp);
            if(expression.size()-1!=location)
            {
                Einsert(current->getRight(),expression, location+1);
            }
        }
        else
        {
            int number=int(expression[location])-48;
            cout << number << endl;
            char c=expression[location];
            Enode *temp=new Enode(c,number,NULL, NULL);
            //cout << temp->getData() << temp->getP() << endl;
            //cout << current << endl;
            if(current->getLeft()==NULL)
            {
                //cout << "setting left" << endl;
                current->setLeft(temp);
                Einsert(current, expression, location+1);
            }
            else
            {
                //cout << "setting right" << endl;
                current->setRight(temp);
            }
        }
    }
}

void Etree::calculate(Enode *current)
{
    //calculate
}

int main()
{
    Etree e;
    e.menu();
}
