#include<iostream>
#include<string>
#include "Farmacie.h"
using namespace std;

int main() {
	Farmacie f1;
	Farmacie f2;
	Farmacie f3("catena", 3, new float[6] {1, 2, 3,99,37,23});

	int n = f3.getMedicamenteIeftine(10);

	cout<<n;

}