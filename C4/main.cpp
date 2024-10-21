#include<iostream>
#include<string>
#include<cstring>
#include "laptop.h"
#include "clasa.h"
using namespace std;

int main() {
    Laptop l1;
    Laptop l2= Laptop(16,"AMD",15.5, true);
    Laptop l3(32,"Nvidia",19.9,true);

    cout<<l3.getRezolutie()<<endl;
  
    Clasa c1;
    c1.pointer=new char[strlen("text")+1];
    strcpy(c1.pointer  ,"text");
    c1.atribut=10;

    Clasa c2=c1;
    strcpy(c2.pointer,"newT");
    cout<<c1.pointer;

    Clasa c3;
    c3=c2;

}
