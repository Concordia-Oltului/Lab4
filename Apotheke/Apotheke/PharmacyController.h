#pragma once
#include "PharmacyRepository.h"

using namespace std;

class PharmacyController {
private:
	PharmacyRepository repo;
public:
	PharmacyController(const PharmacyRepository repository);

	void add(string name, double concentration, int quantity = 1, double price = 0);

	bool remove(string name, double concentration, int quantity = 1);

	~PharmacyController();
};
