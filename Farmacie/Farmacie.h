#include<iostream>
#include<string>
using namespace std;

class Farmacie {
	private:
	static int no;
	const int CODunic;
	string adresa;
	int nrMedicamente;
	float* medicamente;
public:

	Farmacie():CODunic(++no) {		
		this->adresa = "adress";
		this->nrMedicamente = 0;
		this->medicamente = nullptr;
	}
	Farmacie(string adresa, int nrMedicamente, float* medicamente) :CODunic(++no) {
		if (adresa.length() > 0)
			this->adresa = adresa;
		if (nrMedicamente > 0)
			this->nrMedicamente = nrMedicamente;
		if (medicamente != nullptr) {
			this->medicamente = new float[this->nrMedicamente];
			for (int i = 0; i < nrMedicamente; i++) {
				this->medicamente[i] = medicamente[i];
			}
			delete[] medicamente;
		}
		else {
			this->medicamente = new float[this->nrMedicamente];
			for (int i = 0; i < nrMedicamente; i++) {
				this->medicamente[i] = 0;
			}
		}
			
	}

	Farmacie(const Farmacie& f):CODunic(++no){
		this->adresa = f.adresa;
		this->nrMedicamente = f.nrMedicamente;
		this->medicamente = new float[this->nrMedicamente];
		for (int i = 0; i < f.nrMedicamente; i++) {
			this->medicamente[i] = f.medicamente[i];
		}
	}

	const Farmacie& operator=(const Farmacie& f) {
		if (this != &f) {
			this->adresa = f.adresa;
			this->nrMedicamente = f.nrMedicamente;
			if (this->medicamente != nullptr) {
				delete[] medicamente;
			}
			this->medicamente = new float[f.nrMedicamente];
			for (int i = 0; i < f.nrMedicamente; i++) {
				this->medicamente[i] = f.medicamente[i];
			}
		}
		else {
			return *this;
		}

		
	}

	~Farmacie() {
		if (medicamente != nullptr)
			delete[] medicamente;
	}

	void setAdresa(string adresa) {
		this->adresa = adresa;
	}

	string getAdresa() {
		return this->adresa;
	}

	int getNtMedicamente() {
		return this->nrMedicamente;
	}

	int getCodUnic() {
		return this->CODunic;
	}


	bool operator>(const Farmacie& f) {
		return this->nrMedicamente>f.nrMedicamente;
	};

	int getMedicamenteIeftine(int prag) const {
		int count = 0;
		for (int i = 0; i < this->nrMedicamente; i++) {
			if (this->medicamente[i] < prag) {
				count++;
			}
		}
		return count;
	}

	friend ostream& operator<<(ostream& os, const Farmacie& f);
	friend istream& operator>>(istream& is, Farmacie& f);





};

ostream& operator<<(ostream& os, const Farmacie& f) {
	os << "CODunic: " << f.CODunic << endl;
	os << "Adresa: " << f.adresa << endl;
	os << "NrMedicamente: " << f.nrMedicamente << endl;
	os << "Medicamente: ";
	for (int i = 0; i < f.nrMedicamente; i++) {
		os << f.medicamente[i] << " ";
	}
	os << endl;
	return os;
}

istream& operator>>(istream& is, Farmacie& f) {
	cout << "Enter adresa: ";
	is >> f.adresa;
	cout << "Enter nrMedicamente: ";
	is >> f.nrMedicamente;
	if (f.medicamente != nullptr) {
		delete[] f.medicamente;
	}
	f.medicamente = new float[f.nrMedicamente];
	cout << "Enter medicamente: ";
	for (int i = 0; i < f.nrMedicamente; i++) {
		is >> f.medicamente[i];
	}
	return is;
}

int Farmacie::no = 0;