#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<list>
#include<iterator>
using namespace std;

class Animal {
private:
	const int id;
	static int number;
	char* name;
	int legs;
public:
	Animal() :id(++number) {
		legs = 0;
		this->name = new char[strlen("Unknown") + 1];
		strcpy_s(this->name, strlen("Unknown") + 1, "Unknown");
	}

	Animal(const string name,int legs) :id(++number) {
		this->legs = legs;
		this->name = new char[name.length() + 1];
		strcpy_s(this->name, name.length() + 1, name.c_str());
	}

	int getLegs() const {
		return legs;
	}

	void setLegs(int legs) {
		this->legs = legs;
	}

	string getName() const {
		return string(name);
	}

	void setName(const string& newName) {
		delete[] name;
		name = new char[newName.length() + 1];
		strcpy_s(name, newName.length() + 1, newName.c_str());
	}

	~Animal() {
		delete[] name;
	}

	static int getTotal() {
		return number;
	}

	virtual string makeNoise() {
		return "Noise";
	}

	friend void operator<<(fstream& fs, const Animal& a) {
		fs << a.id << endl;
		fs << a.name << endl;
	}
};

int Animal::number = 0;

class Dog : public Animal {
public:
	Dog() : Animal("Dog",4) {};
	string makeNoise() override {
		return "Bark";
	}

};

void afisareLista(list<Animal*> animals) {
	list<Animal*>::iterator it;
	cout << endl;
	for (it = animals.begin(); it != animals.end(); it++)
		cout << (*it)->getName() << " ";
}

int main() {
	Animal a;
	Animal b("Rex",0);
	Dog d;

	vector<Animal*> v;
	v.push_back(&a);
	v.push_back(&b);
	v.push_back(&d);

	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->makeNoise()<<endl;
	}

	fstream fileStream("animals.txt", ios::out);
	fileStream << a;
	fileStream.close();

	list<Animal*> animals;
	animals.push_back(&a);
	animals.push_back(&b);
	animals.push_back(&d);
	animals.reverse();
	afisareLista(animals);


	

	
}