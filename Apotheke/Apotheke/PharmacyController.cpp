#include "PharmacyController.h"
#include <iostream>

using namespace std;

PharmacyController::PharmacyController(PharmacyRepository repository) {
	repo = repository;
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
	int index = repo.find(name, quantity);
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
	int index = repo.find(name, quantity);
	if (index != -1) {
		if (repo.get_quantity(index)<quantity)
			repo.remove_med(name, concentration);
		else {
			int new_quantity = repo.get_quantity(index) - quantity;
			repo.update_med_quantity(index, new_quantity);
		}
		return true;
	}
	return false;
}


PharmacyController::~PharmacyController(){}
