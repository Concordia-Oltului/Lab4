#include "PharmacyRepository.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

PharmacyRepository::PharmacyRepository() {
	//@author: Stefan
	capacity = 2;
	elements = 0;
	med = new Medicine[capacity];
}

PharmacyRepository PharmacyRepository::operator=(PharmacyRepository& repo){
	/*
	Copies the elements from repo in this repo and repo's capacity and elements became this instance capcity and elements
	Input:
		repo (PharmacyRepository) - source repository
	@author: Stefan
	*/
	capacity = repo.get_capacity();
	elements = repo.lenght();
	med = repo.get_all_med();
	return *this;
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

bool PharmacyRepository::update_med_name(int index, string name) {
	/*
	Change name of the element with the index index in med and then returns true
	If index is not in range of the array returns false
	Input:
		index (int) - index in med array
		name (string) - new name 
	Output:
		bool
	@author: Stefan
	*/
	if (index < 0 || index > elements)
		return false;
	else {
		med[index].set_name(name);
		return true;
	}
}

bool PharmacyRepository::update_med_concentration(int index, double concentration) {
	/*
	Change concentration of the element with the index index in med and then returns true
	If index is not in range of the array returns false
	Input:
		index (int) - index in med array
		concentration (double) - new concentration value
	Output:
		bool
	@author: Stefan
	*/
	if (index < 0 || index > elements)
		return false;
	else {
		med[index].set_concentration(concentration);
		return true;
	}
}

bool PharmacyRepository::update_med_price(int index, double price) {
	/*
	Change price of the element with the index index in med and then returns true
	If index is not in range of the array returns false
	Input:
		index (int) - index in med array
		price (double) - new price value
	Output:
		bool
	@author: Stefan
	*/
	if (index < 0 || index > elements)
		return false;
	else {
		med[index].set_price(price);
		return true;
	}
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

vector<Medicine> PharmacyRepository::compute_max_quant(int quantity) {
	/*
	Creates a vector with all medicine whose quantity is below the given parameter
	Input:
		quantity (int) - maximum quantity provided by user
	Output:
		vector<Medicine>
	@author: Victor
	*/
	vector<Medicine> grouped;
	for (int i = 0; i <= lenght() - 1; i++) {
		if (med[i].get_quantity() <= quantity) {
			grouped.push_back(med[i]);
		}
	}
	return grouped;
}

vector<Medicine> PharmacyRepository::search_string(string partial) {
	/*
	Creates a vector with all medicine which contain a certain string given by parameter
	Input:
		partial (string) - provided string
	Output:
		vector<Medicine>
	@author: Victor
	*/
	unsigned int ctr = 0, j = 0;
	string aux;
	vector<Medicine> grouped;
	for (int i = 0; i <= lenght() - 1; i++) {
		aux = med[i].get_name();
		ctr = i;
		j = 0;
		while (ctr < aux.size()) {
			while (aux[ctr] == partial[j] && j < partial.size() && ctr < aux.size()) {
				ctr++;
				j++;
			}
			if (j == partial.size()) {
				grouped.push_back(med[i]);
				break;
			}
			ctr++;
		}
	}
	return grouped;
}


int PharmacyRepository::count_by_price(double minim, double maxim) {
	/*
	Returns the number of form repository with a price value between minim and maxim
	Input:
		minim(double) - minimum price to be in group
		maxim(double) - maximum price to be in group
	Output:
		int
	@author: Stefan
	*/
	int k = 0;
	for (int i = 0; i < elements; i++) {
		if (med[i].get_price() >= minim && med[i].get_price() <= maxim)
			k++;
	}
	return k;
}

Medicine* PharmacyRepository::group_by_price(double minim, double maxim){
	/*
	Returns elements form repository with a price value between minim and maxim
	Input:
		minim(double) - minimum price to be in group
		maxim(double) - maximum price to be in group
	Output:
		Medicine*
	@author: Stefan
	*/
	Medicine* rez = new Medicine[elements];
	int k = 0;
	for (int i = 0; i < elements; i++) {
		if (med[i].get_price() >= minim && med[i].get_price() <= maxim)
			rez[k++] = med[i];
	}
	return rez;
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
	//if (elements != 0)
	//	delete[] med;
}