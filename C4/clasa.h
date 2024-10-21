#include<cstring>
using namespace std;

class Clasa{
    public:
    char* pointer ;
    int atribut;

    Clasa(){
        this->pointer=NULL; 
    }

    Clasa( const Clasa &c){
        this->pointer=new char[strlen(c.pointer)+1];
        strcpy(this->pointer, c.pointer);
        this->atribut=c.atribut;
       
    }

    Clasa operator=(const Clasa &c){
        if(this->pointer !=NULL){
            delete[]this->pointer;
            
        }
        this->pointer = new char[strlen(c.pointer)+1];
        strcpy(this->pointer, c.pointer);
        this->atribut=c.atribut;
        cout<<"Apelare constr copiere"<<endl;
        return *this;
    }
    
    
    };