#include<iostream>
#include<string>
using namespace std;

class Food{
private:
	const int index;
	static int noOfFoods;

	string name;
	char* brand;
	int noOfIngredients;
	string* ingredients;

public:
	

	Food():index(++noOfFoods) {
		this->name = "Unnamed";
		this->noOfIngredients = 0;
		this->brand = new char[strlen("Unknown") + 1];
		strcpy_s(this->brand, strlen("Unknown") + 1, "Unknown");
		this->ingredients = nullptr;
	}

	Food(string name, int noOfIngredients, string* ingredients, const char* brand) :index(++noOfFoods) {
		this->name = name;
		this->noOfIngredients = noOfIngredients;
		this->ingredients = new string[noOfIngredients];
		for (int i = 0; i < noOfIngredients; i++)
			this->ingredients[i] = ingredients[i];
		this->brand = new char[strlen(brand) + 1];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
	}

	Food(const Food& f) :index(++noOfFoods) {
		this->name = f.name;
		this->noOfIngredients = f.noOfIngredients;
		this->ingredients = new string[f.noOfIngredients];
		for (int i = 0; i < f.noOfIngredients; i++)
			this->ingredients[i] = f.ingredients[i];
		this->brand = new char[strlen(f.brand) + 1];
		strcpy_s(this->brand, strlen(f.brand) + 1, f.brand);
	}

	const Food& operator=(const Food& f) {
		if (this != &f) {
			this->name = f.name;
			this->noOfIngredients = f.noOfIngredients;
			if (this->ingredients != nullptr)
				delete[] this->ingredients;
			this->ingredients = new string[noOfIngredients];
			for (int i = 0; i < noOfIngredients; i++)
				this->ingredients[i] = f.ingredients[i];
			if (this->brand != nullptr) {
				delete[] this->brand;
			}
			this->brand = new char[strlen(f.brand) + 1];
			strcpy_s(this->brand, strlen(f.brand) + 1, f.brand);
		}
		return *this;
	}

	~Food() {
		if (this->ingredients != NULL) {
			delete[] ingredients;			
		}
		if (this->brand != nullptr) {
			delete[] brand;
		}
		cout << "index: " << index << " destructed" << endl;
	}

     Food& operator+(const Food& f) {
        Food* result = new Food();
        result->name = this->name + " + " + f.name;
        result->brand = new char[strlen(this->brand) + 1];
        strcpy_s(result->brand, strlen(this->brand) + 1, this->brand);
        result->noOfIngredients = this->noOfIngredients + f.noOfIngredients;
        result->ingredients = new string[result->noOfIngredients];
        for (int i = 0; i < this->noOfIngredients; i++)
            result->ingredients[i] = this->ingredients[i];
        for (int i = 0; i < f.noOfIngredients; i++)
            result->ingredients[this->noOfIngredients + i] = f.ingredients[i];
        return *result;
    }

	Food operator+(const string& ingredient)const {
		Food newFood = *this;
		string* aux = new string[noOfIngredients + 1];
		for (int i = 0; i < noOfIngredients; i++) {
			aux[i] = this->ingredients[i];
		}
		aux[noOfIngredients] = ingredient;
		delete[] newFood.ingredients;
		newFood.ingredients = aux;
		newFood.noOfIngredients++;
		cout << "index:" << newFood.index << endl;
		return newFood;		
	}

	void setBrand(const char* brand) {
		if (this->brand != nullptr) {
			delete[] this->brand;
		}
		if (brand != nullptr) {
			this->brand = new char[strlen(brand) + 1];
			strcpy_s(this->brand, strlen(brand) + 1, brand);
		}
		else {
			this->brand = nullptr;
		}
	}

	void setName(const string& name) {
		this->name = name;
	}

	void afisare() {
		cout << "Food index: " << index <<"; name: "<<name << " ; brand: " << brand << " ; no of ingredients: " << noOfIngredients << " ; ingredients: ";
		if (ingredients != nullptr) {
			for (int i = 0; i < noOfIngredients; i++)
				cout << ingredients[i] << " , ";
		}
		else {
			cout << "None";
		}
		
		cout << endl;
	}
};

int Food::noOfFoods = 0;