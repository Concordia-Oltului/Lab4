#pragma once
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"
#include "PharmacyController.h"

class PharmacyUI{
private:
	PharmacyController ctrl;
	int last_choice, last_update;
	// undo variable
	string last_name;
	double last_concentration, last_price;
	int last_quantity;
	// undo update variable
	string last_changed_name;
	double last_changed_concentration, last_changed_price;
	int last_changed_quantity;
public:

	PharmacyUI();

	PharmacyUI(PharmacyController& other);

	void create_menu();

	void create_update_menu();

	int get_user_option();

	void main_menu(int choice);

	void set_last(string name, double concentration, int quantity, double price);

	void set_undo(int choice);
	
	void undo_update();

	void undo();

	void showUI();

	~PharmacyUI();

};

