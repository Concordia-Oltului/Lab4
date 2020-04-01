#pragma once
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"
#include "PharmacyController.h"

class PharmacyUI{
private:
	PharmacyController ctrl;
public:

	PharmacyUI();

	PharmacyUI(PharmacyController& other);

	void create_menu();

	void create_update_menu();

	int get_user_option();

	void main_menu(int choice);

	void showUI();

	~PharmacyUI();

};

