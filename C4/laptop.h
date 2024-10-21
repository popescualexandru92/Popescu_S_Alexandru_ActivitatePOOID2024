#include<iostream>
#include<string>
using namespace std;

class Laptop {
public:
    static int i;
    const int id = i;
    int ram;
    string CPU;
    float rezolutieEcran;
    bool cameraWeb;

    Laptop(int ram = 8, string CPU = "Intel",float rezolutie=13.3, bool cameraWeb=false) :id(i++) {
        this->ram = ram;
        this->CPU = CPU;
        this->rezolutieEcran=rezolutie;
        this->cameraWeb=cameraWeb;
    }



    ~Laptop(){
        
    }

    int getId(){
        return id;
    }

    int getRAM(){
        return ram;
    }

    string getCPU(){
        return CPU;
    }

    float getRezolutie(){
        return rezolutieEcran;
    }

    bool hasCameraWeb(){
        return cameraWeb;
    }

    void setRAM(int RAM){
        this->ram=RAM;
    }

    void setCPU(string CPU){
        this->CPU=CPU;
    }

    void setRezolutie(float rez){
        this->rezolutieEcran=rez;
    }

    void setCameraWeb(bool cameraWeb){
        this->cameraWeb=cameraWeb;
    }

 
    

    

    static int cateLaptopuri() {
        return i;
    }

    void modificaCPU(string newCPU);

    inline void modificaRAM(int newRam) {
        this->ram = newRam;
    }

};

int Laptop::i = 0;



void Laptop::modificaCPU(string newCPU) {
    this->CPU = newCPU;
}