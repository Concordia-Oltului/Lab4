#include <cassert>
#include <iostream>
#include <vector>
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"
#include "PharmacyController.h"

using namespace std;


void test_getters_setters() {
	Medicine p("paracetamol", 20, 4.5, 10);
	assert(p.get_name() == "paracetamol");
	assert(p.get_name() != "pamol");
	assert(p.get_concentration() == 20);
	assert(p.get_concentration() != 0);
	assert(p.get_price() == 4.5);
	assert(p.get_price() != 4);
	assert(p.get_quantity() == 10);
	assert(p.get_quantity() != 10.5);

	p.set_name("aspirina");
	p.set_concentration(10);
	p.set_price(5.5);
	p.set_quantity(25);

	assert(p.get_name() == "aspirina");
	assert(p.get_concentration() == 10);
	assert(p.get_price() == 5.5);
	assert(p.get_quantity() == 25);
}

void test_add_remove_repo() {
	PharmacyRepository repo;
	for (int i = 130; i < 140; i++) {
		repo.add_med("paracetamol", i, 4.5, 10);
	}
	Medicine* test = repo.get_all_med();
	for (int i = 0; i < 10; i++) {
		assert(test[i].get_concentration() == (130.0 + i));
	}
	for (int i = 130; i < 140; i++) {
		assert(repo.remove_med("paracetamol", i));
	}
}

void test_sort_by_price() {
	PharmacyRepository repo;
	for (int i = 130; i < 140; i++) {
		repo.add_med("paracetamol", 3, 140-i, 10);
	}
	repo.sort_by_price();

	Medicine* test = repo.get_all_med();
	for (int i = 0; i < 10; i++) {
		assert(test[i].get_price() == (i+1));
	}
}

void test_add_remove_controller() {
	PharmacyRepository repo;
	PharmacyController ctrl(repo);
	for (int i = 10; i < 30; i++) {
		ctrl.add("paracetamol", i, 5, 0.5*i);
		ctrl.add("paracetamol", i, 5);
	}
	for (int i = 0; i < 10; i++) {
		assert(ctrl.get_concentration(i) == (10.0 + i));
	}
	for (int i = 10; i < 30; i++) {
		assert(ctrl.remove("paracetamol", i, 7));
		assert(ctrl.remove("paracetamol", i, 1));
		assert(ctrl.remove("paracetamol", i));
		assert(ctrl.remove("paracetamol", i, 6));
	}
}

void test_update_controller() {
	PharmacyRepository repo;
	PharmacyController ctrl(repo);
	for (int i = 10; i < 30; i++) {
		ctrl.add("paracetamol", i, 5, 0.5 * i);
	}
	ctrl.update_name("paracetamol", 15, "aspirina");
	string aux = ctrl.get_name(5);
	assert(aux.compare("aspirina") == 0);
	ctrl.update_concentration("aspirina", 15, 12);
	assert(ctrl.get_concentration(5) == 12);
	ctrl.update_price("aspirina", 12, 432.4);
	assert(ctrl.get_price(5) == 432.4);
	ctrl.update_quantity("aspirina", 12, 120);
	assert(ctrl.get_quantity(5) == 120);
}

void test_compute_quantity() {
	PharmacyRepository repo;
	PharmacyController ctrl(repo);
	for (int i = 10; i < 30; i++) {
		repo.add_med("nurofen", 2 * i, 5, i);
	}
	vector<Medicine> grouped = repo.compute_max_quant(15);
	assert(grouped.size() == 6);
}

void test_search_string() {
	PharmacyRepository repo;
	PharmacyController ctrl(repo);
	for (int i = 10; i < 15; i++) {
		repo.add_med("nurofen", 2 * i, 5, i);
	}
	for (int i = 10; i < 15; i++) {
		repo.add_med("aflen", 2 * i, 5, i);
	}
	vector<Medicine> grouped = repo.search_string("fen");
	assert(grouped.size() == 5);
}

void runAllTests() {
	test_getters_setters();
	test_add_remove_repo();
	test_sort_by_price();
	test_add_remove_controller();
	test_update_controller();
	test_compute_quantity();
	test_search_string();
}