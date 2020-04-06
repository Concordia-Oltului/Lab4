#include <iostream>
#include "PharmacyDomain.h"
#include "PharmacyRepository.h"
#include "PharmacyUI.h"
#include "Test.h"

int main()
{
    runAllTests();

    PharmacyRepository repo;
    PharmacyController new_ctrl(repo);
    PharmacyUI a;
    a.showUI();
}