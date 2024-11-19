#include<iostream>
#include<string>
#include <stdexcept>
using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;
public:
	Autobuz():idAutobuz(++nrAutobuze) {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = nullptr;
	}
	Autobuz(int capacitate, int nrPersoaneImbarcate,const char* producator) :idAutobuz(++nrAutobuze) {
		if (capacitate <= nrPersoaneImbarcate) {
			cout << "Error! Autobuzul cu id="<<this->idAutobuz<<" e invalid: nrPersoaneImbarcate > capacitate";
			throw "Error";
		}		
			this->capacitate = capacitate;
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
			if (producator != nullptr) {
				this->producator = new char[strlen(producator) + 1];
				strcpy_s(this->producator, strlen(producator) + 1, producator);
			}
			else {
				this->producator = nullptr;
			}
	}

	~Autobuz() {
		if (this->producator != nullptr) {
			delete[] producator;
		}
	}

	Autobuz(const Autobuz& a) :idAutobuz(++nrAutobuze) {
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (a.producator != nullptr) {
			this->producator = new char[strlen(a.producator) + 1];
			strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
		}
		else {
			this->producator = nullptr;
		}
	}
	
	const char* getProducator() const {
		return this->producator;
	}

	void setProducator(const char* newProducator) {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		this->producator = new char[(strlen(newProducator) + 1)];
		strcpy_s(this->producator, strlen(newProducator) + 1, newProducator);
	}

	int getNrPersoaneImbarcate() const {
		return this->nrPersoaneImbarcate;
	}

	void setNrPersoaneImbarcate(int newNr) {
		if (newNr <= capacitate)
			this->nrPersoaneImbarcate = newNr;
		else
			cout << "Error! Value not assigned! Nr persoane imbarcate > capacitate=" << this->capacitate << endl;
	}

	Autobuz& operator=(const Autobuz& a) {
		if (this != &a) {
			this->capacitate = a.capacitate;
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
			if (a.producator != nullptr) {
				delete[] this->producator;
				this->producator = new char[strlen(a.producator) + 1];
				strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Autobuz& a);

	int getNumarLocuriLibere() const {
		return this->capacitate - this->nrPersoaneImbarcate;
	}

	operator int() const {
		return this->nrPersoaneImbarcate;
	}

	bool operator>(const Autobuz& a) const {
		return this->capacitate > a.capacitate;
	}
};

int Autobuz::nrAutobuze = 0;
ostream&  operator<<(ostream& os, const Autobuz& a) {
	os << "ID: " << a.idAutobuz << ", capacitate: " 
		<< a.capacitate << ", nr persoane imbarcate: " <<a.nrPersoaneImbarcate 
		<< ", producator: " << a.producator << "."<<endl;
	return os;
}

int main() {
	Autobuz a1;
	Autobuz a2(21, 20, "Man");
	Autobuz a3(a2);
	a3.setProducator("Daimler");
	cout << a3.getProducator()<<endl;
	a3.setNrPersoaneImbarcate(22);
	cout << a3.getNrPersoaneImbarcate() << endl;
	a1 = a3;
	cout << a1.getNrPersoaneImbarcate() << ", " << a1.getProducator() << endl;
	cout << a1;
	cout <<"Nr locuri libere: "<< a1.getNumarLocuriLibere() << endl;
	Autobuz a4(10, 5, "NASA");
	cout << "Comparare: "<<(a4>a1?"Adevarat":"Fals");
}






/* xSă se definească clasa Autobuz care are câmpurile :

• nrAutobuze – întreg static – contorizează automat numărul de autobuze create;

• idAutobuz - intreg constant - id - ul unic al autobuzului

• capacitate – întreg – numărul de persoane care pot fi îmbarcate în autobuz pe locuri;

• nrPersoaneImbarcate – întreg – numărul de persoane aflate în autobuz.Nu poate fi mai mare decât capacitatea autobuzului;

• producator – char* -numele producătorului autobuzului.

XAtributele clasei se definesc în zona privată a clasei

XSă se definească pentru clasa Autobuz constructor fără parametri, constructor cu parametri și destructor.Constructorul cu parametri conține validări pentru parametrii primiți.

XSă se definească pentru clasa Autobuz constructorul de copiere și metode accesor(get si set) pentru doua atribute la alegere.Testați în funcția main().

XSă se supraîncarce pentru clasa Autobuz operatorul = (de atribuire) fără a genera memory leaks și să nu permită auto - atribuirea.Testați în funcția main().

XSă se supraîncarce operatorul << pentru afișarea obiectelor de tipul Autobuz.Elementele sunt afișate pe aceeași linie despărțite prin punct și virgulă și spațiu(; ).Testați în funcția main().

XSă se definească metoda getNumarLocuriLibere() care calculează și returnează numărul de locuri libere rămase în autobuz.Testați în funcția main().

XSă se supraîncarce operator de cast la int care determină numărul de persoane urcate deja în autobuz.Testați în funcția main().

XSă se supraîncarce operator> care va compara două autobuze după capacitatea acestora.Testați în funcția main().

Temele copiate sau create cu ChatGPT vor fi anulate iar lista cu persoanele respective va fi trimisa catre decanat.

Incarcati fisierul CPP pana joi, 21 noiembrie, ora 23:00"""*/