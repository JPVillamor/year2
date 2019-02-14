#include <iostream>

using namespace std;

class add{
	private:
		int a,b,c;
	public:
		int d;
		void input();
		void sum();
		void dip();
		int  geta();
		void operator-();
		void operator+(add);
};

void add::input(){
	cout<<"Enter three numbers:";
	cin>>a>>b>>c; //no setter needed because you're in the class already
}

int add::geta(){
	return(a);
}

void add::sum(){
	d=a+b+c;
}
void add::dip(){
	cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<"the sum is "<<d<<endl;
}
void add::operator-(){ //operator is a reserved word. In this case the operator is meant to negate.
    //negation is actually arbitrarily defined by the user.
	a=-a; b=b; c=-2*c;
}

void add::operator+(add a2){
	cout<<a + a2.geta() <<endl;
	cout<<"Sweet!";
}
int main(){
    add a1, a2;
    a1.input();
    a1.sum();
    a1.dip();
    -a1;
    a1.sum();
    a1.dip();
    a2.input();
    a2.dip();
    a1+a2;
	return 0;
}
