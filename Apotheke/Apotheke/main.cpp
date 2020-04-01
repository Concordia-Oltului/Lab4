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
    PharmacyController new_ctrl(repo);
    PharmacyUI a(new_ctrl);
    a.showUI();
}