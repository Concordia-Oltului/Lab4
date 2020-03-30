#include <cassert>
#include <iostream>
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"

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
		assert(test[i].get_concentration() == (130 + i));
	}
	for (int i = 130; i < 140; i++) {
		assert(repo.remove_med("paracetamol", i));
	}

}


void runAllTests() {
	test_getters_setters();
	test_add_remove_repo();
}