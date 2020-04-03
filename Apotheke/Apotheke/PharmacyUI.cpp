#include "PharmacyUI.h"


PharmacyUI::PharmacyUI() {
	//@author: Stefan

	// create a new controller
	PharmacyController alt_ctrl;
	ctrl = alt_ctrl;

	//undo variables 
	last_choice = -1;
	last_update = -1;
}

PharmacyUI::PharmacyUI(PharmacyController& other) {
	//@author: Stefan

	// copies other to ctrl
	ctrl = other;
	//undo variable
	last_choice = -1;
	last_update = -1;
}

void PharmacyUI::create_menu() {
	//@author: Stefan

	//Create general menu
	cout << "Main menu:" << endl;
	cout << "1. Add new medicine" << endl;
	cout << "2. Remove medicine" << endl;
	cout << "3. Edit medicine" << endl;
	cout << "4. Search" << endl;
	cout << "5. Less than" << endl;
	cout << "6. Sort by price" << endl;
	cout << "7. Undo" << endl;
	cout << "0. Exit" << endl;
}

void PharmacyUI::create_update_menu() {
	//@author: Stefan

	//Create general menu
	cout << "Update menu:" << endl;
	cout << "1. Update name" << endl;
	cout << "2. Update concentration" << endl;
	cout << "3. Update price" << endl;
	cout << "4. Update quantity" << endl;
	cout << "5. Undo" << endl;
	cout << "0. Back" << endl;
}

int PharmacyUI::get_user_option() {
	//@author: Stefan

	//Get user option from keyboard
	int nr;
	cout << "Enter a number" << endl;
	cin >> nr;
	return int(nr);
}

void PharmacyUI::main_menu(int choice) {
	// Applying changes to the controller depends of user choice
	if(choice != 7)// if choice is  not undo last_choice become curent choice
		last_choice = choice; // for undo
	if (choice == 1) { //  Add opotion
		// @author: Stefan
		string name;
		double concentration, price;
		int quantity;
		cout << "Enter name of the new medicine: ";
		cin >> name;
		cout << "Enter concetration of the new medicine: ";
		cin >> concentration;
		cout << "Enter price of the new medicine: ";
		cin >> price;
		cout << "Enter quantity of the new medicine: ";
		cin >> quantity;

		// save user input in case of undo
		set_last(name, concentration, quantity, price); // undo

		if (price < 0) {
			ctrl.add(name, concentration, quantity);
		}
		else {
			ctrl.add(name, concentration, quantity, price);
		}

	}
	if (choice == 2) {//  Remove opotion
		// @author: Stefan
		string name;
		double concentration;
		int quantity;
		cout << "Enter name of the medicine: ";
		cin >> name;
		cout << "Enter concetration of the medicine: ";
		cin >> concentration;
		cout << "Enter quantity to be removed: ";
		cin >> quantity;

		// save user input in case of undo
		set_last(name, concentration, quantity, ctrl.get_price(ctrl.find(name, concentration))); // undo

		if (quantity > 0) {
			bool check = ctrl.remove(name, concentration, quantity);
			if (check == false)
				cout << name << " not found!" << endl;
			ctrl.print_all();
		}
		else {
			bool check = ctrl.remove(name, concentration);
			if (check == false)
				cout << name << " not found!" << endl;
			ctrl.print_all();
		}
	}
	if (choice == 3) {//  Update opotion
		// @author: Stefan
		string name;
		double concentration;
		cout << "Enter name of the new medicine: ";
		cin >> name;
		cout << "Enter concetration of the new medicine: ";
		cin >> concentration;

		// save user input in case of undo
		set_last(name, concentration, -1, -1); // undo

		if (ctrl.find(name, concentration) != -1) { // if medicine is in list
			create_update_menu();
			int update = get_user_option();
			last_update = update; // save user option for update menu
			if (update == 1) { // change name
				string new_name;
				cout << "Enter new name:";
				cin >> new_name;
				last_changed_name = name; // save curent name in case of undo
				last_name = new_name; // save new name in case of undo 
				ctrl.update_name(name, concentration, new_name);
			}
			if (update == 2) { // change concentration
				double new_concentration;
				cout << "Enter new concentration:";
				cin >> new_concentration;
				last_changed_concentration = concentration; // save curent concentration in case of undo 
				last_concentration = new_concentration; // save new concentration in case of undo 
				ctrl.update_concentration(name, concentration, new_concentration);
			}
			if (update == 3) { // change price
				double new_price;
				cout << "Enter new price:";
				cin >> new_price;
				last_changed_price = ctrl.get_price(ctrl.find(name, concentration)); // save curent price in case of undo 
				ctrl.update_price(name, concentration, new_price);
			}
			if (update == 4) { // change quantity
				double new_quantity;
				cout << "Enter new quantity:";
				cin >> new_quantity;
				last_changed_quantity = ctrl.get_quantity(ctrl.find(name, concentration)); // save curent quantity in case of undo 
				ctrl.update_quantity(name, concentration, new_quantity);
			}
			if (update == 5) {
				undo_update();
			}
		}
		else // and if is not print show a message
			cout << name <<" not in list" << endl;
	}


	// To add... -> 4, 5


	if (choice == 6) { // sort medicines by price 
		//@author: Stefan
		ctrl.sort_by_price();
		ctrl.print_all();
	}
	if (choice == 7) { // undo operation
		undo();
	}



}

void PharmacyUI::set_last(string name, double concentration, int quantity, double price) {
	/*
	Sets last_name, last_concentration, last_price, last_quantity for undo operation
	Input:
		- name (string)
		- concentration (double)
		- price (double)
		- quantity (int)
	@author: Stefan
	*/
	last_name = name;
	last_concentration = concentration;
	last_price = price;
	last_quantity = quantity;
}


void PharmacyUI::undo_update() {
	/*
	Does the undo operation for update depends of last_update value 
	@author: Stefan
	*/

	if (last_update != -1) {
		if (last_update == 1) {
			ctrl.update_name(last_name, last_concentration, last_changed_name);
		}
		if (last_update == 2) {
			ctrl.update_concentration(last_name, last_concentration, last_changed_concentration);
		}
		if (last_update == 3) {
			ctrl.update_price(last_name, last_concentration, last_changed_price);
		}
		if (last_update == 4) {
			ctrl.update_quantity(last_name, last_concentration, last_changed_quantity);
		}
	}
	else {
		cout << "Nothing to undo!" << endl;
	}
}

void PharmacyUI::undo() {
	//Does the undo operation depends of last_choice value

	if (last_choice != -1) {

		if (last_choice == 1){ // add->remove
			// author: Stefan
			if (last_quantity > 0) {
				bool check = ctrl.remove(last_name, last_concentration, last_quantity);
			}
			else {
				bool check = ctrl.remove(last_name, last_concentration);
			}
		}
		if (last_choice == 2) { // remove->add
			// author: Stefan
			if (last_price < 0) {
				ctrl.add(last_name, last_concentration, last_quantity);
			}
			else {
				ctrl.add(last_name, last_concentration, last_quantity, last_price);
			}
		}
		if (last_choice == 3) {
			// author: Stefan
			undo_update(); // undo update
		}

		// 4 .. 5

	}
	else{
		cout << "Nothing to undo" << endl;
	}


}

void PharmacyUI::showUI(){
	// Create user interface
	create_menu();
	int choice = get_user_option();
	while (choice >= 1 && choice <= 7){
		main_menu(choice);
		create_menu();
		choice = get_user_option();
	}

}

PharmacyUI::~PharmacyUI() {}