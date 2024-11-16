#include<iostream>
using namespace std;

class Base {
public:
	void honk() {
		cout << "beep" << endl;
	}
};

class A :  public Base {
public:
	void honk() {
		cout << "A beep" << endl;
	}

};

class B :  public Base {
public:
	void honk() {
		cout << "B beep" << endl;
	}
};

class Child :public A, public B{
public:
	void honk() {
		A::honk(); 
	}

};

int main() {
	Base base;
	A a;

	Child c;
	c.honk();
}