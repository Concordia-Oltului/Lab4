#include "PharmacyUI.h"


PharmacyUI::PharmacyUI() {
	PharmacyRepository repo;
	PharmacyController alt_ctrl(repo);
	ctrl = alt_ctrl;
}

PharmacyUI::PharmacyUI(PharmacyController& other) {
	ctrl = other;
}

void PharmacyUI::create_menu() {
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
	cout << "Main menu:" << endl;
	cout << "1. Update name" << endl;
	cout << "2. Update concentration" << endl;
	cout << "3. Update price" << endl;
	cout << "4. Update quantity" << endl;
	cout << "5. Undo" << endl;
	cout << "0. Back" << endl;
}

int PharmacyUI::get_user_option() {
	int nr;
	cout << "Enter a number" << endl;
	cin >> nr;
	return int(nr);
}

void PharmacyUI::main_menu(int choice) {
	if (choice == 1) {
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

		if (price < 0) {
			ctrl.add(name, concentration, quantity);
		}
		else {
			ctrl.add(name, concentration, quantity, price);
		}

	}
	if (choice == 2) {
		string name;
		double concentration;
		int quantity;
		cout << "Enter name of the medicine: ";
		cin >> name;
		cout << "Enter concetration of the medicine: ";
		cin >> concentration;
		cout << "Enter quantity to be removed: ";
		cin >> quantity;

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
	if (choice == 3) {
		string name;
		double concentration;
		cout << "Enter name of the new medicine: ";
		cin >> name;
		cout << "Enter concetration of the new medicine: ";
		cin >> concentration;
		if (ctrl.find(name, concentration) != -1) {
			create_update_menu();
			int update = get_user_option();
			if (update == 1) {
				string new_name;
				cout << "Enter new name:";
				cin >> new_name;
				ctrl.update_name(name, concentration, new_name);
			}
			if (update == 2) {
				double new_concentration;
				cout << "Enter new concentration:";
				cin >> new_concentration;
				ctrl.update_concentration(name, concentration, new_concentration);
			}
			if (update == 3) {
				double new_price;
				cout << "Enter new price:";
				cin >> new_price;
				ctrl.update_price(name, concentration, new_price);
			}
			if (update == 4) {
				double new_quantity;
				cout << "Enter new quantity:";
				cin >> new_quantity;
				ctrl.update_quantity(name, concentration, new_quantity);
			}
			if (update == 5) {
				// to do undo
			}
			if (update == 0) {
				// to do 
			}
		}
		else
			cout << name <<" not in list" << endl;
	}


	// To add... -> 4, 5

	if (choice == 6) {
		ctrl.sort_by_price();
		ctrl.print_all();
	}



}

void PharmacyUI::showUI(){
	create_menu();
	int choice = get_user_option();
	while (choice >= 1 && choice <= 7){
		main_menu(choice);
		create_menu();
		choice = get_user_option();
	}

}

PharmacyUI::~PharmacyUI() {
	cout << "bye" << endl;
}