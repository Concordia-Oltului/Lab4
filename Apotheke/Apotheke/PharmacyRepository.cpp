#include "PharmacyRepository.h"
#include <iostream>

using namespace std;

PharmacyRepository::PharmacyRepository() {
	//@author: Stefan
	capacity = 2;
	elements = 0;
	med = new Medicine[capacity];
}

void PharmacyRepository::operator=(PharmacyRepository repo){
	/*
	Copies the elements from repo in this repo and repo's capacity and elements became this instance capcity and elements
	Input:
		repo (PharmacyRepository) - source repository
	@author: Stefan
	*/
	capacity = repo.get_capacity();
	elements = repo.lenght();
	Medicine* med = repo.get_all_med();
}

void PharmacyRepository::add_med(string name, double concentration, double price, int quantity) {
	/*
	Adds a new object of type Medicine to array;
	Input:
		name (string) - name of the new medicine
		concentration (double) - concentration of the new medicine
		price (double) - price of the new medicine
		quantity (double) - quantity of the new medicine
	Output:
		-
	@author: Stefan
	*/
	if (elements == capacity) {
		Medicine* new_arr = new Medicine[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			new_arr[i] = med[i];
		}
		delete[] med;
		capacity *= 2;
		med = new_arr;
	}
	Medicine new_med(name, concentration, price, quantity);
	med[elements] = new_med;
	elements++;
}

int PharmacyRepository::find(string name, double concentration) {
	/*
	Search if exists an element with the name name and concentration concentration in array
	and returns it's position and if doesn't exist returs -1;
	Input:
		name (string) - name of the searched medicine
		concentration (double) - concentration of the searched medicine
	Output:
		int
	@author: Stefan
	*/
	for (int i = 0; i < elements; i++) {
		if (name.compare(med[i].get_name()) == 0 && concentration == med[i].get_concentration()) {
			return i;
		}
	}
	return -1;
}

bool PharmacyRepository::update_med_quantity(int index, int quantity) {
	/*
	Change quantity of the element with the index index in med and then returns true
	If index is not in range of the array returns false
	Input:
		index (int) - index in med array
		quantity (int) - new quantity value
	Output:
		bool
	@author: Stefan
	*/
	if (index < 0 || index > elements)
		return false;
	else{
		med[index].set_quantity(quantity);
		return true;
	}
}

bool PharmacyRepository::remove_med(string name, double concentration) {
	/*
	Removes the element with name name and concentration concentration if exists in list and return true
	if object is not in array returns false;
	Input:
		name (string) - name of the medicine to be removed
		concentration (double) - concentration of the medicine to be removed
	Output:
		bool
	*/
	int index = find(name, concentration);
	if (index == -1)
		return false;
	else {
		for (int i = index; i < elements - 1; i++)
			med[i] = med[i + 1];
		elements--;
		return true;
	}
}

void PharmacyRepository::sort_by_price() {
	/*
	Sorts the medicines from repository by price
	@author: Stefan
	*/

	int sch = 1;
	while (sch)
	{
		sch = 0;
		for (int i = 0; i < lenght()-1; i++) {
			if (med[i].get_price() > med[i + 1].get_price()) {
				Medicine aux;
				aux = med[i];
				med[i] = med[i + 1];
				med[i + 1] = aux;
				sch = 1;
			}
		}
	}
}

Medicine* PharmacyRepository::get_all_med() {
	/*
	Returns all medicines from the list 
	Output:
		Medicine*
	@author: Stefan
	*/
	return med;
}

PharmacyRepository::~PharmacyRepository() {
	if (elements != 0)
		delete[] med;
}