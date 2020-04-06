#pragma once
#include <iostream>

using namespace std;

class Medicine {
private:
	string name;
	double concentration, price;
	int quantity;
public:

	Medicine() {
		name = "";
		price = -1;
		concentration = -1;
		quantity = -1;
	}
	Medicine(const Medicine& m2) {
		//copy constructor
		name = m2.name;
		price = m2.price;
		concentration = m2.concentration;
		quantity = m2.quantity;
	}
	Medicine(string name_constr, double concentration_constr, double price_constr, int quantity_constr) {
		name = name_constr;
		price = price_constr;
		concentration = concentration_constr;
		quantity = quantity_constr;
	}
	Medicine(Medicine& med) {
		name = med.name;
		price = med.price;
		concentration = med.concentration;
		quantity = med.quantity;
	}
	Medicine operator=(Medicine& med) {
		name = med.name;
		price = med.price;
		concentration = med.concentration;
		quantity = med.quantity;
		return *this;
	}

	string get_name() { return name; }
	void set_name(string alt_name) { name = alt_name; }
	double get_concentration() { return concentration; }
	void set_concentration(double alt_concentration) { concentration = alt_concentration; }
	double get_price() { return price; }
	void set_price(double alt_price) { price = alt_price; }
	int get_quantity() { return quantity; }
	void set_quantity(int alt_quantity) { quantity = alt_quantity; }

	~Medicine() {}
};
