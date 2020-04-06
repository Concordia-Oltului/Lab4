#pragma once
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"

using namespace std;

class PharmacyController {
private:
	PharmacyRepository repo;
public:
	PharmacyController();

	PharmacyController(PharmacyRepository& repository);

	PharmacyController operator=(PharmacyController& other);

	string get_name(int index) { return repo.get_name(index); }
	double get_concentration(int index) { return repo.get_concentration(index); }
	double get_price(int index) { return repo.get_price(index); }
	int get_quantity(int index) { return repo.get_quantity(index); }

	int find(string name, double concentration) { return repo.find(name, concentration); }

	void add(string name, double concentration, int quantity = 1, double price = 0);

	bool remove(string name, double concentration, int quantity = 1);

	void update_name(string old_name, double concentration, string new_name);
	void update_concentration(string name, double old_concentration, double new_concentration);
	void update_price(string name, double concentration, double price);
	void update_quantity(string name, double concentration, double quantity);

	void sort_by_price();

	void print_grouped_by_price(double minim, double maxim);

	void show_max_quant(int quantity);

	void show_partial(string partial);

	void print_all();

	~PharmacyController();
};
