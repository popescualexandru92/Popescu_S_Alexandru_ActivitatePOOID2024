#include<iostream>
#include<string>
#include "Food.h"
using namespace std;

int main() {
	Food f1;
	Food f2;
	f2.afisare();
	Food f3("paste", 3, new string[3]{"apa","oua","faina"}, "Ion");
	f3.afisare();
	Food f4(f3);
	f3.setBrand("Vasile");
	Food f5(f4);
	f5.setName("paine");	
	f1.afisare();
	f1 = f1 + "kethcup";
	f1.afisare();

	



	
}