#include <iostream>
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"
#include "PharmacyUI.h"
#include "Test.h"

int main()
{
    runAllTests();
    std::cout << "Hello World!\n";

    PharmacyRepository repo;
    for (int i = 130; i < 140; i++) {
        repo.add_med("paracetamol", 3, 140 - i, 10);
    }
    cout << "capra";
    PharmacyController new_ctrl(repo);
    PharmacyUI a;
    a.showUI();
}