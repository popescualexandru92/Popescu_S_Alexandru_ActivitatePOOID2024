#include<iostream>
#include<string>
using namespace std;

class Laptop {
public:
    static int i;
    const int id = i;
    int ram;
    string CPU;

    ~Laptop(){
        
    }

    void modificaCPU(string newCPU);

    inline void modificaRAM(int newRam) {
        this->ram = newRam;
    }

    Laptop(int ram = 8, string CPU = "Intel") :id(i++) {
        this->ram = ram;
        this->CPU = CPU;
    }

    static int cateLaptopuri() {
        return i;
    }


};

int Laptop::i = 0;



void Laptop::modificaCPU(string newCPU) {
    this->CPU = newCPU;
}



int main() {
    Laptop l;
    Laptop l1;

    l1.modificaRAM(64);

    cout<<l1.ram<<endl;



    cout << Laptop::cateLaptopuri();




}