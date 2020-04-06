#include "PharmacyController.h"
#include <iostream>
#include <vector>

using namespace std;

PharmacyController::PharmacyController() {
	PharmacyRepository other;
	repo = other;
}

PharmacyController::PharmacyController(PharmacyRepository& repository) {
	repo = repository;
}

PharmacyController PharmacyController::operator=(PharmacyController& other){
	repo = other.repo;
	return *this;
}

void PharmacyController::update_name(string old_name, double concentration, string new_name){
	/*
	Changes medicine name with another name
	Input:
		old_name (string)
		concentration (double)
		new_name (string)
	@author: Stefan
	*/
	int index = repo.find(old_name, concentration); //search if medicine exist in list
	if (index != -1)
		repo.update_med_name(index, new_name);
}

void PharmacyController::update_concentration(string name, double old_concentration, double new_concentration){
	/*
	Changes medicine concentration with another concentration 
	Input:
		name (string)
		old_concentration (double)
		new_concentration (double)
	@author: Stefan
	*/
	int index = repo.find(name, old_concentration); //search if medicine exist in list
	if (index != -1)
		repo.update_med_concentration(index, new_concentration);
}

void PharmacyController::update_price(string name, double concentration, double price){
	/*
	Changes medicine price with another price 
	Input:
		name (string)
		concentration (double)
		price (double)
	@author: Stefan
	*/
	int index = repo.find(name, concentration); //search if medicine exist in list
	if (index != -1)
		repo.update_med_price(index, price);
}

void PharmacyController::update_quantity(string name, double concentration, double quantity){
	/*
	Changes medicine quantity with another quantity
	Input:
		name (string)
		concentration (double)
		quantity (int)
	@author: Stefan
	*/
	int index = repo.find(name, concentration); //search if medicine exist in list
	if (index != -1)
		repo.update_med_quantity(index, quantity);
}

void PharmacyController::sort_by_price(){
	//sort elements from rository by price
	repo.sort_by_price();
}

void PharmacyController::show_max_quant(int quantity) {
	/*
	Prints all medicine with a lower quantity than provided to the console
	Input:
		quantity (int) - provided quantity
	@author: Victor
	*/
	vector<Medicine> group = repo.compute_max_quant(quantity);

	for (int i = 0; i < group.size(); i++) {
		cout << group[i].get_name() << "\t" << group[i].get_concentration() << "\t" << group[i].get_price() << "\t" << group[i].get_quantity() << endl;
	}
}

void PharmacyController::show_partial(string partial) {
	/*
	Prints all medicine containing a given string
	Input:
		partial (string) - provided string
	@author: Victor
	*/
	vector<Medicine> group = repo.search_string(partial);
	
	for (int i = 0; i < group.size(); i++) {
		cout << group[i].get_name() << "\t" << group[i].get_concentration() << "\t" << group[i].get_price() << "\t" << group[i].get_quantity() << endl;
	}
}

void PharmacyController::add(string name, double concentration, int quantity, double price) {
	/*
	Added a new medicine to the list if does not exist in list or increase it's quantity with quantity value
	Input:
		name (string) - name of the new medicine
		concentration (double) - concentration of the new medicine
		price (double) - price of the new medicine
		quantity (double) - quantity of the new medicine
	@author: Stefan
	*/
	//searching for medicine in repo
	int index = repo.find(name, concentration);
	if (index == -1)//if medicine was not found add it into list
		repo.add_med(name, concentration, price, quantity);
	else {// if medicine was found increase it's quantity 
		int new_quantity = repo.get_quantity(index) + quantity; // calculating new quantity
		repo.update_med_quantity(index, new_quantity);
	}
}

bool PharmacyController::remove(string name, double concentration, int quantity) {
	/*
	Remove a medicine from the list if does exist in list and quantity is greater than medicine quantity and return true
	Decrease medicine's quantity with quantity if it is lower than medicine's and return true
	Return false if medicine is not in list
	Input:
		name (string) - name of the medicine
		concentration (double) - concentration of the medicine
		quantity (double) - quantity to be removed
	Output:
		Bool
	@author: Stefan
	*/
	int index = repo.find(name, concentration);
	if (index != -1) {
		if (repo.get_quantity(index) <= quantity)
			repo.remove_med(name, concentration);
		else {
			int new_quantity = repo.get_quantity(index) - quantity;
			repo.update_med_quantity(index, new_quantity);
		}
		return true;
	}
	return false;
}


void PharmacyController::print_all() {
	/*
	Prints elements form repository
	@author: Stefan
	*/
	Medicine* all = repo.get_all_med();
	cout << "Name\tConcentration\tPrice\tQuantity" << endl;
	for (int i = 0; i < repo.lenght(); i++)
		cout << all[i].get_name() << "\t" << all[i].get_concentration() << "\t" << all[i].get_price() << "\t" << all[i].get_quantity() << endl;
}

PharmacyController::~PharmacyController(){}
