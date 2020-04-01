#pragma once
#include <iostream>
#include <cstring>
#include "PharmacyDomain.h"
using namespace std;


class PharmacyRepository {
private:
	int capacity, elements;
	Medicine* med;

public:
	PharmacyRepository();
	
	int get_capacity() { return capacity; }
	int lenght() { return elements; }

	string get_name(int index) { return med[index].get_name(); }
	double get_concentration(int index) { return med[index].get_concentration(); }
	double get_price(int index) { return med[index].get_price(); }
	int get_quantity(int index) { return med[index].get_quantity(); }

	void operator=(const PharmacyRepository repo);

	void add_med(string name, double concentration, double price, int quantity);

	int find(string name, double concentration);

	bool update_med_name(int index, string name);
	bool update_med_concentration(int index, double concentration);
	bool update_med_price(int index, double price);
	bool update_med_quantity(int index, int quantity);

	bool remove_med(string name, double concentration);

	void sort_by_price();

	Medicine* get_all_med();

	~PharmacyRepository();
};